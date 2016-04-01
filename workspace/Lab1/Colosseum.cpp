/*
 * File Name: Colosseum.cpp
 * Author: Cheng Yeh Lee
 * KUID: 2482962
 * Email: chengyeh@ku.edu
 * Assignment: EECS-268 Lab1
 * Description:  Implementation of Colosseum class.
 * Created on: Sep 4, 2015
 *
 */

#include <iostream>
#include <string>
#include "Colosseum.h"

using namespace std;

//Initializes all the variables
Colosseum::Colosseum()
{
	d20 = Dice(20);
	d6 = Dice(6);
	d2 = Dice(2);
}

//Set name, hp, attackLevel, and defenseLevel for Pokemon p
void Colosseum::userBuild(Pokemon& p)
{
	string name;
	int hp;
	int attackLevel;
	int defenseLevel;

	cout << "Please name your pokemon: ";
	getline(cin, name);
	while(name == "" || name == " ")
	{
		cout << "Your name must be at least 1 character long: ";
		getline(cin, name);
	}
	p.setName(name);

	cout << "How many hit points will it have? (1-50): ";
	cin >> hp;
	while(hp < 1 || hp > 50)
	{
		cout << "Sorry. The hit points must be between 1 and 50: ";
		cin >> hp;
	}
	p.setHP(hp);

	cout << "Split fifty points between attack level and defense level\nEnter your attack level (1-49): ";
	cin >> attackLevel;
	while(attackLevel < 1 || attackLevel > 49)
	{
		cout << "Sorry. The attack level must be between 1 and 49: ";
		cin >> attackLevel;
	}
	p.setAttackLevel(attackLevel);

	cout << "Enter your defense level (1-" << (50-p.getAttackLevel()) << "): ";
	cin >> defenseLevel;
	while(defenseLevel < 1 || defenseLevel > (50-p.getAttackLevel()))
	{
		cout << "Sorry. The defense level must be between 1 and " << (50-p.getAttackLevel()) << ": ";
		cin >> defenseLevel;
	}
	p.setDefenseLevel(defenseLevel);
	cin.ignore();

}

//Return true only if the defender died because of the attack, otherwise returns false
bool Colosseum::attack(const Pokemon& attacker, Pokemon& defender)
{
	bool ifAttack = false;
	bool ifDie = false;
	int attackBonus = d20.roll();
	int defenseBonus = d20.roll();
	int damage1 = 0;
	int damage2 = 0;
	int damage3 = 0;
	int totalDamage = 0;
	int attackerScore = attacker.getAttackLevel() + attackBonus;
	int defenferScore = defender.getDefenseLevel() + defenseBonus;

	cout << attacker.getName() << " is attacking " << defender.getName() << endl;
	cout << attacker.getName() << " rolls an attack bonus of " << attackBonus << endl;
	cout << defender.getName() << " rolls a defense bonus of " << defenseBonus << endl;

	//If attack happens roll the d6 dice three times then call reduceHP method. Otherwise the attack missed. Both return false
	if(attackBonus > defenseBonus)
	{
		ifAttack = true;
		damage1 = d6.roll();
		damage2 = d6.roll();
		damage3 = d6.roll();
		totalDamage = damage1 + damage2 + damage3;
		defender.reduceHP(totalDamage);
		cout << "The attack hits dealing 3-D6 damage!\n";
		cout << "The rolls are are " << damage1 << ", " << damage2 << ", " << damage3 << " totaling: " << totalDamage << " damage!\n";
	}
	else
	{
		cout << "The attack missed!\n";
	}

	//If attack happens and the defender die return true
	if(ifAttack == true)
	{
		if(defender.getHP() > 0)
		{
			cout << defender.getName() << " has " << defender.getHP() << " hit points left\n";
			ifDie = false;
		}
		if(defender.getHP() <= 0)
		{
			cout << defender.getName() << " have been defeated!";
			ifDie = true;
		}
	}

	return (ifDie);

}

//If the die returns 1 p1 will go first, or if it returns 2 p2 will go first
void Colosseum::play(Pokemon& p1, Pokemon& p2)
{
	int order;
	cout << "Choosing which player to go first:\n";
	order = d2.roll();
	if(order == 1)
	{
		bool end = false;
		int round = 1;
		cout << "Player 1 will go first.";
		while(end == false)
		{
			cout << "\n\nRound " << round << "!\n";
			if(round <= 10 && end == false)
			{
				end = attack(p1, p2);
			}
			if(round <= 10 && end == false)
			{
				end = attack(p2, p1);
			}
			if(round == 10 && end == false)
			{
				cout << "Both fighters are still standing! It's a draw!";

				end = true;
			}
			round ++;
		}

	}
	else
	{
		bool end = false;
		int round = 1;
		cout << "Player 2 will go first";
		while(end == false)
		{
			cout << "\n\nRound " << round << "!\n";
			if(round <= 10 && end == false)
			{
				end = attack(p2, p1);
			}
			if(round <= 10 && end == false)
			{
				end = attack(p1, p2);
			}
			if(round == 10 && end == false)
			{
				cout << "Both fighters are still standing! It's a draw!";

				end = true;
			}
			round ++;

		}

	}

}


