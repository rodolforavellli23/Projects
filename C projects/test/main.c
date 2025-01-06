#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

// Function to check for keypress
int kbhit()
{
    struct termios oldt, newt;
    int ch;
    int oldf;

    // Save terminal settings
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if (ch != EOF)
    {
        ungetc(ch, stdin);
        return 1;
    }

    return 0;
}

int main()
{
    for (;;)// Infinite loop
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
