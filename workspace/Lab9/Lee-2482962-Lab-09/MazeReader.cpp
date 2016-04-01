/*
 * File Name: MazeReader.cpp
 * Author: Cheng Yeh Lee
 * KUID: 2482962
 * Email: chengyeh@ku.edu
 * Assignment: EECS-268 Lab9
 * Description: Implementation of MazeReader class.
 * Created on: Nov 13, 2015
 *
 */

#include "MazeReader.h"


MazeReader::MazeReader(std::string file) throw (MazeCreationException)
{
	fileName = file;
	myInputFile.open(fileName);

	if(myInputFile.good())
	{
		myInputFile >> m_row;
		myInputFile >> m_col;
		myInputFile >> startRow;
		myInputFile >> startCol;

		if(m_row < 1)
		{
			throw(MazeCreationException("\nInvalid size of rows\n"));
		}
		if(m_col < 1)
		{
			throw(MazeCreationException("\nInvalid size of columns\n"));
		}
		if(startRow < 0 || startCol < 0 || startRow >= m_row || startCol >= m_col)
		{
			throw(MazeCreationException("\nInvalid starting position\n"));
		}
	}
	else
	{
		throw(MazeCreationException("\nFile does not exist\n"));
	}

	try
	{
		readMaze();
	}
	catch(MazeCreationException& e)
	{
		std::cout << e.what() << std::endl;
	}

	myInputFile.close();
}


MazeReader::~MazeReader()
{
        for(int i = 0; i < m_row; i++)
	{
		delete[] m_maze[i];
	}

	delete[] m_maze;
}

const char* const* MazeReader::getMaze() const
{
	return(m_maze);
}


int MazeReader::getCols() const
{
	 return(m_col);
}

int MazeReader::getRows() const
{
	return(m_row);
}

int MazeReader::getStartCol() const
{
	return(startCol);
}

int MazeReader::getStartRow() const
{
	return(startRow);
}

void MazeReader::readMaze()	throw (MazeCreationException)
{
	m_maze = new char*[m_row];

	for(int i = 0; i < m_row; i++)
	{
		m_maze[i] = new char[m_col];
	}

	for(int j = 0; j < m_row; j++)
	{
		for(int k = 0; k < m_col; k++)
		{
			myInputFile >> m_maze[j][k];
		}
	}
}


