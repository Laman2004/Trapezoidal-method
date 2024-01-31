#include<stdio.h>
#include<omp.h>

float f(float x){
	float y;
	y=5*x;
	return y;
}
int main(){
	float sum=0.0,x,h,a=1.0,b=5.0,y=0;
	int i,n=100;
	h=(b-a)/n;
#pragma omp parallel for private(i,x) reduction(+: sum)
	for (i=1;i<=n-1;i++){
		x=a+i*h;
		sum+=f(x);
	}
	y=(f(a)+f(b)+2*sum)*h/2;
	printf("%f",y);
}
