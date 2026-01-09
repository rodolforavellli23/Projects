#!/usr/bin/python3

# Define color codes using ANSI terminal escape sequences
class Colors:
    RED = '\033[91m'
    GREEN = '\033[92m'
    YELLOW = '\033[93m'
    BLUE = '\033[94m'
    ELECTRIC_BLUE = '\033[38;2;125;249;255m'
    ENDC = '\033[0m' # Reset code

# File reader function 
def read_file(file_path: str) -> str:
    with open(file_path) as file:
        for line in file:
            yield f"{' ':<4}{line}"

path = str(input(f"\n{' ':<4}{Colors.ELECTRIC_BLUE}Please provide a valid path for the file that you wish to print:{Colors.ENDC} "))

print(f"\n{''.join(read_file(path))}")
