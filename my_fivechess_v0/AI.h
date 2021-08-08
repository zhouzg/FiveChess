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
	//default_random_engine e;// ��������ʱ������
	uniform_int_distribution<unsigned> u;// ����һ����ΧΪ0~15���޷������ͷֲ�����
};


