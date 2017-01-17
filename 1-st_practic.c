/*3*/
/*----------------------------------------------------------------------------------------------------------------------------------*/
#include <stdio.h>

int main(){
    double A0, difference;
    int N;
    scanf("%lf %lf %d", &A0, &difference, &N);
    printf("%lf", (A0+difference*(N-1)));
    return 0;
}
/*4*/
#include <stdio.h>

int main(){
    double r, phi;
    long double PI=3.14159265358979323846;
    printf("Geben r und phi:\n");// Введите r и phi
    scanf("%lf %lf", &r, &phi);

    /*phi=r * (phi * PI / 180) / 2;*/
    phi = phi*PI / 180;
    printf("Length equal :%f.\nArea equal %f.", (r*phi), (r*r*phi/2));
    return 0;
}
/*----------------------------------------------------------------------------------------------------------------------------------*/
/*6*/
#include<stdio.h>

int main() {
    double a, t;
    int N;
    scanf("%lf %d", &a, &N);
    t = a;
    int i;
    for( i = 0; i < N; i++)
        t = t * a;
    printf("%f", t);
    return 0;
}

/*----------------------------------------------------------------------------------------------------------------------------------*/
/*6(new)*/
#include<stdio.h>
#include<math.h>

int main(){
	double x, s = 1;
	int n;
	printf("Please input osnovanie");
	scanf("%lf",&x);
	printf ("Please input stepen n= \n");
	scanf("%d",&n);
	/*while возвести степень = s*/
	int i = 0;
	while(i < abs(n))
	{
		s*=x;
		i++;
	}
	if(n < 0){
		 s = 1 / s;
	}
	printf("%lf", s);

	return 0;
}

/*----------------------------------------------------------------------------------------------------------------------------------*/
/*7*/
#include <stdio.h>
#include <stdlib.h> 
#include <math.h>
#include <string.h>
#include <time.h>

int main(){
    int n, a;
    a = 124;
    while (n != a){
        printf("Geben number: ");
        scanf("%d", &n);
        if (n > a)
        {
            printf("brauchen weniger<\n");
        }
        else if (n < a)
        {
            printf("brauche mehr >\n");
        }
    }
    printf("Bingo!!");/*и на немецком тоже Bingo*/
    /*getch();*/
}
