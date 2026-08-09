#!/home/greenrocket23/Documentos/GitHub/Projects/Python/mendeleev_tutorial/venv/bin/python3

# Learning how to use this Chemistry library for Python

# Imports =============================================================

from mendeleev import element 
from mendeleev.fetch import fetch_table

# Variables ===========================================================

groups_df = fetch_table("groups")

# Specify unique widths for individual columns with a dictionary
widths = {"group_id": 0,
          "symbol": 10,
          "name": 17}

# New header names for the columns
new_header = ["Group ID", "Symbol", "Name"]

# Getting the dataframe as a string
raw_str = groups_df.to_string(index=False, 
                              header=new_header,
                              col_space=widths)

l_str = raw_str.splitlines() # This function creates a list with
                             # each item being a line that ended 
                             # in a new line char

format_str = "\n".join(f"{' ':<4}{line}" for line in l_str)

# Text Output ========================================================

print(f"\n{format_str}\n")
