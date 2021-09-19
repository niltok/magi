#pragma once

#include <QPainter>
#include <functional>
#include <list>


namespace magiUI {

void EVAEffects(QPainter &painter);
extern std::function<void(QPainter&)> ChinaEffects;
void normalBorder(QPainter &painter);
void MagicaEffects(QPainter &painter);
}
