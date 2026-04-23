#!/home/greenshoots/Documentos/GitHub/Projects/Python/pandas_tutorial/venv/bin/python3

# Filtering Data With Pandas

import pandas as pd

# Variables
cols_list = [ "Name", "Height", "Weight" ]
rows_list = [ num + 1 for num in range(15) ]

# Importing a .csv file into a pandas DataFrame
df_1 = pd.read_csv("./data/data_01.csv", index_col="No")

# Filtering by a single point in the data
df_2 = df_1[ df_1["Type1"] == "Grass" ]

# Filetring by a range of values
df_3 = df_1[ df_1["Weight"] >= 100 ]

# Filtering by a range between two values
# df_4 = df_1[ (df_1["Type1"] == "Grass") & (df_1["Type2"] == "Poison") ]
df_4 = df_1[ (df_1["Weight"] >= 50) & (df_1["Weight"] <= 150) ]

# Filtering Null values out
df_5 = df_1.sort_values(by="Type2").dropna(subset=["Type2"])

# Filter specified value out
df_6 = df_1.value_counts(subset="Weight").loc[lambda x: x >= 2].reset_index(name='total') 
# The 'reset_index(name=...)' part will rename the totals column that is nameless by default

# Filtering columns with the 'filter' function 
df_7_1 = df_1.filter(items=cols_list, axis=1) # 'axis=1' will filter by columns, if 'axis=0' it will filter by rows
df_7_2 = df_1.filter(items=rows_list, axis=0) 

# Filtering rows and columns using the 'loc' function
df_8 = df_1.loc[rows_list, cols_list]

# Output to console
# print(df_6.to_string(index=False))
print(f"\n{df_8.to_string()}\n")
