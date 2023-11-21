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
	Team(const Team& rhs);
	void display();
	void add(Player aPlayer);
	const string getTeamName();
	const int getNumPlayers();
	Player getPlayer(string first, string last);
	void updatePlayerPoints(string first, string last, int extraPoints);
	~Team();
	Team& operator=(const Team& rhs);
private:
	int mNumberOfPlayers;
	vector <Player> *teamPlayers;
	string mCountry;
};
