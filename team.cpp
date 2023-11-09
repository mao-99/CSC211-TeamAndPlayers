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
	cout << "The number of players in the team is: " << this->mNumberOfPlayers << " . The players are: \n";
	for (int i = 0; i < this->teamPlayers->size(); i++) {
		teamPlayers->at(i).display();
	}
}
string Team::getTeamName() {
	return this->mCountry;
}
