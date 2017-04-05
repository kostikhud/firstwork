// Laba1.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>
#include "stdafx.h"
#include "stdlib.h"
#include "fstream"
#include "vector"
#include "string"

using namespace std;

struct Team {
	string name;
	int points = 0;
	int goalsDifference = 0;
};

void input(vector<Team> &);
void sortTable(vector<Team> &);
void output(vector<Team>);

int main()
{
	vector<Team> leage;
	input(leage);
	sortTable(leage);
	output(leage);
	return 0;
}

void input(vector<Team> &leage) {
	string counter;
	Team current;
	string result;

	ifstream fin;
	fin.open("premier_league.csv");

	getline(fin, counter, '\n');

	for (int k = 0; k < 20; k++) {
		getline(fin, current.name, ',');
		for (int i = 0; i < 10; i++) {
			if (i != 9)
				getline(fin, result, ',');
			else
				getline(fin, result, '\n');

			if (result[0] > result[2]) 
				current.points += 3;
			else if (result[0] == result[2]) 
				current.points += 1;		
			current.goalsDifference = +(result[0] - result[2]);
		}

		leage.push_back(current);
		current.points = 0;
		current.goalsDifference = 0;
	}
}

void sortTable(vector<Team> &leage) {
	Team curr;
	for (int i = 0; i < leage.size(); i++)
		for (int j = i; j < leage.size(); j++)
			if ((leage[i].points < leage[j].points)||(leage[i].points==leage[j].points
				&&leage[i].goalsDifference<leage[i].goalsDifference)) {
				curr = leage[i];
				leage[i] = leage[j];
				leage[j] = curr;
			}
}

void output(vector<Team> leage) {
	Team curr = leage[0];
	ofstream fout;
	fout.open("result.csv");
	for (int i = 0; i < leage.size(); i++) {
		fout << leage[i].name << ',' << leage[i].goalsDifference << ','<<leage[i].points<< endl;
	}
	fout.close();
}
