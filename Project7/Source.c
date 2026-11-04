#define _CRT_SECURE_NO_DEPRECATE
#define _USE_MATH_NO_DEFINES
#include <math.h>
#include <stdio.h>
#include <locale.h>
#define p_min 0.5
#define p_max 2.0
#define max_delt_p 5.0

double function(double x); // Функция для рассчёта q
double control(double q1, double q2); // Функция для контроля состояния
double signal(int n); // Функция для вывода состояния
double readfile(); // Фунуция для чтения файлов. Будет создана, когда начнётся изучение соответствующей темы.

int main(void)
{
	setlocale(LC_ALL, "RUS");
	double x;
	printf("Здравствуйте, пользователь. Введите давление(в бар) >> ");
	scanf("%lf", &x);
	double q = function(x);
	printf("Q=%lf", q);
}





double signal(int n) {
	switch (n) {
	case 1: printf("normal"); break;
	case 2: printf("warning"); break;
	}
}

double control(double q1, double q2) {
	if (fabs(q1 - q2) <= max_delt_p) { return signal(1); }
	return signal(2);
}

double function(double x) {
	if (x < p_min) { return pow(x - 0.5, 2) + 8; } //Эквивалентно q= pow(x-0.5, 2)/1 + 8
	if (x >= p_min && x <= p_max) { return 2 * pow(x + 0.75, 0.5) + 42; }//Эквивалентно q= 2 * pow(x-1.25+2, 0.5) + 42
	if (x > p_max) { return 3 * x + 54; } //Эквивалентно q= 3*(x-2) + 60
}
