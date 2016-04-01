/*
 * File Name: Sorts.h
 * Author: Cheng Yeh Lee
 * KUID: 2482962
 * Email: chengyeh@ku.edu
 * Assignment: EECS-268 Lab7
 * Description: Header file of Sorts class. Used to define and time different sorting methods and create test array.
 * Created on: Oct 29, 2015
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
	*  @post Sorts arr using mergeSort algorithm discussed in class
	*  @return None
	*/
	static void mergeSort(T arr[], int size);

        /**
	*  @pre The integers in arr must be filled with values and the number of values in arr must be stored in size
	*  @post Calls quickSort with median flag set to false
	*  @return None
	*/
	static void quickSort(T arr[], int size);

        /**
	*  @pre The integers in arr must be filled with values and the number of values in arr must be stored in size
	*  @post Calls quickSortRec with median flag set to true
	*  @return None
	*/
	static void quickSortWithMedian(T arr[], int size);

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

	private:
        /**
	*  @pre Valid sizes and arrays
	*  @post combine arrays into a single sorted array
	*  @return None
	*/
	static void merge(T* a1, T* a2, int size1, int size2);

        /**
	*  @pre Valid sizes and arrays
	*  @post Sorts the array by partitioning the array, quick sorting every left of the pivot, and quick sorting everything right of the pivot passes median to partition to inform that method how to pick a pivot value
	*  @return None
	*/
	static void quickSortRec(T arr[], int first, int last, bool median);

        /**
	*  @pre Valid sizes and arrays
	*  @post Puts the median value of the array in the last position
	*  @return None
	*/
	static void setMedianPivot(T arr[], int first, int last);

        /**
	*  @pre Valid sizes and arrays
	*  @post Partitions the array. Chooses a pivot based on the median flag, if median is true, use setMedianPivot, otherwise select the last element in the array
	*  @return The index of the pivot
	*/
	static int partition(T arr[], int first, int last, bool median);

	/**
	*  @pre The integers in arr must be filled with values and the number of values in arr must be stored in size
	*  @post For each index in the array, swap it the value at another random index
	*  @return None
	*/
	static void shuffle(T arr[], int size, std::default_random_engine& generator);
};

#include "Sorts.hpp"

#endif /* SORTS_H_ */

