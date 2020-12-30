// exams_resolution.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

/*Exame 2019*/

/*Exc 1*/
double f1(double x)
{
    return sin(x) + pow(x, 5) - 0.2 * x + 1;
}
/*Exc 2*/
double g1(double x, double y) {
    return pow(x, 2) - y - 1.2;
}
double dxg1(double x, double y) {
    return 2 * x;
}
double dyg1(double x, double y) {
    return -1;
}
double g2(double x, double y) {
    return -x + pow(y, 2) - 1;
}
double dxg2(double x, double y) {
    return -1;
}
double dyg2(double x, double y) {
    return 2 * y;
}
/*Exc 3*/
double y(double x) {
    double f = 1.5 * exp(1.5 * x);
    return sqrt(1 + pow(f, 2));
}
/*Exc 4*/
double dT(double x0) {
    return -0.25 * (x0 - 59);
}
/*Exc 5*/
double y_(double x) 
{ return -5 * cos(x) + sin(x) + 10; }
/*Exc 6*/
double z(double x, double y) {
    return 3 * pow(x, 2) - x * y + 11 * y + pow(y, 2) - 8 * x;
}
double dzdx(double x, double y) {
    return -y + 6 * x - 8;
}
double dzdy(double x, double y) {
    return 2 * y - x + 11;
}

double Exame_2019_1(double a, double b) {
    double m;
    for (int i = 0; i < 6; i++) {
        m = (a + b) / 2;
        if (f1(a) * f1(m) < 0) {
            b = m;
        }
        else
            a = m;
    }
    return m;
}
double Exame_2019_2(double x0, double y0)
{
    double x, y;
    for (int i = 0; i < 2; i++)
    {
        x = x0;
        y = y0;
        x0 = x - (g1(x, y) * dyg2(x, y) - g2(x, y) * dyg1(x, y)) / (dxg1(x, y) * dyg2(x, y) - dxg2(x, y) * dyg1(x, y));
        y0 = y - (g2(x, y) * dxg1(x, y) - g1(x, y) * dxg2(x, y)) / (dxg1(x, y) * dyg2(x, y) - dxg2(x, y) * dyg1(x, y));

        cout << "x: " << x0 << " y: " << y0 << endl;
    }
    return x;
}
double Exame_2019_3_Trap(double x0, double xf, double h)
{
    int n = (xf - x0) / h;
    double sum = y(x0) + y(xf);
    for (int i = 0; i < n; i++)
    {
        x0 += h;
        sum += 2 * y(x0);
    }
    sum *= h / 2;
    return sum;
}
double Exame_2019_3_Simp(double x0, double xf, double h) {
    int n = (xf - x0) / h;

    double sum = y(x0) + y(2 * xf);
    for (int i = 0; i < 2 * n; i++)
    {
        x0 += h;
        if (i % 2)
        {
            sum += 4 * y(x0);
        }
        else
            sum += 2 * y(x0);
        sum += 2 * y(x0);
    }
    sum *= h / 3;
    return sum;
}
double Exame_2019_4(double x0, double y0, double h) {
    for (int i = 0; i < 2; i++)
    {
        x0 += h;
        y0 += h * dT(x0);
    }
    return y0;
}
void Exame_2019_5(double x1, double x2) {
    double A = (sqrt(5) - 1) / 2;
    double B = pow(A, 2);
    double x3, x4;
    for (int i = 0; i < 2; i++) {
        x3 = x1 + A * (x2 - x1);
        x4 = x1 + B * (x2 - x1);
        if (y_(x3) > y_(x4)) {
            x2 = x4;
            x4 = x3;
        }
        else
        {
            x1 = x3;
            x3 = x4;
        }
        cout << "x1: " << x1 << "  x2: " << x2 << "  x3: " << x3 << "  x4: " << x4 << endl;
    }

}
void Exame_2019_6(double x0, double y0, double l) {
    cout << "z(x): " << z(x0, y0) << endl;
    double gradx = dzdx(x0, y0);
    double grady = dzdy(x0, y0);
    cout << "Gradiente x: " << gradx << " Gradiente y: " << grady << endl;
    double xn1 = x0 - l * dzdx(x0, y0);
    double yn1 = y0 - l * dzdy(x0, y0);
    double zxn = z(xn1, yn1);
    cout << "xn1 : " << xn1 << " yn1: " << yn1 << endl;
    cout << "z(xn): " << zxn << endl;
}
void Exame_2019() {
    //1.
    /*
    double raiz = Exame_2019_1(-1, 0);
    double erro_abs = abs(-0.8417344 - raiz);
    double erro_rel = erro_abs / (-0.8417344);
    cout << "raiz: " << raiz << "   erro absoluto: " << erro_abs << "  erro relativo: " << erro_rel;
    */

    //2.
    //Exame_2019_2(1, 1);

    //3.
    /*
    cout<<"Trapezio\n";
    double L = Exame_2019_3_Trap(0, 2, 0.25);
    double L1 = Exame_2019_3_Trap(0, 2, 0.25 / 2);
    double L2 = Exame_2019_3_Trap(0, 2, 0.25 / 4);
    double QC = (L1 - L) / (L2 - L1);
    double erro = (L2 - L1) / 3; //metodo de 2a ordem
    cout << "L:" << L << endl << "L1: " << L1 << endl << "L2: " << L2<<endl;
    cout << "QC: " << QC << endl;
    cout << "erro: " << erro<<endl;
    cout<<"Simpson\n";
    double L = Exame_2019_3_Simp(0, 2, 0.25);
    double L1 = Exame_2019_3_Simp(0, 2, 0.25 / 2);
    double L2 = Exame_2019_3_Simp(0, 2, 0.25 / 4);
    double QC = (L1 - L) / (L2 - L1);
    double erro = (L2 - L1) / 3; //metodo de 2a ordem
    cout << "L:" << L << endl << "L1: " << L1 << endl << "L2: " << L2<<endl;
    cout << "QC: " << QC << endl;
    cout << "erro: " << erro;
    */

    //4.
    /*
    double y = Exame_2019_4(2, 2, 0.5);
    cout << "Temp corporal: " << y;
    */

    //5
    //Exame_2019_5(2, 4);
    //Como na ultima iteração o x2 manteve-se igual, conclui-se que f(x3)<f(x4) e por isso o maximo está entre [x1,x4], amplitude = abs(x1-x4)    

    //6

    Exame_2019_6(2, 2, 0.25);

    //Como escolher o melhor lambda?
}



