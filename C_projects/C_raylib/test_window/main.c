#include<raylib.h>
#include<stdio.h>
#include<stdlib.h>

// My first Raylib window

int main() {
	// Variable declaration
	
	// Message to be sent
	const char *message = "Hello World! From Raylib ";

	// Building the Window
	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	InitWindow(800, 600, TextFormat("%s%s", message, RAYLIB_VERSION));
	SetTargetFPS(60);
	SetExitKey(0);

	// Window Loop
	while(!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(GREEN);
		if(IsKeyPressed(KEY_SPACE)) {
			break;
		}
		if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			break;
		}
		EndDrawing();
	}
	CloseWindow();
	
	return 0;
}
