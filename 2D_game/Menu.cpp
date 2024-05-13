#include "Menu.h"


SDL_Texture* Menu::renderText(const std::string& message, const std::string& fontFile,
    SDL_Color color, int fontSize, SDL_Renderer* renderer)
{
    //Открываем шрифт
    TTF_Font* font = TTF_OpenFont(fontFile.c_str(), fontSize);
    if (font == nullptr)
    {
        return nullptr;
    }
    //Сначала нужно отобразить на поверхность с помощью TTF_RenderText,
    //затем загрузить поверхность в текстуру
    SDL_Surface* surf = TTF_RenderText_Blended(font, message.c_str(), color);
    if (surf == nullptr)
    {
        TTF_CloseFont(font);
        return nullptr;
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surf);
    if (texture == nullptr) {
        std::cout << "CreateTexture";
    }
    //Очистка поверхности и шрифта
    SDL_FreeSurface(surf);
    TTF_CloseFont(font);
    return texture;
}

void Menu::renderTexture(SDL_Texture* tex, SDL_Renderer* ren, int x, int y)
{
    int w = 32, h = 32;
    SDL_QueryTexture(tex, NULL, NULL, &w, &h);
    SDL_Rect dst;
    dst.x = x;
    dst.y = y;
    dst.w = w;
    dst.h = h;
    SDL_RenderCopy(ren, tex, NULL, &dst);
}