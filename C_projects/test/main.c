#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

// Function to check for keypress. This is run at every loop on "for(;;){...}"
int kbhit()
{
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);          // Save the old terminal settings
    newt = oldt;                             // Copy old settings to a new var
    newt.c_lflag &= ~(ICANON | ECHO);        // Disables sending input directly to the terminal
    tcsetattr(STDIN_FILENO, TCSANOW, &newt); // This enables the new terminal settings

    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);          // Get current file status flags
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK); // Set non-blocking mode

    ch = getchar(); // If a key is pressed, it's going to 'ch'

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // Restore terminal settings
    fcntl(STDIN_FILENO, F_SETFL, oldf);      // Restore original file status flags

    if (ch != EOF)
    {
        ungetc(ch, stdin); // Push the character back to stdin
        return 1;          // Key pressed
    }

    return 0; // No key pressed
}

int main()
{
    for (;;) // Infinite loop
    {
        if (kbhit())
        {
            break; // Exits the loop
        }
        else
        {
            printf("This will print forever unless you stop it.\n");
        }
    }

    printf("Loop exited.\n");
    return 0;
}
