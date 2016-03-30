/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
There are better ways of solving the problem than a brute-force solution which is of O(n^2)
complexity .
*/
#include<stdlib.h>
#include<stdio.h>

//quicksort
void quicksort(int *A, int first, int last){
	int pivot=0, index1=0, temp=0, index2=0;

	if (first<last){
		pivot = first;
		index1 = first;
		index2 = last;

		while (index1 < index2){
			while (A[index1] <= A[pivot] && index1<last)
				index1++;
			while (A[index2]>A[pivot])
				index2--;
			if (index1<index2){
				temp = A[index1];
				A[index1] = A[index2];
				A[index2] = temp;
			}
		}

		temp = A[pivot];
		A[pivot] = A[index2];
		A[index2] = temp;
		quicksort(A, first, index2 - 1);
		quicksort(A, index2 + 1, last);

	}
}
int findSingleOccurenceNumber(int *A, int len) {
	if (A == NULL)
		return -1;
	int index = 0, result = 0, sum = 0;

	quicksort(A, 0, len - 1);

	while (index < len)
	{
		if (index == len - 1){    //if single occurance element is last element
			result = A[len - 1];
			break;
		}
		sum = A[index] + A[index + 1] + A[index + 2];  //sum of 1st 3 array numbers

		if (sum % 3 == 0)     //if sum is divisible by 3 but if their is single occurance element(2 2 2 3 6 6 6)
		{
			if (A[index] != A[index + 1]){
				result = A[index];
				break;
			}
		}

		if (sum % 3 != 0){ //is sum not divisible by 3 finding single occurance element
			if (A[index] != A[index + 1]){
				result = A[index];
				break;
			}
		}
		index = index + 3; //incrementing array with 3 positions if 3 consecutive elements are equal

	}
	return result;
}
