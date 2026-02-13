#!/usr/bin/python3

# *args   = allows you to pass multiple non-key arguments,
#           and will return an tuple.
# **kargs = allows you to pass multiple keyword-arguments,
#           and will return a python dictionary (key and value pairs)
#
# '*' is the unpacking operator 

# Example Functions
def my_add(*args):
    result = 0
    for item in args:
        result += item
    return result

def return_items(*args):
    for i, item in enumerate(args):
        if (i == (len(args) - 1)):
            yield f"{item}"
        else:
            yield f"{item}, "

def my_print_kwargs(**kwargs):
    for i, (key, value) in enumerate(kwargs.items()):
        if (i == (len(kwargs.items()) - 1)):
            yield f"{key}: {value}"
        else:
            yield f"{key}: {value}, "

def shipping_label(*args, **kwargs):
    # Processings *args
    for i, item in enumerate(args):
        if (i == (len(args) - 1)):
            yield f"{item}\n{' ':<4}"
        else:
            yield f"{item} "
    # Processing **kwargs
    for i, value in enumerate(kwargs.values()):
        if (i == (len(kwargs.values()) - 1)):
            yield f"{value}"
        else:
            yield f"{value} "

# Example dictionaries
args_1 = {"name": "Robert", "age": 32}
args_2 = {"name": "John", "age": 18}

print(f"\n{' ':<4}my_add = {my_add(4, 5, 6)}")
print(f"\n{' ':<4}my_print_kwargs = {''.join(my_print_kwargs(name='Robert', age=32))}")
print(f"\n{' ':<4}return_items = {''.join(return_items(args_1, args_2))}")
print(f"\n{' ':<4}shipping_label = {''.join(shipping_label('Dr.', 'Spongebob', 'Squerpants', 'III', \
                                                            street='123 Fake St.', \
                                                            apt='100', \
                                                            city='Detroit', \
                                                            state='Michigan', \
                                                            zip='54321',))}")
