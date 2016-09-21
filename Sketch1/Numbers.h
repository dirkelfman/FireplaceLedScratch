
boolean number1[] =
{
	1,
	1,
	1,
	1,
	1
};

boolean colon[] =
{
	0,
	1,
	0,
	1,
	0
};
boolean number2[] =
{
	1,1,1,
	0,0,1,
	1,1,1,
	1,0,0,
	1,1,1
};

boolean number3[] =
{
	1,1,1,
	0,0,1,
	1,1,1,
	0,0,1,
	1,1,1
};

boolean number4[] =
{
	1,0,1,
	1,0,1,
	1,1,1,
	0,0,1,
	0,0,1
};

boolean number5[] =
{
	1,1,1,
	1,0,0,
	1,1,1,
	0,0,1,
	1,1,1
};

boolean number6[] =
{
	1,1,1,
	1,0,0,
	1,1,1,
	1,0,1,
	1,1,1
};

boolean number7[] =
{
	1,1,1,
	0,0,1,
	0,0,1,
	0,0,1,
	0,0,1
};

boolean number8[] =
{
	1,1,1,
	1,0,1,
	1,1,1,
	1,0,1,
	1,1,1
};
boolean number9[] =
{
	1,1,1,
	1,0,1,
	1,1,1,
	0,0,1,
	0,0,1
};
boolean number0[] =
{
	1,1,1,
	1,0,1,
	1,0,1,
	1,0,1,
	1,1,1
};

boolean* getNumberImage(int num)
{
	switch (num)
	{
	case 1:
		return number1;
	case 2:
		return number2;
	case 3:
		return number3;
	case 4:
		return number4;
	case 5:
		return number5;
	case 6:
		return number6;
	case 7:
		return number7;
	case 8:
		return number8;
	case 9:
		return number9;
	case 0:
		return number0;
	case -1 :
		return colon;


	}
}