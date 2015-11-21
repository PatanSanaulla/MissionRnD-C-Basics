/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/
int date_eval(char *x);
int mnth_eval(char *x);
int year_eval(char *x);

int isOlder(char *dob1, char *dob2) {
	
	int adt = date_eval(dob1);
	int amn = mnth_eval(dob1);
	int ayr = year_eval(dob1);
	int bdt = date_eval(dob2);
	int bmn = mnth_eval(dob2);
	int byr = year_eval(dob2);
	int adays = 0;
	int bdays = 0;
	if ((ayr>0000 && ayr<9999 && amn <= 12) && (byr>0000 && byr<9999 && bmn <= 12))
	{
		if (amn == 1 || amn == 3 || amn == 5 || amn == 7 || amn == 8 || amn == 10 || amn == 12)
		{
			adays = 31;
		}
		if (bmn == 1 || bmn == 3 || bmn == 5 || bmn == 7 || bmn == 8 || bmn == 10 || bmn == 12)
		{
			bdays = 31;
		}
		if (bmn == 4 || bmn == 6 || bmn == 9 || bmn == 11)
		{
			bdays = 30;
		}
		if (amn == 4 || amn == 6 || amn == 9 ||amn == 11)
		{
			adays = 30;
		}
		if (amn == 2)
		{
			if (ayr % 4 == 0)  { adays = 29; }
			else { adays = 28; }
		}
		if (bmn == 2)
		{
			if (byr % 4 == 0)  { bdays = 29; }
			else { bdays = 28; }
		}
		if (adt>0 && adt <= adays){}
		else
		{
			return -1;
		}
		if (bdt>0 && bdt <= bdays){}
		else
		{
			return -1;
		}
	}
	else { return -1; }

	if (byr < ayr){ return 2; }
		else 
			if (byr > ayr){ return 1; }
			else
				if (ayr == byr && bmn < amn){ return 2; }
				else
					if (ayr == byr && bmn > amn){ return 1; }
					else
						if (ayr == byr && bmn == amn && bdt < adt){ return 2; }
						else
							if (ayr == byr && bmn == amn && bdt > adt){ return 1; }
							else
								if (adt == bdt && amn == bmn && ayr == byr){ return 0; }
								
}

int date_eval(char* x)
{
	int date = (*x - '0') * 10 + (*(x+1) - '0');
	return date;
}
int mnth_eval(char* x)
{
	int mnth = (*(x+3) - '0') * 10 + (*(x+4) - '0');
	return mnth;
}
int year_eval(char* x)
{
	int year = (*(x+6) - '0') * 1000 + (*(x+7) - '0') * 100 + (*(x+8) - '0') * 10 + (*(x+9) - '0');
	return year;
}