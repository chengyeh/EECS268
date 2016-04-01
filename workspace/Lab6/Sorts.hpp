/*
 * File Name: Sorts.hpp
 * Author: Cheng Yeh Lee
 * KUID: 2482962
 * Email: chengyeh@ku.edu
 * Assignment: EECS-268 Lab6
 * Description: Implementation of Sorts class.
 * Created on: Oct 23, 2015
 *
 */


template <typename T>
void Sorts<T>::bubbleSort(T arr[], int size)
{
	T temp;

	for(int j = 0; j < size-1; j++)
	{
		for(int i = 0; i < size-1; i++)
		{
			if(arr[i] > arr[i+1])
			{
				temp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = temp;
			}
		}
	}
	assert( Sorts<T>::isSorted(arr, size) );
}

template <typename T>
void Sorts<T>::bogoSort(T arr[], int size)
{
	std::default_random_engine generator(time(nullptr));
	std::uniform_int_distribution<int> distribution(0, size-1);
	
	while(!isSorted(arr, size))
	{
		shuffle(arr, size, generator);
	}
	assert( Sorts<T>::isSorted(arr, size) );
}


template <typename T>
void Sorts<T>::insertionSort(T arr[], int size)
{
	int j;
	T temp;

	for(int i = 0; i < size; i++)
	{
		j = i;
		while (j > 0 && arr[j] < arr[j-1])
		{
			temp = arr[j];
			arr[j] = arr[j-1];
	    	arr[j-1] = temp;
			j--;
        }
	}
	assert( Sorts<T>::isSorted(arr, size) );
}

template <typename T>
void Sorts<T>::selectionSort(T arr[], int size)
{
	int min;
	T temp;

	for(int i = 0; i < size-1; i++)
	{
		min = i;
		for(int j = i+1; j < size; j++)
		{
			if (arr[j] < arr[min])
			{
				min = j;
			}
		}

		if (min != i)
		{
			temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
	}
	assert( Sorts<T>::isSorted(arr, size) );
}

template <typename T>
bool Sorts<T>::isSorted(T arr[], int size)
{
	for(int i = 0; i < size-1; i++)
	{
		if(arr[i] > arr[i+1])
		{
			return(false);
		}
	}
	return(true);
}

template <typename T>
void Sorts<T>::shuffle(T arr[], int size, std::default_random_engine& generator)
{
	std::uniform_int_distribution<int> distribution(0, size-1);

	for(int i = 0; i < size; i++)
	{
		int swapPosition = distribution(generator);
		int temp = arr[i];
		arr[i] = arr[swapPosition];
		arr[swapPosition] = temp;
	}
}


template <typename T>
int* Sorts<T>::createTestArray(int size, int min, int max)
{
	int* arr = new int[size];
	std::default_random_engine generator(time(nullptr));
	std::uniform_int_distribution<int> distribution(min,max);
	for(int i = 0; i < size; i++)
	{
		int randomNumber = distribution(generator);
		arr[i] = randomNumber;
	}

	return(arr);
}



template <typename T>
double Sorts<T>::sortTimer(std::function<void(T[],int)> sort, T arr[], int size)
{
	std::chrono::system_clock::time_point start;
	std::chrono::system_clock::time_point end;
	std::chrono::duration<double> elapsed;

	start = std::chrono::system_clock::now();

	sort(arr, size);

	end = std::chrono::system_clock::now();
	elapsed = (end - start);
	return(elapsed.count());
}
