// Jan_2018.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

bool isPrimeNumber(int _number)
{
	if (_number < 2) return false;

	if (_number == 2) return true;

	if (_number % 2 == 0) return false;

	int n_toCheck = (_number / 3) + 1;
	for (int j = 3; j <= n_toCheck; j = j + 2)
	{
		if (_number % j == 0) return false;
		else n_toCheck = (_number / j) + 1;
	}
	return true;
}

int main()
{
	int N;
	cout << "Input an Integer (>= 0): \n";
	cin >> N;
	if (N < 0) return -1;

	int i = N / 2;
	int countLoop = 1;

	for (; i >= 2; countLoop++)
	{
		if ((N % i == 0) && isPrimeNumber(i)) break;
		i = N / (countLoop + 1);
	}

	if (i > 1)
	{
		cout << i;
	}
	else if (N >= 2)
	{
		cout << N;
	}
	else
	{
		cout << "-1";
	}

	cout << "\n";
	system("pause");
	return 0;
}


