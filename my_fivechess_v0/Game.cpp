#include "Game.h"
#define BLACK 1
#define WHITE 2


Game::Game()
{
	mode = 0;
	current_player = NULL;
	board.Board_Init();
}


Game::~Game()
{
}
void Game::ChooseMode() {
	do {
		system("cls");
		displayer.showMessage("ѡ�����ģʽ (�˻���������\"1\"�����˶�������\"2\")��");
		cin >> mode;
	} while(!( mode==1 || mode==2 ));
	

}
void Game::InitPlayer() {
	string s;
	if (mode==2) {
		player1 = &human1;
		player2 = &human2;
		displayer.showMessage("Please input Player1's name��");
		cin >> s;
		player1->setName(s);
		displayer.showMessage("Please input Player2's name��");
		cin >> s;
		player2->setName(s);
	}
	else if(mode == 1){
		player1 = &human1;
		player2 = &ai;
		displayer.showMessage("Please input Player1's name��");
		cin >> s;
		player1->setName(s);
		system("cls");
		displayer.showMessage("Hi "+player1->getName()+"! Nice to meet you!\
I'm the AI who will play with you. My designer is a handsome but a little lazy boy, \
who taught me nothing but giving a chess WITHOUT thought. You're sure to win if \
you know the rules of game clearly and your IQ value is NOT negative.\
So don't fear failling, and just enjoy your time. Let's go!");
		//displayer.showMessage("Please input anything to continue:");
		//cin >> s;
		//cin.sync();
		system("pause");
		//cin.get();
	}
}
void Game::ChooseOrder() {
	int first = 0;
	do {
		system("cls");
		//displayer.showMessage("ѡ������ (player1��������\"1\"��player2��������\"2\")��");
		displayer.showMessage("ѡ������ ("+player1->getName()+"��������\"1\"��"+player2->getName()+"��������\"2\")��");
		cin >> first;
	} while (!(first == 1 || first == 2));
	if (first == 1) {
		current_player = player1;
		first_player = player1;
		player1->setColor(BLACK);
		player2->setColor(WHITE);
	}
	else {
		current_player = player2;
		first_player = player2;
		player2->setColor(BLACK);
		player1->setColor(WHITE);
	}
}
void Game::InitGame() {
	ChooseMode();
	InitPlayer();
	ChooseOrder();
}
void Game::StartGame() {
	//Player* current_player;
	Player* takeback_player;
	//Judge judge;
	//Displayer displayer;
	//ChessBoard board;
	Chess chess;

	//current_player = player1;
	bool TakeBack = false;
	string input_msg;
	bool win = false;
	bool restart = false;

	system("cls");
	displayer.showBoard(board);
	while (1)
	{
		//ԭ������Ƿ����¾�
		if (restart) { 
			system("cls");
			//current_player = player1;
			ChooseOrder();//ѡ������
			TakeBack = false;
			input_msg = "";
			win = false;
			restart = false;
			board.Board_Init();
			displayer.showBoard(board);
		}
		//�����Ƿ����
		if (TakeBack && board.getChessNum()>=2) {
			system("cls");
			displayer.showBoard(board);
			if (typeid(*current_player).name() != typeid(AI).name() && mode == 1) {//�Է�ΪAI����ͬ�����
				input_msg = "y";
			}
			else {//�Է�Ϊhuman���辭ͬ�ⷽ�ɻ���
				displayer.showMessage("your friend wants to take back a move. Do you agree? y/n :");
				cin >> input_msg;
			}

			if (input_msg == "y") {//�Է�ͬ�����
				judge.TakeBack(board);//include: board.takeback(), last_chess, stack.pop()
				TakeBack = false;
				takeback_player = NULL;
				system("cls");
				displayer.showBoard(board);
				//if (current_player->getName() == player1->getName())
				//	current_player = player2;
				//else
				//	current_player = player1;
				continue;
			}
			//else {
			//	system("cls");
			//	displayer.showBoard(board);
			//}
		}
		else {
		//	system("cls");
		//	displayer.showBoard(board);
			TakeBack = false;
			takeback_player = NULL;
		}
		system("cls");
		displayer.showBoard(board);
		//��ǰ�������
		displayer.showMessage(current_player->getName() + "'s turn");
		displayer.showMessage("input \"take\" if you want to take back a move");
		displayer.showMessage("input the position of the chess (such as \"ap\" for top-right corner):");

	    //�ж����ӺϷ�
		bool chess_legal = false;
		while (!chess_legal) {

			chess = current_player->GiveChess();
			chess_legal = judge.CheckChessLegal(chess, board);
			if (chess_legal) {//����Ϸ���ˢ������
				board.addChess(chess);// include: last_chess, stack.push_back(chess);
				system("cls");
				displayer.showBoard(board);
				break;
			}
			else {//����Ƿ�����������
				system("cls");
				displayer.showBoard(board);
				displayer.showMessage(current_player->getName() + "'s turn");
				displayer.showMessage("Illegal Input! Please input again:");
			}

			//if (typeid(*current_player).name() == typeid(AI).name()) {//AI player ����
			//	chess = current_player->GiveChess();
			//	chess_legal = judge.CheckChessLegal(chess, board);
			//	if (chess_legal) {//����Ϸ���ˢ������
			//		board.addChess(chess);// include: last_chess, stack.push_back(chess);
			//		system("cls");
			//		displayer.showBoard(board);
			//		break;
			//	}
		
			//}
			//else { //human player����
			//	cin >> input_msg;
			//	if (input_msg == "take") {//�Ƿ����
			//		chess_legal = true;
			//		TakeBack = true;
			//		//TakeBack = current_player->TakeBack();
			//		takeback_player = current_player;
			//		break;
			//	}
			//	else if (input_msg.size() == 2) {//�Ƿ����ӺϷ�
			//		int row = input_msg[0] - 'a';
			//		int col = input_msg[1] - 'a';
			//		chess = current_player->GiveChess({ row,col });
			//		chess_legal = judge.CheckChessLegal(chess, board);
			//	}
			//	if (chess_legal) {//����Ϸ���ˢ������
			//		board.addChess(chess);// include: last_chess, stack.push_back(chess);
			//		system("cls");
			//		displayer.showBoard(board);

			//		break;
			//	}
			//	else {//����Ƿ�����������
			//		system("cls");
			//		displayer.showBoard(board);
			//		displayer.showMessage(current_player->getName() + "'s turn");
			//		displayer.showMessage("Illegal Input! Please input again:");
			//	}

			//}
		}
		if (TakeBack) continue;

		//���ʤ��
		win = judge.CheckWin(board);
		if (win) {
			displayer.showMessage(current_player->getName() + " WIN!");
			displayer.showMessage("Restart the game? y/n:");
			do {
				cin >> input_msg;
			} while (!(input_msg == "y" || input_msg == "n"));
			if (input_msg == "y") {
				restart = true;
				continue;
			}
			else if (input_msg == "n") {
				break;
			}
		}

		//�л�����
		if (current_player->getName() == player1->getName())
			current_player = player2;
		else
			current_player = player1;
	}
}