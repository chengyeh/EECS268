/*
 * File Name: Sorts.hpp
 * Author: Cheng Yeh Lee
 * KUID: 2482962
 * Email: chengyeh@ku.edu
 * Assignment: EECS-268 Lab7
 * Description: Implementation of Sorts class.
 * Created on: Oct 29, 2015
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
void Sorts<T>::mergeSort(T arr[], int size)
{
	int s1 = size / 2;
	int s2 = size - s1;

	if(s1 > 0)
	{
		T* leftArray = arr;
		T* rightArray = arr + s1;

		mergeSort(leftArray, s1);
		mergeSort(rightArray, s2);
		merge(leftArray, rightArray, s1, s2);
	}

	assert(Sorts<T>::isSorted(arr, size));
}

template <typename T>
void Sorts<T>::quickSort(T arr[], int size)
{
	quickSortRec(arr, 0, size - 1, false);

	assert(Sorts<T>::isSorted(arr, size));
}

template <typename T>
void Sorts<T>::quickSortWithMedian(T arr[], int size)
{
	quickSortRec(arr, 0, size - 1, true);

	assert(Sorts<T>::isSorted(arr, size));
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

template <typename T>
void Sorts<T>::merge(T* a1, T* a2, int size1, int size2)
{
	 T* temp = new T[size1 + size2];
	 int leftSize = 0;
	 int rightSize = 0;
	 int mergedSize = 0;

	 while(leftSize < size1 && rightSize < size2)
	 {
		 if(a1[leftSize] < a2[rightSize])
		 {
			 temp[mergedSize] = a1[leftSize];
			 leftSize++;
		 }
		 else
		 {
			 temp[mergedSize] = a2[rightSize];
			 rightSize++;
		 }
		 mergedSize++;
	 }
	 while(leftSize < size1)
	 {
		 temp[mergedSize] = a1[leftSize];
		 leftSize++;
		 mergedSize++;
	 }
	 while(rightSize < size2)
	 {
		 temp[mergedSize] = a2[rightSize];
		 rightSize++;
		 mergedSize++;
	 }

	 for(int i = 0; i < (size1 + size2); i++)
	 {
		 a1[i] = temp[i];
	 }

	 delete[] temp;
}


template <typename T>
void Sorts<T>::quickSortRec(T arr[], int first, int last, bool median)
{
	if(first <  last)
	{
		int pivot = partition(arr, first, last, median);
		quickSortRec(arr, first, pivot - 1, median);
		quickSortRec(arr, pivot + 1, last, median);
	}
}

template <typename T>
void Sorts<T>::setMedianPivot(T arr[], int first, int last)
{
	int pivot = (last+first)/2;
	T temp;

	temp = arr[pivot];
	arr[pivot] = arr[last];
	arr[last] = temp;
}


template <typename T>
int Sorts<T>::partition(T arr[], int first, int last, bool median)
{
	int left = first;
	int right = last - 1;
	int pivot = last;
	T temp;

	if (median)
	{
		setMedianPivot(arr, first, last);
	}

	while (left != right)
	{
		if (arr[left] <= arr[pivot])
		{
			left++;
		}
		else if (arr[right] > arr[pivot])
		{
		    right--;
		}
		else
		{
		    temp = arr[left];
		    arr[left] = arr[right];
		    arr[right] = temp;
		 }
	}

	if (arr[left] > arr[pivot])
	{
		temp = arr[pivot];
		arr[pivot] = arr[left];
		arr[left] = temp;
		pivot = left;
	}

	return(pivot);

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



