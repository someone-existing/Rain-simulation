#include "raylib.h"

const int screenWidth = 1366;
const int screenHeight = 768;
const int maxRain = 200;
struct Rain
{
    Rectangle rect;
    int speed;
    Color color;
};
static Rain rain[maxRain];
void InitRain(){
    for (int i = 0; i < maxRain; i++){
        rain[i].rect.width = GetRandomValue(4, 6);
        rain[i].rect.height = GetRandomValue(20, 25);
        rain[i].rect.x = GetRandomValue(0, screenWidth);
        rain[i].rect.y = GetRandomValue(-rain[i].rect.height, -screenHeight);
        rain[i].speed = GetRandomValue(5, 8);
        rain[i].color = {93, 145, 227, 255};
    }
    
}

void DrawGame(){
    BeginDrawing();

    ClearBackground({224, 236, 255, 255});
    for (int i = 0; i < maxRain; i++){
        DrawRectangleRounded(rain[i].rect, 7.5, 50, rain[i].color);
    }
    

    EndDrawing();
}
void UpdateGame(){
    for (int i = 0; i < maxRain; i++){
        rain[i].rect.y += rain[i].speed;
        if(rain[i].rect.y > screenHeight){
            rain[i].rect.y = GetRandomValue(-rain[i].rect.height, -screenHeight);
        }
    }
}

int main(int argc, char* argv[])
{
    InitWindow(screenWidth, screenHeight, "Rain");
    ToggleFullscreen();
    InitRain();
    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        DrawGame();
        UpdateGame();
    }

    CloseWindow();
    return 0;
}
