#pragma once

#include "interface.h"
#include <vector>

// 推荐从 https://coolors.co/ 复制链接生成色板
namespace colors {
using namespace magi;
using namespace std;

ColorPattern greenToRedLight {
    {168, 230, 207},
    {220, 237, 193},
    {255, 211, 182},
    {255, 170, 165},
    {255, 139, 148}
};

ColorPattern orangeToWhite {
    {240, 128, 128},
    {244, 151, 142},
    {248, 173, 157},
    {251, 196, 171},
    {255, 218, 185}
};

auto rainbowLight = Color::fromCoolors("https://coolors.co/ffadad-ffd6a5-fdffb6-caffbf-9bf6ff-a0c4ff-bdb2ff-ffc6ff-fffffc");
auto blueToWhite = Color::fromCoolors("https://coolors.co/03045e-023e8a-0077b6-0096c7-00b4d8-48cae4-90e0ef-ade8f4-caf0f8");
auto radToWhite = Color::fromCoolors("https://coolors.co/ff0a54-ff477e-ff5c8a-ff7096-ff85a1-ff99ac-fbb1bd-f9bec7-f7cad0-fae0e4");
}
