#include<raylib.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h> // Provides strlen()

// My first Raylib window

int main() {
	// Variable declaration
	
	// Message to be sent
	const char *message = "Hello World! From Raylib ";

	// Getting the lengths
	int len_message = strlen(message);
	int len_version = strlen(RAYLIB_VERSION);
	int length_buffer = len_message + len_version + 1;

	// Building the string to be printed
	char my_str[length_buffer];
	int chars_written = 0;

	chars_written = snprintf(my_str, sizeof(my_str), "%s%s", message, RAYLIB_VERSION);
	printf("\n%4cChars printed by snprintf = %i\n", ' ', chars_written);
	printf("%4cSize of Buffer = %i\n\n", ' ', length_buffer);

	// Building the Window
	InitWindow(800, 600, my_str);
	SetTargetFPS(60);
	while(!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(GREEN);
		EndDrawing();
	}
	CloseWindow();
	
	return 0;
}
