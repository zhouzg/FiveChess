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
	Player *player1, *player2;//��ҽ϶�ʱ��������ָ������ָ�������ң���������ֻ�
	Player *current_player; //��ǰҪ��������
	Player *first_player;   //����
	Judge judge;
	ChessBoard board;
	Displayer displayer;
	int mode; //����ģʽ 


};

