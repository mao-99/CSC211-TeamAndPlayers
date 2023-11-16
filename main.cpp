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
	int playerIndex;
	for (int i = 0; i < myVector.size(); i++) {
		if (myVector.at(i) == name) {
			playerIndex = i;
			break;
		}
		/*if (myVector.at(i) > name) {
			playerIndex = -1;
			break;
		}*/
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
	cout << "The number of players is: " << myPlayers.size() << endl;
	selectionSort(myPlayers);
	for (int i = 0; i < myPlayers.size(); i++) {
		myPlayers.at(i).display();
	}
	vector <Team> allTeams;
	Team firstTeam(myPlayers.at(0).getCountry());
	firstTeam.add(myPlayers.at(0));
	allTeams.push_back(firstTeam);
	for (int i = 1; i < myPlayers.size(); i++) {
		if (myPlayers.at(i).getCountry() != allTeams.at((allTeams.size() - 1)).getTeamName()) {
			Team aTeam(myPlayers.at(i).getCountry());
			aTeam.add(myPlayers.at(i));
			allTeams.push_back(aTeam);
		}
		else {
			allTeams.at((allTeams.size() - 1)).add(myPlayers.at(i));
		}
	}
	cout << "The number of teams: " << allTeams.size() << endl;
	cout << endl;
	cout << "These are the teams: " << endl;
	cout << endl;
	for (int i = 0; i < allTeams.size(); i++) {
		allTeams.at(i).display();
	}
	cout << "Select one: \n 1. Display a team by country code \n 2. Add points to a player using their name and country \n 3. Test the Copy Constructor \n 4. Test the Assignment Operator" << endl;
	int userInput;
	cin >> userInput;
	
	//Things to work on:
	//the copy constructor for a team. when a user copies a team and updates the points for one of the players in the team ensure that it only updates the original team and not its copy. Same for the assignment operator.
	//Use switch cases for the userInput menu instead of using if-statements. Finally, ensure that you ask the user for input in a loop and they choose a menu option to quit.
	
	while (userInput < 1 || userInput > 4) {
		cout << "Please provide a valid selection: ";
		cin >> userInput;
	}
	if (userInput == 1) {
		cout << "Please provide the country code in all caps: ";
		string countryCode;
		cin >> countryCode;
		for (int i = 0; i < allTeams.size(); i++) {
			if (allTeams.at(i).getTeamName() == countryCode) {
				allTeams.at(i).display();
				break;
			}
			if ((i == (allTeams.size() - 1)) && (allTeams.at(i).getTeamName() != countryCode)) {
				cout << "Invalid Country" << endl;
			}
		}
	}
	else if (userInput == 2) {
		string fName, lName, coun;
		cout << "Please provide the player's first name: ";
		cin >> fName;
		cout << "Please provide the player's last name: ";
		cin >> lName;
		cout << "Please provide the player's country: ";
		cin >> coun;
		for (int i = 0; i < allTeams.size(); i++) {
			if (allTeams.at(i).getTeamName() == coun) {
				allTeams.at(i).getPlayer(fName, lName).display();
				cout << "How many points do you want to add to this player? ";
				int extraPoints;
				cin >> extraPoints;
				allTeams.at(i).updatePlayerPoints(fName, lName, extraPoints);
				allTeams.at(i).getPlayer(fName, lName).display();
			}
		}
	}
	return 0;
}
