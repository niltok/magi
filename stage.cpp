#include "statement.h"

using namespace std;

magi::Character ch{};                    // test 用 （删）
long long EndTime = 1000000;             // test 用 （删）



long Size = 0;
long long ID = 0;
int StageNum = 5;
vector<vector<shared_ptr<Bullet_Style>>> bullets(5);



// Bullets_Info : 关卡(int) ,开始时间(long long) ,弹幕数量 (int) ,颜色 (magi::Color) ,中心位置 (magi::Vec2) ,角度范围 (magi::Vec2) ,半径 (double) ,速度 (double), 运动类型 (Kind)

vector<vector<shared_ptr<Bullets_Info>>> stage_info {
    // 关卡1
    {
        make_shared<Bullets_Info> ( Bullets_Info ( 1 , 1000 , 60 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.0,magi::PI2) , SMALL_ , LOW_ , Line ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( 1 , 1500 , 60 , magi::colors("orangeToWhite")[1] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.052359876,magi::PI2 + 0.052359876) , SMALL_ , LOW_ , Line ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( 1 , 2000 , 60 , magi::colors("orangeToWhite")[2] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.0,magi::PI2) , SMALL_ , LOW_ , Line ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( 1 , 2500 , 60 , magi::colors("orangeToWhite")[3] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.052359876,magi::PI2 + 0.052359876) , SMALL_ , LOW_ , Line ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( 1 , 3000 , 60 , magi::colors("orangeToWhite")[4] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.0,magi::PI2) , SMALL_ , LOW_ , Line ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( 1 , 3500 , 60 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.052359876,magi::PI2 + 0.052359876) , SMALL_ , LOW_ , Line ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( 1 , 4000 , 60 , magi::colors("orangeToWhite")[1] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.0,magi::PI2) , SMALL_ , LOW_ , Line ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( 1 , 4500 , 60 , magi::colors("orangeToWhite")[2] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.052359876,magi::PI2 + 0.052359876) , SMALL_ , LOW_ , Line ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( 1 , 5000 , 60 , magi::colors("orangeToWhite")[3] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.0,magi::PI2) , SMALL_ , LOW_ , Line ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( 1 , 5500 , 60 , magi::colors("orangeToWhite")[4] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.052359876,magi::PI2 + 0.052359876) , SMALL_ , LOW_ , Line ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( 1 , 6000 , 60 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.0,magi::PI2) , SMALL_ , LOW_ , Line ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( 1 , 6500 , 60 , magi::colors("orangeToWhite")[1] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.052359876,magi::PI2 + 0.052359876) , SMALL_ , LOW_ , Line ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( 1 , 7000 , 60 , magi::colors("orangeToWhite")[2] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.0,magi::PI2) , SMALL_ , LOW_ , Line ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( 1 , 7500 , 60 , magi::colors("orangeToWhite")[3] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.052359876,magi::PI2 + 0.052359876) , SMALL_ , LOW_ , Line ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( 1 , 8000 , 60 , magi::colors("orangeToWhite")[4] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.0,magi::PI2) , SMALL_ , LOW_ , Line ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( 1 , 8500 , 60 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.052359876,magi::PI2 + 0.052359876) , SMALL_ , LOW_ , Line ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( 1 , 9000 , 60 , magi::colors("orangeToWhite")[1] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.0,magi::PI2) , SMALL_ , LOW_ , Line ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( 1 , 9500 , 60 , magi::colors("orangeToWhite")[2] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.052359876,magi::PI2 + 0.052359876) , SMALL_ , LOW_ , Line ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( 1 , 10000 , 60 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.0,magi::PI2) , SMALL_ , LOW_ , Line ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( 1 , 10500 , 60 , magi::colors("orangeToWhite")[1] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.052359876,magi::PI2 + 0.052359876) , SMALL_ , LOW_ , Line ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( 1 , 11000 , 60 , magi::colors("orangeToWhite")[2] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.0,magi::PI2) , SMALL_ , LOW_ , Line ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( 1 , 11500 , 60 , magi::colors("orangeToWhite")[3] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.052359876,magi::PI2 + 0.052359876) , SMALL_ , LOW_ , Line ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( 1 , 12000 , 60 , magi::colors("orangeToWhite")[4] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.0,magi::PI2) , SMALL_ , LOW_ , Line ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( 1 , 12500 , 60 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.052359876,magi::PI2 + 0.052359876) , SMALL_ , LOW_ , Line ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( 1 , 13000 , 60 , magi::colors("orangeToWhite")[1] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.0,magi::PI2) , SMALL_ , LOW_ , Line ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( 1 , 13500 , 60 , magi::colors("orangeToWhite")[2] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.052359876,magi::PI2 + 0.052359876) , SMALL_ , LOW_ , Line ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( 1 , 14000 , 60 , magi::colors("orangeToWhite")[3] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.0,magi::PI2) , SMALL_ , LOW_ , Line ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( 1 , 14500 , 60 , magi::colors("orangeToWhite")[4] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.052359876,magi::PI2 + 0.052359876) , SMALL_ , LOW_ , Line ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( 1 , 15000 , 60 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.0,magi::PI2) , SMALL_ , LOW_ , Line ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( 1 , 15500 , 60 , magi::colors("orangeToWhite")[1] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.052359876,magi::PI2 + 0.052359876) , SMALL_ , LOW_ , Line ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( 1 , 16000 , 60 , magi::colors("orangeToWhite")[2] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.0,magi::PI2) , SMALL_ , LOW_ , Line ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( 1 , 16500 , 60 , magi::colors("orangeToWhite")[3] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.052359876,magi::PI2 + 0.052359876) , SMALL_ , LOW_ , Line ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( 1 , 17000 , 60 , magi::colors("orangeToWhite")[4] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.0,magi::PI2) , SMALL_ , LOW_ , Line ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( 1 , 17500 , 60 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.052359876,magi::PI2 + 0.052359876) , SMALL_ , LOW_ , Line ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( 1 , 18000 , 60 , magi::colors("orangeToWhite")[1] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.0,magi::PI2) , SMALL_ , LOW_ , Line ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( 1 , 18500 , 60 , magi::colors("orangeToWhite")[2] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.052359876,magi::PI2 + 0.052359876) , SMALL_ , LOW_ , Line ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( 1 , 19000 , 60 , magi::colors("orangeToWhite")[3] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.0,magi::PI2) , SMALL_ , LOW_ , Line ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( 1 , 19500 , 60 , magi::colors("orangeToWhite")[4] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.052359876,magi::PI2 + 0.052359876) , SMALL_ , LOW_ , Line ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( 1 , 20000 , 60 , magi::colors("orangeToWhite")[3] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.0,magi::PI2) , SMALL_ , LOW_ , Line ) ),

    },
    // 关卡2
    {
        make_shared<Bullets_Info> ( Bullets_Info ( 2 , 1000 , 30 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.0,magi::PI2) , SMALL_ , LOW_ , Line ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( 2 , 1500 , 30 , magi::colors("orangeToWhite")[1] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.052359876,magi::PI2 + 0.052359876) , SMALL_ , LOW_ , ReverseLine ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( 2 , 2000 , 30 , magi::colors("orangeToWhite")[2] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.0,magi::PI2) , SMALL_ , LOW_ , Line ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( 2 , 2500 , 30 , magi::colors("orangeToWhite")[3] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.052359876,magi::PI2 + 0.052359876) , SMALL_ , LOW_ , ReverseLine ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( 2 , 3000 , 30 , magi::colors("orangeToWhite")[4] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.0,magi::PI2) , SMALL_ , LOW_ , Line ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( 2 , 3500 , 30 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.052359876,magi::PI2 + 0.052359876) , SMALL_ , LOW_ , ReverseLine ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( 2 , 4000 , 30 , magi::colors("orangeToWhite")[1] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.0,magi::PI2) , SMALL_ , LOW_ , Line ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( 2 , 4500 , 30 , magi::colors("orangeToWhite")[2] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.052359876,magi::PI2 + 0.052359876) , SMALL_ , LOW_ , ReverseLine ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( 2 , 5000 , 30 , magi::colors("orangeToWhite")[3] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.0,magi::PI2) , SMALL_ , LOW_ , Line ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( 2 , 5500 , 30 , magi::colors("orangeToWhite")[4] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.052359876,magi::PI2 + 0.052359876) , SMALL_ , LOW_ , ReverseLine ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( 2 , 6000 , 30 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.0,magi::PI2) , SMALL_ , LOW_ , Line ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( 2 , 6500 , 30 , magi::colors("orangeToWhite")[1] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.052359876,magi::PI2 + 0.052359876) , SMALL_ , LOW_ , ReverseLine ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( 2 , 7000 , 30 , magi::colors("orangeToWhite")[2] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.0,magi::PI2) , SMALL_ , LOW_ , Line ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( 2 , 7500 , 30 , magi::colors("orangeToWhite")[3] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.052359876,magi::PI2 + 0.052359876) , SMALL_ , LOW_ , ReverseLine ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( 2 , 8000 , 30 , magi::colors("orangeToWhite")[4] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.0,magi::PI2) , SMALL_ , LOW_ , Line ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( 2 , 8500 , 30 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.052359876,magi::PI2 + 0.052359876) , SMALL_ , LOW_ , ReverseLine ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( 2 , 9000 , 30 , magi::colors("orangeToWhite")[1] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.0,magi::PI2) , SMALL_ , LOW_ , Line ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( 2 , 9500 , 30 , magi::colors("orangeToWhite")[2] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.052359876,magi::PI2 + 0.052359876) , SMALL_ , LOW_ , ReverseLine ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( 2 , 10000 , 30 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.0,magi::PI2) , SMALL_ , LOW_ , Line ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( 2 , 10500 , 30 , magi::colors("orangeToWhite")[1] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.052359876,magi::PI2 + 0.052359876) , SMALL_ , LOW_ , ReverseLine ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( 2 , 11000 , 30 , magi::colors("orangeToWhite")[2] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.0,magi::PI2) , SMALL_ , LOW_ , Line ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( 2 , 11500 , 30 , magi::colors("orangeToWhite")[3] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.052359876,magi::PI2 + 0.052359876) , SMALL_ , LOW_ , ReverseLine ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( 2 , 12000 , 30 , magi::colors("orangeToWhite")[4] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.0,magi::PI2) , SMALL_ , LOW_ , Line ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( 2 , 12500 , 30 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.052359876,magi::PI2 + 0.052359876) , SMALL_ , LOW_ , ReverseLine ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( 2 , 13000 , 30 , magi::colors("orangeToWhite")[1] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.0,magi::PI2) , SMALL_ , LOW_ , Line ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( 2 , 13500 , 30 , magi::colors("orangeToWhite")[2] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.052359876,magi::PI2 + 0.052359876) , SMALL_ , LOW_ , ReverseLine ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( 2 , 14000 , 30 , magi::colors("orangeToWhite")[3] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.0,magi::PI2) , SMALL_ , LOW_ , Line ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( 2 , 14500 , 30 , magi::colors("orangeToWhite")[4] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.052359876,magi::PI2 + 0.052359876) , SMALL_ , LOW_ , ReverseLine ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( 2 , 15000 , 30 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.0,magi::PI2) , SMALL_ , LOW_ , Line ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( 2 , 15500 , 30 , magi::colors("orangeToWhite")[1] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.052359876,magi::PI2 + 0.052359876) , SMALL_ , LOW_ , ReverseLine ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( 2 , 16000 , 30 , magi::colors("orangeToWhite")[2] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.0,magi::PI2) , SMALL_ , LOW_ , Line ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( 2 , 16500 , 30 , magi::colors("orangeToWhite")[3] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.052359876,magi::PI2 + 0.052359876) , SMALL_ , LOW_ , ReverseLine ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( 2 , 17000 , 30 , magi::colors("orangeToWhite")[4] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.0,magi::PI2) , SMALL_ , LOW_ , Line ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( 2 , 17500 , 30 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.052359876,magi::PI2 + 0.052359876) , SMALL_ , LOW_ , ReverseLine ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( 2 , 18000 , 30 , magi::colors("orangeToWhite")[1] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.0,magi::PI2) , SMALL_ , LOW_ , Line ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( 2 , 18500 , 30 , magi::colors("orangeToWhite")[2] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.052359876,magi::PI2 + 0.052359876) , SMALL_ , LOW_ , ReverseLine ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( 2 , 19000 , 30 , magi::colors("orangeToWhite")[3] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.0,magi::PI2) , SMALL_ , LOW_ , Line ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( 2 , 19500 , 30 , magi::colors("orangeToWhite")[4] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.052359876,magi::PI2 + 0.052359876) , SMALL_ , LOW_ , ReverseLine ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( 2 , 20000 , 30 , magi::colors("orangeToWhite")[3] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.0,magi::PI2) , SMALL_ , LOW_ , Line ) ),

    },
    // 关卡3
    {
        make_shared<Bullets_Info> ( Bullets_Info ( 3 , 1000 , 10 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.052359876,1.0) , SMALL_ , FAST_ , ReverseArc ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( 3 , 3000 , 10 , magi::colors("orangeToWhite")[1] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.052359876,1.0) , SMALL_ , FAST_ , ReverseArc ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( 3 , 5000 , 10 , magi::colors("orangeToWhite")[2] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.052359876,1.0) , SMALL_ , FAST_ , ReverseArc ) ),
    },
    // 关卡4
    {
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Circle ( 4 , 1000 , 10000 , magi::colors("orangeToWhite")[3] , magi::Vec2(0.0,0.0) , magi::Vec2(0.0,magi::PI2) , SMALL_ , FAST_ , Arc_SpeedUp ) ),
    },
    // 关卡5
    {

    }
};


