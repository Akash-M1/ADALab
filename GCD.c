//1.Write a recursive program to
	//b. T o find GCD
#include<stdio.h>

int gcd(int n, int m){
	if(m!=0){
		return gcd(m,n%m);
	}
	else{
		return n;
	}
}


int main(){
	int n,m;
	printf("Enter number for which GCD to be found :");
	scanf("%d %d",&n,&m);
	int res=gcd(n,m);
	printf("GCD of %d and %d is %d\n",n,m,res);
}