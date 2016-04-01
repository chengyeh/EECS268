/*
 * File Name: PreconditionViolationException.cpp
 * Author: Cheng Yeh Lee
 * KUID: 2482962
 * Email: chengyeh@ku.edu
 * Assignment: EECS-268 Lab5
 * Description:  Implementation of PreconditionViolationException class.
 * Created on: Oct 16, 2015
 *
 */

#include "PreconditionViolationException.h"


PreconditionViolationException::PreconditionViolationException(const char* msg) : std::runtime_error(msg)
{}



