#pragma once
#include"Chess.h"
#include"ChessBoard.h"
class Judge
{
public:
	Judge();
	~Judge();
	bool CheckChessLegal( Chess chess, ChessBoard &board);
	//bool CheckWin(const ChessBoard &board);
	bool CheckWin(ChessBoard &board);
	void TakeBack(ChessBoard &board);
};

