#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>

class Game
{
private:
	bool isRunning;
	SDL_Window* window;
	int cnt = 0;

public:
	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	
	void handleEvents();
	void update();
	void render();
	void clean();
	bool running() { return isRunning; }

	static SDL_Renderer* renderer;
	static SDL_Event event;
};
