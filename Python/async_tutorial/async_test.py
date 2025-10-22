#!/home/greenshoots/Documentos/GitHub/Projects/Python/async_tutorial/venv/bin/python3

# Learning async in python

import asyncio as asy

# Function to check to see if the user input was numeric
def is_number(n):
    try:
        return float(n)
    except ValueError as ve:
        print(ve)

# Function to be delayed
async def my_output(n: int | float = 0) -> str:
    print(f"\nThis line was delayed by {n} seconds\n")

async def main():
    # User input
    my_num = input("\nDelay ouput by how many seconds? ")

    # Checking if the user didn't make an input
    if my_num == '':
        my_num = 0
    else:
        my_num = is_number(my_num)

    # Convert to Int if that was what the user typed
    if my_num.is_integer():
        my_num = int(my_num)

    await asy.sleep(my_num) # Sleeping
    await my_output(my_num) # Execute the delayed function

# Program entry point
if __name__ == "__main__":
    asy.run(main())
