#include<stdio.h>

void toh(int n,char s,char d,char a){
	if(n==1){
		printf("Moving from %c to %c\n",s,d);
		return;
	}
	toh(n-1,s,a,d);
	printf("Moving from %c to %c\n",s,d);
	toh(n-1,a,d,s);
}

int main(){
	int n;
	char s,d,a,temp;
	printf("Number of Discs :");
	scanf("%d",&n);
	printf("Enter the Names of Source Destination and Aux towers :");
	scanf("%c",&temp);
	scanf("%c %c %c",&s,&d,&a);
	toh(n,s,d,a);
}