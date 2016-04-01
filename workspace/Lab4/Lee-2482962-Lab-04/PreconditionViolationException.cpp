/*
 * File Name: PreconditionViolationException.cpp
 * Author: Cheng Yeh Lee
 * KUID: 2482962
 * Email: chengyeh@ku.edu
 * Assignment: EECS-268 Lab4
 * Description:  Implementation of PreconditionViolationException class.
 * Created on: Sep 28, 2015
 *
 */

#include "PreconditionViolationException.h"


PreconditionViolationException::PreconditionViolationException(const char* msg) : std::runtime_error(msg)
{}
