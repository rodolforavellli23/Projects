#!/home/greenrocket23/Documentos/GitHub/Projects/Python/mendeleev_tutorial/venv/bin/python3

# Learning how to use this Chemistry library for Python

# Imports =============================================================

from mendeleev import element 
from mendeleev.fetch import fetch_table

# Variables ===========================================================

elements_df = fetch_table("elements")

cols = ["name", 
        "symbol", 
        "atomic_number", 
        "atomic_radius", 
        "density"] # These are just a few of the data fields you can get
                   # from this chemistry library

# Specify unique widths for individual columns with a dictionary
widths = {"name": 0,
          "symbol": 10,
          "atomic_number": 15,
          "atomic_radius": 20,
          "density": 18}

# New header names for the columns
new_header = ["Name", 
              "Symbol", 
              "Atomic Number", 
              "Atomic Radius (ρm)", 
              "Density (g/cm³)"]

# Getting the dataframe as a string
raw_str = elements_df[cols].head(25).to_string(index=False, 
                                               header=new_header,
                                               col_space=widths)

l_str = raw_str.splitlines() # This function creates a list with
                             # each item being a line that ended 
                             # in a new line char

format_str = "\n".join(f"{' ':<4}{line}" for line in l_str)

# Text Output ========================================================

print(f"\n{format_str}\n")
