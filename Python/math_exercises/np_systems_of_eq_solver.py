#!/home/greenshoots/Documentos/GitHub/Projects/Python/math_exercises/venv/bin/python3

# Python program to solve systems of equations: 
#   such that, if a system of equations is equivalent to A @ X = B;
#   where A is the coeficients matrix, X is the incognitae matrix and B is the results matrix;
#   then the incognitae to be found can be calculated by X = A^-1 @ B  

import numpy as np
import sympy as sp
import textwrap

# Functions
def parse_and_check_type(s):
    try:
        # Convert to float first
        num = float(s)
        # Check if the float value is numerically an integer
        if num.is_integer():
            # If it is, cast it to an int and return as 'int'
            return int(num)
        else:
            return num
    except ValueError:
        return "not a number", None

# | 00 01
# | 10 11
def det_matrix_2x2(matrix):
    result = (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0])
    return result

# | 00 01 02 |
# | 10 11 12 |
# | 20 21 22 |
def det_matrix_3x3(matrix):
    result = ((matrix[0][0] * matrix[1][1] * matrix[2][2]) + 
              (matrix[0][1] * matrix[1][2] * matrix[2][0]) + 
              (matrix[1][0] * matrix[2][1] * matrix[0][2]) - 
              (matrix[0][2] * matrix[1][1] * matrix[2][0]) - 
              (matrix[1][2] * matrix[2][1] * matrix[0][0]) - 
              (matrix[0][1] * matrix[1][0] * matrix[2][2]))
    return result

# User Input
print(f"\n{' ':<4}Solve systems of equations:"
      f"\n{' ':<4}The Functionality of this script is limited to solving either 2x2 system of equations or 3x3 systems of equations:")
choice = input(f"\n{' ':<4}Are you going to solve a 2x2 system of equations or a 3x3 system of equations? type either 2x2 or 3x3: ")

if choice == "2x2":
    print(f"\n{' ':<4}Please note that the values of each line must be separated by a ', ' separator."
          f"\n{' ':<4}Also, each line must only take 2 elements.\n")
    a = input(f"{' ':<4}Please input the first line coeficients matrix  : ")
    b = input(f"{' ':<4}Please input the second line coeficients matrix : ")
    print("")

    # Get the B resultants matrix as well
    
    # Processing User Input
    first_line = np.array(list(map(parse_and_check_type, (a.split(", ")))))
    second_line = np.array(list(map(parse_and_check_type, (b.split(", ")))))

    np_input_matrix = np.array([first_line, second_line])

    # # Test output for the Input matrix
    test_prefix = f"{' ':<4}Input matrix = "
    str_out_1 = np.array2string(np_input_matrix, prefix=test_prefix, 
                                                 formatter={'float_kind': lambda x: f"{x: >6.1f}", # ' >' forces alignment and sign space
                                                              'int_kind': lambda x: f"{x: >4d}"})
    # # Determinant of the Input matrix
    determinant_prefix = f"{' ':<4}Determinant of the Input matrix: "

    det_input = det_matrix_2x2(np_input_matrix)

    # # Adjugate matrix of the input matrix
    # # | 00 01 |    |  11 -01 |
    # # | 10 11 | -> | -10  00 |

    adjugate_prefix = f"{' ':<4}Adjugate matrix: "

    np_adjugate_matrix = np.array([[  np_input_matrix[1][1]  , -(np_input_matrix[0][1])],
                                   [-(np_input_matrix[1][0]) ,   np_input_matrix[0][0]]])

    str_out_2 = np.array2string(np_adjugate_matrix, prefix=adjugate_prefix,
                                                    formatter={'float_kind': lambda x: f"{x: >6.1f}", # ' >' forces alignment and sign space
                                                              'int_kind': lambda x: f"{x: >4d}"})

    # # Inverse matrix
    inverse_prefix = f"{' ':<4}Inverse of the Input matrix: "

    np_inverse_matrix = np.array([[(np_adjugate_matrix[0][0] / det_input), (np_adjugate_matrix[0][1] / det_input)],
                                  [(np_adjugate_matrix[1][0] / det_input), (np_adjugate_matrix[1][1] / det_input)]])

    # # Convert to a sympy matrix for cleaner representation of floats as ratios
    sp_inverse_matrix = sp.Matrix(np_inverse_matrix).applyfunc(lambda x: sp.nsimplify(x, rational=True))
    str_out_3 = textwrap.indent((sp.pretty(sp_inverse_matrix)), (f"{' ':<4}"))

    # # Find the result of the Incognitae matrix by multiplying A^-1 @ B

    # Text Output
    print(f"\n{test_prefix}{str_out_1}")
    print(f"\n{' ':<4}{'':{'-'}<80}\n")
    print(f"{determinant_prefix}{det_input}")
    print(f"\n{' ':<4}{'':{'-'}<80}\n")
    print(f"{adjugate_prefix}{str_out_2}")
    print(f"\n{' ':<4}{'':{'-'}<80}\n")
    print(f"{inverse_prefix}\n\n{str_out_3}")
    print(f"\n{' ':<4}{'':{'-'}<80}\n")
