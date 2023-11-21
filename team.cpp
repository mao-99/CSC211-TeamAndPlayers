#include "team.h"
#include <iostream>
using namespace std;

Team::Team() {
	this->mNumberOfPlayers = 0;
	this->mCountry = "NONE";
	this->teamPlayers = new vector <Player>;
}
Team::Team(const Team& rhs) {
	this->mNumberOfPlayers = rhs.mNumberOfPlayers;
	this->mCountry = rhs.mCountry;
	this->teamPlayers = new vector <Player>;
	for (int i = 0; i < rhs.teamPlayers->size(); i++) {
		this->teamPlayers->push_back(rhs.teamPlayers->at(i));
	}
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
const string Team::getTeamName() {
	return this->mCountry;
}
const int Team::getNumPlayers() {
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

Team& Team::operator=(const Team& rhs) {
	if (this != &rhs) {
		this->mCountry = rhs.mCountry;
		delete this->teamPlayers;
		this->teamPlayers = new vector <Player>;
		for (int i = 0; i < rhs.teamPlayers->size(); i++) {
			this->teamPlayers->push_back(rhs.teamPlayers->at(i));
		}
		this->mNumberOfPlayers = this->teamPlayers->size();
	}
	return *this;
}

Team::~Team() {
	delete this->teamPlayers;
}
