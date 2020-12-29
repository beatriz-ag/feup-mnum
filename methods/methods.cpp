// methods.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
using namespace std;

#define erro 0.000001

/*functions*/

double f(double x) { return x; }
double dfdx(double x) { return 1; }
double g(double x, double y) { return x; }
double g1(double x, double y) { return x * y; }
double dg1dx(double x, double y) { return 1 + y; }
double dg1dy(double x, double y) { return 1 + x; }
double g2(double x, double y) { return x * y; }
double dg2dx(double x, double y) { return 1 + y; }
double dg2dy(double x, double y) { return 1 + x; }
double recorr_x(double x, double y, double z) { return x; }
double recorr_y(double x, double y, double z) { return x; }
double recorr_z(double x, double y, double z) { return x; }
double u(double x, double y, double z) { return x + y + z; }
double dudx(double x, double y, double z) { return 1 + y + z; }
double dudy(double x, double y, double z) { return 1 + x + z; }
double dudz(double x, double y, double z) { return 1 + x + y; }
double H1(double x, double y) { return x; }
double H2(double x, double y) { return x; }
double H3(double x, double y) { return x; }
double H4(double x, double y) { return x; }


/*Root solving algorithms ~Real function & Real root*/

/*Method:
 * 1. Representar função no máxima
 * 2. Verificar o nr de raízes
 * 3. Isolar cada uma das raízes == definir um intervalo each
 * 4. Implementar o método
 * 5. Critério de paragem
 */

void Bissection(double x0, double xf) {
	double w;
	do {
		w = (x0 + xf) / 2;
		(f(x0) * f(w) < 0) ? xf = w : x0 = w;
	} while (abs(xf - x0) > erro);
	cout << "\nBissection real root: " << xf << endl;
}

void Rope(double x0, double xf) {
	double w;
	do {
		w = (x0 * f(xf) - xf * f(x0)) / (f(xf) - f(x0));

		(f(x0) * f(w) < 0) ? xf = w : x0 = w;

	} while (abs(xf - x0) > erro);

	cout << "\Rope real root: " << xf << endl;
}

/*Method:
 * 1. Representar função no máxima
 * 2. Verificar o nr de raízes
 * 3. Isolar cada uma das raízes == definir um "guess"
 * 4. Implementar o método
 * 5. Critério de paragem
 */
void Newton(double x0) {
	double xn1 = x0;
	do {
		x0 = xn1;
		/*
		* dfdx(x) can't be zero
		* if (dfdx(x0) == 0) break;
		*/
		xn1 -= f(x0) / dfdx(x0);
	} while (abs(xn1 - x0) > erro);

	cout << "\Newton real root: " << xn1 << endl;
}

/*Method:
 * 1. Representar função no máxima
 * 2. Verificar o nr de raízes
 * 3. Isolar cada uma das raízes == definir um "guess"
 * 4. Definir uma função G(x) = x
 * 5. Se G'(guess) > 1 ---> procurar outra função
 * Aplicar o método
 */
void PicardPeano(double x0) {
	double xn1 = x0;
	do {
		x0 = xn1;
		xn1 = f(x0);

	} while (abs(xn1 - x0) > erro);

	cout << "\PicardPeano real root: " << xn1 << endl;

}

/* equations system*/

void Newton_system(double xn, double yn) {
	double xn1 = xn, yn1 = yn, j;
	do {
		xn = xn1; yn = yn1;
		j = dg1dx(xn, yn) * dg2dy(xn, yn) - dg2dx(xn, yn) * dg1dy(xn, yn);
		xn1 -= (g1(xn, yn) * dg2dy(xn, yn) - g2(xn, yn) * dg1dy(xn, yn)) / j;
		yn1 -= (g2(xn, yn) * dg1dx(xn, yn) - g1(xn, yn) * dg2dx(xn, yn)) / j;

	} while (abs(xn1 - xn) > erro || abs(yn1 - yn) > erro);

	cout << "Newton system real root: P(" << xn1 << "," << yn1 << ")\n";
}

/*
Encontrar G1(x, y) && G2(x, y) tal que | dxG1 | < 1 && | dyG1 | < 1 && | dxG2 | < 1 && | dyG2 | < 1
*/
void PicardPeano_system(double xn, double yn) {
	double xn1 = xn, yn1 = yn;
	do {
		xn = xn1; yn = yn1;
		xn1 = g1(xn, yn);
		yn1 = g2(xn, yn);
	} while (abs(xn1 - xn) > erro || abs(yn1 - yn) > erro);

	cout << "PPeano system real root: P(" << xn1 << "," << yn1 << ")\n";
}

