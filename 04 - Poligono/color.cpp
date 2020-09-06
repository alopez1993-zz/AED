#include <iostream>
#include <cassert>
#include <array>
#include <string>

using namespace std;

    struct Color {int R, G, B;};
    const Color black = {0,0,0};
    const Color white = {255,255,255};
    const Color red = {255,0,0};
    const Color green = {0,255,0};
    const Color blue = {0,0,255};
    const Color yellow = {255,255,0};
    const Color cyan = {0,255,255};
    const Color magenta = {255,0,255};

    Color sumarcolor (Color, Color);
    Color restarcolor (Color, Color);
    Color mezcla (Color color1, Color color2);