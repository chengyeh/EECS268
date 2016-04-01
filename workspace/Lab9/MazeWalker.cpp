/*
 * File Name: MazeWalker.cpp
 * Author: Cheng Yeh Lee
 * KUID: 2482962
 * Email: chengyeh@ku.edu
 * Assignment: EECS-268 Lab9
 * Description: Implementation of MazeWalker class.
 * Created on: Nov 13, 2015
 *
 */

#include "MazeWalker.h"

MazeWalker::MazeWalker(const char* const* mazePtr, int startRow, int startCol, int rows, int cols, Search searchChoice):m_curPos(startRow,startCol), m_startPos(startRow,startCol)
{
	m_maze = mazePtr;
	m_rows = rows;
	m_cols = cols;
	m_searchType = searchChoice;
	m_visited = new int*[rows];

	for(int i = 0; i < rows; i++)
	{
		m_visited[i] = new int[cols];
	}

	for(int j = 0; j < rows; j++)
	{
		for(int k = 0; k < cols; k++)
		{
			m_visited[j][k] = 0;
		}
	}

	m_curPos = m_startPos;
	m_curStep = 1;
	m_visited[startRow][startCol] = m_curStep;
}

MazeWalker::~MazeWalker()
{
	for(int i = 0; i < m_rows; i++)
	{
		delete[] m_visited[i];
	}

	delete[] m_visited;
}

