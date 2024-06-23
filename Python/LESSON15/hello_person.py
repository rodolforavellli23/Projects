# LESSON 15 - Python Command Line Arguments

import argparse

# parser = argparse.ArgumentParser(description='Process some integers.')
# parser.add_argument('integers', metavar='N', type=int, nargs='+',
#                     help='an integer for the accumulator')
# parser.add_argument('--sum', dest='accumulate', action='store_const',
#                     const=sum, default=max,
#                     help='sum the integers (default: find the max)')

# args = parser.parse_args()
# print(args.accumulate(args.integers))

parser = argparse.ArgumentParser(description="Provides a personal greeting.") # Creates the parser

parser.add_argument(
    "-n", "--name", metavar="name"
    required="True", help="The name of the person to be greeted"
) # Adds the argument

args = parser.parse_args() # Parses arguments

msg = f"Hello {args.name}" # message to be given to the user