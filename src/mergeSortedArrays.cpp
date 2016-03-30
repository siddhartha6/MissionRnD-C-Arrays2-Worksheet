/*
OVERVIEW: You are given 2 bank statements that are ordered by date - 
Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include<stdio.h>
struct transaction {
	int amount;
	char date[11];
	char description[20];
};


void str_int(char *date, int *d){

	int index1 = 0, index2 = 0, index3=0;
	d[0] = 0;
	d[1] = 0;
	d[2] = 0;

	for (index1 = index2; date[index1] != '-'; index1++) {
		d[0] = d[0] * 10 + date[index1] - '0';
	}

	for (index2 = index1 + 1; date[index2] != '-'; index2++) {
		d[1] = d[1] * 10 + date[index2] - '0';
	}
	for (index3 = index2 + 1; date[index3] != '\0'; index3++)
		d[2] = d[2] * 10 + date[index3] - '0';

}
struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (A == NULL || B == NULL)
		return NULL;                     //NULL check

	struct transaction *result = (struct transaction *)malloc(sizeof(struct transaction)*(ALen + BLen));
	int index1 = 0, index2 = 0, res_index = 0;
	int date1[3] = { 0, 0, 0 }, date2[3] = { 0, 0, 0 };

	while (index1 < ALen && index2 < BLen)
	{
		str_int(A[index1].date, date1);   //converting string date to integer date
		str_int(B[index2].date, date2);

		if (date1[2] < date2[2]){          //if year1 is less than year2 direct move transaction to result

			result[res_index] = A[index1];
			res_index++;
			index1++;
		}
		else if (date1[2] > date2[2]){    //if year2 is less than year1 direct move transaction to result
 

			result[res_index] = B[index2];
			res_index++;
			index2++;
		}
		else{        //if both the years are equal check months

			if (date1[1] < date2[1]){
				                     //if month of 1st array is less  move transaction to result
				result[res_index] = A[index1];
				res_index++;
				index1++;
			}
			else if (date1[1] > date2[1]){
				                       //if month of 2nd array is less move transaction to result
				result[res_index] = B[index2];
				res_index++;
				index2++;
			}
			else{
				         //if years and months are equal checking day
				if (date1[0] < date2[0]){

					result[res_index] = A[index1];
					res_index++;
					index1++;
				}
				else if (date1[0] > date2[0]){

					result[res_index] = B[index2];
					res_index++;
					index2++;
				}
				else {   //if entire date is equal then move same transactions 2 times
					result[res_index] = A[index1];
					res_index++;
					result[res_index] = B[index2];
					res_index++;
					index1++;
					index2++;
				}

			}
		}

	}
	while (index1 < ALen)          //if BLen traversed completely then moving remaining elements of array A
	{
		result[res_index] = A[index1];
		res_index++;
		index1++;
	}
	while (index2 < BLen)   //if ALen is traversed completely then moving remaining elements of array B
	{
		result[res_index] = B[index2];
		res_index++;
		index2++;
	}

	return result;
}