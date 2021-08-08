#include<iostream>
#include<string>
#include"Chess.h"
#include"ChessBoard.h"
using namespace std;
ChessBoard::ChessBoard(void) {
	Board_Init();
}
void ChessBoard::Board_Init() {
	while (!history.empty()) history.pop();
	last_chess = *new Chess;
	board_state.resize(ROWNUM);//r行
	for (int k = 0; k < ROWNUM; ++k) {
		board_state[k].resize(COLUMN);//每行为c列
	}
	for (int i = 0; i < ROWNUM; i++)
		for (int j = 0; j < COLUMN; j++)
			board_state[i][j] = 0;
}
vector<vector<int> > ChessBoard::getBoardState() {
	return board_state;
}
vector<vector<int> > ChessBoard::getBoardState() const {
	return board_state;
}
void ChessBoard::addChess(Chess chess) {
	Position p;
	if (!history.empty()) { // Is it the fisrt chess?
		p = last_chess.getPosition();
		board_state[p.row][p.col] = last_chess.getColor();
	}

	p = chess.getPosition();
	board_state[p.row][p.col] = chess.getColor()+2;
	last_chess = chess;
	history.push(chess);
}
void ChessBoard::takebackChess(int num) {
	Position p;
	int num_chess = history.size();
	for (int n = 0; n < num && n< num_chess; n++) {
		Chess chess = history.top();
		p = chess.getPosition();
		board_state[p.row][p.col] = 0;

		history.pop();

		if (!history.empty()) { // Is it the fisrt chess?
			last_chess = history.top();
			p = last_chess.getPosition();
			board_state[p.row][p.col] = last_chess.getColor() + 2;
		}

	}

}
Chess ChessBoard::getLastChess() {
	return history.top();
}

string ChessBoard::getChessSymbol(int color) {
	return chess_symbol[color];
}
string ChessBoard::getBoardSymbol(Position p) {
	if (board_state[p.row][p.col] == 0) {
		return board_symbol[p.row].substr(p.col * 3, 3);
	}
	else {
		return chess_symbol[board_state[p.row][p.col]];
	}
}