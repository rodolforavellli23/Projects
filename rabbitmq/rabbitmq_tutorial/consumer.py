#!/usr/bin/python3

import sqlite3
import pika
import json
import sys

# 1. Connect to RabbitMQ
connection = pika.BlockingConnection(pika.ConnectionParameters('localhost'))
channel = connection.channel()

EXCHANGE_NAME = 'db_migration_exchange'
QUEUE_NAME = 'target_db_queue'

print(' [*] Consumer active. Waiting for replication payloads. To exit press CTRL+C')

# 2. Define how to process received messages
def callback(ch, method, properties, body):
    payload = json.loads(body)
    table = payload['table']
    data = payload['data']
    
    # Connect to the target database
    db_connection = sqlite3.connect('banco2.db')
    cursor = db_connection.cursor()
    
    try:
        # Use INSERT OR IGNORE to handle duplicates gracefully if run multiple times
        query = f"INSERT OR IGNORE INTO {table} (id, name, email) VALUES (?, ?, ?)"
        cursor.execute(query, (data['id'], data['name'], data['email']))
        db_connection.commit()
        print(f" [->] Successfully written to second.db: {data['name']}")
        
        # Acknowledge successful processing to RabbitMQ
        ch.basic_ack(delivery_tag=method.delivery_tag)
        
    except sqlite3.Error as e:
        print(f" [!] Database Error: {e}")
        # Reject message and requeue it if database is locked or down
        ch.basic_nack(delivery_tag=method.delivery_tag, requeue=True)
        
    finally:
        db_connection.close()

# Ensure the consumer only grabs 1 message at a time
channel.basic_qos(prefetch_count=1)
channel.basic_consume(queue=QUEUE_NAME, on_message_callback=callback)

try:
    channel.start_consuming()
except KeyboardInterrupt:
    print('\n[*] Consumer stopping safely.')
    connection.close()
    sys.exit(0)