// 当前时间弹幕信息类
struct bullets_effect : public magi::Bullets {
    int Num , Size ;
    long Before ;
    size_t size() const {
        return Size ;
    }
    magi::Point operator[](size_t index) {
        (bullets[Num][Before+index]) -> Pos();
        return (bullets[Num][Before+index]) -> point ;
    }
};

// 获取当前时间弹幕信息
struct getBullet_Re {
    int Num;
    auto operator()() -> shared_ptr<bullets_effect> {
        bullets_effect Re ;
        Re.Num = Num;
        Re.Size = 0;
        long long RelT = magi::Timer::get();
        size_t i = 0;
        while ( i < bullets[Num].size() && bullets[Num][i] -> EndT < RelT ) { i++ ; }
        Re.Before = i;
        while ( i < bullets[Num].size() && bullets[Num][i] -> StartT < RelT ) {
            Re.Size++ ; i++ ;
        }
        return make_shared<bullets_effect> (Re);
    }
};

/* function<shared_ptr<Bullet_Result>()> getBullet_(int k) {
    return [=] () -> shared_ptr<Bullet_Result> {
        Size = 0;
        long long RelT = magi::Timer::get();
        int i = 0;
        // for ( i = 0 ; stage_info1[i].EndT > RelT ; i++ ) {}
        while ( stage_info1[i].EndT < RelT ) { i++; }
        while ( stage_info1[i].StartT < RelT ) {
            i++;
        }
        return ;
    };
} */

vector<magi::Stage> magi::Stage::stage {
    magi::Stage{"Interlaced Bullets Test", getBullet_Re{0}, ch, "qrc:/music/OdeToJoy1",EndTime},
    magi::Stage{"ReverseLine Bullets Test", getBullet_Re{1}, ch, "",EndTime},
    magi::Stage{"Arc Bullets Test", getBullet_Re{2}, ch, "",EndTime},
    magi::Stage{"Circle Bullets Try",getBullet_Re{3},ch,"",EndTime},
    magi::Stage{"Imagine Type Test",getBullet_Re{4},ch,"",EndTime}
};