elif choice == "3x3":
    print(f"\n{' ':<4}Please note that the values of each line must be separated by a ', ' separator."
          f"\n{' ':<4}Also, each line must only take 3 elements.\n")
    a = input(f"{' ':<4}Please input the first line coeficients matrix  : ")
    b = input(f"{' ':<4}Please input the second line coeficients matrix : ")
    c = input(f"{' ':<4}Please input the third line coeficients matrix  : ")

    # Get the B resultants matrix as well

    # Processing User Input
    first_line  = np.array(list(map(parse_and_check_type, (a.split(", ")))))
    second_line = np.array(list(map(parse_and_check_type, (b.split(", ")))))
    third_line  = np.array(list(map(parse_and_check_type, (c.split(", ")))))

    np_input_matrix = np.array([first_line, second_line, third_line])

    # # Test output for the Input matrix
    test_prefix = f"{' ':<4}Input = "
    str_out_1 = np.array2string(np_input_matrix, prefix=test_prefix, 
                                                 formatter={'float_kind': lambda x: f"{x: >6.1f}", # ' >' forces alignment and sign space
                                                              'int_kind': lambda x: f"{x: >4d}"})

    # # Determinant of the Input matrix
    det_input = det_matrix_3x3(np_input_matrix)

    # # Cofactor matrix

    label = f"{' ':<4}Cofactor matrix of the given input matrix: "
    cofactor_prefix = f"{" ":<12}"

    # | 00 01 02 |
    # | 10 11 12 |
    # | 20 21 22 |

    # -----------------------------------------------------------------
    np_a11 = np.array([[np_input_matrix[1][1], np_input_matrix[1][2]], 
                       [np_input_matrix[2][1], np_input_matrix[2][2]]])

    det_a11 = det_matrix_2x2(np_a11)

    # -----------------------------------------------------------------
    np_a12 = np.array([[np_input_matrix[1][0], np_input_matrix[1][2]],
                       [np_input_matrix[2][0], np_input_matrix[2][2]]])

    det_a12 = det_matrix_2x2(np_a12)

    # -----------------------------------------------------------------
    np_a13 = np.array([[np_input_matrix[1][0], np_input_matrix[1][1]], 
                       [np_input_matrix[2][0], np_input_matrix[2][1]]])

    det_a13 = det_matrix_2x2(np_a13)

    # -----------------------------------------------------------------
    np_a21 = np.array([[np_input_matrix[0][1], np_input_matrix[0][2]], 
                       [np_input_matrix[2][1], np_input_matrix[2][2]]])

    det_a21 = det_matrix_2x2(np_a21)

    # -----------------------------------------------------------------
    np_a22 = np.array([[np_input_matrix[0][0], np_input_matrix[0][2]], 
                       [np_input_matrix[2][0], np_input_matrix[2][2]]])

    det_a22 = det_matrix_2x2(np_a22)

    # -----------------------------------------------------------------
    np_a23 = np.array([[np_input_matrix[0][0], np_input_matrix[0][1]], 
                       [np_input_matrix[2][0], np_input_matrix[2][1]]])

    det_a23 = det_matrix_2x2(np_a23)

    # -----------------------------------------------------------------
    np_a31 = np.array([[np_input_matrix[0][1], np_input_matrix[0][2]], 
                       [np_input_matrix[1][1], np_input_matrix[1][2]]])

    det_a31 = det_matrix_2x2(np_a31)

    # -----------------------------------------------------------------
    np_a32 = np.array([[np_input_matrix[0][0], np_input_matrix[0][2]], 
                       [np_input_matrix[1][0], np_input_matrix[1][2]]])

    det_a32 = det_matrix_2x2(np_a32)

    # -----------------------------------------------------------------
    np_a33 = np.array([[np_input_matrix[0][0], np_input_matrix[0][1]],
                       [np_input_matrix[1][0], np_input_matrix[1][1]]])

    det_a33 = det_matrix_2x2(np_a33)

    # -----------------------------------------------------------------
    np_cofactor_matrix = np.array([[ det_a11, -det_a12,  det_a13],
                                   [-det_a21,  det_a22, -det_a23],
                                   [ det_a31, -det_a32,  det_a33]])

    str_out_2 = np.array2string(np_cofactor_matrix, prefix=cofactor_prefix,
                                                    formatter={'float_kind': lambda x: f"{x: >6.1f}", # ' >' forces alignment and sign space
                                                                 'int_kind': lambda x: f"{x: >4d}"})

    # # Transpose of the Cofactor matrix
    # | 00 01 02 |    | 00 10 20 |
    # | 10 11 12 | -> | 01 11 21 |
    # | 20 21 22 |    | 02 12 22 |

    transpose_prefix = f"{' ':<4}Transpose of the above Cofactor matrix: "

    np_transpose_of_cofactor_matrix = np.array([[np_cofactor_matrix[0][0], np_cofactor_matrix[1][0], np_cofactor_matrix[2][0]], 
                                                [np_cofactor_matrix[0][1], np_cofactor_matrix[1][1], np_cofactor_matrix[2][1]],
                                                [np_cofactor_matrix[0][2], np_cofactor_matrix[1][2], np_cofactor_matrix[2][2]]])

    str_out_3 = np.array2string(np_transpose_of_cofactor_matrix, prefix=transpose_prefix, 
                                                                 formatter={'float_kind': lambda x: f"{x: >6.1f}", # ' >' forces alignment and sign space
                                                                              'int_kind': lambda x: f"{x: >4d}"})

    # # Inverse matrix of the input matrix

    inverse_prefix = f"{' ':<4}Inverse of the Input matrix: "

    np_inverse_matrix = np.array([[(np_transpose_of_cofactor_matrix[0][0] / det_input), 
                                   (np_transpose_of_cofactor_matrix[0][1] / det_input), 
                                   (np_transpose_of_cofactor_matrix[0][2] / det_input)], #  End of first line
                                  [(np_transpose_of_cofactor_matrix[1][0] / det_input), 
                                   (np_transpose_of_cofactor_matrix[1][1] / det_input), 
                                   (np_transpose_of_cofactor_matrix[1][2] / det_input)], # End of second line
                                  [(np_transpose_of_cofactor_matrix[2][0] / det_input), 
                                   (np_transpose_of_cofactor_matrix[2][1] / det_input), 
                                   (np_transpose_of_cofactor_matrix[2][2] / det_input)]] #  End of third line
                                )

    # # Convert to a sympy matrix for cleaner representation of floats as ratios
    sp_inverse_matrix = sp.Matrix(np_inverse_matrix).applyfunc(lambda x: sp.nsimplify(x, rational=True))
    str_out_4 = textwrap.indent((sp.pretty(sp_inverse_matrix)), (f"{' ':<4}"))

    # # Find the result of the Incognitae matrix by multiplying A^-1 @ B (IN PROGRESS)
    
    # Text Output
    print(f"\n{test_prefix}{str_out_1}")
    print(f"\n{' ':<4}{'':{'-'}<80}\n")
    print(f"{' ':<4}Determinant of the input matrix: {det_input}")
    print(f"\n{' ':<4}{'':{'-'}<80}\n")
    print(f"{label}\n\n{cofactor_prefix}{str_out_2}")
    print(f"\n{' ':<4}{'':{'-'}<80}\n")
    print(f"{transpose_prefix}{str_out_3}")
    print(f"\n{' ':<4}{'':{'-'}<80}\n")
    print(f"{inverse_prefix}:\n\n{str_out_4}")
    print(f"\n{' ':<4}{'':{'-'}<80}\n")
else:
    print(f"{' ':<4}Invalid choice, this program can only solve either 2x2 or 3x3 systems of equations")