/*Exame 2018*/

/*Exc 1*/
double f1(double x, double y) 
{ return sin(x + y) - exp(x - y); }
double f1x(double x, double y) 
{ return cos(x + y) - exp(x - y); }
double f1y(double x, double y) 
{ return cos(y + x) + exp(x - y); }
double f2(double x, double y) 
{ return cos(x + y) - pow(x, 2) * pow(y, 2);}
double f2x(double x, double y) 
{ return -sin(y + x) - 2 * x * pow(y, 2); }
double f2y(double x, double y) 
{ return -sin(y + x) - 2 * pow(x, 2) * y; }
/*Exc 4*/
double dydx(double x, double y, double z) {
    return z;
}
double dzdx(double x, double y, double z) {
    return -7 * z - 4 * y;
}
/*Exc 5*/
double ff(double x) {
    return pow(x, 2) + pow(x, 4);
}

void Exame_2018_1(double x, double y) {
    double xn = x, yn = y;
    for (int i = 0; i < 3; i++) {
        cout << "xn: " << xn << "  yn: " << yn << endl;
        x = xn;
        y = yn;
        xn -= (f2(x, y) * f2y(x, y) - f2(x, y) * f1y(x, y)) / (f1x(x, y) * f2y(x, y) - f2x(x, y) * f1y(x, y));
        yn -= (f2(x, y) * f1x(x, y) - f1(x, y) * f2x(x, y)) / (f1x(x, y) * f2y(x, y) - f2x(x, y) * f1y(x, y));
    }
}
void Exame_2018_2() {
    cout << "\n1.a. Sistema 1 \n1.b. indiferente?\n\1.c.\nxn+1 = (-6 + 305*y+205*z) /515\nyn+1 = (-6 + 205 * z + 515 * x)/305\nzn+1 = (-6 + 305*y + 515 * x)/205\n";
}
void Exame_2018_3() {
    double hx = 1;
    double hy = 1;
    double sum_v = 1.1 + 7.8 + 1.2 + 9.8;
    double sum_mid = 2.1 + 1.5 + 1.4 + 2.2;
    double center = 4;
    double cub =  (sum_v + sum_mid + center)/9;
    cout << "\n3. cub = " << cub << endl;
}
void Exame_2018_4_a_b() {
    cout << "\n4.a/b\n";

    cout << "dydx = z \ndzdx = Az -By\n";
}
void Exame_2018_4_c(double x0, double y0, double z0, double h) {
    cout << "\n4.c\n";
    double x1 = x0, y1 = y0, z1 = z0;
    for (int i = 0; i < 4; i++) {
        cout << i << ". x: " << x1 << " y: " << y1 << " z: " << z1 << endl;
        x0 = x1; y0 = y1; z0 = z1;
        z1 += dzdx(x0, y0, z0) * h;
        y1 += dydx(x0, y0, z0) * h;
        x1 += h;
    }
}
void Exame_2018_5(double x1, double x2)
{
    cout << "Como é uma função unidimensional, para resolver temos os métodos da trisecção, dos terços  e da aurea. Destes 3, a regra da áurea é o mais efeciente.\n";
    double B = (sqrt(5) - 1) / 1;
    double A = pow(B, 2);
    double x3, x4;
    do {
        x3 = x1 + A * (x2 - x1);
        x4 = x1 + B * (x2 - x1);
        if (ff(x3) > ff(x4)) {
            x2 = x4;
            x4 = x3;
        }
        else
        {
            x1 = x3;
            x3 = x4;
        }

    } while (abs(x3 - x4) > 0.00001);
    cout << "x: " << x3 << endl;
}
void Exame_2018() {
    Exame_2018_1(0.5, 0.25);
    Exame_2018_2();
    Exame_2018_3();
    Exame_2018_4_a_b();
    Exame_2018_4_c(0.4, 2, 1, 0.2);
    Exame_2018_5(-0.0000001, 0.00000001);
}




