/*
 * File Name: CyberChicken.h
 * Author: Cheng Yeh Lee
 * KUID: 2482962
 * Email: chengyeh@ku.edu
 * Assignment: EECS-268 Lab5
 * Description: Header file of CyberChicken class. It derived from Chicken Class. Used to set CyberChicken's information.
 * Created on: Oct 16, 2015
 *
 */

#ifndef CYBERCHICKEN_H_
#define CYBERCHICKEN_H_

#include "Chicken.h"

class CyberChicken : public Chicken
{
	public:
	/**
	*  @pre None
	*  @post Initializes m_name to "Cyber Chicken" and m_sound to "Resistance is futile"
	*  @return Initialzed variables
	*/
	CyberChicken();

	/**
	*  @pre None
	*  @post None
	*  @return Return the inherited member variable, m_eggs
	*/
	int getCyberEggs() const;

	/**
	*  @pre Number of eggs
	*  @post Sets the inherited member variable, m_eggs
	*  @return None
	*/
	void setCyberEggs(int eggs);
};



#endif /* CYBERCHICKEN_H_ */
