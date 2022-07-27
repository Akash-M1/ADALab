//3.Sort a given set of N integer elements using Selection Sort technique and compute its time taken. Run the program for different values of N and record the time taken to sort.

#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void delay(){
	for (int i = 0; i < 500000; ++i)
	{
		int d=i/33;
	}
}

void swap(int arr[],int i,int j){
	if(i==j){
		return;
	}
	int temp=arr[i];
	arr[i]=arr[j];
	arr[j]=temp;
}

void selectionSort(int arr[],int n){
	for(int i=n-1;i>0;i--){
		int max=-999;
		int maxInd=0;
		for (int j = 0; j <= i; ++j)
		{
			delay();
			if(arr[j] > max){
				max=arr[j];
				maxInd=j;
			}
		}
		swap(arr,maxInd,i);
	}
}

int main(){
	int arr[5000],n;
	printf("Enter the number of elements in the Array :");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		arr[i]=(rand() % (1 - 5000 + 1)) + 1;
	}
	clock_t start=clock();
	selectionSort(arr,n);
	clock_t end=clock();

	printf("Time taken by Selection Sort is %f",(double)(end-start)/CLOCKS_PER_SEC);
}