/*Exame 2017*/

/*Exc 1*/
double q1(double x) {
    return pow(x, 2) + pow(x, 4);
}
/*Exc 2*/
double y2(double x) {
    return sqrt(1 + pow(2.5 * exp(2.5 * x), 2));
}

void Exame_2017_1(double x1,double x2) {
    cout << "1.\n Como se trata de uma função unidimensional, para encontrar a minimizar temos disponíveis os métodos dos terços, da secção aurea, da trissecçao e da interpolação quadrática.\n";
    cout << "Vou utilizar o método da aurea, sendo o mais efeciente pois este considera a dimensão do intervalo a reduzir.(isto resulta num nr de iterações menor)";
        //o meu up acaba em 0
    double B = (sqrt(5) - 1) / 2;
    double A = pow(B, 2);
        double x3, x4;
        do {
            x3 = x1 + A * (x2 - x1);
            x4 = x1 + B * (x2 - x1);
            if (q1(x3) <q1(x4)) {
                x2 = x4;
                x4 = x3;
            }
            else
            {
                x1 = x3;
                x3 = x4;
            }
        } while (abs(x1 - x2) > 0.000001);
        cout << "x1: " << x1<< " x2: " << x2<< endl;

}
double Exame_2017_2_simp(double a, double b, double h) {
    double sum = y2(a) + y2(b);
    
    do {
        a += h;
        sum += 2 * y2(a);
    } while (abs(b - a) > 0.000001);
    return sum * h / 2;
}
double Exame_2017_2_trap(double a, double b, double h)
{
    double n = (b - a) / h;
    double sum = y2(a) + y2(b);
    for (int i = 1; i < n; i++) {
        a += h;
        if (i % 2)
        {
            sum += 4 * y2(a);
        }
        else
            sum += 2 * y2(a);
    }
    return sum * h / 3;
}
void Exame_2017() {
    Exame_2017_1(-1, 1);
    double Lt = Exame_2017_2_trap(0, 1, 0.125);
    double Ls = Exame_2017_2_simp(0, 1, 0.125);
    double L1t = Exame_2017_2_trap(0, 1, 0.125/2);
    double L1s = Exame_2017_2_simp(0, 1, 0.125/2);
    double L2t = Exame_2017_2_trap(0, 1, 0.125/2);
    double L2s = Exame_2017_2_simp(0, 1, 0.125/2);


}




