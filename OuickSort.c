//9. Sort a given set of N integer elements using Quick Sort technique and compute its time taken

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int arr[],int i,int j){
	if(i==j){
		return;
	}
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;

}

int partition(int arr[],int si,int ei){
	int temp=arr[si];
	int count=0;
	for (int i = si+1; i <= ei; ++i)
	{
		if(temp>arr[i]){
			count++;
		}
	}
	swap(arr,si,si+count);

	int i=si, j=ei;

	while(i<j){
		if(arr[i]<temp){
			i++;
		}
		else if(arr[j]>=temp){
			j--;
		}
		else{
			swap(arr,i,j);
			i++;
			j--;
		}
	}
	return si+count;

}


void quickSort(int arr[],int si,int ei){
	if(si>=ei){
		return;
	}

	int i=partition(arr,si,ei);
	quickSort(arr,si,i-1);
	quickSort(arr,i+1,ei);
}


int main(){
	int arr[5000],n;
	printf("Enter the number of elements in the Array :");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		arr[i]=(rand() % (1 - 5000 + 1)) + 1;
	}

	clock_t start=clock();
	quickSort(arr,0,n-1);
	clock_t end=clock();

	printf("Time taken by Quick Sort is %f",(double)(end-start)/CLOCKS_PER_SEC);
}