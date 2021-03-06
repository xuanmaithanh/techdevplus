// CodingChallenge_Dec_2017.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

typedef struct
{
	int m_integer1;
	float m_float;
	bool m_bool;
	int m_integer2;
	char m_char;
	char* m_string;
	/*
	int m_integer1;
	float m_float;
	char* m_string;
	int m_integer2;
	char m_char2;
	bool m_bool;
	*/

} Packing;

void testSizePacking()
{
	cout << "Size of Packing struct===" << sizeof(Packing);
}

float doRoundFoatAfterComma(float _number, int _n_AfterComma)
{
	double _number_adjust = _number * pow(10, _n_AfterComma);
	long _number_adjust_rounded = long(_number_adjust);
	return _number_adjust_rounded / (pow(10, _n_AfterComma));
}

int doFindTheIntersectBetweenCircle_And_StraightLine()
{
	int X0, Y0, A, B, R;
	cout << "Input the coordinate of center of circle : (X0, Y0), radius of circle (R), and paramater (A, B) of equation of straight-line";
	cout << "\nInput following the order : X0 Y0 R A B : ";
	cin >> X0 >> Y0 >> R >> A >> B;
	if (R <= 0)
	{
		//Wrong input for R since R has to > 0
		return -1;
	}
	// The equation of circle : (x - X0)^2 + (y - Y0)^2 = R^2 (1)
	// Replace y = A*x + B to (1) to have quadratic equation
	// (x - X0)^2 + (A*x + B - Y0)^2 = R^2   ---> is same to
	// x^2*(1 + A^2) + x*(2*A*Y0 - 2*X0 - 2*A*B) + (X0^2 + B^2 + Y0^2 - 2*B*Y0 - R^2) = 0
	// Let's replace m_coefficient_x_2 = 1 + A^2, m_coefficient_x_1 = 2*A*Y0 - 2*X0 - 2*A*B, m_coefficient = X0^2 + B^2 + Y0^2 - 2*B*Y0 - R^2

	long m_coefficient_x_2 = 1 + A * A;
	int m_coefficient_x_1 = 2 * A*Y0 - 2 * X0 - 2 * A*B;
	long m_coefficient = X0 * X0 + B * B + Y0 * Y0 - 2 * B*Y0 - R * R;

	//Check how to solve quadratic equation from: https://en.wikipedia.org/wiki/Quadratic_equation
	//Check m_coefficient_x_1*m_coefficient_x_1 - 4*m_coefficient_x_2*m_coefficient
	long m_delta_coefficient = m_coefficient_x_1 * m_coefficient_x_1 - 4 * m_coefficient_x_2*m_coefficient;
	if (m_delta_coefficient < 0)
	{
		cout << "\nNO";
	}
	else if (m_delta_coefficient == 0)
	{
		float m_x_intersect = doRoundFoatAfterComma((-m_coefficient_x_1) / (2 * m_coefficient_x_2), 3);
		float m_y_intersect = doRoundFoatAfterComma(A*m_x_intersect + B, 3);
		cout << "\nYES";
		cout << "\n(" << m_x_intersect << "," << m_y_intersect << ")";
	}
	else
	{
		float m_delta_coefficient_SQRT = sqrt(m_delta_coefficient);
		float m_x1_intersect = doRoundFoatAfterComma((-m_coefficient_x_1 + m_delta_coefficient_SQRT) / (2 * m_coefficient_x_2), 3);
		float m_y1_intersect = doRoundFoatAfterComma(A*m_x1_intersect + B, 3);
		float m_x2_intersect = doRoundFoatAfterComma((-m_coefficient_x_1 - m_delta_coefficient_SQRT) / (2 * m_coefficient_x_2), 3);
		float m_y2_intersect = doRoundFoatAfterComma(A*m_x2_intersect + B, 3);
		cout << "\nYES";
		if (m_x1_intersect < m_x2_intersect)
		{
			cout << "\n(" << m_x1_intersect << "," << m_y1_intersect << ")";
			cout << "(" << m_x2_intersect << "," << m_y2_intersect << ")";
		}
		else if (m_x1_intersect > m_x2_intersect)
		{
			cout << "\n(" << m_x2_intersect << "," << m_y2_intersect << ")";
			cout << "(" << m_x1_intersect << "," << m_y1_intersect << ")";
		}
		else
		{
			if (m_y1_intersect < m_y2_intersect)
			{
				cout << "\n(" << m_x1_intersect << "," << m_y1_intersect << ")";
				cout << "(" << m_x2_intersect << "," << m_y2_intersect << ")";
			}
			else
			{
				cout << "\n(" << m_x2_intersect << "," << m_y2_intersect << ")";
				cout << "(" << m_x1_intersect << "," << m_y1_intersect << ")";
			}
		}

	}
	return 0;

}

int main()
{
	//doFindTheIntersectBetweenCircle_And_StraightLine();
	testSizePacking();
	cout << "\n";
	system("pause");
	return 0;
}



