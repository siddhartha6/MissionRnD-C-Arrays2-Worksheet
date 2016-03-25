/*
OVERVIEW: You are given 2 bank statements that are ordered by date. 
Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.


ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {

	if (A == NULL || B == NULL)
		return NULL;
	int A_index = 0, res = 0, res_index = 0, B_index = 0, date_index = 0, flag = 0;

	struct transaction *result = (struct transaction *)malloc(sizeof(struct transaction)*(ALen + BLen));

    //comparing each transaction in one array with each transaction in other array
	for (A_index = 0; A_index < ALen; A_index++){

		for (B_index = 0; B_index < BLen; B_index++)
		{
			for (date_index = 0; date_index < 10; date_index++)
			{
				if (A[A_index].date[date_index] == B[B_index].date[date_index])
				{
					res = 1;
				}
				else{
					res = 0;
					break;
				}
			}
			if (res == 1)
			{
				result[res_index] = A[A_index];
				++res_index;
				flag = 1;
			}
		}
	}

	if (flag != 1)
		 return NULL;

	return result;
}

