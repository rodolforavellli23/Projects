#include <stdio.h>
#include <string.h>

int main()
{
    char str[20];

    // Right padding with spaces (total width 10)
    sprintf(str, "%-10s", "Hello");
    printf("\n\t'%s'\n", str); // 'Hello     '

    // Left padding with spaces
    sprintf(str, "%10s", "Hello");
    printf("\t'%s'\n", str); // '     Hello'


    ////////////////////////////////////////////////////////////////////////////
    // Padding with specific character (requires extra steps)
    memset(str, 0, sizeof(str)); // Clears the content of str by wiping the array
    const char *original = "Hello";
    char pad_char = '*';
    int total_width = 10;
    
    int len = strlen(original);
    int pad_len = total_width - len;
    
    // Create a padding string of '*'s
    char padding[20];
    memset(padding, pad_char, pad_len);
    padding[pad_len] = '\0';
    
    snprintf(str, sizeof(str), "%s%.*s", original, pad_len, padding);
    printf("\t'%s'\n\n", str);  // 'Hello*****'

    return 0;
}
