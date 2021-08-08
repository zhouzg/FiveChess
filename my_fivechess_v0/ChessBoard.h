#pragma once
#include"Chess.h"
#include<string>
#include<vector>
#include<stack>
using namespace std;
class ChessBoard {
public:
	ChessBoard();
	void Board_Init();//初始化
	vector<vector<int> > getBoardState();
	vector<vector<int> > getBoardState() const;
	void addChess(Chess chess);
	void takebackChess(int num);//悔棋num个
	Chess getLastChess();
	string getChessSymbol(int color);
	string getBoardSymbol(Position p);

	int getChessNum() {
		return history.size();
	}
	bool BoardEmpty() {
		return history.empty();
	}
	int getChessState(Position p) {
		int c = board_state[p.row][p.col];
		if (c > 2)
			return c - 2;
		else
			return c;
	}
	int getROWNUM() {
		return ROWNUM;
	}
	int getCOLUMN() {
		return COLUMN;
	}

private:
	static const int ROWNUM = 16;//棋盘行数
	static const int COLUMN = 16;//棋盘列数
	vector<vector<int> > board_state;
	Chess last_chess;
	stack<Chess> history;
	const string chess_symbol[5] = { " ","●","○","▲","△" }; //◆◇
	const vector<string> board_symbol = //一个符号占两个字节
	                   { "┏ ┳ ┳ ┳ ┳ ┳ ┳ ┳ ┳ ┳ ┳ ┳ ┳ ┳ ┳ ┓ ",
						 "┣ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ┫ ",
		   			 	 "┣ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ┫ ",
						 "┣ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ┫ ",
						 "┣ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ┫ ",
						 "┣ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ┫ ",
						 "┣ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ┫ ",
						 "┣ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ┫ ",
						 "┣ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ┫ ",
						 "┣ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ┫ ",
						 "┣ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ┫ ",
						 "┣ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ┫ ",
						 "┣ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ┫ ",
						 "┣ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ┫ ",
						 "┣ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ┫ ",
						 "┗ ┻ ┻ ┻ ┻ ┻ ┻ ┻ ┻ ┻ ┻ ┻ ┻ ┻ ┻ ┛ " };
};