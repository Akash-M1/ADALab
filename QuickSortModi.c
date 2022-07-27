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

int partition(int A[], int l, int r) 
{ 
    int x = A[r];
    int i = l;
    for (int j = l ; j <=r ; j++) 
    { 
        if (A[j] <  x) 
        { 
            swap(A,i,j);
            i = i + 1;
        } 
    } 
    swap(A,i,r);
    return i;
}

int kthMin(int arr[],int si,int ei,int k){
	int i=partition(arr,si,ei);

	if(i==k-1){
		return arr[i];
	}
	else if(i < k-1)
		return kthMin(arr,i+1,ei,k);
	else
		return kthMin(arr,si,i-1,k);
}


int main(){
	int arr[5000],n;
	printf("Enter the number of elements in the Array :");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		arr[i]=(rand() % (1 - 5000 + 1)) + 1;
	}

	for (int i = 0; i < n; ++i)
	{
		printf("%d ",arr[i]);
	}

	printf("\n%d",kthMin(arr,0,n-1,4));
}