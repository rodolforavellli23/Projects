#!/usr/bin/python3

# How to manually interpolate (or extrapolate) using python

# Functions
def m_slope(y2:float, y1:float, x2:float, x1:float)->float:
    m = (y2 - y1)/(x2 - x1)
    return m

def line_eq(x_new:float, x1:float, y1:float, m:float)->float:
    y = y1 + ((x_new - x1)*m)
    return y

def main():
    # Local Variables
    pad=f"{' ':<4}"

    # Padding
    print()

    # Main Loop
    while(True):
        print(f"\n{pad}Provide the values for x1, x2, y1, y2 and the x value you want to iterpolate to:\n")
        x1=float(input(f"{pad}Value x1: "))
        x2=float(input(f"{pad}Value x2: "))
        y1=float(input(f"{pad}Value y1: "))
        y2=float(input(f"{pad}Value y2: "))
        x_new=float(input(f"{pad}Value x_new: "))

        m = m_slope(y2, y1, x2, x1)

        y = line_eq(x_new, x1, y1, m)

        print(f"\n{pad}Interpolated Value for {x_new}: {y:.4f}\n\n"
              f"{pad}Do you wish to interpolate a value again? (type 'yes' or 'no'): ", end="")
        decision=str(input())

        if decision == "yes":
            print()
            continue
        elif decision == "no":
            print()
            break
        else:
            print(f"\n\n{pad}Invalid input! Exiting program...\n\n")
            break

# Program Entry Point
if __name__ == "__main__":
    main()