bool MazeWalker::walkMaze()
{
	char m_up = 'n';
	char m_down = 'n';
	char m_left = 'n';
	char m_right = 'n';

	if(m_curPos.getRow()-1 >= 0)
	{
		m_up = m_maze[m_curPos.getRow()-1][m_curPos.getCol()];
	}
	if(m_curPos.getRow()+1 < m_rows)
	{
		m_down = m_maze[m_curPos.getRow()+1][m_curPos.getCol()];
	}
	if(m_curPos.getCol()-1 >= 0)
	{
		m_left = m_maze[m_curPos.getRow()][m_curPos.getCol()-1];
	}
	if(m_curPos.getCol()+1 < m_cols)
	{
		m_right = m_maze[m_curPos.getRow()][m_curPos.getCol()+1];
	}


	int moveUP = m_curPos.getRow()-1;
	int moveDOWN = m_curPos.getRow()+1;
	int moveLEFT = m_curPos.getCol()-1;
	int moveRIGHT = m_curPos.getCol()+1;

	if(m_searchType == Search::DFS)
	{
		if(isGoalReached())
		{
			while(m_moveStack.size() > 0)
			{
				m_moveStack.pop();
			}

			return(true);
		}
		else
		{
			if((m_up == 'P' || m_up == 'E') && moveUP >= 0)
			{
				Position up = Position(m_curPos.getRow()-1, m_curPos.getCol());
				m_moveStack.push(up);
			}
			if((m_right == 'P' || m_right == 'E') && moveRIGHT < m_cols)
			{
				Position right = Position(m_curPos.getRow(), m_curPos.getCol()+1);
				m_moveStack.push(right);
			}
			if((m_down == 'P' || m_down == 'E') && moveDOWN < m_rows)
			{
				Position down = Position(m_curPos.getRow()+1, m_curPos.getCol());
				m_moveStack.push(down);
			}
			if((m_left == 'P' || m_left == 'E') && moveLEFT >= 0)
			{
				Position left = Position(m_curPos.getRow(), m_curPos.getCol()-1);
				m_moveStack.push(left);
			}

			while(m_moveStack.size() > 0)
			{
				Position temp = Position(m_moveStack.top().getRow(), m_moveStack.top().getCol());
				m_moveStack.pop();

				if(m_visited[temp.getRow()][temp.getCol()] == 0)
				{
					move(temp);
					storeValidMoves();
					walkMaze();
				}
			}
		}
	}
	if(m_searchType == Search::BFS)
	{
		m_moveQueue.push(m_curPos);

		while(m_moveQueue.size() > 0)
		{
			m_curPos = Position(m_moveQueue.front().getRow(), m_moveQueue.front().getCol());

			if(m_curPos.getRow() != m_startPos.getRow() || m_curPos.getCol() != m_startPos.getCol())
			{
				storeValidMoves();
			}

			if(m_curPos.getRow()-1 >= 0)
			{
				m_up = m_maze[m_curPos.getRow()-1][m_curPos.getCol()];
			}
			else
			{
				m_up = 'n';
			}

			if(m_curPos.getRow()+1 < m_rows)
			{
				m_down = m_maze[m_curPos.getRow()+1][m_curPos.getCol()];
			}
			else
			{
				m_down = 'n';
			}

			if(m_curPos.getCol()-1 >= 0)
			{
				m_left = m_maze[m_curPos.getRow()][m_curPos.getCol()-1];
			}
			else
			{
				m_left = 'n';
			}

			if(m_curPos.getCol()+1 < m_cols)
			{
				m_right = m_maze[m_curPos.getRow()][m_curPos.getCol()+1];
			}
			else
			{
				m_right = 'n';
			}

			int moveUP = m_curPos.getRow()-1;
			int moveDOWN = m_curPos.getRow()+1;
			int moveLEFT = m_curPos.getCol()-1;
			int moveRIGHT = m_curPos.getCol()+1;

			m_moveQueue.pop();

			if(isGoalReached())
			{
				while(m_moveQueue.size() > 0)
				{
					m_moveQueue.pop();
				}

				return(true);
			}
			else
			{
				if((m_up == 'P' || m_up == 'E') && moveUP >= 0)
				{
					Position up = Position(m_curPos.getRow()-1, m_curPos.getCol());

					if(m_visited[up.getRow()][up.getCol()] == 0)
					{
						m_moveQueue.push(up);
					}
				}
				if((m_right == 'P' || m_right == 'E') && moveRIGHT < m_cols)
				{
					Position right = Position( m_curPos.getRow() , m_curPos.getCol()+1 );

					if( m_visited[ right.getRow() ][ right.getCol() ] == 0 )
					{
						m_moveQueue.push(right);
					}
				}
				if((m_down == 'P' || m_down == 'E') && moveDOWN < m_rows)
				{
					Position down = Position(m_curPos.getRow()+1, m_curPos.getCol());

					if(m_visited[down.getRow()][down.getCol()] == 0)
					{
						m_moveQueue.push(down);
					}
				}
				if((m_left == 'P' || m_left == 'E') && moveLEFT >= 0)
				{
					Position left = Position(m_curPos.getRow(), m_curPos.getCol()-1);

					if(m_visited[left.getRow()][left.getCol()] == 0)
					{
						m_moveQueue.push(left);
					}
				}
			}
		}
	}

	return(false);
}

const int* const* MazeWalker::getVisited() const
{
	return(m_visited);
}

int  MazeWalker::getVisitedRows() const
{
	return(m_rows);
}

int MazeWalker::getVisitedCols() const
{
	return(m_cols);
}

const char* const* MazeWalker::getMaze() const
{
	return(m_maze);
}

void MazeWalker::storeValidMoves()
{
	if(m_searchType == Search::DFS)
	{
		m_curStep++;
		m_visited[m_curPos.getRow()][m_curPos.getCol()] = m_curStep;
	}
	else if(m_searchType == Search::BFS)
	{
		m_curStep++;
		m_visited[m_curPos.getRow()][m_curPos.getCol()] = m_curStep;
	}
}

void MazeWalker::move(Position& p)
{
	m_curPos = Position(p.getRow(), p.getCol());
}

bool MazeWalker::isGoalReached() const
{
	if(m_maze[m_curPos.getRow()][m_curPos.getCol()] == 'E')
	{
		return(true);
	}
	else
	{
		return(false);
	}
}


