#pragma once

#include <iostream>
#include <cmath>
#include <chrono>
#include <memory>
#include <list>
#include <vector>
#include <algorithm>
#include "interface.h"

using namespace std;

struct Bullet_Style;

extern long Size;
extern long long ID;
extern int StageNum;

const double SMALL_ = 5.0 , MIDDLE_ = 7.0 , LARGE_ = 10.0 ;           // 弹幕大小
const double LOW_ = 0.06 , NORMAL_ = 0.09 , FAST_ = 0.12 ;            // 弹幕速度
enum Kind { Line , Arc , ReverseLine , ReverseArc , Arc_SpeedUp , Line_ChangeSpeed };                  // 弹幕类型

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

// 自定义变速反向直线
struct BulletLine_ChangeSpeed : public Bullet_Style {
    BulletLine_ChangeSpeed ( long long id , magi::Color c , double r , magi::Vec2 center , double angle , double speed , double Afterspeed , long long ChangeT , long long EndT ) : Bullet_Style (id,c,r,center,angle,speed,0,0) , ChangeT(ChangeT) , Afterspeed(Afterspeed) {
        this -> BeforeT = 120/speed;
        this -> AfterT = 120/Afterspeed;
        this -> EndT = ChangeT + AfterT;
        this -> StartT = this -> EndT - EndT;
        }
    magi::Vec2 Pos () {
        long long RealT = magi::Timer::get() ;
        long long RelaT = EndT - RealT + (BeforeT - AfterT);
        double Speed = this -> speed ;
        if ( this -> ChangeT < RealT ) { Speed = this -> Afterspeed; RelaT = EndT - RealT; }
        this -> point.pos.x = cos(angle)*Speed*RelaT + center.x ;
        this -> point.pos.y = sin(angle)*Speed*RelaT + center.y ;
        // cout << "(" << StartT << "," << EndT << ")" << endl ;
        return this -> point.pos;
    }
    long long ChangeT;
    double Afterspeed;
    long long BeforeT,AfterT;
};

// 变速曲线
struct BulletArc_SpeedUp : public Bullet_Style {
    BulletArc_SpeedUp ( long long id , magi::Color c , double r , magi::Vec2 center , double angle , double speed , long long StartT , long long EndT ) : Bullet_Style (id,c,r,center,angle,speed,StartT,EndT) {}
    magi::Vec2 Pos () {
        double Speed,Angle;
        long long RealT = magi::Timer::get() ;
        long long RelaT = magi::Timer::get() - StartT ;
        Angle = 0.00628 * RelaT + this -> angle ;
        Speed = this -> speed - 0.0000001 * RealT ;
        this -> point.pos.x = cos(Angle)*Speed*RelaT + center.x ;
        this -> point.pos.y = sin(Angle)*Speed*RelaT + center.y ;
        // cout << "(" << this -> point.pos.x << "," << this -> point.pos.y << ")" << Speed << endl ;

        // cout << this -> center.x << "," << this -> center.y << endl ;
        return this -> point.pos;
    }
};
/* struct BulletArc_SpeedUp : public Bullet_Style {
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
}; */

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
    Bullets_Info () {}
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

// EVA
struct Creat_BulletsInfo_EVA : public Bullets_Info {
    Creat_BulletsInfo_EVA ( int NUM , long long StartT , int n , magi::Vec2 center , magi::Vec2 range , double r , double speed , Kind kind ) {
        this -> EndT = StartT + 9000;                                                  // EndT 计算
        double startt = StartT;
        double endt = this -> EndT;
        int size_ = magi::colors("EVA").size() ;
            for ( int i = 0 ; i < n ; i++ ) {
                for ( int j = 0 ; j < 60 ; j++ ) {
                    bullets[NUM -1].push_back( Creat ( startt , endt , magi::colors("EVA")[i%size_] , r , center , (range.x + ((range.y-range.x)/60 * j)) , speed , kind ) );
                }
                range.x += pow(-1,i%2)*0.052359876 ;
                range.y += pow(-1,i%2)*0.052359876 ;
                startt += 500 ;
                endt += 500 ;
            }
    }
};

// 迷宫
struct Creat_BulletsInfo_Maze : public Bullets_Info {
    Creat_BulletsInfo_Maze ( int NUM , long long ChangeT , int n , magi::Color c , magi::Vec2 center , magi::Vec2 range , double r , double speed , double Afterspeed ) {
        this -> EndT = 5000;
        for (int i =0; i < n ; i++) {
            bullets[NUM -1].push_back( make_shared<BulletLine_ChangeSpeed> (BulletLine_ChangeSpeed(ID,c,r,center,(range.x + ((range.y-range.x)/n * i)),speed,Afterspeed,ChangeT,EndT)) );ID++;
        }
    }
};

// 缩圈
struct Creat_BulletsInfo_Circle : public Bullets_Info {
    Creat_BulletsInfo_Circle ( int NUM , long long StartT , int n , magi::Vec2 center , magi::Vec2 range , double r , double speed , Kind kind ) {
        this -> EndT = StartT + 9000;                                                  // EndT 计算
        double startt = StartT;
        double endt = this -> EndT;
        double angle = range.x ;
        int size_ = magi::colors("EVA").size() ;
        int colorsize = 10 ;
            for ( int i = 0 ; i < n ; i++ ) {
                bullets[NUM - 1].push_back( Creat ( startt , endt , magi::colors("graduatedBlue")[ (i/colorsize)%(2*(size_-1)) < 9 ? (i/colorsize)%(2*(size_-1)) : ((2*(size_-1))-(i/colorsize)%(2*(size_-1))) ].mix(magi::colors("graduatedBlue")[ (i/colorsize+1)%(2*(size_-1)) < 9 ? (i/colorsize+1)%(2*(size_-1)) : ((2*(size_-1))-(i/colorsize+1)%(2*(size_-1))) ],(i%colorsize)/(colorsize-1.0)) ,
                                                    r , center , angle , speed , kind ) );
                startt += 5 ;
                endt += 5 ;
                angle += 0.005 ;
        }
    }
};

// 烟花
struct Creat_BulletsInfo_Fireworks : public Bullets_Info {
    Creat_BulletsInfo_Fireworks  () {

    }
};


/* // bulletsinfo 构建函数
size_t Creat_bulletsinfo () {

} */

struct CharacterInfo : public magi::Character {

};

bool Less_Than ( shared_ptr<Bullet_Style> a , shared_ptr<Bullet_Style> b ) {
    if ( a -> StartT < b -> StartT ) { return true; }
    else if ( a -> StartT > b -> StartT ) { return false; }
    else if ( a -> EndT < b -> EndT ) { return true; }
    else { return false; }
}
void magi:: initBullets () {
    for (int i = 0 ; i < StageNum ; i++) {
        sort ( bullets[i].begin() , bullets[i].end() , Less_Than );
    }
}
