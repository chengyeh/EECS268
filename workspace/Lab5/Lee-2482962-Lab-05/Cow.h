/*
 * File Name: Cow.h
 * Author: Cheng Yeh Lee
 * KUID: 2482962
 * Email: chengyeh@ku.edu
 * Assignment: EECS-268 Lab5
 * Description: Header file of Cow class. It derived from FarmAnimal Class. Used to set Cow's information.
 * Created on: Oct 16, 2015
 *
 */

#ifndef COW_H_
#define COW_H_

#include "FarmAnimal.h"

class Cow : public FarmAnimal
{
	protected:
	double m_milkProduced;

	public:
	/**
	*  @pre None
	*  @post Initializes m_name to "Cow" and m_sound to "Moo"
	*  @return Initialzed variables
	*/
	Cow();

	/**
	*  @pre None
	*  @post None
	*  @return Return m_milkProduced
	*/
	double getMilkProduced() const;

	/**
	*  @pre Number of gallons
	*  @post If gallons is > 0, assigns the value to m_milkProduced. Set to 0 otherwise
	*  @return None
	*/
	void setMilkProduced(double gallons);
};

#endif /* COW_H_ */
