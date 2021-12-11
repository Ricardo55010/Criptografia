#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "time.h"

int primalidad(long long int);
int exponenciar(long long int,long long int,long long int);

int main(){
	  long long int n;
	  printf("Ingrese un número impar n\n");
	  scanf("%lld",&n);
	  primalidad(n);
}

int primalidad(long long int n){
	int k=0;
	long long int m=n-1;
	printf("n=%lld\n",n);
	printf("n-1=%lld\n",n-1);
	/*while((n-1)!=((pow(2,k))*m)){
		printf("%d != (2^%d)*%d\n",n-1,k,m);
		m++;
		if((n-1)==((pow(2,k))*m)){
			printf("Es m impar?");	
			if(m%2==0){
				k++;
				m=0;
				printf(" No\n");	
			}
			else{
				printf(" Si\n");
				printf("%d = (2^%d)*%d\n",n-1,k,m);
				printf("por lo tanto k=%d; m=%d\n",k,m);
			}
		}
		
	}*/
	if(m%2==1){
		printf("m=%lld es impar con k=%d\n",m,k);
	}
	else{
		while(m%2==0){
		printf("m=%lld es par con k=%d\n",m,k);
			m=m/2;
			k++;
		}
		printf("m=%lld es impar con k=%d\n",m,k);
	printf("%lld = (2^%d)*%lld\n",n-1,k,m);
	}
	srand(time(NULL));
	long long int a= (rand()%(n-2)) +1;
	printf("Se escogió un numero random a=%lld\n",a);
	int b= exponenciar(a,m,n);
	printf("b=%d^%d mod %d=%d\n",a,m,n,b); 
	if(b!=1){
		printf("Como b!=1 continuamos al siguiente paso\n");
		for(k;k!=0;k--){
			if(b==n-1){
				printf("b=-1 mod %d =%d por lo tanto n=%d es primo\n",n,b,n);
			return 1;
			}
			else{
				b=exponenciar(b,2,n);
			}
		}
		printf("Es compuesto");
		return 0;
	}
	else{
		printf("n=%d es primo",n);
	}
	return -1;
}

int exponenciar(long long int x,long long int a,long long int n){
	printf("Entra en acción el algorimo de exponenciación\n");
	long long int b[40];
	int i=0;
	long long int z=1;
	printf("x=%lld\n",x);
	printf("a=%lld\n",a);
	printf("n=%lld\n",n);
	printf("b=");
	while(a!=0){	
		if(a==1){
			b[i]=1;	
			a=a-1;
		}
		else{
			if(a%2==0){
				b[i]=0;
			}
			else{
				b[i]=1;
			}
			a=a/2;
		}
		printf("%lld",b[i]);
	i++;	 
	}
	printf("\n");
	printf("i	bi	z=z2	z=x*z\n");
	for(i=i-1;i!=-1;i--){
		z=(int)pow(z,2) %n;
		printf("%d	%lld	%lld	",i,b[i],z);
		if(b[i]==1){
			z=x*z%n;
			printf("%lld\n",z);
		}
		else{
			printf("  \n");
		}
	}
	return z;
}
