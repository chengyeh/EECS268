/*
 * File Name: MazeCreationException.cpp
 * Author: Cheng Yeh Lee
 * KUID: 2482962
 * Email: chengyeh@ku.edu
 * Assignment: EECS-268 Lab9
 * Description:  Implementation of MazeCreationException class.
 * Created on: Nov 13, 2015
 *
 */

#include "MazeCreationException.h"

MazeCreationException::MazeCreationException(const char* message) : std::runtime_error(message)
{}
