#pragma once

#include <iostream>
#include <cmath>
#include <chrono>
#include <memory>
#include <list>
#include <vector>
#include "interface.hpp"

using namespace std;

struct Bullet;
struct Bullet_Line;
struct Bullet_Circal;

struct Bullet;
struct stage;
struct StageInfo;
struct CharacterInfo;

const double PI=3.1415926;
const double SMALL_ = 5.0 , MIDDLE_ = 10.0 , LARGE_ = 15.0 ;           // 弹幕大小
const double LOW_ = 0.06 , NORMAL_ = 0.09 , FAST_ = 012 ;              // 弹幕速度
enum Kind { Line , Circle };                                             // 弹幕类型

long Size = 0;
long long ID = 0;
magi::Character ch;             // test 用

const magi::Color c1(240, 128, 128),c2(244, 151, 142),c3(248, 173, 157),c4(251, 196, 171),c5(255, 218, 185);


// 弹幕样式
struct Bullet_Style {
    Bullet_Style () {  speed = LOW_ ; point = magi::Point ( 0 , magi::Color() , SMALL_ ) ; angle = 0.0 ; StartT = 0 ; EndT = 0 ; };
    Bullet_Style ( magi::Point point , double angle , double speed , long long StartT ) : point (point) ,angle (angle) , speed (speed) , StartT (StartT) {}
    magi::Point point;
    double angle , speed ;
    long long StartT,EndT;
};

// 弹幕运动方式实现
// 直线
struct Bullet_Line : virtual public Bullet_Style {
    Bullet_Line () {}
    Bullet_Line ( magi::Point point , double angle , double speed , long long StartT ) : Bullet_Style (point,angle,speed,StartT) {}
    magi::Vec2 Pos_Line () {
        long long RelaT = magi::Timer::get() - StartT ;
        point.pos.x = cos(angle)*speed*RelaT ;
        point.pos.y = sin(angle)*speed*RelaT ;

        return point.pos;
    }
};

// 曲线
struct Bullet_Circal : virtual public Bullet_Style {
    Bullet_Circal () {}
    Bullet_Circal ( magi::Point point , double angle , double speed , long long StartT ) : Bullet_Style (point,angle,speed,StartT) {}
    magi::Vec2 Pos_Circal () {
        long long RelaT = magi::Timer::get() - StartT ;
        point.pos.x = 0 ;                                                                                       // !!!待定
        point.pos.y = 0 ;

        return point.pos;
    }
};



// 弹幕终效果
struct Bullet_Result : public Bullet_Line , public Bullet_Circal {
    Bullet_Result () {}
    Bullet_Result ( long long id , magi::Color c , double r , double angle , double speed , long long StartT, Kind kind ) : 
    Bullet_Line(magi::Point (id,c,r),angle,speed,StartT) ,
    Bullet_Circal(magi::Point (id,c,r),angle,speed,StartT) , kind(kind) {}
    Kind kind ;
};

vector<Bullet_Result> LineType ( long long &ID , int n , magi::Color c , double r , double speed , long long StartT ) {
    vector<Bullet_Result> Re { Bullet_Result ( ID , c , r , 0.0 , speed , StartT , Line ) }; ID++;
    double angle ;
    for ( int i=1 ; i<n ; i++ ) {
        Re.push_back ( Bullet_Result ( ID , c , r , ((PI/(double)n)*i) , speed , StartT , Line ) ), ID++ ;
    }
    return Re;
}


vector<Bullet_Result> CircalType ( long long &ID , int n , magi::Color c , double r , double speed , long long StartT ) {
    vector<Bullet_Result> Re { Bullet_Result ( ID , c , r , 0.0 , speed , StartT , Circle ) }; ID++;
    double angle ;
    for ( int i=1 ; i<n ; i++ ) {
        Re.push_back ( Bullet_Result ( ID , c , r , ((PI/(double)n)*i) , speed , StartT , Circle ) ), ID++ ;
    }
    return Re;
}

struct Bullets_Info {
    Bullets_Info ( long long StartT , int n , magi::Color c , double r , double speed , Kind kind ) : n(n) , c(c) , r (r) , speed(speed) , StartT(StartT) ,kind(kind) {
        EndT = StartT + 5000;                                                  // EndT 计算
        switch (kind) {
            case Line:
                bullets = LineType( ID , n , c , r , speed , StartT );
                break;
            case Circle:
                bullets = CircalType( ID , n , c , r , speed , StartT );
                break;
        }
    }
    int n;
    Kind kind;
    magi::Color c;
    double r;
    double speed;
    long long StartT;
    long long EndT;
    vector<Bullet_Result> bullets;
};


struct CharacterInfo : public magi::Character {

};