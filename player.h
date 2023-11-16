//player.h
#pragma once
#include <string>
using namespace std;
class Player {
public:
	Player(int rnk, string fName, string lName, string coun, int pnts);
	Player();
	void setRank(int rnk);
	void setLastName(string lName);
	void setFirstName(string fName);
	void setCountry(string coun);
	void setPoints(int pnts);
	void display() const;
	int getRank() const;
	int getPoints() const;
	void addPoints(int pnts);
	string getLastName() const;
	string getFirstName() const;
	string getCountry() const;
	bool operator==(const Player& rhs);
	bool operator==(string name);
	bool operator<(string name);
	bool operator>(string name);
	bool operator!=(const Player& rhs);
	bool operator<(const Player& rhs);
	bool operator>(const Player& rhs);
	bool operator<=(const Player& rhs);
	bool operator>=(const Player& rhs);
private:
	int rank;
	int points;
	string firstName;
	string lastName;
	string country;
};
