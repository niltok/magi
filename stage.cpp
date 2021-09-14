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
    // Creat_BulletsInfo_Maze : 关卡(int) ,改变时间(long long) ,改变位置(double) ,弹幕数量 (int) ,颜色 (magi::Color) ,中心位置 (magi::Vec2) ,角度范围 (magi::Vec2)(起始位置,开口大小) ,半径 (double) ,速度 (double),改变速度 (double)
    {
        // make_shared<Bullets_Info> ( Bullets_Info ( Stage_Three , 1000 , 80 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,0.0) , magi::Vec2(0.0,6.0) , SMALL_ , 0.5 , ReverseLine ) ),
        // 前段
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 3248 , 80 , 60 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,0.0) , magi::Vec2(210,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 5683 , 80 , 60 , magi::colors("orangeToWhite")[1] , magi::Vec2(0.0,0.0) , magi::Vec2(20,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 8118 , 80 , 60 , magi::colors("orangeToWhite")[2] , magi::Vec2(0.0,0.0) , magi::Vec2(90,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 10553 , 80 , 60 , magi::colors("orangeToWhite")[3] , magi::Vec2(0.0,0.0) , magi::Vec2(220,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 12988 , 80 , 60 , magi::colors("orangeToWhite")[4] , magi::Vec2(0.0,0.0) , magi::Vec2(60,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 15423 , 80 , 60 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,0.0) , magi::Vec2(170,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 17858 , 80 , 60 , magi::colors("orangeToWhite")[1] , magi::Vec2(0.0,0.0) , magi::Vec2(140,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 20293 , 80 , 60 , magi::colors("orangeToWhite")[2] , magi::Vec2(0.0,0.0) , magi::Vec2(100,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 22728 , 80 , 60 , magi::colors("orangeToWhite")[3] , magi::Vec2(0.0,0.0) , magi::Vec2(260,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 25163 , 80 , 60 , magi::colors("orangeToWhite")[4] , magi::Vec2(0.0,0.0) , magi::Vec2(220,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 27598 , 80 , 60 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,0.0) , magi::Vec2(290,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 30033 , 80 , 60 , magi::colors("orangeToWhite")[1] , magi::Vec2(0.0,0.0) , magi::Vec2(50,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 32468 , 80 , 60 , magi::colors("orangeToWhite")[2] , magi::Vec2(0.0,0.0) , magi::Vec2(170,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 34903 , 80 , 60 , magi::colors("orangeToWhite")[3] , magi::Vec2(0.0,0.0) , magi::Vec2(200,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 37338 , 80 , 60 , magi::colors("orangeToWhite")[4] , magi::Vec2(0.0,0.0) , magi::Vec2(310,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 39773 , 80 , 60 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,0.0) , magi::Vec2(270,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 42208 , 80 , 60 , magi::colors("orangeToWhite")[1] , magi::Vec2(0.0,0.0) , magi::Vec2(70,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 44643 , 80 , 60 , magi::colors("orangeToWhite")[2] , magi::Vec2(0.0,0.0) , magi::Vec2(150,40) , SMALL_ , LOW_ , 0.5) ),
        // 中段
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 49494 , 80 , 60 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,0.0) , magi::Vec2(270,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 50735 , 80 , 60 , magi::colors("orangeToWhite")[1] , magi::Vec2(0.0,0.0) , magi::Vec2(230,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 51660 , 80 , 60 , magi::colors("orangeToWhite")[2] , magi::Vec2(0.0,0.0) , magi::Vec2(310,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 52070 , 80 , 60 , magi::colors("orangeToWhite")[3] , magi::Vec2(0.0,0.0) , magi::Vec2(310,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 53270 , 80 , 60 , magi::colors("orangeToWhite")[4] , magi::Vec2(0.0,0.0) , magi::Vec2(270,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 54090 , 80 , 60 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,0.0) , magi::Vec2(200,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 54500 , 80 , 60 , magi::colors("orangeToWhite")[1] , magi::Vec2(0.0,0.0) , magi::Vec2(200,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 55340 , 80 , 60 , magi::colors("orangeToWhite")[2] , magi::Vec2(0.0,0.0) , magi::Vec2(150,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 55700 , 80 , 60 , magi::colors("orangeToWhite")[3] , magi::Vec2(0.0,0.0) , magi::Vec2(150,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 56520 , 80 , 60 , magi::colors("orangeToWhite")[4] , magi::Vec2(0.0,0.0) , magi::Vec2(100,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 56930 , 80 , 60 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,0.0) , magi::Vec2(100,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 57770 , 80 , 60 , magi::colors("orangeToWhite")[1] , magi::Vec2(0.0,0.0) , magi::Vec2(260,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 58130 , 80 , 60 , magi::colors("orangeToWhite")[2] , magi::Vec2(0.0,0.0) , magi::Vec2(260,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 58950 , 80 , 60 , magi::colors("orangeToWhite")[3] , magi::Vec2(0.0,0.0) , magi::Vec2(350,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 59360 , 80 , 60 , magi::colors("orangeToWhite")[4] , magi::Vec2(0.0,0.0) , magi::Vec2(350,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 60200 , 80 , 60 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,0.0) , magi::Vec2(300,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 60560 , 80 , 60 , magi::colors("orangeToWhite")[1] , magi::Vec2(0.0,0.0) , magi::Vec2(300,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 61380 , 80 , 60 , magi::colors("orangeToWhite")[2] , magi::Vec2(0.0,0.0) , magi::Vec2(50,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 61790 , 80 , 60 , magi::colors("orangeToWhite")[3] , magi::Vec2(0.0,0.0) , magi::Vec2(50,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 62630 , 80 , 60 , magi::colors("orangeToWhite")[4] , magi::Vec2(0.0,0.0) , magi::Vec2(300,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 62990 , 80 , 60 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,0.0) , magi::Vec2(300,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 63810 , 80 , 60 , magi::colors("orangeToWhite")[1] , magi::Vec2(0.0,0.0) , magi::Vec2(200,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 64220 , 80 , 60 , magi::colors("orangeToWhite")[2] , magi::Vec2(0.0,0.0) , magi::Vec2(200,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 65060 , 80 , 60 , magi::colors("orangeToWhite")[3] , magi::Vec2(0.0,0.0) , magi::Vec2(135,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 65420 , 80 , 60 , magi::colors("orangeToWhite")[4] , magi::Vec2(0.0,0.0) , magi::Vec2(135,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 66240 , 80 , 60 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,0.0) , magi::Vec2(37,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 66650 , 80 , 60 , magi::colors("orangeToWhite")[1] , magi::Vec2(0.0,0.0) , magi::Vec2(37,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 67490 , 80 , 60 , magi::colors("orangeToWhite")[2] , magi::Vec2(0.0,0.0) , magi::Vec2(320,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 67850 , 80 , 60 , magi::colors("orangeToWhite")[3] , magi::Vec2(0.0,0.0) , magi::Vec2(320,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 68670 , 80 , 60 , magi::colors("orangeToWhite")[4] , magi::Vec2(0.0,0.0) , magi::Vec2(234,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 69080 , 80 , 60 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,0.0) , magi::Vec2(234,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 69920 , 80 , 60 , magi::colors("orangeToWhite")[1] , magi::Vec2(0.0,0.0) , magi::Vec2(159,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 70280 , 80 , 60 , magi::colors("orangeToWhite")[2] , magi::Vec2(0.0,0.0) , magi::Vec2(159,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 71100 , 80 , 60 , magi::colors("orangeToWhite")[3] , magi::Vec2(0.0,0.0) , magi::Vec2(7,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 71510 , 80 , 60 , magi::colors("orangeToWhite")[4] , magi::Vec2(0.0,0.0) , magi::Vec2(7,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 72350 , 80 , 60 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,0.0) , magi::Vec2(89,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 72710 , 80 , 60 , magi::colors("orangeToWhite")[1] , magi::Vec2(0.0,0.0) , magi::Vec2(89,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 73530 , 80 , 60 , magi::colors("orangeToWhite")[2] , magi::Vec2(0.0,0.0) , magi::Vec2(178,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 73940 , 80 , 60 , magi::colors("orangeToWhite")[3] , magi::Vec2(0.0,0.0) , magi::Vec2(178,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 74780 , 80 , 60 , magi::colors("orangeToWhite")[4] , magi::Vec2(0.0,0.0) , magi::Vec2(84,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 75140 , 80 , 60 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,0.0) , magi::Vec2(84,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 75960 , 80 , 60 , magi::colors("orangeToWhite")[1] , magi::Vec2(0.0,0.0) , magi::Vec2(120,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 76370 , 80 , 60 , magi::colors("orangeToWhite")[2] , magi::Vec2(0.0,0.0) , magi::Vec2(120,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 77210 , 80 , 60 , magi::colors("orangeToWhite")[3] , magi::Vec2(0.0,0.0) , magi::Vec2(240,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 77570 , 80 , 60 , magi::colors("orangeToWhite")[4] , magi::Vec2(0.0,0.0) , magi::Vec2(240,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 78390 , 80 , 60 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,0.0) , magi::Vec2(0,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 78800 , 80 , 60 , magi::colors("orangeToWhite")[1] , magi::Vec2(0.0,0.0) , magi::Vec2(0,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 79640 , 80 , 60 , magi::colors("orangeToWhite")[2] , magi::Vec2(0.0,0.0) , magi::Vec2(99,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 80000 , 80 , 60 , magi::colors("orangeToWhite")[3] , magi::Vec2(0.0,0.0) , magi::Vec2(99,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 80820 , 80 , 60 , magi::colors("orangeToWhite")[4] , magi::Vec2(0.0,0.0) , magi::Vec2(200,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 81230 , 80 , 60 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,0.0) , magi::Vec2(200,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 82070 , 80 , 60 , magi::colors("orangeToWhite")[1] , magi::Vec2(0.0,0.0) , magi::Vec2(80,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 82430 , 80 , 60 , magi::colors("orangeToWhite")[2] , magi::Vec2(0.0,0.0) , magi::Vec2(80,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 83250 , 80 , 60 , magi::colors("orangeToWhite")[3] , magi::Vec2(0.0,0.0) , magi::Vec2(167,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 83660 , 80 , 60 , magi::colors("orangeToWhite")[4] , magi::Vec2(0.0,0.0) , magi::Vec2(167,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 84500 , 80 , 60 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,0.0) , magi::Vec2(237,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 84860 , 80 , 60 , magi::colors("orangeToWhite")[1] , magi::Vec2(0.0,0.0) , magi::Vec2(237,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 85680 , 80 , 60 , magi::colors("orangeToWhite")[2] , magi::Vec2(0.0,0.0) , magi::Vec2(45,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 86090 , 80 , 60 , magi::colors("orangeToWhite")[3] , magi::Vec2(0.0,0.0) , magi::Vec2(45,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 86930 , 80 , 60 , magi::colors("orangeToWhite")[4] , magi::Vec2(0.0,0.0) , magi::Vec2(120,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 87290 , 80 , 60 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,0.0) , magi::Vec2(120,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 88110 , 80 , 60 , magi::colors("orangeToWhite")[1] , magi::Vec2(0.0,0.0) , magi::Vec2(76,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 88520 , 80 , 60 , magi::colors("orangeToWhite")[2] , magi::Vec2(0.0,0.0) , magi::Vec2(76,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 89360 , 80 , 60 , magi::colors("orangeToWhite")[3] , magi::Vec2(0.0,0.0) , magi::Vec2(156,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 89720 , 80 , 60 , magi::colors("orangeToWhite")[4] , magi::Vec2(0.0,0.0) , magi::Vec2(156,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 90540 , 80 , 60 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,0.0) , magi::Vec2(286,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 90950 , 80 , 60 , magi::colors("orangeToWhite")[1] , magi::Vec2(0.0,0.0) , magi::Vec2(286,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 91790 , 80 , 60 , magi::colors("orangeToWhite")[2] , magi::Vec2(0.0,0.0) , magi::Vec2(314,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 92150 , 80 , 60 , magi::colors("orangeToWhite")[3] , magi::Vec2(0.0,0.0) , magi::Vec2(314,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 92970 , 80 , 60 , magi::colors("orangeToWhite")[4] , magi::Vec2(0.0,0.0) , magi::Vec2(37,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 93380 , 80 , 60 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,0.0) , magi::Vec2(37,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 94220 , 80 , 60 , magi::colors("orangeToWhite")[1] , magi::Vec2(0.0,0.0) , magi::Vec2(105,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 94580 , 80 , 60 , magi::colors("orangeToWhite")[2] , magi::Vec2(0.0,0.0) , magi::Vec2(105,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 95400 , 80 , 60 , magi::colors("orangeToWhite")[3] , magi::Vec2(0.0,0.0) , magi::Vec2(53,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 95810 , 80 , 60 , magi::colors("orangeToWhite")[4] , magi::Vec2(0.0,0.0) , magi::Vec2(53,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 96650 , 80 , 60 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,0.0) , magi::Vec2(189,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 97010 , 80 , 60 , magi::colors("orangeToWhite")[1] , magi::Vec2(0.0,0.0) , magi::Vec2(189,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 97830 , 80 , 60 , magi::colors("orangeToWhite")[2] , magi::Vec2(0.0,0.0) , magi::Vec2(239,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 98240 , 80 , 60 , magi::colors("orangeToWhite")[3] , magi::Vec2(0.0,0.0) , magi::Vec2(239,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 99080 , 80 , 60 , magi::colors("orangeToWhite")[4] , magi::Vec2(0.0,0.0) , magi::Vec2(329,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 99440 , 80 , 60 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,0.0) , magi::Vec2(329,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 100260 , 80 , 60 , magi::colors("orangeToWhite")[1] , magi::Vec2(0.0,0.0) , magi::Vec2(67,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 100670 , 80 , 60 , magi::colors("orangeToWhite")[2] , magi::Vec2(0.0,0.0) , magi::Vec2(67,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 101510 , 80 , 60 , magi::colors("orangeToWhite")[3] , magi::Vec2(0.0,0.0) , magi::Vec2(341,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 101870 , 80 , 60 , magi::colors("orangeToWhite")[4] , magi::Vec2(0.0,0.0) , magi::Vec2(341,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 102690 , 80 , 60 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,0.0) , magi::Vec2(268,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 103100 , 80 , 60 , magi::colors("orangeToWhite")[1] , magi::Vec2(0.0,0.0) , magi::Vec2(268,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 103940 , 80 , 60 , magi::colors("orangeToWhite")[2] , magi::Vec2(0.0,0.0) , magi::Vec2(158,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 104300 , 80 , 60 , magi::colors("orangeToWhite")[3] , magi::Vec2(0.0,0.0) , magi::Vec2(158,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 105120 , 80 , 60 , magi::colors("orangeToWhite")[4] , magi::Vec2(0.0,0.0) , magi::Vec2(78,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 105530 , 80 , 60 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,0.0) , magi::Vec2(78,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 106370 , 80 , 60 , magi::colors("orangeToWhite")[1] , magi::Vec2(0.0,0.0) , magi::Vec2(30,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 106730 , 80 , 60 , magi::colors("orangeToWhite")[2] , magi::Vec2(0.0,0.0) , magi::Vec2(30,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 107550 , 80 , 60 , magi::colors("orangeToWhite")[3] , magi::Vec2(0.0,0.0) , magi::Vec2(103,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 107960 , 80 , 60 , magi::colors("orangeToWhite")[4] , magi::Vec2(0.0,0.0) , magi::Vec2(103,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 108800 , 80 , 60 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,0.0) , magi::Vec2(34,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 109160 , 80 , 60 , magi::colors("orangeToWhite")[1] , magi::Vec2(0.0,0.0) , magi::Vec2(34,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 109980 , 80 , 60 , magi::colors("orangeToWhite")[2] , magi::Vec2(0.0,0.0) , magi::Vec2(342,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 110390 , 80 , 60 , magi::colors("orangeToWhite")[3] , magi::Vec2(0.0,0.0) , magi::Vec2(342,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 111230 , 80 , 60 , magi::colors("orangeToWhite")[4] , magi::Vec2(0.0,0.0) , magi::Vec2(25,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 111590 , 80 , 60 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,0.0) , magi::Vec2(25,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 112410 , 80 , 60 , magi::colors("orangeToWhite")[1] , magi::Vec2(0.0,0.0) , magi::Vec2(102,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 112820 , 80 , 60 , magi::colors("orangeToWhite")[2] , magi::Vec2(0.0,0.0) , magi::Vec2(102,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 113660 , 80 , 60 , magi::colors("orangeToWhite")[3] , magi::Vec2(0.0,0.0) , magi::Vec2(193,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 114020 , 80 , 60 , magi::colors("orangeToWhite")[4] , magi::Vec2(0.0,0.0) , magi::Vec2(193,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 114840 , 80 , 60 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,0.0) , magi::Vec2(260,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 115250 , 80 , 60 , magi::colors("orangeToWhite")[1] , magi::Vec2(0.0,0.0) , magi::Vec2(260,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 116090 , 80 , 60 , magi::colors("orangeToWhite")[2] , magi::Vec2(0.0,0.0) , magi::Vec2(301,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 116450 , 80 , 60 , magi::colors("orangeToWhite")[3] , magi::Vec2(0.0,0.0) , magi::Vec2(301,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 117270 , 80 , 60 , magi::colors("orangeToWhite")[4] , magi::Vec2(0.0,0.0) , magi::Vec2(28,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 117680 , 80 , 60 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,0.0) , magi::Vec2(28,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 118520 , 80 , 60 , magi::colors("orangeToWhite")[1] , magi::Vec2(0.0,0.0) , magi::Vec2(1,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 118880 , 80 , 60 , magi::colors("orangeToWhite")[2] , magi::Vec2(0.0,0.0) , magi::Vec2(1,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 119700 , 80 , 60 , magi::colors("orangeToWhite")[3] , magi::Vec2(0.0,0.0) , magi::Vec2(98,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 120110 , 80 , 60 , magi::colors("orangeToWhite")[4] , magi::Vec2(0.0,0.0) , magi::Vec2(98,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 120950 , 80 , 60 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,0.0) , magi::Vec2(188,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 121310 , 80 , 60 , magi::colors("orangeToWhite")[1] , magi::Vec2(0.0,0.0) , magi::Vec2(188,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 122130 , 80 , 60 , magi::colors("orangeToWhite")[2] , magi::Vec2(0.0,0.0) , magi::Vec2(206,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 122540 , 80 , 60 , magi::colors("orangeToWhite")[3] , magi::Vec2(0.0,0.0) , magi::Vec2(206,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 123380 , 80 , 60 , magi::colors("orangeToWhite")[4] , magi::Vec2(0.0,0.0) , magi::Vec2(110,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 123740 , 80 , 60 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,0.0) , magi::Vec2(110,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 124560 , 80 , 60 , magi::colors("orangeToWhite")[1] , magi::Vec2(0.0,0.0) , magi::Vec2(24,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 124970 , 80 , 60 , magi::colors("orangeToWhite")[2] , magi::Vec2(0.0,0.0) , magi::Vec2(24,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 125810 , 80 , 60 , magi::colors("orangeToWhite")[3] , magi::Vec2(0.0,0.0) , magi::Vec2(303,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 126170 , 80 , 60 , magi::colors("orangeToWhite")[4] , magi::Vec2(0.0,0.0) , magi::Vec2(303,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 126990 , 80 , 60 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,0.0) , magi::Vec2(224,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 127400 , 80 , 60 , magi::colors("orangeToWhite")[1] , magi::Vec2(0.0,0.0) , magi::Vec2(224,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 128240 , 80 , 60 , magi::colors("orangeToWhite")[2] , magi::Vec2(0.0,0.0) , magi::Vec2(157,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 128600 , 80 , 60 , magi::colors("orangeToWhite")[3] , magi::Vec2(0.0,0.0) , magi::Vec2(157,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 129420 , 80 , 60 , magi::colors("orangeToWhite")[4] , magi::Vec2(0.0,0.0) , magi::Vec2(236,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 129830 , 80 , 60 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,0.0) , magi::Vec2(236,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 130670 , 80 , 60 , magi::colors("orangeToWhite")[1] , magi::Vec2(0.0,0.0) , magi::Vec2(166,60) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 131030 , 80 , 60 , magi::colors("orangeToWhite")[2] , magi::Vec2(0.0,0.0) , magi::Vec2(166,60) , SMALL_ , LOW_ , 0.5) ),
        // 后段
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 134623 , 80 , 60 , magi::colors("orangeToWhite")[3] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 137060 , 80 , 60 , magi::colors("orangeToWhite")[4] , magi::Vec2(0.0,0.0) , magi::Vec2(70,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 139519 , 80 , 60 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,0.0) , magi::Vec2(144,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 141529 , 80 , 60 , magi::colors("orangeToWhite")[1] , magi::Vec2(0.0,0.0) , magi::Vec2(70,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 141939 , 80 , 60 , magi::colors("orangeToWhite")[2] , magi::Vec2(0.0,0.0) , magi::Vec2(40,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 143959 , 80 , 60 , magi::colors("orangeToWhite")[3] , magi::Vec2(0.0,0.0) , magi::Vec2(160,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 144369 , 80 , 60 , magi::colors("orangeToWhite")[4] , magi::Vec2(0.0,0.0) , magi::Vec2(189,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 146389 , 80 , 60 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,0.0) , magi::Vec2(310,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 146799 , 80 , 60 , magi::colors("orangeToWhite")[1] , magi::Vec2(0.0,0.0) , magi::Vec2(330,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 148819 , 80 , 60 , magi::colors("orangeToWhite")[2] , magi::Vec2(0.0,0.0) , magi::Vec2(100,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 149229 , 80 , 60 , magi::colors("orangeToWhite")[3] , magi::Vec2(0.0,0.0) , magi::Vec2(80,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 151249 , 80 , 60 , magi::colors("orangeToWhite")[4] , magi::Vec2(0.0,0.0) , magi::Vec2(66,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 151659 , 80 , 60 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,0.0) , magi::Vec2(80,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 153679 , 80 , 60 , magi::colors("orangeToWhite")[1] , magi::Vec2(0.0,0.0) , magi::Vec2(286,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 154089 , 80 , 60 , magi::colors("orangeToWhite")[2] , magi::Vec2(0.0,0.0) , magi::Vec2(266,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 156109 , 80 , 60 , magi::colors("orangeToWhite")[3] , magi::Vec2(0.0,0.0) , magi::Vec2(320,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 156519 , 80 , 60 , magi::colors("orangeToWhite")[4] , magi::Vec2(0.0,0.0) , magi::Vec2(340,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 158539 , 80 , 60 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,0.0) , magi::Vec2(140,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 158949 , 80 , 60 , magi::colors("orangeToWhite")[1] , magi::Vec2(0.0,0.0) , magi::Vec2(160,40) , SMALL_ , LOW_ , 0.5) ),
    
    },
    // 关卡4
    {                                                                    // 起始时间，结束时间，生成时间间隔
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Circle ( Stage_Four , 1000 , 15860 , 5 , magi::Vec2(0.0,0.0) , magi::Vec2(0.0,magi::PI2) , MIDDLE_ , LOW_ , Arc_SpeedUp ) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Circle ( Stage_Four , 19400 , 36150 , 5 , magi::Vec2(0.0,0.0) , magi::Vec2(0.0,magi::PI2) , MIDDLE_ , LOW_ , Arc_SpeedUp ) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Circle ( Stage_Four , 37230 , 51140 , 5 , magi::Vec2(0.0,0.0) , magi::Vec2(0.0,magi::PI2) , MIDDLE_ , LOW_ , Arc_SpeedUp ) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Circle ( Stage_Four , 55030 , 87300 , 5 , magi::Vec2(0.0,0.0) , magi::Vec2(0.0,magi::PI2) , MIDDLE_ , LOW_ , Arc_SpeedUp ) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Circle ( Stage_Four , 90815 , 100000 , 5 , magi::Vec2(0.0,0.0) , magi::Vec2(0.0,magi::PI2) , MIDDLE_ , LOW_ , Arc_SpeedUp ) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Circle ( Stage_Four , 100300 , 100500 , 5 , magi::Vec2(0.0,0.0) , magi::Vec2(0.0,magi::PI2) , MIDDLE_ , LOW_ , Arc_SpeedUp ) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Circle ( Stage_Four , 100850 , 101000 , 5 , magi::Vec2(0.0,0.0) , magi::Vec2(0.0,magi::PI2) , MIDDLE_ , LOW_ , Arc_SpeedUp ) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Circle ( Stage_Four , 101430 , 101600 , 5 , magi::Vec2(0.0,0.0) , magi::Vec2(0.0,magi::PI2) , MIDDLE_ , LOW_ , Arc_SpeedUp ) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Circle ( Stage_Four , 101960 , 102000 , 5 , magi::Vec2(0.0,0.0) , magi::Vec2(0.0,magi::PI2) , MIDDLE_ , LOW_ , Arc_SpeedUp ) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Circle ( Stage_Four , 102520 , 102650 , 5 , magi::Vec2(0.0,0.0) , magi::Vec2(0.0,magi::PI2) , MIDDLE_ , LOW_ , Arc_SpeedUp ) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Circle ( Stage_Four , 103070 , 103200 , 5 , magi::Vec2(0.0,0.0) , magi::Vec2(0.0,magi::PI2) , MIDDLE_ , LOW_ , Arc_SpeedUp ) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Circle ( Stage_Four , 103630 , 103730 , 5 , magi::Vec2(0.0,0.0) , magi::Vec2(0.0,magi::PI2) , MIDDLE_ , LOW_ , Arc_SpeedUp ) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Circle ( Stage_Four , 104185 , 104295 , 5 , magi::Vec2(0.0,0.0) , magi::Vec2(0.0,magi::PI2) , MIDDLE_ , LOW_ , Arc_SpeedUp ) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Circle ( Stage_Four , 104740 , 104850 , 5 , magi::Vec2(0.0,0.0) , magi::Vec2(0.0,magi::PI2) , MIDDLE_ , LOW_ , Arc_SpeedUp ) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Circle ( Stage_Four , 108320 , 125030 , 5 , magi::Vec2(0.0,0.0) , magi::Vec2(0.0,magi::PI2) , MIDDLE_ , LOW_ , Arc_SpeedUp ) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Circle ( Stage_Four , 126020 , 140030 , 5 , magi::Vec2(0.0,0.0) , magi::Vec2(0.0,magi::PI2) , MIDDLE_ , LOW_ , Arc_SpeedUp ) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Circle ( Stage_Four , 143930 , 176115 , 5 , magi::Vec2(0.0,0.0) , magi::Vec2(0.0,magi::PI2) , MIDDLE_ , LOW_ , Arc_SpeedUp ) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Circle ( Stage_Four , 179480 , 211680 , 5 , magi::Vec2(0.0,0.0) , magi::Vec2(0.0,magi::PI2) , MIDDLE_ , LOW_ , Arc_SpeedUp ) ),
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
        Re.Before = i ;
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
    magi::Stage{"缩圈",getBullet_Re{3},ch,"青花瓷.mp3", 229333, "", magiUI::ChinaEffects},
    magi::Stage{"烟花",getBullet_Re{4},ch,"敬具.mp3",EndTime, ""}
};


