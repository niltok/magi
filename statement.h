#pragma once

#include <iostream>
#include <cmath>
#include <chrono>
#include <memory>
#include <list>
#include <vector>
#include "interface.h"

using namespace std;

extern long Size;
extern long long ID;

const double SMALL_ = 5.0 , MIDDLE_ = 7.0 , LARGE_ = 10.0 ;           // 弹幕大小
const double LOW_ = 0.06 , NORMAL_ = 0.09 , FAST_ = 0.12 ;              // 弹幕速度
enum Kind { Line , Arc , ReverseLine };                                             // 弹幕类型

const magi::Color c1(240, 128, 128),c2(244, 151, 142),c3(248, 173, 157),c4(251, 196, 171),c5(255, 218, 185);


// 弹幕样式
struct Bullet_Style {
    Bullet_Style () { speed = LOW_ ; point = magi::Point ( 0 , magi::Color() , SMALL_ ) ; angle = 0.0 ; StartT = 0 ; EndT = 0 ; };
    Bullet_Style ( long long id , magi::Color c , double r , magi::Vec2 center , double angle , double speed , long long StartT , long long EndT ) : point (magi::Point(id,c,r)) ,angle (angle) , speed (speed) , StartT (StartT) , EndT (EndT) , center(center) {}
    magi::Point point;
    magi::Vec2 center;
    double angle , speed ;
    long long StartT , EndT ;
    virtual magi::Vec2 Pos() {}
};

// 弹幕运动方式实现
// 直线
struct Bullet_Line : public Bullet_Style {
    Bullet_Line ( long long id , magi::Color c , double r , magi::Vec2 center , double angle , double speed , long long StartT , long long EndT ) : Bullet_Style (id,c,r,center,angle,speed,StartT,EndT) {}
    magi::Vec2 Pos () {
        long long RelaT = magi::Timer::get() - StartT ;
        this -> point.pos.x = cos(angle)*speed*RelaT + center.x ;
        this -> point.pos.y = sin(angle)*speed*RelaT + center.y ;
        return this -> point.pos;
    }
};

// 曲线
struct Bullet_Arc : public Bullet_Style {
    Bullet_Arc ( long long id , magi::Color c , double r , magi::Vec2 center , double angle , double speed , long long StartT , long long EndT ) : Bullet_Style (id,c,r,center,angle,speed,StartT,EndT) {}
    magi::Vec2 Pos () {
        angle += 0.003 ;
        long long RelaT = magi::Timer::get() - StartT ;
        this -> point.pos.x = cos(angle)*speed*RelaT + center.x ;
        this -> point.pos.y = sin(angle)*speed*RelaT + center.y ;
        return this -> point.pos;
    }
};

// 反向直线
struct Bullet_ReverseLine : public Bullet_Style {
    Bullet_ReverseLine ( long long id , magi::Color c , double r , magi::Vec2 center , double angle , double speed , long long StartT , long long EndT ) : Bullet_Style (id,c,r,center,angle,speed,StartT,EndT) {}
    magi::Vec2 Pos () {
        long long RelaT = EndT - magi::Timer::get() ;
        this -> point.pos.x = cos(angle)*speed*RelaT + center.x ;
        this -> point.pos.y = sin(angle)*speed*RelaT + center.y ;
        return this -> point.pos;
    }
};


shared_ptr<Bullet_Style> Creat ( long long StartT , long long EndT , magi::Color c , double r , magi::Vec2 center , double angle , double speed , Kind kind ) {
    shared_ptr<Bullet_Style> Re;
    switch (kind) {
            case Line:
                Re = make_shared<Bullet_Line> ( Bullet_Line(ID,c,r,center,angle,speed,StartT,EndT) );
                ID++;
                break;
            case Arc:
                Re = make_shared<Bullet_Arc> ( Bullet_Arc(ID,c,r,center,angle,speed,StartT,EndT) );
                ID++;
                break;
            case ReverseLine:
                Re = make_shared<Bullet_ReverseLine> ( Bullet_ReverseLine(ID,c,r,center,angle,speed,StartT,EndT) );
                ID++;
                break;
                break;
        }
    return Re;
}


struct Bullets_Info {
    Bullets_Info ( long long StartT , int n , magi::Color c , magi::Vec2 center , magi::Vec2 range , double r , double speed , Kind kind ) : n(n) , StartT(StartT) , range(range) {
        this -> EndT = StartT + 10000;                                                  // EndT 计算
            for ( int i = 0 ; i < n ; i++ ) {
                this -> bullets.push_back( Creat ( StartT , EndT , c , r , center , (range.x + ((range.y-range.x)/n * i)) , speed , kind ) );
        }
    }
    int n;
    long long StartT;
    long long EndT;
    magi::Vec2 range;
    vector<shared_ptr<Bullet_Style>> bullets ;
};


struct CharacterInfo : public magi::Character {

};

