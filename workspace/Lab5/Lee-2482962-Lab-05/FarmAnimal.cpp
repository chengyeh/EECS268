/*
 * File Name: FarmAnimal.cpp
 * Author: Cheng Yeh Lee
 * KUID: 2482962
 * Email: chengyeh@ku.edu
 * Assignment: EECS-268 Lab5
 * Description:  Implementation of FarmAnimal class.
 * Created on: Oct 16, 2015
 *
 */

#include "FarmAnimal.h"

FarmAnimal::FarmAnimal()
{
	m_name = "unset";
	m_sound ="unset";
}

std::string FarmAnimal::getName() const
{
	return(m_name);
}

void FarmAnimal::setName(std::string name)
{
	m_name = name;
}

std::string FarmAnimal::getSound() const
{
	return(m_sound);
}

void FarmAnimal::setSound(std::string sound)
{
	m_sound = sound;
}
