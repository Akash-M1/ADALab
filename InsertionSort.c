#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void delay(){
	for (int i = 0; i < 500000; ++i)
	{
		int d=i/33;
	}
}

void insertionSort(int arr[],int n){
	for (int i = 1; i < n ; ++i)
	{
		int temp=arr[i];
		int j;
		for(j=i-1;j>=0 && temp<arr[j]; j--){
			delay();
			arr[j+1]=arr[j];
		}
		arr[j+1]=temp;
	}
}

int main(){
	int arr[5000],n;
	printf("Enter the number of elements in the Array :");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		arr[i]=(rand() % (1 - 5000 + 1)) + 1;
	}
	// insertionSort(arr,n);

	// for (int i = 0; i < n; ++i)
	// {
	// 	printf("%d ",arr[i]);
	// }


	clock_t start=clock();
	insertionSort(arr,n);
	clock_t end=clock();

	printf("Time taken by Insertion Sort is %f",(double)(end-start)/CLOCKS_PER_SEC);
}