#!/usr/bin/python3

def calculate_grades(**kwargs):
    if not kwargs:
        print("\n\tNo grades provided!")
        return

    total = 0
    print("\n\tGrades Received:")
    for subject, grade in kwargs.items():
        print(f"\t{subject}: {grade}")
        total += grade

    average = total / len(kwargs)
    print(f"\n\tAverage Grade: {average:.2f}\n")

# Ask user to enter subjects and grades in a single line
print("\n\tEnter subjects and grades like this: math=85 english=90 science=78")
user_input = input("\n\tYour input: ")

try:
    # Parse the input string into a dictionary
    subject_grade_pairs = user_input.strip().split()
    grades_dict = {}

    for pair in subject_grade_pairs:
        if '=' not in pair:
            raise ValueError("Missing '=' in a subject=grade pair.")
        subject, grade = pair.split('=')
        grades_dict[subject] = float(grade)

    # Call the function with keyword arguments
    calculate_grades(**grades_dict)

except ValueError as e:
    print(f"\n\tERROR: {e}")
    print("\tPlease make sure to enter subjects and numeric grades in the correct format.")
