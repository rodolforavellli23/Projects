#!/home/greenrocket23/Documentos/GitHub/Projects/Python/mendeleev_tutorial/venv/bin/python3

# Learning how to use this Chemistry library for Python

# Imports =========================================================================

from mendeleev import element 
import textwrap

# Functions =======================================================================

def has_no_digit(s: str)->bool:
    return not any(c.isdigit() for c in s)

def parse_and_check_type(str_input: str, pad: str):
    try:
        if (has_no_digit(str_input)):
            return str_input
        
        num = float(str_input)

        if num.is_integer():
            return int(num)
        else:
            raise ValueError

    except ValueError:
        print(f"\n{pad}Only type either a string or an integer!\n")

    except Exception as e:
        print(f"\n{pad}An unexpected error has occurred!\n{pad}{e}\n")

# Variables =======================================================================

## Textual padding
pad = f"{' ':<4}"

## User input sanitation
my_symbol = str(input(f"\n{pad}Declare an atomic element symbol, or its atomic number: "))

treated_user_input = parse_and_check_type(my_symbol, pad)

## Getting the element object from the sanitized user input
my_element = element(treated_user_input)

## Information to be returned

### Name
element_name = f"{pad}The element's name is: {my_element.name}" 

### Electronic shell configuration (using textwrap for nicer formatting)
message_1 = f"{pad}The element's electronic shell configuration is: {dict(my_element.ec.conf)}"
element_electronic_shell = textwrap.fill(message_1, 
                                         width=100, 
                                         subsequent_indent=pad)

### Number of electrons per electronic shell
message_2 = f"{pad}The element's number of electrons per valence shell is: " + \
            f"{my_element.ec.electrons_per_shell()}"
element_number_of_electrons = textwrap.fill(message_2, 
                                            width=100,
                                            subsequent_indent=pad)
### Total Number of electrons
element_total_number_of_electrons = f"{pad}The element's total number of electrons when " + \
                                    f"electrically neutral is: {my_element.electrons}"

# Text Output =====================================================================

print(f"\n{element_name}\n"
      f"\n{element_electronic_shell}\n"
      f"\n{element_number_of_electrons}\n"
      f"\n{element_total_number_of_electrons}\n")
