#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include <string>
#include <map>
#include <iostream>


class Menu
{
private:
public:
	SDL_Texture* renderText(const std::string& message, const std::string& fontFile, SDL_Color color, int fontSize, SDL_Renderer* renderer);
	void renderTexture(SDL_Texture* tex, SDL_Renderer* ren, int x, int y);

};