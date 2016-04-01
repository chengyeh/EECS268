/*
 * File Name: Cow.cpp
 * Author: Cheng Yeh Lee
 * KUID: 2482962
 * Email: chengyeh@ku.edu
 * Assignment: EECS-268 Lab5
 * Description: Implementation of Cow class.
 * Created on: Oct 16, 2015
 *
 */

#include <iostream>
#include "Cow.h"

Cow::Cow()
{
	m_name = "Cow";
	m_sound = "Moo";
}

double Cow::getMilkProduced() const
{
	return(m_milkProduced);
}

void Cow::setMilkProduced(double gallons)
{
	if(gallons > 0)
	{
		m_milkProduced = gallons;
	}
	else
	{
		m_milkProduced = 0;
	}
}
