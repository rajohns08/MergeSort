#include "MergeSort.h"
#include <vector>

using namespace std;

template <class T>
vector<T> MergeSort<T>::mergeSort(vector<T> arr)						// Function responsible for breaking up the vector
{
	int middle = arr.size() / 2;										// Establish the middle of the array so that it can be broken up into two halves from that point
	
	if (arr.size() == 1)												// The return case from the recursion. Return when the array has been broken up until it has a single element
	{
		return arr;
	}

	vector<T> leftArr(arr.begin(), (arr.begin() + middle));				// Divide the array into 2 new halves: a left side and a right side
	vector<T> rightArr((arr.begin() + middle), arr.end());

	leftArr = mergeSort(leftArr);										// Recursively call mergeSort on each half to continue breaking up the arrays until they are a single element
	rightArr = mergeSort(rightArr);

	return merge(leftArr, rightArr);									// Merge each left and right subarray
}

template <class T>
vector<T> MergeSort<T>::merge(vector<T> leftArr, vector<T> rightArr)	// Function responsible for merging back vectors
{
	vector<T> mergedVector;												// Create the new merged array to be returned

	while(!leftArr.empty() && !rightArr.empty())						// If there are still elements in both the left and right arrays, you must compare
	{																	// to decide which is smaller, and thus which one to add to the merged array
		if (leftArr[0] > rightArr[0])
		{
			mergedVector.push_back(rightArr[0]);						// If the first element in right array is smaller, then add it to the merged array
			rightArr.erase(rightArr.begin());							// and remove it from the right array
		}
		else
		{
			mergedVector.push_back(leftArr[0]);							// If the left array's element was smaller add this one
			leftArr.erase(leftArr.begin());
		}
	}

	while (!leftArr.empty())											// If one of the arrays is empty, go ahead and add the rest of the elements from the other array
	{
		mergedVector.push_back(leftArr[0]);
		leftArr.erase(leftArr.begin());
	}

	while (!rightArr.empty())
	{
		mergedVector.push_back(rightArr[0]);
		rightArr.erase(rightArr.begin());
	}

	return mergedVector;												// Return the sorted merged array
}

template <class T>
T *MergeSort<T>::mergeSort(T arr[], int firstIndex, int lastIndex)
{
	int middle = (firstIndex + lastIndex) / 2;							// Compute the middle index

	if (firstIndex == lastIndex)										// If the arr has only one element return case from recursion
	{
		return arr;
	}

	mergeSort( arr, 0, middle );										// Call mergeSort recursively for the left half and right half of array until it is
	mergeSort( arr, (middle + 1), lastIndex );							// broken up into one element arrays

	return merge(arr, firstIndex, lastIndex);							// Merge the arrays that were previously broken up
}

template <class T>
T *MergeSort<T>::merge(T arr[], int firstIndex, int lastIndex)
{
	T mergedArray[10000];												// Temporary array for holding the merged values
	int middle = (firstIndex + lastIndex) / 2;							// Compute the middle index
	int i = firstIndex;													// First index for "left array" which is actually just the left side of one array
	int k = middle + 1;													// First index for "right array"
	int j = firstIndex;													// First index for the merged array

	while ( (i <= middle) && (k <= lastIndex) )							// While both arrays still have elements left 
	{
		
		if (arr[i] < arr[k])											// If the left array has the smaller first value, then move it to merged array. Next increment the
		{																// indices as to "erase" that element from the array and move the merged array to the next index
			mergedArray[j] = arr[i];
			j++;
			i++;
		}
		else
		{
			mergedArray[j] = arr[k];
			j++;
			k++;
		}
	}
	
	while ( i <= middle )												// If only left array has elements left, then continuously fill those elements 
	{																	// into the merged array until there are none left
		mergedArray[j] = arr[i];
		j++;
		i++;
	}

	while ( k <= lastIndex )											// If only right array has elements left, then continuously fill those elements 
	{																	// into the merged array until there are none left
		mergedArray[j] = arr[k];
		j++;
		k++;
	}

	for (int m = firstIndex; m <= lastIndex; m++)						// Copy elements from the temporary merged array back to the main array. We can't return the temp 
	{																	// array because it is stored on the stack and it will be destroyed on the function returns.
		arr[m] = mergedArray[m];										// Therefore the memory location being referenced will be invalid.
	}

	return arr;
}