#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "time.h"

int euclides(int,int);
int inverso(int, int);

int main(){
	int m,n,r,inv;
	printf("Hola, este programa calcula el maximo comun divisor de dos numeros dados para encontrar si dicho número tiene inverso multiplicativo\n");
	printf("Ingresa el valor m (número mayor)\n");
	scanf("%d",&m);
	printf("Ingresa el valor n (número menor)\n");
	scanf("%d",&n);
	r= euclides(m,n);
	printf("El maximo comun divisor de %d y %d es %d, por lo tanto",m,n,r);
	if(r==1){
		printf(" %d tiene inverso multiplicativo\n ",n);
		inv=inverso(m,n);
		printf("El inverso multiplicativo es: %d",inv);
	}
	else{
		printf(" %d no tiene inverso multiplicativo\n ",n);
	}
	return 0;
}

int euclides(int m,int n){
		int r;
		while(n!=0){//ciclo while en el que se aplica el algoritmo de euclides hasta obtener un número m que al ser dividido por un numero n no deje ningun residuo r
		r=m %n;
		m=n;
		n=r;
	}
	return m;
}

int inverso(int m,int n){
	int q[50];
	int t[50];
	int r;
	int i=1;
	int j=2;
	int auxm=m;
	int auxn=n;
	t[0]=0;
	t[1]=1;
	while(auxn!=0){//ciclo while en el que se aplica el algoritmo de euclides hasta obtener un número m que al ser dividido por un numero n no deje ningun residuo r
		q[i]= auxm / auxn;
		r=auxm %auxn;
		printf("%d/%d;r=%d;",auxm,auxn,r);
		auxm=auxn;
		auxn=r;
		printf("q(%d)=%d\n",i,q[i]);
		i++;

	}
	while(i!=1){
		t[j]=(t[j-2]-(q[j-1]*t[j-1]))%m;
		if(t[j]<0){
			t[j]=m+t[j];
		}
		printf("t(%d)=%d\n",j,t[j]);
		j++;
		i--;
	}
	return t[j-2];
}
