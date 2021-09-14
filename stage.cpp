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
        // make_shared<Bullets_Info> ( Bullets_Info ( Stage_Three , 1000 , 60 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,0.0) , magi::Vec2(0.0,6.0) , SMALL_ , 0.5 , ReverseLine ) ),
        // 前半
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 3248 , 60 , 60 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,0.0) , magi::Vec2(210,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 5683 , 60 , 60 , magi::colors("orangeToWhite")[1] , magi::Vec2(0.0,0.0) , magi::Vec2(20,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 8118 , 60 , 60 , magi::colors("orangeToWhite")[2] , magi::Vec2(0.0,0.0) , magi::Vec2(90,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 10553 , 60 , 60 , magi::colors("orangeToWhite")[3] , magi::Vec2(0.0,0.0) , magi::Vec2(220,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 12988 , 60 , 60 , magi::colors("orangeToWhite")[4] , magi::Vec2(0.0,0.0) , magi::Vec2(60,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 15423 , 60 , 60 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,0.0) , magi::Vec2(170,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 17858 , 60 , 60 , magi::colors("orangeToWhite")[1] , magi::Vec2(0.0,0.0) , magi::Vec2(140,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 20293 , 60 , 60 , magi::colors("orangeToWhite")[2] , magi::Vec2(0.0,0.0) , magi::Vec2(100,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 22728 , 60 , 60 , magi::colors("orangeToWhite")[3] , magi::Vec2(0.0,0.0) , magi::Vec2(260,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 25163 , 60 , 60 , magi::colors("orangeToWhite")[4] , magi::Vec2(0.0,0.0) , magi::Vec2(220,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 27598 , 60 , 60 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,0.0) , magi::Vec2(290,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 30033 , 60 , 60 , magi::colors("orangeToWhite")[1] , magi::Vec2(0.0,0.0) , magi::Vec2(50,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 32468 , 60 , 60 , magi::colors("orangeToWhite")[2] , magi::Vec2(0.0,0.0) , magi::Vec2(170,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 34903 , 60 , 60 , magi::colors("orangeToWhite")[3] , magi::Vec2(0.0,0.0) , magi::Vec2(200,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 37338 , 60 , 60 , magi::colors("orangeToWhite")[4] , magi::Vec2(0.0,0.0) , magi::Vec2(310,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 39773 , 60 , 60 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,0.0) , magi::Vec2(270,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 42208 , 60 , 60 , magi::colors("orangeToWhite")[1] , magi::Vec2(0.0,0.0) , magi::Vec2(70,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 44643 , 60 , 60 , magi::colors("orangeToWhite")[2] , magi::Vec2(0.0,0.0) , magi::Vec2(150,40) , SMALL_ , LOW_ , 0.5) ),
        // 后半
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 49494 , 60 , 60 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,0.0) , magi::Vec2(270,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 50735 , 60 , 60 , magi::colors("orangeToWhite")[1] , magi::Vec2(0.0,0.0) , magi::Vec2(230,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 51660 , 60 , 60 , magi::colors("orangeToWhite")[2] , magi::Vec2(0.0,0.0) , magi::Vec2(310,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 52070 , 60 , 60 , magi::colors("orangeToWhite")[3] , magi::Vec2(0.0,0.0) , magi::Vec2(310,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 53270 , 60 , 60 , magi::colors("orangeToWhite")[4] , magi::Vec2(0.0,0.0) , magi::Vec2(270,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 54090 , 60 , 60 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,0.0) , magi::Vec2(200,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 54500 , 60 , 60 , magi::colors("orangeToWhite")[1] , magi::Vec2(0.0,0.0) , magi::Vec2(200,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 55340 , 60 , 60 , magi::colors("orangeToWhite")[2] , magi::Vec2(0.0,0.0) , magi::Vec2(150,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 55700 , 60 , 60 , magi::colors("orangeToWhite")[3] , magi::Vec2(0.0,0.0) , magi::Vec2(150,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 56520 , 60 , 60 , magi::colors("orangeToWhite")[4] , magi::Vec2(0.0,0.0) , magi::Vec2(100,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 56930 , 60 , 60 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,0.0) , magi::Vec2(100,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 57770 , 60 , 60 , magi::colors("orangeToWhite")[1] , magi::Vec2(0.0,0.0) , magi::Vec2(320,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 58130 , 60 , 60 , magi::colors("orangeToWhite")[2] , magi::Vec2(0.0,0.0) , magi::Vec2(320,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 58950 , 60 , 60 , magi::colors("orangeToWhite")[3] , magi::Vec2(0.0,0.0) , magi::Vec2(90,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 59360 , 60 , 60 , magi::colors("orangeToWhite")[4] , magi::Vec2(0.0,0.0) , magi::Vec2(90,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 60200 , 60 , 60 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 60560 , 60 , 60 , magi::colors("orangeToWhite")[1] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 61380 , 60 , 60 , magi::colors("orangeToWhite")[2] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 61790 , 60 , 60 , magi::colors("orangeToWhite")[3] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 62630 , 60 , 60 , magi::colors("orangeToWhite")[4] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 62990 , 60 , 60 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 63810 , 60 , 60 , magi::colors("orangeToWhite")[1] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 64220 , 60 , 60 , magi::colors("orangeToWhite")[2] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 65060 , 60 , 60 , magi::colors("orangeToWhite")[3] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 65420 , 60 , 60 , magi::colors("orangeToWhite")[4] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 66240 , 60 , 60 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 66650 , 60 , 60 , magi::colors("orangeToWhite")[1] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 67490 , 60 , 60 , magi::colors("orangeToWhite")[2] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 67850 , 60 , 60 , magi::colors("orangeToWhite")[3] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 68670 , 60 , 60 , magi::colors("orangeToWhite")[4] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 69080 , 60 , 60 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 69920 , 60 , 60 , magi::colors("orangeToWhite")[1] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 70280 , 60 , 60 , magi::colors("orangeToWhite")[2] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 71100 , 60 , 60 , magi::colors("orangeToWhite")[3] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 71510 , 60 , 60 , magi::colors("orangeToWhite")[4] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 72350 , 60 , 60 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 72710 , 60 , 60 , magi::colors("orangeToWhite")[1] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 73530 , 60 , 60 , magi::colors("orangeToWhite")[2] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 73940 , 60 , 60 , magi::colors("orangeToWhite")[3] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 74780 , 60 , 60 , magi::colors("orangeToWhite")[4] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 75140 , 60 , 60 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 75960 , 60 , 60 , magi::colors("orangeToWhite")[1] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 76370 , 60 , 60 , magi::colors("orangeToWhite")[2] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 77210 , 60 , 60 , magi::colors("orangeToWhite")[3] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 77570 , 60 , 60 , magi::colors("orangeToWhite")[4] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 78390 , 60 , 60 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 78800 , 60 , 60 , magi::colors("orangeToWhite")[1] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 79640 , 60 , 60 , magi::colors("orangeToWhite")[2] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 80000 , 60 , 60 , magi::colors("orangeToWhite")[3] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 80820 , 60 , 60 , magi::colors("orangeToWhite")[4] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 81230 , 60 , 60 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 82070 , 60 , 60 , magi::colors("orangeToWhite")[1] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 82430 , 60 , 60 , magi::colors("orangeToWhite")[2] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 83250 , 60 , 60 , magi::colors("orangeToWhite")[3] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 83660 , 60 , 60 , magi::colors("orangeToWhite")[4] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 84500 , 60 , 60 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 84860 , 60 , 60 , magi::colors("orangeToWhite")[1] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 85680 , 60 , 60 , magi::colors("orangeToWhite")[2] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 86090 , 60 , 60 , magi::colors("orangeToWhite")[3] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 86930 , 60 , 60 , magi::colors("orangeToWhite")[4] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 87290 , 60 , 60 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 88110 , 60 , 60 , magi::colors("orangeToWhite")[1] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 88520 , 60 , 60 , magi::colors("orangeToWhite")[2] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 89360 , 60 , 60 , magi::colors("orangeToWhite")[3] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 89720 , 60 , 60 , magi::colors("orangeToWhite")[4] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 90540 , 60 , 60 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 90950 , 60 , 60 , magi::colors("orangeToWhite")[1] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 91790 , 60 , 60 , magi::colors("orangeToWhite")[2] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 92150 , 60 , 60 , magi::colors("orangeToWhite")[3] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 92970 , 60 , 60 , magi::colors("orangeToWhite")[4] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 93380 , 60 , 60 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 94220 , 60 , 60 , magi::colors("orangeToWhite")[1] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 94580 , 60 , 60 , magi::colors("orangeToWhite")[2] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 95400 , 60 , 60 , magi::colors("orangeToWhite")[3] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 95810 , 60 , 60 , magi::colors("orangeToWhite")[4] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 96650 , 60 , 60 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 97010 , 60 , 60 , magi::colors("orangeToWhite")[1] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 97830 , 60 , 60 , magi::colors("orangeToWhite")[2] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 98240 , 60 , 60 , magi::colors("orangeToWhite")[3] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 99080 , 60 , 60 , magi::colors("orangeToWhite")[4] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 99440 , 60 , 60 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 100260 , 60 , 60 , magi::colors("orangeToWhite")[1] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 100670 , 60 , 60 , magi::colors("orangeToWhite")[2] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 101510 , 60 , 60 , magi::colors("orangeToWhite")[3] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 101870 , 60 , 60 , magi::colors("orangeToWhite")[4] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 102690 , 60 , 60 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 103100 , 60 , 60 , magi::colors("orangeToWhite")[1] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 103940 , 60 , 60 , magi::colors("orangeToWhite")[2] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 104300 , 60 , 60 , magi::colors("orangeToWhite")[3] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 105120 , 60 , 60 , magi::colors("orangeToWhite")[4] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 105530 , 60 , 60 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 106370 , 60 , 60 , magi::colors("orangeToWhite")[1] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 106730 , 60 , 60 , magi::colors("orangeToWhite")[2] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 107550 , 60 , 60 , magi::colors("orangeToWhite")[3] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 107960 , 60 , 60 , magi::colors("orangeToWhite")[4] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 108800 , 60 , 60 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 109160 , 60 , 60 , magi::colors("orangeToWhite")[1] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 109980 , 60 , 60 , magi::colors("orangeToWhite")[2] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 110390 , 60 , 60 , magi::colors("orangeToWhite")[3] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 111230 , 60 , 60 , magi::colors("orangeToWhite")[4] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 111590 , 60 , 60 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 112410 , 60 , 60 , magi::colors("orangeToWhite")[1] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 112820 , 60 , 60 , magi::colors("orangeToWhite")[2] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 113660 , 60 , 60 , magi::colors("orangeToWhite")[3] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 114020 , 60 , 60 , magi::colors("orangeToWhite")[4] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 114840 , 60 , 60 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 115250 , 60 , 60 , magi::colors("orangeToWhite")[1] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 116090 , 60 , 60 , magi::colors("orangeToWhite")[2] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 116450 , 60 , 60 , magi::colors("orangeToWhite")[3] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 117270 , 60 , 60 , magi::colors("orangeToWhite")[4] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 117680 , 60 , 60 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 118520 , 60 , 60 , magi::colors("orangeToWhite")[1] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 118880 , 60 , 60 , magi::colors("orangeToWhite")[2] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 119700 , 60 , 60 , magi::colors("orangeToWhite")[3] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 120110 , 60 , 60 , magi::colors("orangeToWhite")[4] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 120950 , 60 , 60 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 121310 , 60 , 60 , magi::colors("orangeToWhite")[1] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 122130 , 60 , 60 , magi::colors("orangeToWhite")[2] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 122540 , 60 , 60 , magi::colors("orangeToWhite")[3] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 123380 , 60 , 60 , magi::colors("orangeToWhite")[4] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 123740 , 60 , 60 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 124560 , 60 , 60 , magi::colors("orangeToWhite")[1] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 124970 , 60 , 60 , magi::colors("orangeToWhite")[2] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 125810 , 60 , 60 , magi::colors("orangeToWhite")[3] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 126170 , 60 , 60 , magi::colors("orangeToWhite")[4] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 126990 , 60 , 60 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 127400 , 60 , 60 , magi::colors("orangeToWhite")[1] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 128240 , 60 , 60 , magi::colors("orangeToWhite")[2] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 128600 , 60 , 60 , magi::colors("orangeToWhite")[3] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 129420 , 60 , 60 , magi::colors("orangeToWhite")[4] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 129830 , 60 , 60 , magi::colors("orangeToWhite")[0] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 130670 , 60 , 60 , magi::colors("orangeToWhite")[1] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
        make_shared<Bullets_Info> ( Creat_BulletsInfo_Maze ( Stage_Three , 131030 , 60 , 60 , magi::colors("orangeToWhite")[2] , magi::Vec2(0.0,0.0) , magi::Vec2(0,40) , SMALL_ , LOW_ , 0.5) ),
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
    magi::Stage{"缩圈",getBullet_Re{3},ch,"青花瓷.mp3", 229333, ""},
    magi::Stage{"烟花",getBullet_Re{4},ch,"敬具.mp3",EndTime, ""}
};