/*Teste 2017*/

/*Exc 6*/
double dzdt(double t, double y, double z) { return 1.5 + pow(t, 2) + t * z; }
double dydt(double t, double y, double z) { return z; }

void Teste_2017_1() {
    cout << "\n1.Maxima input:\n"
        << "A:matrix([18,-1,1],[3,-5,4],[6,7,29]);"
        << "da:0.5;db:0.5;"
        << "B: matrix([1],[2],[3]);"
        << "AB: addcol(A,B);"
        << "AB: echelon(AB);"
        << "AB: rowop(AB,1,2,-1/18)\nAB: rowop(AB,1,3,1/87);\nAB: rowop(AB,2,3,-23/29);"
        << "DA: zeromatrix(3,3)+da;\nDB:zeromatrix(3,1)+db;\nX:col(AB,4);\n BP: DB-DA.X;"
        << "AP: addcol(A,AP);\nAP: addcol(A,BP);\nAP:echelon(AP)....";
    cout << "\n\nx: 0.023789\ny: -0.0657207\nz: 0.03132004\n";
}
void Teste_2017_2()
{
    cout << "\n2.";
    vector<vector<double>> A = { {6,0.5,3,0.25},{1.2,3,0.25,0.2},{-1,0.25,4,2},{2,4,1,8} };
    vector<double> B = { 19,-2.2,9,15 };
    vector<double> x = { 1.67969,-1.78160,1.93752,2.1036 };
    double x1, x2, x3, x4;
    for (int i = 0; i < 4; i++) {
        x1 = (B[0] - (A[0][1] * x[1] + A[0][2] * x[2] + A[0][3] * x[3])) / A[0][0];
        x2 = (B[1] - (A[1][0] * x1 + A[1][2] * x[2] + A[1][3] * x[3])) / A[1][1];
        x3 = (B[2] - (A[2][0] * x1 + A[2][1] * x[1] + A[2][3] * x[3])) / A[2][2];
        x4 = (B[3] - (A[3][0] * x1 + A[3][1] * x[1] + A[3][2] * x[2])) / A[3][3];
    }
    cout << "x1: " << x1 << " x2: " << x2 << " x3: " << x3 << " x4: "<< x4;
}
void Teste_2017_3() {
    double inte = (0.8/ 2) * (1.16 + 0.42 + 2 * ( 0.65 ));
    cout << "\n3.\ns: " << inte << endl;
    double inte1 = (0.4 / 2)* (1.16 + 0.42 + 2 * ( 1.08 + 0.65 +  1.24 ));
    cout << "\ns': " << inte1 << endl;
    double inte2 = (0.2 / 2) * (1.16 + 0.42 + 2 * (0.45 + 1.08 + 0.53 + 0.65 + 1.32 + 1.24 + 1.18));
    cout << "\ns'': " << inte2 << endl;
    double erro = (inte2 - inte1) / 3;
    cout << "erro: " << erro << endl;

}
void Teste_2017_4() {
    double hx = 1.8 / 2;
    double hy = 1.8 / 2;
    double sum_v = 1.1 + 4.1 + 1.2 + 6.5;
    double sum_mid = 1.4 + 2.2 + 1.5 + 2.1;
    double mid = 4.5;
    double cub = (hx * hy) / 9 * (sum_v + 4*sum_mid + 16*mid);
    cout << "\n4.cub: " << cub<<endl;
}
void Teste_2017_6_euler(double t0,  double y0, double z0, double h) {
    cout << "\n6.\nEuler\n";
    double tn=t0, yn=y0, zn=z0;
    for (int i = 0; i < 3; i++) {
        cout << "t: " << tn << " y: " << yn << " z: " << zn << endl;

        t0 = tn; y0 = yn; z0 = zn;
        zn += h * dzdt(t0, y0, z0);
        yn += h * dydt(t0, y0, z0);
        tn += h;
    }
}
void Teste_2017_6_RK4(double t0,  double y0, double z0, double h) {
    cout << "\n6.\RK4\n";

    double y1,y2,y3,y4, z1, z2, z3, z4;
    for (int i = 0; i < 3; i++) {
        cout << "t0: " << t0 << " y0: " << y0 << " z0: " << z0 << endl;

        y1 = h * dydt(t0, y0, z0);
        z1 = h * dzdt(t0, y0, z0);
        y2 = h * dydt(t0 + h / 2, y0+y1/2, z0 + z1 / 2);
        z2 = h * dzdt(t0 + h / 2, y0 + y1/ 2, z0 + z1 / 2);
        y3 = h * dydt(t0 + h / 2, y0 + y2 / 2, z0 + z2 / 2);
        z3 = h * dzdt(t0 + h / 2, y0 + y2 / 2, z0 + z2/ 2);
        y4 = h * dydt(t0 + h, y0 + y3, z0 + z3);
        z4 = h * dzdt(t0 + h, y0 + y3, z0 + z3);
        t0 += h;
        y0 += (y1 / 6 + y2 / 3 + y3 / 3 + y4 / 6);
        z0 += (z1 / 6 + z2 / 3 + z3 / 3 + z4 / 6);
    }
}
void Teste_2017() {

    Teste_2017_1();
    Teste_2017_2();
    Teste_2017_3();
    Teste_2017_4();
    Teste_2017_6_euler(1, 0, 1,0.2);
    Teste_2017_6_RK4(1, 0, 1,0.2);


}




