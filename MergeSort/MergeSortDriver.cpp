#include <iostream>
#include <vector>
#include "MergeSort.h"
#include "MergeSort.cpp"

using namespace std;

int main()
{
	const int ARRAY_SIZE = 4;
	int tArray[ARRAY_SIZE] = {1, 9, 3, 7};
	vector<double> testArray(tArray, (tArray + (sizeof(tArray) / sizeof(tArray[0]))));

	MergeSort<double> mergeObj;
	vector<double> sortedArray = mergeObj.mergeSort(testArray);

	for (size_t i = 0; i < testArray.size(); i++)
		cout << sortedArray[i] << endl;

	cin.get();
	return 0;
}