/*linear equations system*/

void Gauss() {
	cout << "\nGauss: Done in Maxima ~~Step by step in pag.92\n";
	cout << "1.load(linearalgebra);\n2.A:matrix([...],...);\n3.A:echelon(A);\n4.A:rowop(A,y,x,value);\n5.Repeat\n";
}

void Cholesky() {
	cout << "\nCholesky: Done in Maxima ~~Thank you Villate\n";
	cout << "1.load(linearalgebra);\n2.A:matrix([...],...);\n3.[P,L,U]:get_lu_factors(lu_factor(transpose(A)));"
		<< "4.B: transpose(U);\n5.C:transpose(L);\n6.y: invert(B).matrix(b);\n7.x:invert(C).y;\n";
}

/*
Define recorrence formulas
*/
void Gauss_sideil(double xn, double yn, double zn) {
	double xn1 = xn, yn1 = yn, zn1 = zn;
	do {
		xn = xn1; yn = yn1; zn = zn1;
		xn1 = recorr_x(xn, yn, zn);
		yn1 = recorr_y(xn1, yn, zn);
		zn1 = recorr_z(xn1, yn1, zn);
	} while (abs(xn1 - xn) > erro | abs(yn1 - yn) > erro | abs(zn1 - zn) > erro);

	cout << "Gauss-sidel root: P(" << xn1 << "," << yn1 << "," << zn1 << ")\n";
}

void Gauss_Jacobi(double xn, double yn, double zn) {
	double xn1 = xn, yn1 = yn, zn1 = zn;
	do {
		xn = xn1; yn = yn1; zn = zn1;
		xn1 = recorr_x(xn, yn, zn);
		yn1 = recorr_y(xn, yn, zn);
		zn1 = recorr_z(xn, yn, zn);
	} while (abs(xn1 - xn) > erro | abs(yn1 - yn) > erro | abs(zn1 - zn) > erro);

	cout << "Gauss-Jacobi root: P(" << xn1 << "," << yn1 << "," << zn1 << ")\n";
}

/*Integration*/

/*Quadrature*/

void Trapezium(double x0, double xf, double h) {
	int n = (xf - x0) / h;
	double sum = f(x0) + f(xf);
	for (int i = 1; i < n; i++) {
		x0 += h;
		sum += 2 * f(x0);
	}
	sum *= h / 2;
	cout << "Trampezium integral sol: " << sum << endl;
}

void Simpson(double x0, double xf, double h) {
	int n = (xf - x0) / h;
	double sum = f(x0) + f(xf);
	for (int i = 1; i < n; i++) {
		if (i % 2)
			sum += 4 * f(x0);
		else
			sum += 2 * f(x0);
	}
	sum *= h / 3;
	cout << "Simpson integral sol: " << sum << endl;

}

/*Cubature*/

void Trapezium_cub(double x0, double xf, double y0, double yf, double h) {
	double hx = (xf - x0) / 2;
	double hy = (yf - y0) / 2;
	double sum_vert = g(x0, y0) + g(x0, yf) + g(xf, y0) + g(xf, yf);
	double sum_mid = g(x0 + hx, y0) + g(x0 + hx, yf) + g(xf, y0 + hy) + g(x0, yf + hy);
	double center = g(x0 + hx, y0 + hy);
	double integral = (sum_vert + 4 * sum_mid + 4 * center) * (hx * hy) / 9;

	cout << "\nTrampezium cubature integral sol: " << integral << endl;

}

void Simpason_cub(double x0, double xf, double y0, double yf, double h) {
	double hx = (xf - x0) / 2;
	double hy = (yf - y0) / 2;
	double sum_vert = g(x0, y0) + g(x0, yf) + g(xf, y0) + g(xf, yf);
	double sum_mid = g(x0 + hx, y0) + g(x0 + hx, yf) + g(xf, y0 + hy) + g(x0, yf + hy);
	double center = g(x0 + hx, y0 + hy);
	double integral = (sum_vert + 4 * sum_mid + 16 * center) * (hx * hy) / 4;

	cout << "\n Simpson cubature integral sol: " << integral << endl;

}

/*EDO's*/

double Euler(double x0, double xf, double y, double h) {
	do {
		y += h * dg1dy(x0, y);
		x0 += h;
	} while (abs(xf - x0) > erro);
	return y;

	cout << "\nEuler y: " << y << endl;
}

