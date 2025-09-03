#!/usr/bin/python3

import pandas as pd

calories = {"Day 1": 1750, "Day 2": 2100, "Day 3": 1700} # python dictionary

series_calories = pd.Series(calories)
# series_calories.loc["Day 3"] += 500 

print(f"\n{series_calories}\n")
# print(f'Day 3 = {series_calories.loc["Day 3"]}\n\n')
print(f'Calories below 2000: \n\n{series_calories.loc[series_calories < 2000]}\n\n')
