#include <map>
#include <string>
#include "interface.h"

// 推荐从 https://coolors.co/ 复制链接生成色板
namespace magi {
ColorPattern &colors(const std::string &name) {
    static std::map<std::string, ColorPattern> c {
        {
            "greenToRedLight", {
                {168, 230, 207},
                {220, 237, 193},
                {255, 211, 182},
                {255, 170, 165},
                {255, 139, 148}
            }
        },

        {
            "orangeToWhite", {
                {240, 128, 128},
                {244, 151, 142},
                {248, 173, 157},
                {251, 196, 171},
                {255, 218, 185}
            }
        },

        {
            "EVA",{
                {48, 42, 67},
                {157, 86, 174},
                {140, 227, 96},
                {113, 115, 224},
                {51, 64, 106},
                {193, 97, 36},

            }
        },

        {
            "rainbowLight",
            Color::fromCoolors("https://coolors.co/ffadad-ffd6a5-fdffb6-caffbf-9bf6ff-a0c4ff-bdb2ff-ffc6ff-fffffc")
        },
        {
            "blueToWhite",
            Color::fromCoolors("https://coolors.co/03045e-023e8a-0077b6-0096c7-00b4d8-48cae4-90e0ef-ade8f4-caf0f8")
        },
        {
            "radToWhite",
            Color::fromCoolors("https://coolors.co/ff0a54-ff477e-ff5c8a-ff7096-ff85a1-ff99ac-fbb1bd-f9bec7-f7cad0-fae0e4")
        },
        {
            "graduatedBlue",
            Color::fromCoolors("https://coolors.co/03045e-023e8a-0077b6-0096c7-00b4d8-48cae4-90e0ef-ade8f4-caf0f8")
        }
    };
    return c[name];
}
}
