#pragma once
#include "ChessBoard.h"
class Displayer
{
public:
	Displayer();
	~Displayer();
	void showBoard(ChessBoard board);
	void showMessage(string msg);
};

