#include "RenderSDL.h"
RenderSDL::RenderSDL(const Settings& settings):
    screenWidth(settings.screenWidth), screenHeight(settings.screenHeight)
{
    if (!InitSDL())
    {
        DestroySDL();
        throw std::runtime_error("Render: Init Error");
    }
}
void RenderSDL::Draw(const Entity& entity)
{
    SDL_SetRenderDrawColor(ren, 0, 32, 255, 255);
    SDL_RenderCopyF(ren, textures[entity.getType()], nullptr, &entity.getRectBound());
    //SDL_Delay(5000);
}
bool RenderSDL::LoadTexture(const std::vector<const char*> texturesPath)
{
    SDL_Texture* tex;
    for (auto path : texturesPath)
    {
        tex = IMG_LoadTexture(ren, path);
        if (tex == nullptr) {
                    std::cout << "SDL:LoadTextureError: " << SDL_GetError() <<" "<<path << std::endl;
                    return false;
            }
        textures.push_back(tex);
        //SDL_DestroyTexture(tex);
    }
    tex = nullptr;
    return true;
}
void RenderSDL::UpdateRen()
{
    SDL_RenderPresent(ren);
    SDL_RenderClear(ren);
}
bool RenderSDL::InitSDL()
{
    bool success = true;
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        std::cout << "SDL:InitError:" << SDL_GetError() << std::endl;
        success = false;
    }
    int flags = IMG_INIT_PNG;
    if (!(IMG_Init(flags) & flags)) {
        std::cout << "Can't init image: " << IMG_GetError() << std::endl;
        return false;
    }

    win = SDL_CreateWindow("PongSDL", 100, 100, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
    if (win == nullptr)
    {
        std::cout << "SDL:CreateWindowError:" << SDL_GetError() << std::endl;
        success = false;
    }
    ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (ren == nullptr) {
        std::cout << "SDL:CreateRendererError: " << SDL_GetError() << std::endl;
        success = false;
    }
    SDL_SetRenderDrawColor(ren, 0, 255, 255, 255);
    SDL_RenderClear(ren);
    SDL_RenderPresent(ren);
    return success;
}
//bool RenderSDL::Draw(const std::vector<UnitInfo>& unitData, const char* fileTex, const Settings& settings)
//{
//    tex = IMG_LoadTexture(ren, fileTex);
//    if (tex == nullptr) {
//        std::cout << "SDL:CreateTextureFromSurfaceError: " << SDL_GetError() << std::endl;
//        return false;
//    }
//    SDL_SetRenderDrawColor(ren, 0, 255, 255, 255);
//    SDL_RenderClear(ren);
//    SDL_RenderPresent(ren);
//    SDL_Rect r;
//    SDL_SetRenderDrawColor(ren, 0, 34, 255, 0);
//    for (const auto& unitInfo : unitData)
//    {
//        //Поменять везде на 0.5? Или ввести доп. переменную типа пополам плюс к кэшированию!!!
//        r.x = unitInfo.posX - unitInfo.w / 2;
//        r.y = unitInfo.posY - unitInfo.h / 2;
//        r.w = unitInfo.w;
//        r.h = unitInfo.h;
//        //Отправить структуру или в класс
//        //DrawUnit(ren, tex, r);
//        /*SDL_RenderDrawLine(ren,
//            r.x + r.w / 2,
//            r.y + r.h / 2,
//            r.x + r.w / 2 + static_cast<int>(sqrtf((float)settings.SqDistanceView) * unitInfo.directX),
//            r.y + r.h / 2 + static_cast<int>(sqrtf((float)settings.SqDistanceView) * unitInfo.directY));*/
//        //DrawVisibleCone(ren, unitInfo, settings);
//        //SDL_SetRenderDrawColor(ren, 0, 34, 255, 0);
//
//    }
//
//    SDL_RenderPresent(ren);
//    SDL_Delay(5000);
//    return true;
//}
void  RenderSDL::DestroySDL()
{
    SDL_DestroyWindow(win);
    win = nullptr;

    SDL_DestroyRenderer(ren);
    ren = nullptr;
    for (auto texture:textures)
    {
        SDL_DestroyTexture(texture);
    }
    SDL_Quit();
    IMG_Quit();
}

RenderSDL::~RenderSDL()
{
    DestroySDL();
    std::cout << "DestroySDL" << std::endl;
}
