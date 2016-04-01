/*
 * File Name: AnimalPen.h
 * Author: Cheng Yeh Lee
 * KUID: 2482962
 * Email: chengyeh@ku.edu
 * Assignment: EECS-268 Lab5
 * Description: Header file of AnimalPen class. It derived from the stack class. Used to add, peek, and release animals.
 * Created on: Oct 16, 2015
 *
 */

#ifndef ANIMALPEN_H_
#define ANIMALPEN_H_

#include "Stack.h"
#include "FarmAnimal.h"

class AnimalPen : public Stack<FarmAnimal*>
{
	public:
	/**
	*  @pre None
	*  @post None
	*  @return None
	*/
	AnimalPen();

	/**
	*  @pre The AnimalPen is not empty
	*  @post Deletes all the animal in the stack
	*  @return None
	*/
	~AnimalPen();

	/**
	*  @pre FarmAnimal pointer
	*  @post Pushes the animal pointer into the pen
	*  @return None
	*/
	void addAnimal(FarmAnimal* animal);

	/**
	*  @pre None
	*  @post Returns a pointer to the next animal.
	*  @return FarmAnimal pointer
	*/
	FarmAnimal* peakAtNextAnimal();

	/**
	*  @pre None
	*  @post Delete animal object and removes the animal pointer from the stack
	*  @return None
	*/
	void releaseAnimal();

	/**
	*  @pre None
	*  @post Returns true is the pen is empty, false otherwise
	*  @return isEmpty()
	*/
	bool isPenEmpty();
};



#endif /* ANIMALPEN_H_ */
