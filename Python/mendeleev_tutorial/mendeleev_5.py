#!/home/greenrocket23/Documentos/GitHub/Projects/Python/mendeleev_tutorial/venv/bin/python3

# Learning how to use this Chemistry library for Python

# Imports =========================================================================

## Suppress a FutureWarning from the mendeleev library
import warnings

warnings.simplefilter(action="ignore", 
                      category="FutureWarning")

## Libraries being used
from mendeleev.vis import periodic_table
from bokeh.io import output_file, save

# Variables ==========================================================================

## Textual pad
pad = f"{' ':<4}"

## Periodic table plot
periodic_table_plot = periodic_table(height=600, 
                                     width=800, 
                                     title="Periodic Table",
                                     backend="bokeh")

## Setting the name of the output file
output_file("periodic_table.html")

## Save generated plot to output file
save(periodic_table_plot)

# Output ==========================================================================

print(f"\n{pad}Visualisation saved successfully to 'periodic_table.html'\n")
