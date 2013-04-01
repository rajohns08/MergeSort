#ifndef MERGESORT_H
#define MERGESORT_H

#include <vector>

using namespace std;

template <class T>
class MergeSort													// Class for merge sorting vectors and primitive arrays
{
public:
	vector<T> mergeSort(vector<T> arr);							// Public functions called from outside the class that are responsible for breaking up the array
	T *mergeSort(T arr[], int firstIndex, int lastIndex);		// into single element arrays. One function for vectors, the other for arrays.
private:
	vector<T> merge(vector<T> leftArr, vector<T> rightArr);		// Private functions that are only called from within mergeSort that are responsible for the 
	T *merge(T arr[], int firstIndex, int lastIndex);			// merging of the broken up arrays from mergeSort. One function for vectors, the other for arrays.
};	

#endif