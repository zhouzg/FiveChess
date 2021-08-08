#pragma once
#include<iostream>
#include<string>
#include"Chess.h"
#include"Player.h"
using namespace std;

class Human:public Player
{
public:
	Human(string name, int color = 0) :Player(name, color) {}
	Human();
	~Human();
	Chess GiveChess() {
		Chess c;
		string input_msg="";
		while (input_msg.size() != 2) {

		}
		cin >> input_msg;
		if (input_msg.size() == 2) {//是否落子合法
			int row = input_msg[0] - 'a';
			int col = input_msg[1] - 'a';
		
		return c;
	}
	//Chess GiveChess(Position p) {
	//	return Chess(getColor(), p);
	//}
	bool TakeBack() {  //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		return true;
	}



};

