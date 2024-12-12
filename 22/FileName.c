#define _USE_MATH_DEFINES 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <math.h>
typedef double (*func)(double);
double Yx(double);
double Sx(double);
double Vx(double);
double tabl(func, double, double, double);
int lab22task1 ();
int main()
{
	setlocale(LC_CTYPE, "RUS");
	char c;
	printf("Введите номер задания лабораторной ");
	scanf("%c", &c);
	switch (c)
	{
	case '1':
		lab22task1();
		break;
	case '2':
		//lab19task2();
		break;
	case '3':
		//lab19task3();
		break;
	default:
		printf("Неизвестная операция.\n");
	}
}
double Yx(double x)
{
	double y = 0.3 * pow(cos(pow(x, 3)), 5) + 0.001 * log(pow(x, 0.4));
	return y;
}
double Sx(double x)
{
	double y = (2.5 * exp(-3 * x)-4*pow(x,2))/(log(fabs(x))+sin(x));
	return y;
}
double Vx(double x)
{
	double y;
	if (x >0)
		y = 1 / (pow(x,2)+2*x);
	else
		y = 1 - pow(x, 3);
	return y;
}
double tabl(func y, double x1,double x2, double s)
{
	for (double i=x1; i<x2;i+=s)
		printf("|%+12.2lg|%+12.2lg|\n", i, y(i));
}
int lab22task1 ()
{
	
	getchar();
	int d;
	double x2,x1,s;
	double (*y[])(double, double, double) = {Yx,Sx,Vx};
	printf("Введите х начальную\n");
	scanf("%lf", &x1);
	printf("Введите х конечную\n");
	scanf("%lf", &x2);
	printf("Введите шаг табуляции\n");
	scanf("%lf", &s);
	getchar();
	printf("Введите номер функции ");
	scanf("%d", &d);
	tabl(Yx, x1, x2, s);
	//switch (d)
	//{
	//case '1':
	//	y = Yx;
	//	break;
	//case '2':
	//	y = Sx;
	//	break;
	//case '3':
	//	y = Vx;
	//	break;
	//default:
	//	printf("Неизвестная операция.\n");
	//}
	tabl(y[d], x1, x2, s);
	//printf("|%+12.6lf |%+12.6lf |%+12.6lf |", Yx(x), Sx(x), Vx(x));
}