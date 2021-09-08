#pragma once

#include <iostream>
#include <cmath>
#include <chrono>
#include <memory>
#include <list>
#include <vector>
#include "interface.h"

using namespace std;

struct Bullet_Style;

extern long Size;
extern long long ID;

const double SMALL_ = 5.0 , MIDDLE_ = 7.0 , LARGE_ = 10.0 ;           // 弹幕大小
const double LOW_ = 0.06 , NORMAL_ = 0.09 , FAST_ = 0.12 ;            // 弹幕速度
enum Kind { Line , Arc , ReverseLine , ReverseArc , Arc_SpeedUp };                  // 弹幕类型

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

extern vector<vector<shared_ptr<Bullet_Style>>> bullets;

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
        double Angle;
        long long RelaT = magi::Timer::get() - StartT ;
        Angle = 0.0001875 * RelaT + this -> angle ;
        this -> point.pos.x = cos(Angle)*speed*RelaT + center.x ;
        this -> point.pos.y = sin(Angle)*speed*RelaT + center.y ;
        return this -> point.pos;
    }
};
// 变速曲线
struct BulletArc_SpeedUp : public Bullet_Style {
    BulletArc_SpeedUp ( long long id , magi::Color c , double r , magi::Vec2 center , double angle , double speed , long long StartT , long long EndT ) : Bullet_Style (id,c,r,center,angle,speed,StartT,EndT) {}
    magi::Vec2 Pos () {
        double Angle,Speed;
        long long RelaT = magi::Timer::get() - StartT ;
        Angle = 0.0001875 * RelaT + this -> angle ;
        Speed = 0.0001 *RelaT + this -> speed ;
        this -> point.pos.x = cos(Angle)*Speed*RelaT + center.x ;
        this -> point.pos.y = sin(Angle)*Speed*RelaT + center.y ;
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

// 反向曲线
struct Bullet_ReverseArc : public Bullet_Style {
    Bullet_ReverseArc ( long long id , magi::Color c , double r , magi::Vec2 center , double angle , double speed , long long StartT , long long EndT ) : Bullet_Style (id,c,r,center,angle,speed,StartT,EndT) {}
    magi::Vec2 Pos () {
        double Angle;
        long long RelaT = EndT - magi::Timer::get() ;
        Angle = 0.0001875 * RelaT + this -> angle ;
        this -> point.pos.x = cos(Angle)*speed*RelaT + center.x ;
        this -> point.pos.y = sin(Angle)*speed*RelaT + center.y ;
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
            case ReverseArc:
                Re = make_shared<Bullet_ReverseArc> ( Bullet_ReverseArc(ID,c,r,center,angle,speed,StartT,EndT) );
                ID++;
                break;
            case Arc_SpeedUp:
                Re = make_shared<BulletArc_SpeedUp> ( BulletArc_SpeedUp(ID,c,r,center,angle,speed,StartT,EndT) );
                ID++;
                break;
        }
    return Re;
}

// 当前时间所有弹幕信息
struct Bullets_Info {
    Bullets_Info ( int NUM , long long StartT , int n , magi::Color c , magi::Vec2 center , magi::Vec2 range , double r , double speed , Kind kind ) {
        this -> EndT = StartT + 10000;                                                  // EndT 计算
        for ( int i = 0 ; i < n ; i++ ) {
            bullets[NUM -1].push_back( Creat ( StartT , EndT , c , r , center , (range.x + ((range.y-range.x)/n * i)) , speed , kind ) );
        }
    }
    // int n;
    long long StartT;
    long long EndT;
    // magi::Vec2 range;
    // vector<shared_ptr<Bullet_Style>> bullets ;
};

// 缩圈
struct Creat_BulletsInfo_Circle : public Bullets_Info {
    Creat_BulletsInfo_Circle ( int NUM , long long StartT , int n , magi::Color c , magi::Vec2 center , magi::Vec2 range , double r , double speed , Kind kind ) : Bullets_Info (NUM,StartT,n,c,center,range,r,speed,kind) {
        this -> EndT = StartT + 10000;                                                  // EndT 计算
        double startt = this -> StartT;
            for ( int i = 0 ; i < n ; i++ ) {
                bullets[NUM - 1].push_back( Creat ( startt , EndT , c , r , center , 0.0 , speed , kind ) );
                startt += 100 ;
        }
    }
};


/* // bulletsinfo 构建函数
size_t Creat_bulletsinfo () {

} */

struct CharacterInfo : public magi::Character {

};

