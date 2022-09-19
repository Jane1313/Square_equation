#include <stdio.h>
#include <assert.h>
#include <math.h>

int Solve_square (double a, double b, double c, double* x1, double* x2);
int Solve_linear (double a, double b, double* x);

int main()
{
	printf ("Hello! It's a solver of square equation!\n");
	printf ("Please, enter the coefficients a, b, c: ");

	double a = NAN, b = NAN, c = NAN, x1 = NAN, x2 = NAN;
	scanf ("%lg%lg%lg", &a, &b, &c);
	assert (isfinite (a) != 0 && isfinite (b) != 0 && isfinite (c) != 0);

	int number_solutions = Solve_square (a, b, c, &x1, &x2);

	if (number_solutions > 2)
		printf ("Infinitely many solutions\n");
	else if (number_solutions < 1)
		printf ("No solutions\n");
	else if (number_solutions == 1)
		printf ("x1 = x2 = %lg\n", x1);
	else
		printf ("x1 = %lg; x2 = %lg\n", x1, x2);

	return 0;
}

int Solve_square (double a, double b, double c, double* x1, double* x2)
{
	assert (x1 != x2);

	if (a == 0)
		return Solve_linear (b, c, x1);

	if (c == 0)
	{
		*x1 = 0;
		if (b == 0)
			return 1;
		else
		{
			Solve_linear (a, b, x2);
			return 2;
		}
	}

	double d = b*b - 4*a*c;

	if (d < 0)
		return 0;

	if (d == 0)
	{
		*x1 = (-b) / (2*a);
		return 1;
	}

	*x1 = (-b - sqrt(d)) / (2*a);
	*x2 = (-b + sqrt(d)) / (2*a);

	return 2;
}

int Solve_linear (double a, double b, double* x)
{
	if (a == 0)
		if (b == 0)
			return 3;
		else
			return 0;
	else
	{
		*x = -b / a;
		return 1;
	}
}