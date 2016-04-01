/*
 * File Name: Pokemon.cpp
 * Author: Cheng Yeh Lee
 * KUID: 2482962
 * Email: chengyeh@ku.edu
 * Assignment: EECS-268 Lab1
 * Description:  Implementation of Pokemon class.
 * Created on: Sep 4, 2015
 *
 */


#include "Pokemon.h"

using namespace std;

//Initializes all the variables
Pokemon::Pokemon()
{
	int m_hp = 0;
	int m_attackLevel = 0;
	int m_defenseLevel = 0;
	string m_name = "";
}

//reduce amount of m_hp
void Pokemon::reduceHP(int amount)
{
	int playerHP = getHP();
	playerHP = playerHP - amount;
	setHP(playerHP);
}

//Set value of m_hp
void Pokemon::setHP(int hp)
{
	m_hp = hp;
}

//Set value of m_attackLevel
void Pokemon::setAttackLevel(int attactLevel)
{
	m_attackLevel = attactLevel;
}

//Set value of m_defenseLevel
void Pokemon::setDefenseLevel(int defenseLevel)
{
	m_defenseLevel = defenseLevel;
}

//Set value of m_name
void Pokemon::setName(string name)
{
	m_name = name;
}

//Return m_hp
int Pokemon::getHP() const
{
	return(m_hp);
}

//Return m_attackLevel
int Pokemon::getAttackLevel() const
{
	return(m_attackLevel);
}

//Return m_defenseLevel
int Pokemon::getDefenseLevel() const
{
	return(m_defenseLevel);
}

//Return m_name
string Pokemon::getName() const
{
	return(m_name);
}
