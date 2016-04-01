/*
 * File Name: Sorts.h
 * Author: Cheng Yeh Lee
 * KUID: 2482962
 * Email: chengyeh@ku.edu
 * Assignment: EECS-268 Lab6
 * Description: Header file of Sorts class. Used to define and time different sorting methods and create test array.
 * Created on: Oct 23, 2015
 *
 */

#ifndef SORTS_H_
#define SORTS_H_

#include <random>
#include <ctime>
#include <chrono>
#include <cassert>
#include <functional>

template <typename T>
class Sorts
{
	public:
	/**
	*  @pre The integers in arr must be filled with values and the number of values in arr must be stored in size
	*  @post Sorts the integers in arr into ascending order
	*  @return None
	*/
	static void bubbleSort(T arr[], int size);

	/**
	*  @pre The integers in arr must be filled with values and the number of values in arr must be stored in size
	*  @post Sorts the integers in arr into ascending order
	*  @return None
	*/
	static void bogoSort(T arr[], int size);

	/**
	*  @pre The integers in arr must be filled with values and the number of values in arr must be stored in size
	*  @post Sorts the integers in arr into ascending order
	*  @return None
	*/
	static void insertionSort(T arr[], int size);

	/**
	*  @pre The integers in arr must be filled with values and the number of values in arr must be stored in size
	*  @post Sorts the integers in arr into ascending order
	*  @return None
	*/
	static void selectionSort(T arr[], int size);

	/**
	*  @pre The integers in arr must be filled with values and the number of values in arr must be stored in size
	*  @post Returns true if arr is in ascending order, false otherwise
	*  @return True or false
	*/
	static bool isSorted(T arr[], int size);

	/**
	*  @pre The integers in arr must be filled with values and the number of values in arr must be stored in size
	*  @post For each index in the array, swap it the value at another random index
	*  @return None
	*/
	static void shuffle(T arr[], int size, std::default_random_engine& generator);

	/**
	*  @pre User gives a valid size, min, and max
	*  @post Creates a new array of the specified size and contains random values that fall within the range specified by min and max (inclusive)
	*  @return An integer array
	*/
	static int* createTestArray(int size, int min, int max);

	/**
	*  @pre A valid sort function
	*  @post Returns the time, in seconds, of executing sort function
	*  @return elapsed.count()
	*/
	static double sortTimer(std::function<void(T[],int)> sort, T arr[], int size);
};

#include "Sorts.hpp"

#endif /* SORTS_H_ */
