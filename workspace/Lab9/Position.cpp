/*
 * File Name: Position.cpp
 * Author: Cheng Yeh Lee
 * KUID: 2482962
 * Email: chengyeh@ku.edu
 * Assignment: EECS-268 Lab9
 * Description: Implementation of Position class.
 * Created on: Nov 13, 2015
 *
 */

#include "Position.h"

Position::Position(int row, int col)
{
	m_row = row;
	m_col = col;
}

int Position::getRow() const
{
	return(m_row);
}


int Position::getCol() const
{
	return(m_col);
}


