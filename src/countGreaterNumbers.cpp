/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
        

	int index1 = 0, index2 = 0, count = 0;

	for (index1 = 0; index1<len; index1++)
	{
		int year1 = 0, year2 = 0, dd1 = 0, dd2 = 0, mm1 = 0, mm2 = 0;
		for (index2 = 6; date[index2] != '\0'; index2++)
		{                                             //converting string part of year to int
			year1 = year1 * 10 + Arr[index1].date[index2] - '0';
			year2 = year2 * 10 + date[index2] - '0';
		}
		if (year1>year2)                    //if given input year is lesser than than transaction then increment count
			count++;
		if (year1 == year2)
		{
			for (index2 = 3; date[index2] != '-'; index2++)
			{                                      //converting string part of month to int
				mm1 = mm1 * 10 + Arr[index1].date[index2] - '0';
				mm2 = mm2 * 10 + date[index2] - '0';
			}

			if (mm1>mm2)
				count++;
			if (mm1 == mm2)
			{
				for (index2 = 0; date[index2] != '-'; index2++)
				{                                               //converting string part of day to int
					dd1 = dd1 * 10 + Arr[index1].date[index2] - '0';
					dd2 = dd2 * 10 + date[index2] - '0';
				}

				if (dd1>dd2)
					count++;
			}
		}
	}
	return count;
}
