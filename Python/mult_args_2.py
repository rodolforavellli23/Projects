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
    return ", ".join(f"{key}: {value}" for key, value in kwargs.items())

def my_kwargs_list(keys: list, items: list)->str:
    # Zip keys with each individual sub-list (record)
    data = [dict(zip(keys, record)) for record in values]
    # Use join to handle the semicolon separator between records
    results = [my_print_kwargs(**item) for item in data]
    my_string = "; ".join(results)

    return my_string

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
keys = ["name", "age"]
values = [["Robert", 32], ["John", 18]]

str_1 = my_kwargs_list(keys, values)

print(f"\n{' ':<4}my_add = {my_add(4, 5, 6)}")
print(f"\n{' ':<4}my_print_kwargs = {''.join(my_print_kwargs(name='Robert', age=32))}")
print(f"\n{' ':<4}return_items = {str_1}")
print(f"\n{' ':<4}shipping_label = {''.join(shipping_label('Dr.', 'Spongebob', 'Squerpants', 'III', \
                                                            street='123 Fake St.', \
                                                            apt='100', \
                                                            city='Detroit', \
                                                            state='Michigan', \
                                                            zip='54321',))}")