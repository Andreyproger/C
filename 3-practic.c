/*--1_task----------------------------------------------------------*/
#include <stdio.h>
#include <limits.h>
#include <time.h>
#include <stdlib.h>

int Min(int a, int b){
	return (a < b)? a:b;
}

int Max(int a, int b){
	return (a>b)? a:b;
}

int *GenArray(int n,int a, int b)
{	int i=0;
	int *ar=NULL;
	srand(time(NULL));
	ar = (int*)malloc(sizeof(int)*n);
	for (i;i<n;i++) {
		ar[i]= (int)(a+(double)rand()*(b-a)/RAND_MAX);/*в качественном софте нужно писать (b-a+1)*//*в качественном софте нужно писать (b-a+1)*/
	}
	return ar;
}

void MinMaxArray(int *a, int n, int *max, int *min){
	int i;
	if (n==0) 
		{
		*min=INT_MIN;
		*max=INT_MAX;
		}
	*min=a[0];
	*max=a[0];
	for (i=0;i<n;i++)
		{
		 *min=Min(*min,a[i]);
		*max=Max(*max,a[i]);
		}
}

int main(){
	int n, max=INT_MAX, min = INT_MIN, i = 0, a, b, *ar;
	printf("Enter the number: ");
	scanf("%d", &n);
	if(n == 0)
	{
		printf("min = %d,\nmax = %d", min, max);
		return 0;
	}
	printf("Enter a,b in [a,b]");
	scanf("%d %d", &a,&b);
	ar = GenArray(n,a,b);
	for(; i < n; i++){
		printf("%d ", ar[i]);
	}
	printf("\n");
	MinMaxArray(ar, n, &max, &min);
	printf("min = %d,\nmax = %d", min, max);
	return 0;
}
/*--2_task----------------------------------------------------------*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int *GenArray(int n,int a, int b)
{	int i;
	int *ar=NULL;
	srand(time(NULL));
	ar = (int*)malloc(sizeof(int)*n);
	for (i=0;i<n;i++) {
		ar[i]=a+rand()%(b-a+1);/*в качественном софте нужно писать (b-a+1)*/
	}
	return ar;
}

int main(){
	int a,b,N,i, *ar1;
	scanf("%d %d %d", &N, &a,&b);
	/*GenArray(N,a,b);*/
	i = 0;
	ar1= GenArray(N,a,b);
	for(;i<N;i++)
		printf("%d ", ar1[i]);
	return 0;
}
/*--execise3----------------------------------------------------------*/
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
/*const int len=10000000;*/

int *GenArray(int n,int a, int b)
{	int i;
	int *ar=NULL;
	srand(time(NULL));
	ar = (int*)malloc(sizeof(int)*n);
	for (i=0;i<n;i++) {
		ar[i]=a+rand()%(b-a+1);/*в качественном софте нужно писать (b-a+1)*/
	}
	return ar;
}
void reversearray(int n, int *A, int *B){
	int i =0;
	for(; i < n; i++){
		B[i] = A[n-i-1];
	}
}

int main(){
	int N,*ar,a,b;
	int mas[100000], reverse[100000];
	int i; /*счетчик*/
	scanf("%d %d %d", &N, &a,&b);
	ar = GenArray(N,a,b);
	reversearray(N, ar,reverse);
	i=0;
	for(; i < N; i++)
		printf("%d ", ar[i]);
	i=0;
	for(; i < N; i++)
		printf("%d ", reverse[i]);
	return 0;
}
/*task4*/
#include <stdio.h>

void sort(unsigned char *a, int l)
{
	int ar[3], i;
	ar[0] = 0;
	ar[1] = 0;
	ar[2] = 0;
	for (i=0; i<l; i++)
		ar[a[i]-1]++;
	for (i=0; i<ar[0]; i++)
		a[i]=1;
	for (i=ar[0]; i<ar[1]+ar[0]; i++)
		a[i]=2;
	for (i=ar[1]+ar[0]; i<ar[2]+ar[1]+ar[0]; i++)
		a[i]=3;
}

int main()
{
	int *ar;
	int i,n;
	printf("Введите к-во элементов массива: ");
    scanf("%d", &n);
    ar = (int*) malloc(n*sizeof(int));
    for (i=0; i<n; i++)
    {
    	printf("1, 2 or 3? ");
    	scanf("%d", &ar[i]);
    }
    sort(ar, n);
    for (i=0; i<n; i++)
    	printf("%d\n", ar[i]);
    return 0;
}
/*function ATOI*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>


int myAtoi(char *str)
{
    int res = 0;
    int sign = 1;
    int i = 0;

    /*if (str[0] == '-')
    {
        sign = -1;  
        i++;  
    }*/

    for (; str[i] != '\0'; ++i)
        res = res*10 + str[i];
   

    return sign*res;
}

int main(){
	int i;
	char s[255];
	printf("Enter string of length mensche 255:\n");
	for(i = 0; i <255; i++){
		scanf("%s", &s[i]);
	}
	printf("atoi of string = %d",myAtoi(s));
	return 0;
}
/*task6*/
#include <stdio.h>
#include <string.h>

int changeStringSize(int *s, int N){
	int len_str = strlen(*s);
	return len_str;
}

int main(){
	int N, str[256], i =0;
	scanf("Enter length of string:\n");
	scanf("%d", &N);
	printf("Enter string of length mensche 255:\n");
	for(i = 0; i <N; i++){
		scanf("%s", &str[i]);
	}
	printf("%d",changeStringSize(str, 5));
	return 0;
}
/*task7*/
#include <stdio.h>

int StringSize(char *s)
{
	int i=0;
	while (s[i] != '\0')
		i++;
	return i;
}

char *code(char *str)
{	const int a = 32; /*взял из задания*/
	const int b = 127; /*взял из задания*/
	int l = StringSize(str), i=0, k=0, size = 3*l-1;/*size  - размер нужной строки*/
	char *res; /*наш результат*/
	res = (char *) malloc(size * sizeof(char)); /*выделяем размер под массив*/
	while (str[i] != '\0')/*пока не конец строки*/
	{   /*i - индекс исходной строки*/
	    /*k - индекс получаемой строки*/
		res[k] = str[i];/*сначала вставляем элемент из строки str*/
		if (str[i+1] != '\0') res[k+1] = (char)(rand()%(b-a)+a);/*вставляем случайный символ с кодом (rand()%(b-a)+a)*/
		if (str[i+1] != '\0') res[k+2] = (char)(rand()%(b-a)+a);/*вставляем случайный символ с кодом (rand()%(b-a)+a)*/
		i++;/*текущий индекс*/
		k=k+3;/*результатирующий индекс*/
	}
	return res;
}

char *decode(char *str)
{
	int i=0, l=StringSize(str);
	char *res;
	res = (char *) malloc(l * sizeof(char)/3+1);/*выделяем размер под массив*/
	for (i=0; i<l; i=i+3)
		res[i/3]=str[i];/*из кодированной строки получаем нужний символь*/
	return res;/*возвращаем результат*/
}

int main()
{
	char s[200];
	srand(time(0));
	printf("Input a string for coding: ");gets(s); /*приглашение на ввод и сам ввод*/
	printf("%s\n", code(s)); /*вывод закодированной строки*/
	printf("\n");
	printf("Input a string for decoding: "); /*приглашение на ввод строки для декодирования*/
	gets(s);/*ввод закодированной строки*/
	printf("%s\n", decode(s));/* печать декодированной строки*/
	return 0;
}
