#include "statement.h"

using namespace std;

magi::Character ch;             // test 用 （删）


long Size = 0;
long long ID = 0;



// 开始时间(long long) ,弹幕数量 (int) ,颜色 (magi::Color) , 半径(double) ,速度 (double), 运动类型 (Kind)

vector<vector<Bullets_Info>> info_stage {
    // 关卡1
    {
        Bullets_Info (1000,10,c1,SMALL_,LOW_,Line),
        Bullets_Info (3000,10,c2,MIDDLE_,LOW_,Line),
        Bullets_Info (5000,10,c2,LARGE_,LOW_,Line),

    },
    // 关卡2
    {
        Bullets_Info (1000,10,magi::Color(0,0,0),SMALL_,LOW_,Line),
    }
};

struct bullets_effect : public magi::Bullets {
    int Num , Size ;
    long Before ;
    size_t size() const {
        return Size ;
    }
    magi::Point operator[](size_t index) {
        long push = 0;
        while ( index > info_stage[Num][Before+push].n - 1 ){ index = index - info_stage[Num][Before+push].n; push++;}
        (info_stage[Num][Before+push].bullets[index]) -> Pos();
        return (info_stage[Num][Before+push].bullets[index]) -> point ;

    }
};

struct getBullet_Re {
    int Num;
    auto operator()() -> shared_ptr<bullets_effect> {
        bullets_effect Re ;
        Re.Num = Num;
        Re.Size = 0;
        long long RelT = magi::Timer::get();
        int i = 0;
        while ( info_stage[Num][i].EndT < RelT ) { i++ ; }
        Re.Before = i;
        while ( info_stage[Num][i].StartT < RelT ) {
            Re.Size += info_stage[Num][i].n;
            i++;
        }
        return make_shared<bullets_effect> (Re);
    }
};

/* function<shared_ptr<Bullet_Result>()> getBullet_(int k) {
    return [=] () -> shared_ptr<Bullet_Result> {
        Size = 0;
        long long RelT = magi::Timer::get();
        int i = 0;
        // for ( i = 0 ; info_stage1[i].EndT > RelT ; i++ ) {}
        while ( info_stage1[i].EndT < RelT ) { i++; }
        while ( info_stage1[i].StartT < RelT ) {
            i++;
        }
        return ;
    };
} */

vector<magi::Stage> magi::Stage::stage {
    magi::Stage{"Stage1", getBullet_Re{0}, ch, ""},
    magi::Stage{"Stage2", getBullet_Re{1}, ch, ""}
    
};
