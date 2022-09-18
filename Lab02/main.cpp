// TowerHannoiGame.cpp : Defines the entry point for the console application.
//

#include "StackQueue.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class TowersOfHannoiGame
{
public:
	TowersOfHannoiGame() : m_GameEnded(false)
	{
		for (int i = 0; i < NUM_TOWERS; i++) {
			towers[i] = ArrayBasedStack();	// Instantiate 3 tower objects
		}

		for (int i = TOWER_SIZE; i >=1; i--) {
			towers[0].push(i);				// Add 4 disks in decreasing size to the first tower
		}
	}

	bool IsGameEnded() { return m_GameEnded; }

	void CheckGameStatus() {
		if (towers[2].toString() == "4 3 2 1 ") {
			m_GameEnded = true;
		}

		return;
	}

	void PrintTowers()
	{
		cout << endl;
		cout << "Tower 1: " << towers[0].toString() << endl;
		cout << "Tower 2: " << towers[1].toString() << endl;
		cout << "Tower 3: " << towers[2].toString() << endl << endl;
		cout << "--------------------------------------" << endl << endl;
	}

	void MoveDisk(int disk, int towerFrom, int towerTo) {
		// Decrement tower ID's to be aligned with array indices
		towerFrom--;
		towerTo--;

		// Error handling for the selected disk not on top of stack
		if (towers[towerFrom].peek() != disk) {
			cout << "--------------------------------------" << endl;
			cout << "ERROR: Disk not on top of the stack" << endl;
			cout << "--------------------------------------" << endl;
			return;
		}

		// If towerTo is empty no need to peek it
		if (towers[towerTo].isEmpty()) {
			towers[towerFrom].pop();
			towers[towerTo].push(disk);
			return;
		}
		
		// Error handling for bigger disk on top of small disk
		if (towers[towerTo].peek() < disk) {
			cout << "--------------------------------------" << endl;
			cout << "ERROR: Disk too small to place on" << endl;
			cout << "--------------------------------------" << endl;
			return;
		}

		// Move the disk
		towers[towerFrom].pop();
		towers[towerTo].push(disk);
	}

private:
	bool m_GameEnded;
	ArrayBasedStack towers[3];
	const int TOWER_SIZE = 4;
	const int NUM_TOWERS = 3;
};

int main()
{

	cout << "Enter in moves to make for Towers  of  Hannoi" << endl;
	cout << "Progam will exit once towers have  been successfully moved of" << endl;
	cout << "or string of -1 is entered. Moves must be entired in format of" << endl;
	cout << "<disk>,<column from>,<column to>   NOTE no spaces!!!!" << endl;

	TowersOfHannoiGame game;

	bool receivedEndToken = false;

	while (!receivedEndToken && !game.IsGameEnded())
	{
		std::string inputLine;
		game.PrintTowers();
		cout << "Enter Move " << endl;
		getline(cin, inputLine);
		if (inputLine == "-1")
		{
			receivedEndToken = true;
		}
		else
		{
			std::vector<std::string> output;
			std::string::size_type prev_pos = 0, pos = 0;
			// Snippet from https://stackoverflow.com/questions/5167625/splitting-a-c-stdstring-using-tokens-e-g
			// tokenizing a string
			while ((pos = inputLine.find(",", pos)) != std::string::npos)
			{
				std::string substring(inputLine.substr(prev_pos, pos - prev_pos));
				output.push_back(substring);
				prev_pos = ++pos;
			}
			//Need to get last token
			output.push_back(inputLine.substr(prev_pos, pos - prev_pos)); // Last word

			if (output.size() != 3)
			{
				receivedEndToken = true;
				cout << "Invalid input recieved = " + inputLine << endl;
			}
			else
			{
				std::string disk = output[0];
				std::string from = output[1];
				std::string to = output[2];

				if (disk.size() == 0 || from.size() == 0 || to.size() == 0)
				{
					receivedEndToken = true;
					cout << "Invalid input recieved = " + inputLine << endl;
				}

				int diskId = atoi(disk.c_str()); 
				int fromId = atoi(from.c_str());
				int toId = atoi(to.c_str());
				//if any number is zero we didn't have a integer
				if (diskId == 0 || fromId == 0 || toId == 0)
				{
					receivedEndToken = true;
					cout << "Invalid input recieved = " + inputLine << endl;
				}

				cout << "Disk " << diskId << " From " << fromId << " To " << toId << endl;

				game.MoveDisk(diskId, fromId, toId);	// Move disk to designated tower
			}
		}

		game.CheckGameStatus();

	}

	if (game.IsGameEnded() == true) {
		cout << "--------------------------------------" << endl;
		cout << "Congratulations! You won the game" << endl;
		cout << "--------------------------------------" << endl << endl;
	}

    return 0;
}

