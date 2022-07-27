#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void delay(){
	for (int i = 0; i < 500000; ++i)
	{
		int d=i/33;
	}
}

void merge(int arr[],int si,int ei,int mid){
	int i=si,j=mid+1,k=si;
	int res[ei+1];
	while(i<=mid && j<=ei){
		if(arr[i]<arr[j]){
			res[k]=arr[i];
			k++;
			i++;
		}
		else if(arr[i]>arr[j]){
			res[k]=arr[j];
			k++;
			j++;
		}
	}
	while(i<=mid){
		res[k]=arr[i];
		i++;
		k++;
	}
	while(j<=ei){
		res[k]=arr[j];
		j++;
		k++;
	}
	for(int i=si;i<=ei;i++){
		arr[i]=res[i];
	}
}

void mergeSort(int arr[],int si,int ei){
	if(si>=ei){
		return;
	}
	delay();
	int mid=(si+ei)/2;

	mergeSort(arr,si,mid);
	mergeSort(arr,mid+1,ei);

	merge(arr,si,ei,mid);

}

int main(){
	int arr[5000],n;
	printf("Enter the number of elements in the Array :");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		arr[i]=(rand() % (1 - 5000 + 1)) + 1;
	}
	clock_t start=clock();
	mergeSort(arr,0,n-1);
	clock_t end=clock();

	printf("Time taken by Merge Sort is %f",(double)(end-start)/CLOCKS_PER_SEC);
}