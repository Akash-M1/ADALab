//2.b. Implement Recursive Linear search and determine the time required to search an element. Repeat the experiment for different values of N and plot a graph of the time taken versus N.

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void delay(){
	for (int i = 0; i < 500000; ++i)
	{
		int d=i/33;
	}
}


int linearSearch(int arr[], int k,int si,int ei){
	if(si>ei){
		return -1; 
	}
	if(arr[si]==k){
		return si;
	}
	delay();
	return linearSearch(arr,k,si+1,ei);
}


int main(){
	int arr[5000],n;
	printf("Enter the number of elements in the Array :");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		arr[i]=(rand() % (1 - 5000 + 1)) + 1;
	}
	clock_t start=clock();
	int i=linearSearch(arr,-1,0,n-1);
	clock_t end=clock();

	printf("Time taken by Linear Search is %f",(double)(end-start)/CLOCKS_PER_SEC);
}