/*Exame 2016*/

/*Exc1*/
double fa(double x, double y)
{
    return pow(x, 2) - y - 1.2;
}
double dxfa(double x, double y) 
{ return 2 * x; }
double dyfa(double x, double y) 
{ return -1; }
double fb(double x, double y) 
{ return -x + pow(y, 2) - 1; }
double dxfb(double x, double y)
{ return -1; }
double dyfb(double x, double y)
{ return 2 * y; }
/*Exc2*/
double f6(double x) { return pow(x, 7) + 0.5 * x - 0.5; }
/*Exc5*/
double dydt(double t, double z) { return z; }
double dzdt(double t, double z) { return 0.5 + pow(t, 2) + t * z; }
/*Exc6*/
double fq(double x) { return sqrt(1 + pow(1.5 * exp(1.5 * x), 2)); }

void Exame_2016_1(double a, double b) {
    double an, bn;
    for (int i = 0; i < 2; i++) {
        an = a;
        bn = b;
        a -= (fa(an, bn) * dyfb(an, bn) - fb(an, bn) * dyfa(an, bn)) / (dxfa(an, bn) * dyfb(an, bn) - dxfb(an, bn) * dyfa(an, bn));
        b -= (fb(an, bn) * dxfa(an, bn) - fa(an, bn) * dxfb(an, bn)) / (dxfa(an, bn) * dyfb(an, bn) - dxfb(an, bn) * dyfa(an, bn));
        cout << "x: " << a << "  y:" << b << endl;
    }
}
void Exame_2016_2(double a0, double b0) {
    double w;
    for (int i = 0; i < 4; i++) {
        w = (a0 * f6(b0) - b0 * f6(a0)) / (f6(b0) - f6(a0));
        if (f6(a0) * f6(w) < 0)
        {
            b0 = w;
        }
        else
            a0 = w;
        cout << "xe : " << a0 << "  xd: " << b0 << "  xn: " << w << endl;
    }
}
void Exame_2016_5_euler(double t, double y, double z, double h) {
    double zn, yn;
    for (int i = 0; i < 3; i++)
    {
        zn = z;
        yn = y;
        z += dzdt(t, zn) * h;
        y += dydt(t, zn) * h;
        t += h;
        cout << "y: " << y << "  z: " << z << endl;
    }
}
void Exame_2016_5_rK4(double x, double y, double z, double h) {
    for (int i = 0; i < 3; i++) {
        double y1 = h * dydt(x, z);
        double z1 = h * dzdt(x, z);
        double y2 = h * dydt(x + h / 2, z + z1 / 2);
        double z2 = h * dzdt(x + h / 2, z + z1 / 2);
        double y3 = h * dydt(x + h / 2, z + z2 / 2);
        double z3 = h * dzdt(x + h / 2, z + z2 / 2);
        double y4 = h * dydt(x + h, z + z3);
        double z4 = h * dzdt(x + h, z + z3);
        y += (y1 / 6 + y2 / 3 + y3 / 3 + y4 / 6);
        z += (z1 / 6 + z2 / 3 + z3 / 3 + y4 / 6);
        x += h;

        cout << "x: " << x << "  y: " << y << "  z: " << z << endl;
    }
}
double Exame_2016_6_trap(double a, double b, double h) {

    int n = (b - a) / h;
    double sum = fq(a) + fq(b);
    for (int i = 1; i < n; i++) {
        a += h;
        sum += 2 * fq(a);

    }
    return h / 2 * sum;
}
double Exame_2016_6_Simp(double a, double b, double h) {

    int n = (b - a) / h;
    double sum = fq(a) + fq(2 * b);
    for (int i = 1; i < 2 * n; i++) {
        a += h;
        if (i % 2 == 0) {
            sum += 2 * fq(a);
        }
        else
            sum += 4 * fq(a);

    }

    return h / 3 * sum;
}
void Exame_2016() {

    Exame_2016_1(1, 1);
    Exame_2016_2(0, 0.8000000);
    Exame_2016_5_euler(0, 0, 1, 0.25);
    Exame_2016_5_rK4(0, 0, 1, 0.25);

    double L1s = Exame_2016_6_Simp(0, 2, 0.5);
    double L1t = Exame_2016_6_trap(0, 2, 0.5);
    double L2s = Exame_2016_6_Simp(0, 2, 0.25);
    double L2t = Exame_2016_6_trap(0, 2, 0.25);
    double L3s = Exame_2016_6_Simp(0, 2, 0.125);
    double L3t = Exame_2016_6_trap(0, 2, 0.125);
    cout << "L1 : " << L1t << "  " << L1s << endl;
    cout << "L2 : " << L2t << "  " << L2s << endl;
    cout << "L2 : " << L3t << "  " << L3s << endl;
    cout << "QC " << (L2t - L1t) / (L3t - L2t) << "  " << (L2s - L1s) / (L3s - L2s) << endl;




}



