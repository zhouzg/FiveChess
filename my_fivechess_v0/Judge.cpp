#include "Judge.h"



Judge::Judge()
{
}


Judge::~Judge()
{
}

bool Judge::CheckChessLegal( Chess chess, ChessBoard &board) {
	Position p = chess.getPosition();
	if (p.row <= board.getROWNUM()-1 && p.row >= 0 && p.col <= board.getCOLUMN()-1 && p.col >= 0) {
		if (board.getBoardState()[p.row][p.col] == 0) {
			return true;
		}
		else return false;
	}
	else {
		return false;
	}
}
bool Judge::CheckWin(ChessBoard &board) {
	if (board.BoardEmpty()) return false; //¿ÕÆåÅÌ

	Chess last_chess = board.getLastChess();
	Position p = last_chess.getPosition();
	int count;
	Position ptr;
	int board_col = board.getCOLUMN();
	int board_row = board.getROWNUM();
	/*******************      ºá       ***************************/
   	count = 0;
	ptr = p;
	ptr.col++;
	while (ptr.col <= board_col-1 && count <= 4 && last_chess.getColor() == board.getChessState(ptr)) {
		count++;
		ptr.col++;
	}	
	ptr = p;
	ptr.col--;
	while (ptr.col >= 0 && count <= 4 && last_chess.getColor() == board.getChessState(ptr)) {
		count++;
		ptr.col--;
	}
	if (count + 1 >= 5)return true;
	/*******************      ×Ý       ***************************/
	count = 0;
	ptr = p;
	ptr.row++;
	while (ptr.row <= board_row-1 && count <= 4 && last_chess.getColor() == board.getChessState(ptr)) {
		count++;
		ptr.col++;
	}
	ptr = p;
	ptr.row--;
	while (ptr.row >= 0 && count <= 4 && last_chess.getColor() == board.getChessState(ptr)) {
		count++;
		ptr.row--;
	}
	if (count + 1 >= 5)return true;
	/*******************      ×óÐ±       ***************************/
	count = 0;
	ptr = p;
	ptr.col++;
	ptr.row++;
	while (ptr.col <= board_col - 1 && ptr.row <= board_row - 1 && count <= 4 && last_chess.getColor() == board.getChessState(ptr)) {
		count++;
		ptr.col++;
		ptr.row++;
	}
	ptr = p;	
	ptr.col--;
	ptr.row--;
	while (ptr.col >= 0 && ptr.row >= 0 && count <= 4 && last_chess.getColor() == board.getChessState(ptr)) {
		count++;
		ptr.col--;
		ptr.row--;
	}
	if (count + 1 >= 5)return true;
	/*******************      ÓÒÐ±       ***************************/
	count = 0;
	ptr = p;
	ptr.col--;
	ptr.row++;
	while (ptr.row <= board_row - 1 && ptr.col >=0 && ptr.row <= board_row - 1 && count <= 4 && last_chess.getColor() == board.getChessState(ptr)) {
		count++;
		ptr.col--;
		ptr.row++;
	}
	ptr = p;
	ptr.col++;
	ptr.row--;
	while (ptr.col <= board_col - 1 && ptr.row >= 0 && count <= 4 && last_chess.getColor() == board.getChessState(ptr)) {
		count++;
		ptr.col++;
		ptr.row--;
	}
	if (count + 1 >= 5)return true;

	return false;
}
void Judge::TakeBack(ChessBoard &board) {
	int n = 0;
	if (board.getChessNum() >= 2) {
		n = 2;
	}
	else {
		n = 0;
	}
	board.takebackChess(n);
}
