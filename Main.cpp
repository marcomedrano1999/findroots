/*
Programa para calcular las raices reales de un polinomio de la forma: 
					aX^3 + bX^2 + cX + d = 0
mediante el método general.
*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double calcular_q(double a, double b) {
	/*
	
	*/
	return (pow(a, 2) - (3 * b)) / 9;
}


double calcular_r(double a, double b, double c) {
	/*
	Entradas:
	
	Salida:
	q - valor para calcular el discriminante.
	*/
	double numerador = (2 * pow(a, 3)) - (9 * a*b) + (27 * c);
	return numerador / 54;
}

double calcular_discriminante(double q, double r) {
	return (pow(q, 3) - pow(r, 2));
}

double sgn(double num) {
	if (num > 0)
		return 1;
	if (num == 0)
		return 0;
	return -1;
}


int main(int argc, char *argv[]) {
	if (argc != 5)
	{
		cout << "Numero de argumentos incorrecto." << endl;
		return -1;
	}
	
	double a = atof(argv[1]);
	if (a==0)
	{
		cout << "Error en los datos ingresados." << endl;
		return -1;
	}
	double b = atof(argv[2]);
	double c = atof(argv[3]);
	double d = atof(argv[4]);
	const double PI = 2 * acos(0.0);


	double q = calcular_q(b/a, c/a);
	double r = calcular_r(b/a, c/a, d/a);
	double discr = calcular_discriminante(q, r);
	double phi;
	
	double X1, X2, X3;
	cout << fixed << setprecision(5);
	if (discr > 0)
	{
		phi = (1.0 / 3.0) * acos(r / pow(q, 1.5));
		X1 = (-2 * pow(q, 0.5) * cos(phi)) - ((b / a) / 3.0);
		X2 = (-2 * pow(q, 0.5) * cos(phi + ((2.0/3.0)* PI ))) - ((b / a) / 3);
		X3 = (-2 * pow(q, 0.5) * cos(phi - ((2.0 / 3.0)* PI ))) - ((b / a) / 3);
		cout << "{ " << X1 << ", " << X2 << ", " << X3 << "}";
		return 0;
	}

	if (discr == 0) {
		X1 = (-2 * pow(r, 1.0 / 3.0)) - (a / (b * 3));
		X2 = pow(r, 1.0 / 3.0) - (a / (b * 3));
		cout << "{ " << X1 << "}" << endl;
	}

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
