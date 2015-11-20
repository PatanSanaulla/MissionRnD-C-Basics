/*
OVERVIEW:  Given 2 integers (num1, num2), write a function that returns the count of numbers between the num1..num2 that are divisible by num1.
		E.g.: count(3, 15) returns 5 (3, 6, 9, 12, 15).

INPUTS:  Two numbers num1, num2.
		num1, num2 >= 0.

OUTPUT: Return the count of numbers between the num1..num2 that are divisible by num1.

ERROR CASES: Return -1 in error cases.

NOTES:
*/
int count(int num1, int num2) {
	int c = 0,num=num1;
	if (num1 == 0){ return -1; }
	else
		if (num1 == 1){ return num2;}
		else
		if (num2 == 0 || num2 ==1 || num1>num2) {return 0;}
		else{
			while (num <= num2)
			{
				num = num + num1;
				++c;
			}
			return c;
		}
}