#!/usr/bin/python3

import pandas as pd

# the data is located at ./data/data_01.csv

df = pd.read_csv("./data/data_01.csv")

# print(f"\n{df.to_string()}\n")
print(f"\n{df.loc[0]}\n")
