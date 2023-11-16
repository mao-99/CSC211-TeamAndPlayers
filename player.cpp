//player.cpp
#include "player.h"
#include <iostream>

Player::Player(int rnk, string fName, string lName, string coun, int pnts)
{
	rank = rnk;
	firstName = fName;
	lastName = lName;
	country = coun;
	points = pnts;
}
Player::Player() {
	rank = -1;
	firstName = "";
	lastName = "";
	country = "";
	points = -1;
}
void Player::setRank(int rnk) {
	rank = rnk;
}
void Player::setCountry(string coun) {
	country = coun;
}
void Player::setFirstName(string fName) {
	firstName = fName;
}
void Player::setLastName(string lName) {
	lastName = lName;
}
void Player::setPoints(int pnts) {
	points = pnts;
}
int Player::getRank() const {
	return rank;
}
int Player::getPoints() const {
	return points;
}
void Player::addPoints(int pnts) {
	this->points += pnts;
}
string Player::getFirstName() const {
	return firstName;
}
string Player::getLastName() const {
	return lastName;
}
string Player::getCountry() const {
	return country;
}
void Player::display() const {
	cout << "Player Name: " << firstName << " " << lastName << " . Player country code: " << country << " . Player rank: " << rank << " .Player points: " << points << endl;
}
bool Player::operator==(const Player& rhs) {
	return (firstName == rhs.getFirstName());
}
bool Player::operator!=(const Player& rhs) {
	return !(firstName == rhs.getFirstName());
}
bool Player::operator<(const Player& rhs) {
	return (this->country < rhs.getCountry());
}
bool Player::operator>(const Player& rhs) {
	return (rhs.getFirstName() < firstName);
}
bool Player::operator<=(const Player& rhs) {
	return !(firstName > rhs.getFirstName());
}
bool Player::operator>=(const Player& rhs) {
	return !(firstName < rhs.getFirstName());
}
bool Player::operator==(string name) {
	return (this->firstName == name);
}
bool Player::operator<(string coun) {
	return (this->country < coun);
}
bool Player::operator>(string name) {
	return (this->firstName > name);
}