double RK2(double x0, double xf, double y, double h) {
	do {
		y += h * dg1dy(x0 + h / 2, y + h / 2 * dg1dy(x0, y));
		x0 += h;
	} while (abs(xf - x0) > erro);
	cout << "\RK2 y: " << y << endl;

	return y;
}

double RK4(double x0, double xf, double y, double h) {
	double y1, y2, y3, y4;
	do {
		y1 = h * dg1dy(x0, y);
		y2 = h * dg1dy(x0 + h / 2, y + y1 / 2);
		y3 = h * dg1dy(x0 + h / 2, y + y2 / 2);
		y4 = h * dg1dy(x0 + h, y + y3);
		y = (y1 / 6 + y2 / 3 + y3 / 3 + y4 / 6);
		x0 += h;
	} while (abs(xf - x0) > erro);
	cout << "\RK4 y: " << y << endl;

	return y;
}

double QC_erro(double x0, double xf, double y, double h, char f)
{
	double S, S1, S2, QC, error;
	switch (f) {
	case 'e':
		S = Euler(x0, xf, y, h);
		S1 = Euler(x0, xf, y, h / 2);
		S2 = Euler(x0, xf, y, h / 4);
		error = (S2 - S1) / 2;
		break;
	case '2':
		S = RK2(x0, xf, y, h);
		S1 = RK2(x0, xf, y, h / 2);
		S2 = RK2(x0, xf, y, h / 4);
		error = (S2 - S1) / 3;
		break;
	case '4':
		S = RK4(x0, xf, y, h);
		S1 = RK4(x0, xf, y, h / 2);
		S2 = RK4(x0, xf, y, h / 4);
		error = (S2 - S1) / 15;
		break;
	}
	QC = (S1 - S) / (S2 - S1);
	cout << " QC: " << QC << endl;
	cout << "error: " << error << endl;
}

/*EDO's 3var */

double Euler_sys(double x0, double xf, double y, double z, double h, char yz) {
	double yn1 = y, zn1 = z;
	do {
		y = yn1; z = zn1;
		yn1 += h * dudy(x0, y, z);
		zn1 += h * dudz(x0, y, z);
		x0 += h;
	} while (abs(xf - x0) > erro);

	cout << "\nEuler y: " << y << " z: " << z << endl;

	if (yz == 'y')
		return yn1;
	else if (yz == 'z')
		return zn1;
}

double RK2_sys(double x0, double xf, double y, double z, double h, char yz) {
	double yn1 = y, zn1 = z;
	do {
		y = yn1; z = zn1;
		yn1 += h * dudy(x0 + h / 2, y + (h / 2) * dudy(x0, y, z), z + (h / 2) * dudz(x0, y, z));
		zn1 += h * dudz(x0 + h / 2, y + (h / 2) * dudy(x0, y, z), z + (h / 2) * dudz(x0, y, z));
		x0 += h;
	} while (abs(xf - x0) > erro);

	cout << "\nEuler y: " << y << " z: " << z << endl;

	if (yz == 'y')
		return yn1;
	else if (yz == 'z')
		return zn1;
}

double RK4_sys(double x0, double xf, double y, double z, double h, char yz) {
	double y1, y2, y3, y4, z1, z2, z3, z4;
	do {
		y1 = h * dudy(x0, y, z);
		z1 = h * dudz(x0, y, z);
		y2 = h * dudy(x0 + h / 2, y + y1 / 2, z + z1 / 2);
		z2 = h * dudz(x0 + h / 2, y + y1 / 2, z + z1 / 2);
		y3 = h * dudy(x0 + h / 2, y + y2 / 2, z + z2 / 2);
		z3 = h * dudz(x0 + h / 2, y + y2 / 2, z + z2 / 2);
		y4 = h * dudy(x0 + h, y + y3, z + z3);
		z4 = h * dudz(x0 + h, y + y3, z + z3);
		x0 += h;
		y += y1 / 6 + y2 / 3 + y3 / 3 + y4 / 6;
		z += z1 / 6 + z2 / 3 + z3 / 3 + z4 / 6;

	} while (abs(xf - x0) > erro);

	cout << "\nEuler y: " << y << " z: " << z << endl;

	if (yz == 'y')
		return y;
	else if (yz == 'z')
		return z;
}

