/*
Program that calculates the real roots of the cubic ecuation in the following form: 
					aX^3 + bX^2 + cX + d = 0
using the Vieta's trigonometric formula
*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double calculate_q(double a, double b) {
	/*
	Inputs:
	The coefficients of the cubic ecuation in the following form:
					X^3 + aX^2 + bX + c = 0
	Output:
	The 'q' element in the Vieta's method, defined by:
					q = ( a^2 - 3b) / 9
	*/
	return (pow(a, 2) - (3 * b)) / 9;
}


double calculate_r(double a, double b, double c) {
	/*
	Inputs:
	The coefficients of the cubic ecuation in the following form:
					X^3 + aX^2 + bX + c = 0
	Output:
	The 'r' element in the Vieta's method, defined by:
					r = ( 2a^3 - 9ab + 27c) / 54
	*/
	double numerator = (2 * pow(a, 3)) - (9 * a*b) + (27 * c);
	return numerator / 54;
}

double calcular_discriminante(double q, double r) {
	/*
	Inputs:
	The 'q' and 'r' elements in the Vieta's method.
	Output:
	The discriminant element in the Vieta's method, defined by:
				 S = q^3 - r^2
	*/
	return (pow(q, 3) - pow(r, 2));
}

double sgn(double num) {
	/*
	Sign function.
	input:
	A real number 'num'.
	Output:
	The sign of the number 'num'
	*/
	if (num > 0)
		return 1;
	if (num == 0)
		return 0;
	return -1;
}


int main(int argc, char *argv[]) {
	
	//If the number of arguments is different from five (the program name and the four
	//coefficients), the program returns cero roots
	if (argc != 5)
	{
		cout << "{}" << endl;
		return -1;
	}
	
	//We convert the coefficients to double
	//If the coefficient 'a' is equal to cero, the program returns cero roots
	double a = atof(argv[1]);
	if (a==0)
	{
		cout << "{}" << endl;
		return -1;
	}
	double b = atof(argv[2]);
	double c = atof(argv[3]);
	double d = atof(argv[4]);
	const double PI = 2 * acos(0.0);

	//We calculate the elements needed in the Vieta's method
	double q = calculate_q(b/a, c/a);
	double r = calculate_r(b/a, c/a, d/a);
	double discr = calcular_discriminante(q, r);
	double phi;
	
	double X1, X2, X3;
	cout << fixed << setprecision(5);

	//The discriminant tells us which formula we need to apply

	//Three different real roots
	if (discr > 0)
	{
		phi = (1.0 / 3.0) * acos(r / pow(q, 1.5));
		X1 = (-2 * pow(q, 0.5) * cos(phi)) - ((b / a) / 3.0);
		X2 = (-2 * pow(q, 0.5) * cos(phi + ((2.0/3.0)* PI ))) - ((b / a) / 3);
		X3 = (-2 * pow(q, 0.5) * cos(phi - ((2.0 / 3.0)* PI ))) - ((b / a) / 3);
		cout << "{ " << X1 << ", " << X2 << ", " << X3 << "}";
		return 0;
	}

	//Two real roots (the second one is repeated)
	if (discr == 0) {
		X1 = (-2 * pow(r, 1.0 / 3.0)) - (a / (b * 3));
		X2 = pow(r, 1.0 / 3.0) - (a / (b * 3));
		cout << "{ " << X1 << ", " << X2 << ", " << X2 << "}" << endl;
	}

	//One real root
	else {
		if (q > 0)
		{
			phi = (1.0 / 3.0)*acosh(abs(r) / pow(q, 3.0 / 2.0));
			X1 = (-2 * sgn(r) * pow(q, 0.5)*cosh(phi)) - (b / (a * 3));
			cout << "{ " << X1 << "}" << endl;
		}
		if (q == 0) {
			X1 = (-1 * pow((d / a) - (pow((b/a), 3) / 3), 1.0 / 3.0)) - (b / (a * 3));
			cout << "{ " << X1 << "}" << endl;
		}
		if (q < 0) {
			phi = (1.0 / 3.0)*asinh(abs(r) / pow(abs(q), 3.0 / 2.0));
			X1 = (-2 * sgn(r) * pow(abs(q), 0.5)*sinh(phi)) - (b / (a * 3));
			cout << "{ " << X1 << "}" << endl;
		}
	}
	return 0;
}
