#pragma once
#include<iostream>
#include<string>
#include"Chess.h"
using namespace std;
class Player
{
public:
	Player();
	Player(string name,int color=0);
	~Player();
	//virtual Chess GiveChess(Position p = { -1,-1 }) = 0;
	virtual Chess GiveChess() = 0;
	//bool TakeBack();  //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	string getName() {
		return name;
	}
	int getColor() {
		return color;
	}
	void setName(string name) {
		this->name = name;
	}
	void setColor(int color) {
		this->color = color;
	}
private:
	string name;
	int color;

};

