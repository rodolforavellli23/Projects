#!/home/greenshoots/Documentos/GitHub/Projects/Python/pandas_tutorial/venv/bin/python3

import pandas as pd

# A Series is a one-dimensional labeled array that can hold data of any type. Think of it like a single column in a spreadsheet.
# Each value in a Series has an associated index label (like row numbers, but can be customized).

# Note_01: In Python, cunstructors are captalized, unlike functions and variables (which must start with a lowercase character by convention)

data_int    = [100, 102, 104, 200, 202] # python lists (are arrays)
data_float  = [100.1, 102.2, 104.3]
data_string = ["A", "B", "C"]
data_bool   = [True, False, True]

# series_data = pd.Series(data_bool)
series_data = pd.Series(data_int)
# series_data = pd.Series(data_bool, index=["a", "b", "c"])
# series_data = pd.Series(data_int, index=["Apt.01", "Apt.02", "Apt.03"])
# series_data = pd.Series(data_int, index=["a", "b", "c"])
# series_data.loc["c"] = 200

# print(f'\n{series_data}\n\n"c" = {series_data.loc["c"]}\n\n')
# print(f'\n{series_data}\n\n"c" = {series_data.iloc[2]}')
# print(f'\n"a" = {series_data.iloc[0]}\n\n')
print(f"\n{series_data[series_data < 200]}\n\n")
