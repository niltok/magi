#include "statement.h"
#include "effects.h"

using namespace std;

magi::Character ch{"Paimon1.png", magi::Vec2(0, -6), 5, magi::Color("ef233c")};                    // test 用 （删）
long long EndTime = 1000000;             // test 用 （删）



long Size = 0;
long long ID = 0;
int StageNum = 5;
vector<vector<shared_ptr<Bullet_Style>>> bullets(5);



// Bullets_Info : 关卡(int) ,开始时间(long long) ,弹幕数量 (int) ,颜色 (magi::Color) ,中心位置 (magi::Vec2) ,角度范围 (magi::Vec2) ,半径 (double) ,速度 (double) ,运动类型 (Kind)

vector<vector<shared_ptr<Bullets_Info>>> stage_info {
    // 关卡1
    {
        make_shared<Bullets_Info> ( Creat_BulletsInfo_EVA ( Stage_One , 5000 , 250 , magi::Vec2(0.0,-100.0) , magi::Vec2(0.0,magi::PI2) , SMALL_ , LOW_ , Line ) )
    },
    // 关卡2
    {
        make_shared<Bullets_Info> ( Bullets_Info ( Stage_Two , 1000 , 30 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.0,magi::PI2) , SMALL_ , LOW_ , Line ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( Stage_Two , 1500 , 30 , magi::colors("orangeToWhite")[1] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.052359876,magi::PI2 + 0.052359876) , SMALL_ , LOW_ , ReverseLine ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( Stage_Two , 2000 , 30 , magi::colors("orangeToWhite")[2] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.0,magi::PI2) , SMALL_ , LOW_ , Line ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( Stage_Two , 2500 , 30 , magi::colors("orangeToWhite")[3] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.052359876,magi::PI2 + 0.052359876) , SMALL_ , LOW_ , ReverseLine ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( Stage_Two , 3000 , 30 , magi::colors("orangeToWhite")[4] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.0,magi::PI2) , SMALL_ , LOW_ , Line ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( Stage_Two , 3500 , 30 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.052359876,magi::PI2 + 0.052359876) , SMALL_ , LOW_ , ReverseLine ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( Stage_Two , 4000 , 30 , magi::colors("orangeToWhite")[1] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.0,magi::PI2) , SMALL_ , LOW_ , Line ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( Stage_Two , 4500 , 30 , magi::colors("orangeToWhite")[2] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.052359876,magi::PI2 + 0.052359876) , SMALL_ , LOW_ , ReverseLine ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( Stage_Two , 5000 , 30 , magi::colors("orangeToWhite")[3] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.0,magi::PI2) , SMALL_ , LOW_ , Line ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( Stage_Two , 5500 , 30 , magi::colors("orangeToWhite")[4] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.052359876,magi::PI2 + 0.052359876) , SMALL_ , LOW_ , ReverseLine ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( Stage_Two , 6000 , 30 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.0,magi::PI2) , SMALL_ , LOW_ , Line ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( Stage_Two , 6500 , 30 , magi::colors("orangeToWhite")[1] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.052359876,magi::PI2 + 0.052359876) , SMALL_ , LOW_ , ReverseLine ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( Stage_Two , 7000 , 30 , magi::colors("orangeToWhite")[2] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.0,magi::PI2) , SMALL_ , LOW_ , Line ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( Stage_Two , 7500 , 30 , magi::colors("orangeToWhite")[3] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.052359876,magi::PI2 + 0.052359876) , SMALL_ , LOW_ , ReverseLine ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( Stage_Two , 8000 , 30 , magi::colors("orangeToWhite")[4] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.0,magi::PI2) , SMALL_ , LOW_ , Line ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( Stage_Two , 8500 , 30 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.052359876,magi::PI2 + 0.052359876) , SMALL_ , LOW_ , ReverseLine ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( Stage_Two , 9000 , 30 , magi::colors("orangeToWhite")[1] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.0,magi::PI2) , SMALL_ , LOW_ , Line ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( Stage_Two , 9500 , 30 , magi::colors("orangeToWhite")[2] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.052359876,magi::PI2 + 0.052359876) , SMALL_ , LOW_ , ReverseLine ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( Stage_Two , 10000 , 30 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.0,magi::PI2) , SMALL_ , LOW_ , Line ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( Stage_Two , 10500 , 30 , magi::colors("orangeToWhite")[1] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.052359876,magi::PI2 + 0.052359876) , SMALL_ , LOW_ , ReverseLine ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( Stage_Two , 11000 , 30 , magi::colors("orangeToWhite")[2] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.0,magi::PI2) , SMALL_ , LOW_ , Line ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( Stage_Two , 11500 , 30 , magi::colors("orangeToWhite")[3] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.052359876,magi::PI2 + 0.052359876) , SMALL_ , LOW_ , ReverseLine ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( Stage_Two , 12000 , 30 , magi::colors("orangeToWhite")[4] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.0,magi::PI2) , SMALL_ , LOW_ , Line ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( Stage_Two , 12500 , 30 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.052359876,magi::PI2 + 0.052359876) , SMALL_ , LOW_ , ReverseLine ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( Stage_Two , 13000 , 30 , magi::colors("orangeToWhite")[1] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.0,magi::PI2) , SMALL_ , LOW_ , Line ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( Stage_Two , 13500 , 30 , magi::colors("orangeToWhite")[2] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.052359876,magi::PI2 + 0.052359876) , SMALL_ , LOW_ , ReverseLine ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( Stage_Two , 14000 , 30 , magi::colors("orangeToWhite")[3] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.0,magi::PI2) , SMALL_ , LOW_ , Line ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( Stage_Two , 14500 , 30 , magi::colors("orangeToWhite")[4] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.052359876,magi::PI2 + 0.052359876) , SMALL_ , LOW_ , ReverseLine ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( Stage_Two , 15000 , 30 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.0,magi::PI2) , SMALL_ , LOW_ , Line ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( Stage_Two , 15500 , 30 , magi::colors("orangeToWhite")[1] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.052359876,magi::PI2 + 0.052359876) , SMALL_ , LOW_ , ReverseLine ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( Stage_Two , 16000 , 30 , magi::colors("orangeToWhite")[2] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.0,magi::PI2) , SMALL_ , LOW_ , Line ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( Stage_Two , 16500 , 30 , magi::colors("orangeToWhite")[3] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.052359876,magi::PI2 + 0.052359876) , SMALL_ , LOW_ , ReverseLine ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( Stage_Two , 17000 , 30 , magi::colors("orangeToWhite")[4] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.0,magi::PI2) , SMALL_ , LOW_ , Line ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( Stage_Two , 17500 , 30 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.052359876,magi::PI2 + 0.052359876) , SMALL_ , LOW_ , ReverseLine ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( Stage_Two , 18000 , 30 , magi::colors("orangeToWhite")[1] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.0,magi::PI2) , SMALL_ , LOW_ , Line ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( Stage_Two , 18500 , 30 , magi::colors("orangeToWhite")[2] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.052359876,magi::PI2 + 0.052359876) , SMALL_ , LOW_ , ReverseLine ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( Stage_Two , 19000 , 30 , magi::colors("orangeToWhite")[3] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.0,magi::PI2) , SMALL_ , LOW_ , Line ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( Stage_Two , 19500 , 30 , magi::colors("orangeToWhite")[4] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.052359876,magi::PI2 + 0.052359876) , SMALL_ , LOW_ , ReverseLine ) ),
        make_shared<Bullets_Info> ( Bullets_Info ( Stage_Two , 20000 , 30 , magi::colors("orangeToWhite")[3] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.0,magi::PI2) , SMALL_ , LOW_ , Line ) ),

    },
    // 关卡3    3248+2435* n ; (0,17)
    // Creat_BulletsInfo_Maze : 关卡(int) ,改变时间(long long) ,改变位置(double) ,弹幕数量 (int) ,颜色 (magi::Color) ,中心位置 (magi::Vec2) ,角度范围 (magi::Vec2) ,半径 (double) ,速度 (double),改变速度 (double)
    {
        // make_shared<Bullets_Info> ( Bullets_Info ( Stage_Three , 1000 , 60 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,0.0) , magi::Vec2(0.0,6.0) , SMALL_ , 0.5 , ReverseLine ) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 3248 , 60 , 60 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,0.0) , magi::Vec2(0.0,6.0) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 5683 , 60 , 60 , magi::colors("orangeToWhite")[1] , magi::Vec2(0.0,0.0) , magi::Vec2(0.0,6.0) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 8118 , 60 , 60 , magi::colors("orangeToWhite")[2] , magi::Vec2(0.0,0.0) , magi::Vec2(0.0,6.0) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 10553 , 60 , 60 , magi::colors("orangeToWhite")[3] , magi::Vec2(0.0,0.0) , magi::Vec2(0.0,6.0) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 12988 , 60 , 60 , magi::colors("orangeToWhite")[4] , magi::Vec2(0.0,0.0) , magi::Vec2(0.0,6.0) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 15423 , 60 , 60 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,0.0) , magi::Vec2(0.0,6.0) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 17858 , 60 , 60 , magi::colors("orangeToWhite")[1] , magi::Vec2(0.0,0.0) , magi::Vec2(0.0,6.0) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 20293 , 60 , 60 , magi::colors("orangeToWhite")[2] , magi::Vec2(0.0,0.0) , magi::Vec2(0.0,6.0) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 22728 , 60 , 60 , magi::colors("orangeToWhite")[3] , magi::Vec2(0.0,0.0) , magi::Vec2(0.0,6.0) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 25163 , 60 , 60 , magi::colors("orangeToWhite")[4] , magi::Vec2(0.0,0.0) , magi::Vec2(0.0,6.0) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 27598 , 60 , 60 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,0.0) , magi::Vec2(0.0,6.0) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 30033 , 60 , 60 , magi::colors("orangeToWhite")[1] , magi::Vec2(0.0,0.0) , magi::Vec2(0.0,6.0) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 32468 , 60 , 60 , magi::colors("orangeToWhite")[2] , magi::Vec2(0.0,0.0) , magi::Vec2(0.0,6.0) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 34903 , 60 , 60 , magi::colors("orangeToWhite")[3] , magi::Vec2(0.0,0.0) , magi::Vec2(0.0,6.0) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 37338 , 60 , 60 , magi::colors("orangeToWhite")[4] , magi::Vec2(0.0,0.0) , magi::Vec2(0.0,6.0) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 39773 , 60 , 60 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,0.0) , magi::Vec2(0.0,6.0) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 42208 , 60 , 60 , magi::colors("orangeToWhite")[1] , magi::Vec2(0.0,0.0) , magi::Vec2(0.0,6.0) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 44643 , 60 , 60 , magi::colors("orangeToWhite")[2] , magi::Vec2(0.0,0.0) , magi::Vec2(0.0,6.0) , SMALL_ , LOW_ , 0.5) ),
        
    },
    // 关卡4
    {
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Circle ( 4 , 1000 , (15860 - 1000) / 5 , magi::Vec2(0.0,0.0) , magi::Vec2(0.0,magi::PI2) , MIDDLE_ , LOW_ , Arc_SpeedUp ) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Circle ( 4 , 19400 , (36150 - 19400) / 5 , magi::Vec2(0.0,0.0) , magi::Vec2(0.0,magi::PI2) , MIDDLE_ , LOW_ , Arc_SpeedUp ) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Circle ( 4 , 37230 , (51140 - 37230) / 5 , magi::Vec2(0.0,0.0) , magi::Vec2(0.0,magi::PI2) , MIDDLE_ , LOW_ , Arc_SpeedUp ) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Circle ( 4 , 55030 , (87300 - 55030) / 5 , magi::Vec2(0.0,0.0) , magi::Vec2(0.0,magi::PI2) , MIDDLE_ , LOW_ , Arc_SpeedUp ) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Circle ( 4 , 90815 , (100000 - 90815) / 5 , magi::Vec2(0.0,0.0) , magi::Vec2(0.0,magi::PI2) , MIDDLE_ , LOW_ , Arc_SpeedUp ) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Circle ( 4 , 100300 , (100500 - 100300) / 5 , magi::Vec2(0.0,0.0) , magi::Vec2(0.0,magi::PI2) , MIDDLE_ , LOW_ , Arc_SpeedUp ) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Circle ( 4 , 100850 , (101000 - 100850) / 5 , magi::Vec2(0.0,0.0) , magi::Vec2(0.0,magi::PI2) , MIDDLE_ , LOW_ , Arc_SpeedUp ) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Circle ( 4 , 101430 , (101600 - 101430) / 5 , magi::Vec2(0.0,0.0) , magi::Vec2(0.0,magi::PI2) , MIDDLE_ , LOW_ , Arc_SpeedUp ) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Circle ( 4 , 101960 , (102000 - 101960) / 5 , magi::Vec2(0.0,0.0) , magi::Vec2(0.0,magi::PI2) , MIDDLE_ , LOW_ , Arc_SpeedUp ) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Circle ( 4 , 102520 , (102650 - 102520) / 5 , magi::Vec2(0.0,0.0) , magi::Vec2(0.0,magi::PI2) , MIDDLE_ , LOW_ , Arc_SpeedUp ) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Circle ( 4 , 103070 , (103200 - 103070) / 5 , magi::Vec2(0.0,0.0) , magi::Vec2(0.0,magi::PI2) , MIDDLE_ , LOW_ , Arc_SpeedUp ) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Circle ( 4 , 103630 , (103730 - 103630) / 5 , magi::Vec2(0.0,0.0) , magi::Vec2(0.0,magi::PI2) , MIDDLE_ , LOW_ , Arc_SpeedUp ) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Circle ( 4 , 104185 , (104295 - 104185) / 5 , magi::Vec2(0.0,0.0) , magi::Vec2(0.0,magi::PI2) , MIDDLE_ , LOW_ , Arc_SpeedUp ) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Circle ( 4 , 104740 , (104850 - 104740) / 5 , magi::Vec2(0.0,0.0) , magi::Vec2(0.0,magi::PI2) , MIDDLE_ , LOW_ , Arc_SpeedUp ) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Circle ( 4 , 108320 , (125030 - 108329) / 5 , magi::Vec2(0.0,0.0) , magi::Vec2(0.0,magi::PI2) , MIDDLE_ , LOW_ , Arc_SpeedUp ) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Circle ( 4 , 126020 , (140030 - 125020) / 5 , magi::Vec2(0.0,0.0) , magi::Vec2(0.0,magi::PI2) , MIDDLE_ , LOW_ , Arc_SpeedUp ) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Circle ( 4 , 143930 , (176115 - 143930) / 5 , magi::Vec2(0.0,0.0) , magi::Vec2(0.0,magi::PI2) , MIDDLE_ , LOW_ , Arc_SpeedUp ) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Circle ( 4 , 179480 , (211680 - 179480) / 5 , magi::Vec2(0.0,0.0) , magi::Vec2(0.0,magi::PI2) , MIDDLE_ , LOW_ , Arc_SpeedUp ) ),
    },
    // 关卡5
    {
        make_shared<Bullets_Info> ( Bullets_Info ( Stage_Five , 1000 , 10 , magi::colors("orangeToWhite")[2] , magi::Vec2(0.0,-100.0) , magi::Vec2(0.052359876,1.0) , LARGE_ , LOW_ , Line ) ),
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
    size_t i = 0;
    auto operator()() -> shared_ptr<bullets_effect> {
        bullets_effect Re ;
        Re.Num = Num;
        Re.Size = 0;
        long long RelT = magi::Timer::get();
        while ( i < bullets[Num].size() && bullets[Num][i] -> EndT < RelT ) { i++ ; }
        Re.Before = i;
        for ( size_t j = i; j < bullets[Num].size() && bullets[Num][j] -> StartT < RelT; j++ ) {
            Re.Size++ ;
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

magi::Character ch_adam {"EVA_Adam.png", magi::Vec2(-1.4, 6.5), 10, magi::Color("78000000")};

vector<magi::Stage> magi::Stage::stage {
    magi::Stage{"Death and Rebirth", getBullet_Re{0}, ch_adam, "OdeToJoy1.mp3",140000, "EVA1.jpg", magiUI::EVAEffects},
    magi::Stage{"ReverseLine Bullets Test", getBullet_Re{1}, ch, "440.mp3",EndTime, ""},
    magi::Stage{"迷宫", getBullet_Re{2}, ch, "Sis puella magica!.mp3",EndTime, ""},
    magi::Stage{"缩圈",getBullet_Re{3},ch,"青花瓷.mp3", 229333, ""},
    magi::Stage{"烟花",getBullet_Re{4},ch,"敬具.mp3",EndTime, ""}
};


