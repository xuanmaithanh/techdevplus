// Jan_2018.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

bool isPrime(int _number)
{
	if (_number < 2) return false;
	for (int j = _number / 2; j >= 2; j--)
	{
		if (_number % j == 0) return false;
	}
	return true;
}

void main()
{
	bool isRunning = true;
	while (isRunning)
	{
		unsigned int N;
		cout << "Input an Integer (>= 0): \n";
		cin >> N;
		if (N < 0) isRunning = false;
		int i = N / 2;
		for (; i >= 2; i--)
		{
			if ((N % i == 0) & isPrime(i)) break;
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
	}
	cout << "\n";
	system("pause");
}


