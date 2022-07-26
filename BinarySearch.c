#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void delay(){
	for (int i = 0; i < 5000000; ++i)
	{
		int d=i/33;
	}
}


int binarySearch(int arr[], int k, int si, int ei){
	if(si>ei){
		return -1;
	}
	delay();
	int mid=(si+ei)/2;
	if(arr[mid]==k){
		return mid;
	}
	else if(arr[mid]>k){
		return binarySearch(arr,k,si,mid-1);
	}
	else{
		return binarySearch(arr,k,mid+1,ei);
	}
}

void swap(int arr[], int i, int j){
	if(i==j){
		return;
	}
	int temp=arr[i];
	arr[i]=arr[j];
	arr[j]=temp;
}

void bubbleSort(int arr[], int n){
	for(int i=n-1;i>=0;i--){
		for(int j=0;j<i;j++){
			if(arr[j]>arr[j+1]){
				swap(arr,j,j+1);
			}
		}
	}
}



int main(){
	int arr[5000],n;
	printf("Enter the number of elements in the Array :");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		arr[i]=(rand() % (1 - 5000 + 1)) + 1;
	}
	bubbleSort(arr,n);
	clock_t start=clock();
	int j=binarySearch(arr,-1,0,n-1);
	clock_t end=clock();

	printf("Time taken by Binary Search is %f",(double)(end-start)/CLOCKS_PER_SEC);

	// for (int i = 0; i < n; ++i)
	// {
	// 	printf("%d ",arr[i]);
	// }
	// int j=binarySearch(arr,109,0,n-1);
	// printf("%d\n",j);
}