/*Exame 2015*/

/*Exc 1*/
double dTdt(double T, double t) {
    return -0.25 * (T - 37);
}
/*Exc 4*/
double recx(double x) {
    return 2 * log(2 * x);
}
/*Exc 5*/
double y3(double x) {
    return sqrt(1 + pow((2.5 * exp(2.5 * x)), 2));
}
/*Exc 7*/
double f7(double x) {
    return pow(x, 3) - 10 * sin(x) + 2.8;
}

void Exame_2015_7(double x0, double xf) {
    cout << "\n7.\n";
    double m;
    for (int i = 0; i < 2; i++)
    {
        m = (x0 + xf) / 2;
        if(f7(x0) * f7(m) < 0)
            xf = m; 
        else
            x0 = m;

        cout << "x0: " << x0 << " xf: " << xf << endl;
    }
}
void Exame_2015_6()
{
    cout << "\n6.\nOdeio teoria pt2.\n";
}
void Exame_2015_5_simp(double x0, double xf, double h) {
    double x = x0;
    cout << "\n5.Simpson:\n";
    cout << "\nh: " << h << " h': " << h / 2 << " h'': " << h / 4 ;
    double n = (xf - x0) / h;
    double sum1 = y3(x0) + y3(xf);
    for (int i = 1; i < n; i++) {
        x0 += h;
        if (i % 2)
            sum1 += 4 * y3(x0);
        else
            sum1 += 2 * y3(x0);
    }
    sum1 *= (h / 3);
    cout << "\nL1: " << sum1 ;
    h /= 2;
    x0 = x;
    n = (xf - x0) / h;
    double sum2 = y3(x0) + y3(xf);
    for (int i = 1; i < n; i++) {
        x0 += h;
        if (i % 2)
            sum2 += 4 * y3(x0);
        else
            sum2 += 2 * y3(x0);
    }
    sum2 *= (h / 3);
    cout << "\nL2: " << sum2 ;
    x0 = x;

    h /= 2;
    n = (xf - x0) / h;
    double sum3 = y3(x0) + y3(xf);
    for (int i = 1; i < n; i++) {
        x0 += h;
        if (i % 2)
            sum3 += 4 * y3(x0);
        else
            sum3 += 2 * y3(x0);
    }
    sum3 *= (h / 3);
    cout << "\nL3: " << sum3 ;
    cout << "\nQC: " << (sum2 - sum1) / (sum3 - sum2);
    cout << "\nerro: " << abs((sum3 - sum2) / 15);
}
void Exame_2015_5_trap(double x0, double xf, double h) {
    double x = x0;
    cout << "\n5.Trapezio:\n";
    cout << "\n h: " << h << "h': " << h / 2 << "h'': "<<h / 4 ;
    double n = (xf - x0) / h;
    double sum1 = y3(x0) + y3(xf);
    for (int i = 1; i < n; i++) {
        x0 += h;
        sum1 += 2 * y3(x0);
    }
    sum1 *= (h / 2);
    cout << "\nL1: " << sum1 ;
    h /= 2;
    x0 = x;

     n = (xf - x0) / h;
    double sum2 = y3(x0) + y3(xf);
    for (int i = 1; i < n; i++) {
        x0 += h;
        sum2 += 2 * y3(x0);
    }
    sum2 *= (h / 2);
    cout << "\nL2: " << sum2 ;
    h /= 2;
    x0 = x;

     n = (xf - x0) / h;
    double sum3 = y3(x0) + y3(xf);
    for (int i = 1; i < n; i++) {
        x0 += h;
        sum3 += 2 * y3(x0);
    }
    sum3 *= (h / 2);
    cout << "\nL3: " << sum3 ;
    cout << "\nQC: " << (sum2 - sum1) / (sum3 - sum2);
    cout << "\nerro: " << abs((sum3 - sum2) / 3);
}
void Exame_2015_4_2(double xn) {
    cout << "\n4.2.\n";
    cout << "x: " << xn << endl;
    for (int i = 0; i < 1; i++) {
        xn = recx(xn);
        cout << "x: " << xn << endl;
    }

    cout << "\n4.3.\nresiduo:" << abs(xn-1.1) << endl;
}
void Exame_2015_4_1() {
    cout << "\n4.1.\n Calculate dfdx to each recorrence formula and verify if |dfdx(x)|<1;\n";
}
void Exame_2015_3() {
    cout << "\n3.a.\n Maxima:\nA:matrix([1,1/2,1/3,-1],[1/2,1/3,1/4,1],[1/3,1/4,1/5,1]);\nA:echelon(A);\n";
    cout << "\n3.b.\n Maxima:\nA:rowop(A,1,2,1/2);\nA:rowop(A,1,3,-1/6);\nA:rowop(A,2,3,1);\n";
    cout << "\n3.c.\n explained pag.101 book\n";
}
void Exame_2015_2()
{
    cout << "\n2.\nTeoria não é para mim\n";
}
void Exame_2015_1(double T, double t) {
    cout << "Exame 2015\n\n1.\n";
    double h = 0.4;
    for (int i = 0; i < 3; i++) {
        cout << " T: " << T<<endl;
        T += h * dTdt(T, t);
        t += h;
    }
}
void Exame_2015() {
    Exame_2015_1(3,5);
    Exame_2015_2();
    Exame_2015_3();
    Exame_2015_4_1();
    Exame_2015_4_2(1.1);
    Exame_2015_5_simp(0, 1, 0.125);
    Exame_2015_5_trap(0, 1, 0.125);
    Exame_2015_6();
    Exame_2015_7(1.5, 4.2);
}




