//7. Implement Johnson Trotteralgorithm to generate permutations

#include<stdio.h>
#include<stdlib.h>


int searchArray(int arr[], int n, int mobile){
	for(int i = 0; i < n;i++){
		if(arr[i]==mobile){
			return i+1;
		}
	}
	return 0;
}

int fact(int n){
	if(n==0 || n==1){
		return 1;
	}
	return n*fact(n-1);
}

int mobileSearch(int arr[], int n, int dir[]){
	int mobile=0, mobile_prev=0;
	for(int i=0;i<n;i++){
		if(dir[arr[i]-1]==0 && i!=0){
			if(arr[i]>arr[i-1] && arr[i]>mobile_prev){
				mobile=arr[i];
				mobile_prev=mobile;
			}
		}
	}

	for(int i = 0; i < n;i++){
		if(dir[arr[i]-1]==1 && i!=n-1){
			if(arr[i]>arr[i+1] && arr[i]>mobile_prev){
				mobile=arr[i];
				mobile_prev=mobile;
			}
		}
	}

	if(mobile != 0)
		return mobile;
	else
		return 0;
}

void permutationPrint(int arr[], int n, int dir[]){
	int mobile=mobileSearch(arr,n,dir);
	int getPos=searchArray(arr,n,mobile);

	if(dir[arr[getPos-1]-1]==0){
		int temp=arr[getPos-1];
		arr[getPos-1]=arr[getPos-2];
		arr[getPos-2]=temp;
	}
	if(dir[arr[getPos-1]-1]==1){
		int temp=arr[getPos-1];
		arr[getPos-1]=arr[getPos];
		arr[getPos]=temp;
	}


	for (int i = 0; i < n; ++i)
	{
		if(arr[i]>mobile && dir[arr[i]-1]==0){
			dir[arr[i]-1]=1;
		}

		else if(arr[i]>mobile && dir[arr[i]-1]==1){
			dir[arr[i]-1]=0;
		}
	}

	for (int i = 0; i < n; ++i)
	{
		printf("%d",arr[i]);
	}

	printf(" ");
}

void johnsonTrotter(int n){
	int dir[300];
	int arr[300];
	for(int i=0;i<n;i++){
		arr[i]=i+1;
	}

	for (int i = 0; i < n; ++i)
	{
		printf("%d",arr[i]);
	}

	printf(" ");

	for (int i = 0; i < n; ++i)
	{
		dir[i]=0;
	}

	for (int i = 1; i < fact(n); ++i)
	{
		permutationPrint(arr, n, dir);
	}

}


int main(){
	int n;
	printf("Enter the value of N : ");
	scanf("%d",&n);
	printf("Permutations of 5 digit number is \n");
	johnsonTrotter(n);
}