/*
 * File Name: main.cpp
 * Author: Cheng Yeh Lee
 * KUID: 2482962
 * Email: chengyeh@ku.edu
 * Assignment: EECS-268 Lab1
 * Description: The main class. Implementation of all class files in the project. Allows the user to repeat as desired
 * Created on: Sep 4, 2015
 *
 */

#include <iostream>
#include <string>
#include "Colosseum.h"
#include "Pokemon.h"

using namespace std;

int main()
{
	bool play = true;
	char answer;

	while(play == true)
	{
		//Declare class instances
		Pokemon player1;
		Pokemon player2;
		Colosseum c;

		//Call userBuild method to ask users to build their Pokemons
		cout << "Player 1, build your Pokemon!\n=====================\n";

		c.userBuild(player1);

		cout << "Player 2, build your Pokemon!\n=====================\n";

		c.userBuild(player2);

		//Call play method to start the game
		c.play(player1, player2);

		//Ask users if they want to play it again
		do
		{
			cout << "\nDo you want to play again? (y/n): ";
			cin >> answer;

		}while(answer != 'Y' && answer != 'y' && answer != 'N' && answer != 'n');
		cin.ignore();

		if(answer == 'Y' || answer == 'y')
		{
			cout << "\n\n";
			play = true;

		}
		if(answer == 'N' || answer == 'n')
		{
			play = false;
		}

	}

	cout << "Thanks for playing!" << endl;

	return 0;

}


