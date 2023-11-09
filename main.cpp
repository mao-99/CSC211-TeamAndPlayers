//main.cpp
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include "player.h"
#include "team.h"
using namespace std;

//The template selection sort function that sorts a vector 
template <typename Type>
void selectionSort(vector <Type>& myVector) {
	int i = 0, j, smallestIndex;
	Type temp;
	//This loop is used to get the index of the smallest value in the vector
	for (i; i < myVector.size(); i++) {
		smallestIndex = i;
		for (j = i + 1; j < myVector.size(); j++) {
			if (myVector.at(j) < myVector.at(smallestIndex)) {
				smallestIndex = j;
			}
		}
		temp = myVector.at(i);
		myVector.at(i) = myVector.at(smallestIndex);
		myVector.at(smallestIndex) = temp;
	}
};

//This template function is used to search for a player in a vector
template <typename Type>
int search(vector <Type> myVector, string name) {
	//This loop runs through the vector and finds players who we are searching for
	int playerIndex = -1;
	for (int i = 0; i < myVector.size(); i++) {
		bool found = false;
		if (myVector.at(i) == name) {
			found = true;
			playerIndex = i;
		}
		if (myVector.at(i) > name) {
			break;
		}
	}
	return playerIndex;
}

int main() {
	ifstream file;
	file.open("womenTennisPlayers.txt");
	if (!file.is_open()) {
		cout << "File open error" << endl;
		return 1;
	}
	int r, p;
	string fN, lN, c;
	vector <Player> myPlayers;
	while (!file.eof()) {
		file >> r;
		file >> lN;
		file >> fN;
		file >> c;
		if (c == "???") {
			c = "Unknown";
		}
		file >> p;
		Player x(r, fN, lN, c, p);
		x.display();
		myPlayers.push_back(x);
	}
	cout << endl;
	cout << "This is a check for after reading the players from the file \n";
	cout << "The vector size is: " << myPlayers.size() << endl;
	cout << endl;
	cout << "This is the vector after sorting: " << endl;
	selectionSort(myPlayers);
	for (int i = 0; i < myPlayers.size(); i++) {
		myPlayers.at(i).display();
	}
	vector <Team> allTeams;
	Team firstTeam(myPlayers.at(0).getCountry());
	allTeams.push_back(firstTeam);
	for (int i = 1; i < myPlayers.size(); i++) {
		if (myPlayers.at(i).getCountry() != allTeams.at((allTeams.size() - 1)).getTeamName()) {
			Team aTeam(myPlayers.at(i).getCountry());
			allTeams.push_back(aTeam);
		}
	}
	for (int i = 0; i < allTeams.size(); i++) {
		cout << allTeams.at(i).getTeamName() << endl;
	}
	/*string userInput;
	cout << "Type a players name or press n to quit: " << endl;
	cin >> userInput;
	while (userInput != "n") {
		for (int i = 0; i < userInput.length(); i++) {
			userInput[i] = toupper(userInput[i]);
		}
		int val = search(myPlayers, userInput);
		if (val == -1) {
			cout << "The player was not found" << endl;
		}
		else {
			myPlayers.at(val).display();
		}
		cout << "Type another players name or press n to quit: " << endl;
		cin >> userInput;

	}*/
	Team jpnTeam("JPN");
	int val = search(myPlayers, "KAROLINA");
	jpnTeam.add(myPlayers.at(val));
	jpnTeam.display();

	cout << endl;

	return 0;
}