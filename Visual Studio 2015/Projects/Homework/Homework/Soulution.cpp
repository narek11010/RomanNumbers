#include <iostream>
#include <math.h>

using namespace std;

#define one 'I'
#define five 'V'
#define ten 'X'
#define fifty 'L'
#define hundred 'C'
#define fivehundred 'D'
#define thousand 'M'


void print(int curr, int lenght)
{

	char point;
	char fivepoint;
	char tenpoint;

	if (lenght == 1)
	{
		point = one;
		fivepoint = five;
		tenpoint = ten;
	}
	else if (lenght == 2)
	{
		point = ten;
		fivepoint = fifty;
		tenpoint = hundred;
	}
	else if (lenght == 3)
	{
		point = hundred;
		fivepoint = fivehundred;
		tenpoint = thousand;
	}


	if (curr < 4)
	{
		for (int i = 0; i < curr; ++i)
		{
			cout << point;
		}
	}
	else if (curr == 4)
	{
		cout << point << fivepoint;
	}
	else if (curr > 4 && curr < 9)
	{
		cout << fivepoint;

		for (int i = 1; i <= curr - 5; ++i)
		{
			cout << point;
		}

	}
	else if (curr == 9)
	{
		cout << point << tenpoint;
	}
}

void int_to_roman(int x, int lenght)
{
	if (lenght == 4)
	{
		int curr = x / 1000;

		for (int i = 0; i < curr; ++i)
		{
			cout << thousand;
		}
		int_to_roman(x - curr * 1000, lenght - 1);
	}
	else if (lenght == 3)
	{
		int curr = x / 100;
		print(curr, lenght);
		int_to_roman(x - curr * 100, lenght - 1);
	}
	else if (lenght == 2)
	{
		int curr = x / 10;
		print(curr, lenght);
		int_to_roman(x - curr * 10, lenght - 1);
	}
	else if (lenght == 1)
	{
		int curr = x;
		print(curr, lenght);
	}

	return;
}

int main()
{
	//while (true)
	//{
		cout << "Please enter number between 1 and 3999 \n";
		int x;
		cin >> x;

		if (x > 3999)
		{
			cout << "Please type number between 1 and 3999 \n";
			return 0;
		}

		int lenght = 1;

		if (x > 9 && x < 100)
		{
			++lenght;
		}
		else if (x > 99 && x < 1000)
		{
			lenght += 2;
		}
		else if (x > 999 && x < 4000)
		{
			lenght += 3;
		}

		int_to_roman(x, lenght);

		cout << "\n";
//	}
}