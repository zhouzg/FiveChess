#pragma once
#include<stdlib.h>
#include<iostream>
#include <random>
#include <ctime>
#include<string>
#include"Chess.h"
#include"Player.h"


using namespace std;
class AI:public Player
{
public:
	//AI();
	~AI() {}
	AI(string name = "AI", int color = 0):Player(name, color) {
		//e.seed(time(NULL)- current_time);
		uniform_int_distribution<unsigned> uu(0, 15);
		u = uu;
	}

	//Chess GiveChess(Position pp ) {
	Chess GiveChess() {
		Position p;
		static default_random_engine e(time(0));
		//e.seed(time(0));
		p.col = u(e);
		p.row = u(e);
		return Chess(getColor(), p);
	}
private:
	//default_random_engine e;// 创建引擎时给种子
	uniform_int_distribution<unsigned> u;// 定义一个范围为0~15的无符号整型分布类型
};


