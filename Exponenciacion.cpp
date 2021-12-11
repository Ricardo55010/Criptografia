#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "time.h"

int exponenciar(int,int,int);

int main(){
	int x,a,n;
	printf("Ingrese el valor base (x)\n");
	scanf("%d",&x);
	printf("Exponente (a)\n");
	scanf("%d",&a);
	printf("Divisor (n)\n");
	scanf("%d",&n);
	exponenciar(x,a,n);

}

int exponenciar(int x,int a,int n){
	int b[40];
	int i=0;
	int z=1;
	printf("x=%d\n",x);
	printf("a=%d\n",a);
	printf("n=%d\n",n);
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
		printf("%d",b[i]);
	i++;	 
	}
	printf("\n");
	printf("i	bi	z=z2	z=x*z\n");
	for(i=i-1;i!=-1;i--){
		z=(int)pow(z,2) %n;
		printf("%d	%d	%d	",i,b[i],z);
		if(b[i]==1){
			z=x*z%n;
			printf("%d\n",z);
		}
		else{
			printf("  \n");
		}
	}
	return z;
}
