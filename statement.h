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
enum Kind { Line , Circle };                                             // 弹幕类型

const magi::Color c1(240, 128, 128),c2(244, 151, 142),c3(248, 173, 157),c4(251, 196, 171),c5(255, 218, 185);


// 弹幕样式
struct Bullet_Style {
    Bullet_Style () { speed = LOW_ ; point = magi::Point ( 0 , magi::Color() , SMALL_ ) ; angle = 0.0 ; StartT = 0 ; };
    Bullet_Style ( long long id , magi::Color c , double r , double angle , double speed , long long StartT ) : point (magi::Point(id,c,r)) ,angle (angle) , speed (speed) , StartT (StartT) {}
    magi::Point point;
    double angle , speed ;
    long long StartT;
    virtual magi::Vec2 Pos() {}
};

// 弹幕运动方式实现
// 直线
struct Bullet_Line : public Bullet_Style {
    Bullet_Line () {}
    Bullet_Line ( long long id , magi::Color c , double r , double angle , double speed , long long StartT ) : Bullet_Style (id,c,r,angle,speed,StartT) {}
    magi::Vec2 Pos () {
        long long RelaT = magi::Timer::get() - StartT ;
        this -> point.pos.x = cos(angle)*speed*RelaT ;
        this -> point.pos.y = sin(angle)*speed*RelaT ;

        return this -> point.pos;
    }
};

// 曲线
struct Bullet_Circal : public Bullet_Style {
    Bullet_Circal () {}
    Bullet_Circal ( long long id , magi::Color c , double r , double angle , double speed , long long StartT ) : Bullet_Style (id,c,r,angle,speed,StartT) {}
    magi::Vec2 Pos () {
        long long RelaT = magi::Timer::get() - StartT ;
        point.pos.x = cos(angle)*speed*RelaT*RelaT ;                                                                                       // !!!待定
        point.pos.y = sin(angle)*speed*RelaT*RelaT ;

        return point.pos;
    }
};

shared_ptr<Bullet_Style> Creat ( long long StartT , magi::Color c , double r , double angle , double speed , Kind kind ) {
    shared_ptr<Bullet_Style> Re;
    switch (kind) {
            case Line:
                Re = make_shared<Bullet_Line> ( Bullet_Line(ID,c,r,angle,speed,StartT) );
                ID++;
                break;
            case Circle:
                Re = make_shared<Bullet_Circal> ( Bullet_Circal(ID,c,r,angle,speed,StartT) );
                ID++;
                break;
        }
    return Re;
}


struct Bullets_Info {
    Bullets_Info ( long long StartT , int n , magi::Color c , magi::Vec2 range , double r , double speed , Kind kind ) : n(n) , StartT(StartT) , range(range) {
        this -> EndT = StartT + 10000;                                                  // EndT 计算
            for ( int i = 0 ; i < n ; i++ ) {
                this -> bullets.push_back( Creat ( StartT , c , r , (range.x + ( (range.y-range.x)/(double)n) * i) , speed , kind ) );
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

