/*
 * File Name: MazeReader.h
 * Author: Cheng Yeh Lee
 * KUID: 2482962
 * Email: chengyeh@ku.edu
 * Assignment: EECS-268 Lab9
 * Description: Header file of MazeReader class.
 * Created on: Nov 13, 2015
 *
 */

#ifndef MAZEREADER_H_
#define MAZEREADER_H_

#include <iostream>
#include <fstream>
#include <stdexcept>

#include "MazeCreationException.h"


class MazeReader
{
public:

	/**
	*  @pre
	*  @post A MazeReader is created. A 2D char array is allocated with the maze information.
	*  @throws MazeCreationExecption
	*  @returns none
	*/
	MazeReader(std::string file) throw (MazeCreationException);

	/**
	*  @pre A maze exists
	*  @post The maze is deallocated.
	*  @return None
	*/
	~MazeReader();

	/**
	*  @pre the file was formatting and read in correctly
	*  @post none
	*  @return Returns pointer to the maze
	*/
	const char* const* getMaze() const;

	/**
	*  @pre the file was formatted and read in correctly
	*  @post none
	*  @returns the number of columns listed in the file
	*/
	int getCols() const;

	/**
	*	@pre the file was formatted and read in correctly
	*	@post none
	*	@returns the number of rows listed in the file
	*/
	int getRows() const;

	/**
	*	@pre the file was formatted and read in correctly
	*	@post none
	*	@returns the starting column
	*/
	int getStartCol() const;

	/**
	*	@pre the file was formatted and read in correctly
	*	@post none
	*	@returns the starting row
	*/
	int getStartRow() const;

protected:

	/**
	*	@pre the file is properly formatted
	*	@post the characters representing the maze are stores
	*	@returns none
	*/
	void readMaze()	throw (MazeCreationException);

private:

	int m_row;
	int m_col;
	int startRow;
	int startCol;
	char** m_maze;
	std::ifstream myInputFile;
	std::string fileName;

};



#endif /* MAZEREADER_H_ */
