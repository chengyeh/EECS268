/*
 * File Name: Colosseum.h
 * Author: Cheng Yeh Lee
 * KUID: 2482962
 * Email: chengyeh@ku.edu
 * Assignment: EECS-268 Lab1
 * Description: Header file of Colosseum class. Used to define the name, hp, attack level, and defense level for users' pokemon and handle the game.
 * Created on: Sep 4, 2015
 *
 */

#ifndef COLOSSEUM_H_
#define COLOSSEUM_H_

#include <iostream>
#include <string>
#include "Pokemon.h"
#include "Dice.h"

class Colosseum
{
	private:
	Dice d20;
	Dice d6;
	Dice d2;

	public:
	/**
	*  @pre None
	*  @post Initializes Dice to appropriate sizes
	*  @return Initialzed Dice with numSides sides
	*/
	Colosseum();

	/**
	*  @pre A Pokemon class instances
	*  @post Sets all the values for name, hp, attackLevel, and defenseLevel of the Pokemon passed in
	*  @return None
	*/
	void userBuild(Pokemon& p);

	/**
	*  @pre Two Pokemon class instances
	*  @post Return true only if the defender died because of the attack, otherwise return false
	*  @return ifDie
	*/
	bool attack(const Pokemon& attacker, Pokemon& defender);

	/**
	*  @pre Two Pokemon class instances
	*  @post Game end when either player dies or rounds are over
	*  @return None
	*/
	void play(Pokemon& p1, Pokemon& p2);

};




#endif /* COLOSSEUM_H_ */
