#pragma once
#include<iostream>
#include<string>
#include"Chess.h"
#include"ChessBoard.h"
#include"Displayer.h"
#include"Player.h"
#include"Judge.h"
#include"Human.h"
#include"AI.h"
class Game
{
public:
	Game();
	~Game();
	void ChooseMode();
	void InitPlayer();
	void ChooseOrder();
	void InitGame();
	void StartGame();
private:
	//void playchess(Player &player1, Player &player2, Judge &judge, ChessBoard &board, Displayer &displayer);
	Human human1, human2;
	AI ai;
	Player *player1, *player2;//玩家较多时，可以用指针数组指向参与玩家，方便玩家轮换
	Player *current_player; //当前要落子棋手
	Player *first_player;   //先手
	Judge judge;
	ChessBoard board;
	Displayer displayer;
	int mode; //对弈模式 


};

