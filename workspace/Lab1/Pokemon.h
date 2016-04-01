/*
 * File Name: Pokemon.h
 * Author: Cheng Yeh Lee
 * KUID: 2482962
 * Email: chengyeh@ku.edu
 * Assignment: EECS-268 Lab1
 * Description: Header file of Pokemon class. Used to set and get Pokemon's information.
 * Created on: Sep 4, 2015
 *
 */

#ifndef POKEMON_H_
#define POKEMON_H_

#include <string>

using namespace std;

class Pokemon
{
	private:
	int m_hp;
	int m_attackLevel;
	int m_defenseLevel;
	string m_name;

	public:
	/**
	*  @pre None
	*  @post Initializes all numeric data to zero and strings to ""
	*  @return Initialzed variables
	*/
	Pokemon();

	/**
	*  @pre amount of totalDamage
	*  @post Reduces m_hp by the amount
	*  @return None
	*/
	void reduceHP(int amount);

	/**
	*  @pre User input hp
	*  @post Set value of m_hp
	*  @return None
	*/
	void setHP(int hp);

	/**
	*  @pre User input attackLevel
	*  @post Set value of m_attackLevel
	*  @return None
	*/
	void setAttackLevel(int attactLevel);

	/**
	*  @pre User input defenseLevel
	*  @post Set value of m_defenseLevel
	*  @return None
	*/
	void setDefenseLevel(int defenseLevel);

	/**
	*  @pre User input name
	*  @post Set value of m_name
	*  @return None
	*/
	void setName(string name);

	/**
	*  @pre None
	*  @post None
	*  @return the value of m_hp
	*/
	int getHP() const;

	/**
	*  @pre None
	*  @post None
	*  @return the value of m_attackLevel
	*/
	int getAttackLevel() const;

	/**
	*  @pre None
	*  @post None
	*  @return the value of m_defenseLevel
	*/
	int getDefenseLevel() const;

	/**
	*  @pre None
	*  @post None
	*  @return the value of m_name
	*/
	string getName() const;

};




#endif /* POKEMON_H_ */