double QC_erro_sys(double x0, double xf, double y, double z, double h, char f)
{
	double Sy, S1y, S2y, Sz, S1z, S2z, QCy, QCz, errory, errorz;
	switch (f) {
	case 'e':
		Sy = Euler_sys(x0, xf, y, z, h, 'y');
		S1y = Euler_sys(x0, xf, y, z, h / 2, 'y');
		S2y = Euler_sys(x0, xf, y, z, h / 4, 'y');
		Sz = Euler_sys(x0, xf, y, z, h, 'z');
		S1z = Euler_sys(x0, xf, y, z, h / 2, 'z');
		S2z = Euler_sys(x0, xf, y, z, h / 4, 'z');

		errory = (S2y - S1y) / 2;
		errorz = (S2z - S1z) / 2;

		break;
	case '2':
		Sy = RK2_sys(x0, xf, y, z, h, 'y');
		S1y = RK2_sys(x0, xf, y, z, h / 2, 'y');
		S2y = RK2_sys(x0, xf, y, z, h / 4, 'y');
		Sz = RK2_sys(x0, xf, y, z, h, 'z');
		S1z = RK2_sys(x0, xf, y, z, h / 2, 'z');
		S2z = RK2_sys(x0, xf, y, z, h / 4, 'z');

		errory = (S2y - S1y) / 2;
		errorz = (S2z - S1z) / 2;
		break;
	case '4':
		Sy = RK4_sys(x0, xf, y, z, h, 'y');
		S1y = RK4_sys(x0, xf, y, z, h / 2, 'y');
		S2y = RK4_sys(x0, xf, y, z, h / 4, 'y');
		Sz = RK4_sys(x0, xf, y, z, h, 'z');
		S1z = RK4_sys(x0, xf, y, z, h / 2, 'z');
		S2z = RK4_sys(x0, xf, y, z, h / 4, 'z');
		errory = (S2y - S1y) / 2;
		errorz = (S2z - S1z) / 2;
		break;
	}
	QCy = (S1y - Sy) / (S2y - S1y);
	QCz = (S1z - Sz) / (S2z - S1z);

	cout << " QCy: " << QCy << " QCz: " << QCz << endl;
	cout << "errory: " << errory << " errorz: " << errorz << endl;
}

/*Optimization*/

void Aurea(double x1, double x2, bool min) {
	double B = (sqrt(5) - 1) / 2;
	double A = pow(B, 2);
	double x3, x4;

	do {
		x3 = x1 + A * (x2 - x1);
		x4 = x1 + B * (x2 - x1);

		if (min) {
			if (f(x3) < f(x4)) {
				x2 = x4;
				x4 = x3;
			}
			else
			{
				x1 = x3;
				x3 = x4;
			}
		}
		else
		{
			if (f(x3) < f(x4)) {
				x1 = x3;
				x4 = x2;
			}
			else
			{
				x2 = x4;
				x4 = x3;
			}
		}
	} while (abs(x1 - x2) > erro);
	if (min) {
		double min = x1;
		if (x2 < min)
			min = x2;
		else if (x3 < min)
			min = x3;
		else if (x4 < min)
			min = x4;
		cout << "Aurea min: " << min;
	}
	else
	{
		double max = x1;
		if (x2 > min)
			max = x2;
		else if (x3 > min)
			max = x3;
		else if (x4 > min)
			max = x4;
		cout << "Aurea max: " << min;
	}
}

void Gradiente(double xn, double yn, double h) {
	double xn1 = xn, yn1 = yn;
	do {
		xn = xn1; yn = yn1;
		xn1 += h * dg1dx(xn, yn);
		yn1 += h * dg1dy(xn, yn);
		if (g1(xn1, yn1) < g1(xn, yn))
		{
			h *= 2;
			xn = xn1;
			yn = yn1;
		}
		else
			h /= 2;
	} while (abs(xn1 - xn) > erro || abs(yn1 - yn) > erro);
	cout << "Gradiente min: P(" << xn1 << "," << yn1 << ")\n";
}

/*Find inverted hessian matrix in maxima w/ invert(Hessian(f,[x,y]));*/
void LM(double xn, double yn, double h) {
	double xn1 = xn, yn1 = yn;
	do {
		xn = xn1; yn = yn1;
		xn1 -= H1(xn, yn) * dg1dx(xn, yn) + H2(xn, yn) * dg1dy(xn, yn) + h * dg1dx(xn, yn);
		yn1 -= H3(xn, yn) * dg1dx(xn, yn) + H4(xn, yn) * dg1dy(xn, yn) + h * dg1dx(xn, yn);
		if (g1(xn1, yn1) - g1(xn, yn) < 0) {
			h /= 2;
		}
		else
			h *= 2;
	} while (abs(xn1 - xn) > erro || abs(yn1 - yn) > erro);

}


int main()
{
	std::cout << "Hello World!\n";
}

