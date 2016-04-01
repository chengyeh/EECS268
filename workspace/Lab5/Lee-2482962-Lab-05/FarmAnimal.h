/*
 * File Name: FarmAnimal.h
 * Author: Cheng Yeh Lee
 * KUID: 2482962
 * Email: chengyeh@ku.edu
 * Assignment: EECS-268 Lab5
 * Description: Header file of FarmAnimal class. The base class of all animals. Used to set animal's information.
 * Created on: Oct 16, 2015
 *
 */

#ifndef FARMANIMAL_H_
#define FARMANIMAL_H_

#include <string>

class FarmAnimal
{
	protected:
	std::string m_name;
	std::string m_sound;

	public:
	/**
	*  @pre None
	*  @post Initializes m_name and m_sound to "unset"
	*  @return Initialzed variables
	*/
	FarmAnimal();

	/**
	*  @pre None
	*  @post None
	*  @return m_name
	*/
	std::string getName() const;

	/**
	*  @pre a string
	*  @post sets m_name to name
	*  @return None
	*/
	void setName(std::string name);

	/**
	*  @pre None
	*  @post None
	*  @return m_sound
	*/
	std::string getSound() const;

	/**
	*  @pre a string
	*  @post sets m_sound to sound
	*  @return None
	*/
	void setSound(std::string sound);
};



#endif /* FARMANIMAL_H_ */
