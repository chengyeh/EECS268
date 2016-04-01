/*
 * File Name: MazeWalker.h
 * Author: Cheng Yeh Lee
 * KUID: 2482962
 * Email: chengyeh@ku.edu
 * Assignment: EECS-268 Lab9
 * Description: Header file of MazeWalker class.
 * Created on: Nov 13, 2015
 *
 */

#ifndef MAZEWALKER_H_
#define MAZEWALKER_H_

#include <iostream>
#include <stack>
#include <queue>

#include "Position.h"

enum class Search
{
	DFS,
	BFS
};

class MazeWalker
{
public:

	/**
	*	@pre The mazePtr pointer is to a valid maze.
	*	@post A maze walker if created ready to traverse the maze from the start position is the specified order.
	*	@return none
	*/
	MazeWalker(const char* const* mazePtr, int startRow, int startCol, int rows, int cols, Search searchChoice);

	/**
	*	@pre The visited array still exists and has the same dimensions (rows X cols)
	*	@post The visited array is deallocated
	*	@return None
	*/
	~MazeWalker();

	/**
	*	@pre The maze is a valid maze.
	*	@post The maze is traversed until (either dfs or bfs) the end is reached or all moves are exhausted.
	*	@return true if an exit was reached, false otherwise
	*/
	bool walkMaze();

	/**
	*	@pre None
	*	@post None
	*	@return A const pointer to the visited array. (A pointer that cannot change the array)
	*/
	const int* const* getVisited() const;

	/**
	* 	@pre none
	* 	@post none
	*	@return number of rows in maze
	*/
	int getVisitedRows() const;

	/**
	* 	@pre none
	* 	@post none
	*	@return number of cols in maze
	*/
	int getVisitedCols() const;

	/**
	*	@pre None
	*	@post None
	*	@return A const pointer to the maze. (A pointer that cannot change the array)
	*/
	const char* const* getMaze() const;

protected:

	/**
	*	@pre The current position is valid.
	*	@post Either the stack (dfs) or queue (bfs) is loaded with valid moves from the current position.
	*	@return None
	*/
	void storeValidMoves();

	/**
	*	@pre The position is valid.
	*	@post The current position is set to p and the position is updated as marked.
	*	@return None
	*/
	void move(Position& p);


	/**
	*	@pre none
	*	@post none
	*	@returns If the current position is the exit, true is returned. False is returned otherwise.
	*/
	bool isGoalReached() const;


	Search m_searchType;
	const char* const* m_maze;
	int** m_visited;
	int m_rows, m_cols;
	Position m_curPos;
	Position m_startPos;

	std::stack<Position> m_moveStack;
	std::queue<Position> m_moveQueue;

	int m_curStep;
};



#endif /* MAZEWALKER_H_ */
