/*--Quadratic_equation_with_epsilon---------------------------------------------*/
#include <stdio.h>
#include <math.h>

int main()
{
  int n;
  double E,yk;
  printf ("Enter the number which sqrt you want to know: ");
  scanf ("\n %d", &n);
  printf ("Enter accuracy: ");
  scanf ("\n %lf", &E);

	yk=1;
	do
		{	
			yk=(yk+n/yk)/2;
			printf("%lf\n",yk);
		} 
	while (fabs(yk*yk-n)>E);
	
	printf("%.12lf is the sqrt of %d with %lf accuracy",yk,n,E);
		
  return 0;
}
/*--Quadratic_equation_without_epsilon---------------------------------------------*//*--Quadratic_equation_without_epsilon---------------------------------------------*/
#include <stdio.h>
#include <math.h>

int root(double a, double b, double c, double *x1, double *x2)
{
double D=b*b-4*a*c;
	    if (D<0) return 0;
			else if (D==0) 
				{
					*x1=-b/(2*a);
					return 1;
				}
				else if (D>0) 
					{
						*x1=(-b+sqrt(D))/(2*a);
						*x2=(-b-sqrt(D))/(2*a);
						return 2;
					}
}

int main()
{
  double a,b,c,r,x1,x2;
  printf ("input koef");
  scanf ("\n %lf%lf%lf", &a,&b,&c);
  r=root(a,b,c,&x1,&x2);
  if (r==0) printf("Not exists roots");
	else if (r==1) printf("The root is %lf ", x1);
		else if (r==2) printf("The roots is %lf %lf", x1,x2);

  return 0;
}
/* 2_3*/
#include <stdio.h>

int main() {

	int m, n, i, min,max;
	double a, b, a0, delta;

	printf("Enter n, m: ");	/* input*/
	scanf("%d %d", &n, &m);
	printf("Enter a, b: ");
	scanf("%lf %lf", &a, &b);

/*	delta = (m - n) > 0 ? (b - a) / (m - n) : (a - b) / (n - m);*/
	delta = (b - a) / (m - n);
	a0 = a - delta * n;

	min = m > n ? n : m;	/* output*/
	max = m > n ? m : n;
	for(i = min; i <= max; i++) {
		printf("%lf ", a0+delta*i);
	}
	printf("\n");

}

/*--random---------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	
	srand(time(NULL));
	printf("%u\n",  rand()%5);
return 0;
}/**/

/*--poly---------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
	double ai,x0,V;
	int n,i;
	
	
	FILE *f;
	/*printf(&f);*/
	f = fopen("poly.txt","rt");
	if (f == NULL)
		{
		printf("Impossible to open or make file\n");
		return 1;
		}
	
	fscanf(f,"%d",&n);
	fscanf(f,"%lf",&x0);
	printf("%d %lf\n", n, x0);
	
	for (i=n+1;i>0;i--)
	{	
		fscanf(f,"%lf",&ai);
		printf("%lf\n",ai);
		V=V*x0+ai;
	}
	printf("Value of polynomial in point %lf is %lf",x0,V);
	fclose(f);
	return 0;
}

/*--NOD&NOK---------------------------------------------*/
#include <stdio.h>
 
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int euclid_algo (int arg1, int arg2) {
    return arg2 ? euclid_algo (arg2, arg1 % arg2) : arg1;
}

/*
короткая версия алгоритма евклида
int euclid_algo (int arg1, int arg2) {
    return arg2 ? euclid_algo (arg2, arg1 % arg2) : arg1;
}
*/


int find_NOK (int x, int y)
{
    return x*y/gcd(x,y);
}

int main(){
	int n,m; 
	scanf("%d %d", &n, &m);
	printf("NOD: %d,\nNOK: %d", /*gcd*/euclid_algo(n,m), find_NOK(n,m));
	return 0;
}

/*--max_from_3_numbers---------------------------------------------*/
#include <stdio.h>
	
int MAX(int a, int b)
	{
	if (a>b) return a;
	else return b;
	}
	
int max3(int n, int k, int l)
	{
	int max;
	max = MAX(n,MAX(k,l));
	return max;
	}
	
int main()
{

	int n,k,l,m;
	printf("Enter three numbers: ");
	scanf("%d%d%d",&n,&k,&l);
	m=max3(n,k,l);
	printf("Maximum of %d,%d,%d is %d", n, k, l, m);
	
return 0;
}

/*--leap_year---------------------------------------------------------*/
#include <stdio.h>

int main(){
	
	char true = 1;
	char false = 0;
	int year;
	int res = 0;
	scanf("%d", &year);
	/*if((year % 4 == 0)&&(year % 100 != 0)||(year % 400 ==0)){
		printf("\nURA!\nVisokosnii!");}
	else
		printf("Not Visokosnii!");*/
	
	(((year % 4 == 0)&&(year % 100 != 0))||(year % 400 ==0))? printf("true") : printf("false");
	
	return 0 ;
}

/*--fibonacci---------------------------------------------------------*/
#include <stdio.h>
#include <conio.h>
 
int main()
{
    int fib1 = 0, fib2 = 1;
    int fib = 0;
    int n;
    int i;
 
    printf("Input N: ");
    scanf("%d", &n);
 
    fib = 1;
 
    for (i = 1; i <= n; i++)
    {
        fib = fib2 + fib1;
        fib2 = fib1;
        fib1 = fib;
 
        printf("%d  ", fib);
    }
 
    getch();
    return 0;
}

/*--7---------------------------------------------------------*/
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int main()
{
	int a, b, n, i, c;
	double min, max, s=0;
	srand(time(0));
	printf("Количество чисел: \n");
	scanf("%d", &n);
	printf("Введите 2 целых числа - диапозон: ");
	scanf("%d%d", &a, &b);
	min = b; max = a;
	for (i = 0; i < n; i++)
	{
		c = (int)(a+(double)rand()*(b-a)/RAND_MAX);
		printf("%d ", c);
		if (c>max) max = c;
		if (c<min) min = c;
		s+=c;
	}
	printf("\nМинимум = %f\nМаксимум = %f\nСумма = %f\n", min, max, s);
	return 0;
}
