/*
 * File Name: Chicken.h
 * Author: Cheng Yeh Lee
 * KUID: 2482962
 * Email: chengyeh@ku.edu
 * Assignment: EECS-268 Lab5
 * Description: Header file of Chicken class. It derived from FarmAnimal Class. Used to set Chicken's information.
 * Created on: Oct 16, 2015
 *
 */

#ifndef CHICKEN_H_
#define CHICKEN_H_

#include "FarmAnimal.h"

class Chicken : public FarmAnimal
{
	protected:
	int getEggs() const;

	void setEggs(int eggs);

	int m_eggs;

	public:
	/**
	*  @pre None
	*  @post Initializes m_name to "Chicken" and m_sound to "Cluck"
	*  @return Initialzed variables
	*/
	Chicken();
};



#endif /* CHICKEN_H_ */
