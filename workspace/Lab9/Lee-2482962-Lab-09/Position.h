/*
 * File Name: Position.h
 * Author: Cheng Yeh Lee
 * KUID: 2482962
 * Email: chengyeh@ku.edu
 * Assignment: EECS-268 Lab9
 * Description: Header file of Position class. It is used to represent possible moves in the maze
 * Created on: Nov 13, 2015
 *
 */

#ifndef POSITION_H_
#define POSITION_H_

class Position
{
public:

	/**
	*	@pre None
	*	@post Position created with row and col values set.
	*	@return None
	*/
	Position(int row, int col);

	/**
	* 	@pre none
	* 	@post none
	*	@return row value
	*/
	int getRow() const;

	/**
	*	@pre none
	*	@post none
	*	@return col value
	*/
	int getCol() const;

private:

	int m_row;
	int m_col;
};



#endif /* POSITION_H_ */
