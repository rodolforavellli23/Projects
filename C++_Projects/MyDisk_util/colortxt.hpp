#pragma once

#include <iostream>
#include <string>

/*Common ANSI Color Codes:
Text Colors (Foreground):
30: Black
31: Red
32: Green
33: Yellow
34: Blue
35: Magenta
36: Cyan
37: White
90-97: Bright versions of the above colors
Background Colors:
40: Black
41: Red
42: Green
43: Yellow
44: Blue
45: Magenta
46: Cyan
47: White
100-107: Bright versions of the above colors
*/

void SetColor(std::string textColor) {
    std::cout << "\033[" << textColor << "m";
}

void ResetColor() {
    std::cout << "\033[0m";
}