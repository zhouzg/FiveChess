#pragma once
struct Position
{
	int row;
	int col;
};
class Chess {
public:
	Chess() {//默认构造函数
		this->color = 0;
	};
	Chess(int color, Position p) { 
		this->color = color;// black 1 white 2 last_black 3 last_white 4
		this->row = p.row;
		this->col = p.col;
	}
	
	int getColor() {
		return color;
	}

	Position getPosition() {
		Position p;
		p.row = this->row;
		p.col = this->col;
		return p;
	}
private:
	int row, col;
	int color;
};