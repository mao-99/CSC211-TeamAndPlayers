#include "team.h"
#include <iostream>
using namespace std;

Team::Team() {
	this->mNumberOfPlayers = 0;
	this->mCountry = "NONE";
	this->teamPlayers = new vector <Player>;
}
Team::Team(string country) {
	this->mCountry = country;
	this->teamPlayers = new vector <Player>;
	this->mNumberOfPlayers = 0;
}
void Team::add(Player aPlayer) {
	this->teamPlayers->push_back(aPlayer);
	this->mNumberOfPlayers += 1;
}
void Team::display() {
	cout << "The number of players in the " << mCountry << " team is : " << this->mNumberOfPlayers << ".The players are : \n";
	for (int i = 0; i < this->teamPlayers->size(); i++) {
		teamPlayers->at(i).display();
	}
	cout << endl;
}
string Team::getTeamName() {
	return this->mCountry;
}
int Team::getNumPlayers() {
	return this->mNumberOfPlayers;
}
Player Team::getPlayer(string first, string last) {
	for (int i = 0; i < this->teamPlayers->size(); i++) {
		if (this->teamPlayers->at(i).getFirstName() == first && this->teamPlayers->at(i).getLastName() == last) {
			return this->teamPlayers->at(i);
		}
	}
}
void Team::updatePlayerPoints(string first, string last, int extraPoints) {
	for (int i = 0; i < this->teamPlayers->size(); i++) {
		if (this->teamPlayers->at(i).getFirstName() == first && this->teamPlayers->at(i).getLastName() == last) {
			int originalPoints = this->teamPlayers->at(i).getPoints();
			this->teamPlayers->at(i).setPoints(originalPoints + extraPoints);
		}
	}
}
