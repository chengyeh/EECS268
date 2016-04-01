/*
 * File Name: CyberChicken.cpp
 * Author: Cheng Yeh Lee
 * KUID: 2482962
 * Email: chengyeh@ku.edu
 * Assignment: EECS-268 Lab5
 * Description: Implementation of CyberChicken class.
 * Created on: Oct 16, 2015
 *
 */

#include <iostream>
#include "CyberChicken.h"

CyberChicken::CyberChicken()
{
	m_name = "Cyber Chicken";
	m_sound = "Resistance is futile";
}

int CyberChicken::getCyberEggs() const
{
	return(m_eggs);
}

void CyberChicken::setCyberEggs(int eggs)
{
	m_eggs = eggs;
}
