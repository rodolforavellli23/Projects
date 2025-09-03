#!/home/greenshoots/Documentos/GitHub/Projects/Python/pandas_tutorial/venv/bin/python3

import pandas as pd

Australia = ["New South Wales", "Victoria", "Queensland", "Western Australia", "South Australia", "Tasmania"]
counter   = range(1, (len(Australia) + 1))
series_Australia = pd.Series(Australia, index=counter)

print(f"\n{series_Australia}\n\n")
