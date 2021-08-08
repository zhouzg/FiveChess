#include "Player.h"



Player::Player()
{
}

Player::~Player()
{
}
Player::Player(string name, int color) {
	this->name = name;
	this->color = color;
}
//Chess Player::GiveChess(Position p) {
//	return Chess(this->color, p);
//}
//bool Player::TakeBack() {
//	return true;
//}
//string Player::getName() {
//	return name;
//}
//int Player::getColor() {
//	return color;
//}
