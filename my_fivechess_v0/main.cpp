#include<iostream>
#include<string>
#include"Chess.h"
#include"ChessBoard.h"
#include"Displayer.h"
#include"Player.h"
#include"Judge.h"
#include"Game.h"
#include"AI.h"
#define BLACK 1
#define WHITE 2
using namespace std;

int main() {
	Game game;
	//cout << typeid(game).name() << endl;
	game.InitGame();
	game.StartGame();
}

//int main() {
//	AI ai;
//	Player *player = &ai;
//	cout << typeid(ai).name() << endl;
//	cout << typeid(typeid(ai).name()).name() << endl;
//	cout << typeid(AI).name() << endl;
//	cout << (typeid(*player).name() == typeid(AI).name()) << endl;
//	
//	Position p;
//	for (int i = 0; i < 10; i++) {
//		p = ai.GiveChess().getPosition();
//		cout << p.row << " " << p.col << endl;
//	}
//	AI ai2;
//	cout << "-----------------" << endl;
//	for (int i = 0; i < 10; i++) {
//		p = ai2.GiveChess().getPosition();
//		cout << p.row << " " << p.col << endl;
//	}
//	int i = 0;
//	do {
//		p = ai2.GiveChess().getPosition();
//		i++;
//	} while(! (p.col ==4&&p.row==4));
//	cout << "-----------------" << endl;
//	cout << i << endl;
//
//
//}


//int main() {
//	Player player1("大好");
//	Player player2("大波");
//	player1.setColor(BLACK);
//	player2.setColor(WHITE);
//
//	Player* current_player;
//	Player* takeback_player;
//	Judge judge;
//	Displayer displayer;
//	ChessBoard board;
//	Chess chess;
//
//	current_player = &player1;
//	bool TakeBack = false;
//	string input_msg;
//	bool win = false;
//	bool restart = false;
//	displayer.showBoard(board);
//	while (1)
//	{
//		if (restart) {
//			system("cls");
//			current_player = &player1;
//			TakeBack = false;
//			input_msg = "";
//			win = false;
//			restart = false;
//			board.Board_Init();
//			displayer.showBoard(board);
//		}
//		//对手是否悔棋
//		if (TakeBack) {
//			displayer.showMessage("your friend wants to take back a move. Do you agree? y/n :");
//				cin >> input_msg;
//			if (input_msg == "y") {
//				judge.TakeBack(board);//include: board.takeback(), last_chess, stack.pop()
//				TakeBack = false;
//				takeback_player = NULL;
//				system("cls");
//				displayer.showBoard(board);
//				//if (current_player->getName() == player1.getName())
//				//	current_player = &player2;
//				//else
//				//	current_player = &player1;
//				continue;
//			}
//		}
//		//当前玩家落子
//		displayer.showMessage(current_player->getName() + "'s turn");
//		displayer.showMessage("input \" take \" if you want to take back a move");
//		displayer.showMessage("input your chess:");
//
//		bool chess_legal = false;
//		while (!chess_legal) {
//			cin >> input_msg;
//			if (input_msg == "take") {//是否悔棋
//				chess_legal = true;
//				TakeBack = true;
//				takeback_player = current_player;
//				break;
//			}
//			else if (input_msg.size() == 2) {//是否落子合法
//				int row = input_msg[0] - 'a';
//				int col = input_msg[1] - 'a';
//				chess = current_player->GiveChess({ row,col });
//				chess_legal = judge.CheckChessLegal(chess, board);
//			}
//			if (chess_legal) {
//				//刷新棋盘
//				board.addChess(chess);// include: last_chess, stack.push_back(chess);
//				system("cls");
//				displayer.showBoard(board);
//
//				break;
//			}
//			else {
//				system("cls");
//				displayer.showBoard(board);
//				displayer.showMessage(current_player->getName() + "'s turn");
//				displayer.showMessage("please input again:");
//			}
//		}
//		if(TakeBack) continue;
//		//检查胜负
//		win = judge.CheckWin(board);
//		if (win) {
//			displayer.showMessage(current_player->getName() + " win!");
//			displayer.showMessage("Start a new game? y/n:");
//			cin >> input_msg;
//			if (input_msg == "y") {
//				restart = true;
//				continue;
//			}
//			else if (input_msg == "n") {
//				break;
//			}
//		}
//		if (current_player->getName() == player1.getName())
//			current_player = &player2;
//		else
//			current_player = &player1;
//
//
//
//	}
//
//}

//int main() {
//	int a;
//	cout<<" A B C D"<<endl;
//	cout << "a b c d e f g h i j k l n m o" << endl;
//	cout << "┏ ┳ ┳ ┳ ┳ ┳ ┳ ┳ ┳ ┳ ┳ ┳ ┳ ┳ ┓ " << endl;
//	cout << "┣ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ┫ " << endl;
//	cout << "┣ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ┫ " << endl;
//	cout << "┣ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ┫ " << endl;
//	cout << "┣ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ┫ " << endl;
//	cout << "┣ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ┫ " << endl;
//	cout << "┣ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ┫ " << endl;
//	cout << "┣ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ┫ " << endl;
//	cout << "┣ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ┫ " << endl;
//	cout << "┣ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ┫ " << endl;
//	cout << "┣ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ┫ " << endl;
//	cout << "┣ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ┫ " << endl;
//	cout << "┣ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ┫ " << endl;
//	cout << "┣ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ┫ " << endl;
//	cout << "┣ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ╋ ┫ " << endl;
//	cout << "┗ ┻ ┻ ┻ ┻ ┻ ┻ ┻ ┻ ┻ ┻ ┻ ┻ ┻ ┛ " << endl;
//	cout << "┣ ╋ ╋ ●╋ ╋ ╋ ┫ " << endl;
//	cout << "◇○●◇╋ ╋ ╋ ○" << endl;
//	cout << "┗ ┻ ┻ ┻ ┻ ┻ ┻ ┛ " << endl;
//
//	cin >> a;
//	if (1) {
//		system("cls");
//		cout << "clear"<<endl;
//	}
//}

