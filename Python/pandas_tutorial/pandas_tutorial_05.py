#!/usr/bin/python3

import pandas as pd

def repeat(n: str, i: int)->str:
    out = f"{n}" * i
    return out

Australia = {
        "States and Territories": [
            "New South Wales",
            "Victoria",
            "Queensland",
            "Western Australia",
            "South Australia",
            "Tasmania",
            "Australian Capital Territory",
            "Northern Territory"],
        "Population": [
            "8,339,347",
            "6,812,477",
            "5,459,413",
            "2,878,563",
            "1,851,704",
              "572,780",
              "466,813",
              "252,473"],
        "Area (km²)": [
              "800,150 km²",
              "227,444 km²",
            "1,729,742 km²",
            "2,527,013 km²",
              "983,482 km²",
               "68,401 km²",
                "2,356 km²",
            "1,420,970 km²"
            ]
        }

units = Australia["States and Territories"]

count = list()

for i in range(1, (len(units) + 1)):
    count.append(i)

df = pd.DataFrame(Australia, index=count)

print(f"\nAustralia\n{repeat('-', 9)}\n{df}")
