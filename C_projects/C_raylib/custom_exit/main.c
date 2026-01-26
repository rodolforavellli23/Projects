#include<raylib.h>
#include<stdlib.h>
#include<stdio.h>

int main() {
    // START PROGRAM

    // Variable declaration in the program scope

    // Things Declared in here don't need to be recalculated
    // by the Window main loop

    // Closing trigger
    bool shouldExit = false;

    // Messages to be printed
    const char *message_1 = "Press 'Q' or 'X' button to quit";
    const char *message_2 = "Escape key is now disabled!";

    // Set font parameters
    int fontSize = 30;
    int fontOffset = 300;
    int lineSpacing = 35;

    // Calculate the text width
    int textWidth_1 = MeasureText(message_1, fontSize);
    int textWidth_2 = MeasureText(message_2, fontSize);

    // Building the window
    SetConfigFlags(FLAG_WINDOW_RESIZABLE | \
                   FLAG_WINDOW_HIGHDPI | \
                   FLAG_MSAA_4X_HINT);

    InitWindow(800, 600, "Custom Exit Logic");
    SetTargetFPS(60);
    SetExitKey(0);  // Disable the default ESC behavior

    // Window main loop
    while (!shouldExit && !WindowShouldClose()) {
        if (IsWindowResized()) {
            // This confirms the window has changed size
            // Raylib handles the buffer swap internally,
            // but checking this can help you reset your UI layouts.
        }

        // Variable declation in the scope of the Window main loop

        // Things set in this escope are here because
        // they need to be updated by the Window main loop

        // Get current dimensions
        int screenWidth = GetScreenWidth();
        int screenHeight = GetScreenHeight();

        // message_1 width
        int xPos_1 = (screenWidth - textWidth_1) / 2;

        // message_2 width
        int xPos_2 = (screenWidth - textWidth_2) / 2;

        // both use the same font height
        int yPos = (screenHeight - fontSize) / 2;

        // Custom exit logic: Press Q to quit
        if (IsKeyPressed(KEY_Q)) {
            shouldExit = true;
        }

        // Drawing the window
    	BeginDrawing();
    		ClearBackground(DARKGRAY);
    		DrawText(message_1, xPos_1 - fontOffset, yPos - lineSpacing, fontSize, WHITE);
    		DrawText(message_2, xPos_2 - fontOffset, yPos, fontSize, RED);
    	EndDrawing(); 
   }

   // END PROGRAM
   CloseWindow();
   return 0;
}
