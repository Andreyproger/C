#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Complex{
	double Re;
	double Im;
}Complex;

Complex cRead(){
	Complex t;
	printf("\nReal part:");
	scanf("%lf", &t.Re);
	/*printf*/
	printf("\nImage part:");
	scanf("%lf", &t.Im);
	return t;
}

Complex cAdd(const Complex C1, const Complex C2){
	Complex C;
	C.Re = C1.Re + C2.Re;
	C.Im = C1.Im + C2.Im;
	return C;
}

Complex cSub(const Complex C1, const Complex C2){
	Complex C;
	C.Re = C1.Re - C2.Re;
	C.Im = C1.Im - C2.Im;
	return C;
}

Complex cMul(const Complex C1, const Complex C2){
	Complex C;
	C.Re = C1.Re*C2.Im - C2.Re* C1.Im;
	C.Im = C1.Im* C2.Re + C2.Im*C1.Re;
	return C;
}

double cReal(const Complex C){
	return C.Re;
}

double cImag(const Complex C){
	return C.Im;
}

Complex CConj(const Complex C){
	Complex C1=C;
	C1.Im = -C.Im;
	/*= {C.Re,-C.Im};*/
	return C1;
}

double Modul(const Complex C){
	double r;
	r = sqrt(C.Re*C.Re + C.Im*C.Im);
	return r;
}

double Arg(const Complex C1){
	double result, cf,sf, Re1 = C1.Re, Im1 = C1.Im;
	
	cf = Re1/(sqrt(Re1*Re1+ Im1*Im1));
	sf = Im1/(sqrt(Re1*Re1+ Im1*Im1));
	/*No output*/
	return atan(sf/cf);
}

Complex cDiv(const Complex C1, const Complex C2){
	Complex C;
	C.Re = (C1.Re*C2.Re + C1.Im*C2.Im)/Modul(C2);
	C.Im = (C2.Re*C1.Im + C2.Im*C1.Re)/Modul(C2); 
	return C;
}

void Complex_Output(Complex C){
	if(C.Im>=0){
		printf("\n%lf+%lf*i", C.Re, C.Im);
		}
	else printf("\n%lf%lf*i",C.Re, C.Im);
}


int main(){
	Complex C1, C2, CADD;
	C1 = cRead();
	C2 = cRead();
	Complex_Output(C1);
	Complex_Output(C2);
	CADD = cAdd(C1, C2);
	Complex_Output(CADD);
	Complex_Output(cMul(C1,C2));
	printf("\nArg(C1) = %lf", Arg(C1));
	printf("\nMODUL(C2) = %lf", Modul(C1));
	return 0;
}
