//team.h
#pragma once
#include <string>
#include <vector>
#include "player.h"
using namespace std;
class Team {
public:
	Team(string country);
	Team();
	void display();
	void add(Player aPlayer);
	string getTeamName();
	int getNumPlayers();
	Player getPlayer(string first, string last);
	void updatePlayerPoints(string first, string last, int extraPoints);
private:
	int mNumberOfPlayers;
	vector <Player> *teamPlayers;
	string mCountry;
};