/*Exame 2014*/

/*Exc 1*/
double dxdt(double t, double x, double z) {
    return z;
}
double dzdt(double t, double x, double z,double k) {
    return (z - k * x) / 20;
}
/*Exc 2*/
double g(double x) {
    return -x + 40 * cos(sqrt(x)) + 3;
}
double dgdx(double x) {
    return -(20 * sin(sqrt(x))) / sqrt(x) - 1;
}
/*Exc 5*/
double f5(double x) {
    return 5 * cos(x) - sin(x);
}

void Exame_2014_5(double x1, double x2) {
    cout << "\n5.\n";
   double B = (sqrt(5) - 1) / 2;
   double A = pow(B, 2);
   double x3, x4;
   x3 = x1 + A * (x2 - x1);
   x4 = x1 + B * (x2 - x1);
   cout << "x1: " << x1 << " x2: " << x2 << " x3: " << x3 << " x4: " << x4 << " f(x1): " << f5(x1) << " f(x2): " << f5(x2) << " f(x3): " << f5(x3) << " f(x4):  " << f5(x4) << endl;
   for (int i = 0; i < 3; i++) {
       x3 = x1 + A * (x2 - x1);
       x4 = x1 + B * (x2 - x1);

       if (f5(x3) < f5(x4)) {
           x2 = x4;
           x4 = x3;
       }
       else
       {
           x1 = x3;
           x3 = x4;
       }
       cout << "x1: " << x1 << " x2: " << x2 << " x3: " << x3 << " x4: " << x4 << " f(x1): " << f5(x1) << " f(x2): " << f5(x2) << " f(x3): " << f5(x3) << " f(x4):  " << f5(x4) << endl;

   }

}
void Exame_2014_3() {
    cout << "\n3.\n Maxima: echelon(AB);rowops...";
}
void Exame_2014_2(double x) {
    cout << "\n2.a. Maxima draw && verify the existence of 3 roots.\n";

    cout << "\n2.b.\nx: " << x << " g(x): " << g(x) << endl;

    for (int i = 0; i < 2; i++) {
        x -= g(x) / dgdx(x);
        cout << "x: " << x<<" g(x): "<<g(x)<<endl;
    }
}
void Exame_2014_1(double x, double t, double z, double h) {
    cout << "\n1.\n";
    double xn5 = x, zn5 = z;
    double xn20 = x, zn20 = z;
    double xn40 = x, zn40 = z;
    double x5=x, z5=z, x20=x, z20=z, x40=x, z40=z;
        cout << "k = 5                           k = 20                          k=40\n";
    for(int i = 0; i < 17; i++){
        cout << "x5: " << xn5 <<" t5: " << t <<  "\tx20: " << xn20 << " t20: " << t << "\tx40: " << xn40 << " t40: " << t << endl;
        x5= xn5; z5 = zn5;
        x20 = xn20; z20 = zn20;
        x40 = xn40; z40 = zn40;

        xn5 += h * dxdt(t, x5, z5);
        zn5 += h * dzdt(t, x5, z5, 5);

        xn20 += h * dxdt(t, x20, z20);
        zn20 += h * dzdt(t, x20, z20, 20);

        xn40 += h * dxdt(t, x40, z40);
        zn40 += h * dzdt(t, x40, z40, 40);
        t += h;
    }

    cout << "\nEm k= 40, é a unica situaçáo em que se verifica x(1.6) = 0;\n";
}
void Exame_2014() {
    cout << "\n\nExame 2014\n";
    Exame_2014_1(1,0,0,0.1);
    Exame_2014_2(1.7);
    Exame_2014_5(2, 4);



}



int main()
{
    cout << fixed;
    cout.precision(6);
    //Exame_2019();
    //Exame_2018();
    //Exame_2017();
    //Teste_2017();
    //Exame_2016();
    //Exame_2015();
    Exame_2014();
}
