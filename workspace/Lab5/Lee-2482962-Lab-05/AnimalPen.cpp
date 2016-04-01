/*
 * File Name: AnimalPen.cpp
 * Author: Cheng Yeh Lee
 * KUID: 2482962
 * Email: chengyeh@ku.edu
 * Assignment: EECS-268 Lab5
 * Description: Implementation of AnimalPen class.
 * Created on: Oct 16, 2015
 *
 */

#include "AnimalPen.h"

AnimalPen::AnimalPen()
{}

AnimalPen::~AnimalPen()
{
	if(!isPenEmpty())
	{
		releaseAnimal();
	}
}

void AnimalPen::addAnimal(FarmAnimal* animal)
{
	push(animal);
}

FarmAnimal* AnimalPen::peakAtNextAnimal()
{
	return(peek());
}

void AnimalPen::releaseAnimal()
{
	pop();
}

bool AnimalPen::isPenEmpty()
{
	return(isEmpty());
}


