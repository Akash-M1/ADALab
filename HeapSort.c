#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b){
	int temp=*a;
	*a = *b;
	*b = temp;
}

void heapify(int arr[],int i,int n){
	int largest=i;
	int left=2*i+1;
	int right=2*i+2;

	if(left<n && arr[largest]<arr[left]){
		largest = left;
	}
	if(right<n && arr[largest]<arr[right]){
		largest=right;
	}

	if(largest != i){
		swap(&arr[i],&arr[largest]);

		heapify(arr,largest,n);
	}

}

void heapSort(int arr[],int n){
	for (int i = n/2-1; i >=0; i--)
	{
		heapify(arr,i,n);
	}

	for(int i = n-1; i>=0;i--){
		swap(&arr[i],&arr[0]);

		heapify(arr,0,i);
	}
}

void printArray(int arr[], int N)
{
	for (int i = 0; i < N; i++)
		printf("%d ", arr[i]);
	printf("\n");
}


int main(){
	int arr[]={5,9,2,15,3,8,6};

	heapSort(arr,7);
	printArray(arr,7);

}