#!/usr/bin/python3

import sqlite3
import pika
import json

# 1. Connect to RabbitMQ
connection = pika.BlockingConnection(pika.ConnectionParameters('localhost'))
channel = connection.channel()

# Declare a durable exchange of type 'direct'
EXCHANGE_NAME = 'db_migration_exchange'
channel.exchange_declare(exchange=EXCHANGE_NAME, exchange_type='direct', durable=True)
channel.queue_declare(queue='target_db_queue', durable=True)
channel.queue_bind(exchange='db_migration_exchange', queue='target_db_queue', routing_key='migration_routing_key')

# 2. Extract Data from Source Database
db_connection = sqlite3.connect('banco1.db')
cursor = db_connection.cursor()

# We grab the rows from our source table
cursor.execute("SELECT id, name, email FROM users")
rows = cursor.fetchall()

print(f"[*] Found {len(rows)} records in first.db. Starting migration dump...")

# 3. Publish rows to RabbitMQ
for row in rows:
    payload = {
        "table": "users",
        "action": "INSERT",
        "data": {
            "id": row[0],
            "name": row[1],
            "email": row[2]
        }
    }
    
    # Send message to the exchange with a specific routing key
    channel.basic_publish(
        exchange=EXCHANGE_NAME,
        routing_key='migration_routing_key',
        body=json.dumps(payload),
        properties=pika.BasicProperties(
            delivery_mode=2,  # Make message persistent on disk
        )
    )
    print(f" [x] Sent to Exchange: {payload['data']['name']}")

# Clean up connections
db_connection.close()
connection.close()
print("[*] All migration data sent to RabbitMQ.")
