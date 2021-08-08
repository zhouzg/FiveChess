#include "Displayer.h"
#include "ChessBoard.h"
#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;


Displayer::Displayer()
{
}


Displayer::~Displayer()
{
}

void Displayer::showBoard(ChessBoard board) {
	vector<vector<int> > state = board.getBoardState();
	cout << "  a b c d e f g h i j k l n m o p" << endl;//横轴标识
	for (int i = 0; i < state.size(); i++) {
		cout << char('a' + i);//纵轴标识
		for (int j = 0; j < state[0].size(); j++) {
			cout << board.getBoardSymbol({ i,j });
		}
		cout << endl;
	}
}
void Displayer::showMessage(string msg) {
	cout << msg << endl;
}
