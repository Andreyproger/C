#include <stdio.h>
#include <math.h>
#include <string.h>
#include <limits.h>

#define pi 3.1415

struct complex
{
    double Re, Im;
};

void cPrint (struct complex C)
{
    if (C.Im >= 0)
        printf("%f+%fi\n", C.Re, C.Im);
    else
        printf("%f%fi\n", C.Re, C.Im);
}

struct complex cAdd(struct complex C1, struct complex C2)
{
    struct complex temp;
    temp.Re = C1.Re + C2.Re;
    temp.Im = C1.Re + C2.Im;
    return temp;
}

struct complex cSub(struct complex C1, struct complex C2)
{
    struct complex temp;
    temp.Re = C1.Re - C2.Re;
    temp.Im = C1.Im - C2.Im;
    return temp;
}

double cReal(struct complex C1)
{
    return C1.Re;
}

double cImag(struct complex C1)
{
    return C1.Im;
}

struct complex cConj(struct complex C1)
{
    struct complex temp;
    temp.Re = C1.Re;
    temp.Im = -C1.Im;
    return temp;
}

double cAbs(struct complex C)
{
    int a = C.Re, b = C.Im;
    return sqrt(a*a+b*b);
}

double cArg(struct complex C)
{
    int a = C.Re, b = C.Im;
    if (a == 0)
        if (b == 0)
            return INT_MIN;
        else
            return pi/2;
    else
        if (b < 0)
            return -atan(-b/abs(a));
        else
            return atan(b/abs(a));
    
}

struct complex cMul(struct complex C1, struct complex C2)
{
    struct complex temp;
    temp.Re = C1.Re*C2.Re - C1.Im*C2.Im;
    temp.Im = C1.Re*C2.Im + C1.Im*C2.Re;
    return temp;
}

struct complex cDiv(struct complex C1, struct complex C2)
{
    struct complex temp;
    temp.Re = (C1.Re*C2.Re + C1.Im*C2.Im)/cAbs(C2);
    temp.Im = (C2.Re*C1.Im - C2.Im*C1.Re)/cAbs(C2);
    return temp;
}

/*struct complex cRead(char *str)
{

    int i, l = strlen(str), c=0;
    double a, b;
    int f = 0   ;
    char t[100];
    struct complex temp;
    for (i = 0; i < l; i++)
    {
        if ( (str[i] != '+') && (str[i] != 'i') && (str[i] != '-') && (str[i] != '.'))
        {
            t[c] = str[i];
            c++;
        }
        else
        {
            if (f==0)
            {
                a = atof(t);
                f=1;
            }
            else
                b = atof(t);
            strcpy(t, "\0");
            c = 0;
        }
    }
    temp.Re = a;
    temp.Im = b;
    return temp;
}*/

struct complex cRead(double a, double b)
{
    struct complex temp;
    temp.Re = a;
    temp.Im = b;
    return temp;
}

int main()
{
    char s[100];
    double a, b;
    struct complex C1, C2;
    printf("Р’РІРµРґРёС‚Рµ РєРѕРјРїР»РµРєСЃРЅРѕРµ С‡РёСЃР»Рѕ РІ С„РѕСЂРјР°С‚Рµ a, b: ");
    scanf("%lf%lf", &a, &b);
    C1 = cRead(a, b);
    cPrint(C1);
    printf("Р’РІРµРґРёС‚Рµ РєРѕРјРїР»РµРєСЃРЅРѕРµ С‡РёСЃР»Рѕ РІ С„РѕСЂРјР°С‚Рµ a,b: ");
    scanf("%lf%lf", &a, &b);
    C2 = cRead(a,b);
    cPrint(C2);
    printf("РЎСѓРјРјР°: ");
    cPrint(cAdd(C1, C2));
    printf("Р Р°Р·РЅРѕСЃС‚СЊ: ");
    cPrint(cSub(C1, C2));
    printf("РџСЂРѕРёР·РІРµРґРµРЅРёРµ: ");
    cPrint(cMul(C1, C2));
    printf("Р§Р°СЃС‚РЅРѕРµ: ");
    cPrint(cDiv(C1, C2));
    printf("РњРѕРґСѓР»СЊ 1-РѕРіРѕ: %f: \n", cAbs(C1));
    printf("РђСЂРіСѓРјРµРЅС‚ 1-РѕРіРѕ: %f: \n", cArg(C1)); 
    printf("РЎРѕРїСЂСЏР¶С‘РЅРЅРѕРµ 1-РѕРіРѕ: "); cPrint(cConj(C1));
    printf("Re 1-РѕРіРѕ: %f: \n", cReal(C1));
    printf("Im 1-РѕРіРѕ: %f: \n", cImag(C1));
    return 0;
}
