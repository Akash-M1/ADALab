//6. Write program to obtain the T opological ordering of vertices in a given digraph.

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <stdbool.h>

int q[30];
int f=-1,r=-1;


bool isEmpty(){
	if(f==-1 && r==-1){
		return true;
	}
	return false;
}

void enQueue(int i){
	if(f==-1 && r==-1){
		f=0;
	}
	q[++r]=i;
	return;
}

int deQueue(){
	if(isEmpty()){
		return -1;
	}
	if(f==r){
		int temp=q[f];
		f=-1;
		r=-1;
		return temp;
	}
	int temp=q[f];
	f++;
	return temp;

}


void topoLogicalSorting(int arr[10][10],int n){
	int sorted[10];
	int k=0;
	int indegrees[10];
	for (int i = 0; i < n; ++i)
	{
		indegrees[i]=0;
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(arr[i][j]==1)
				indegrees[j]++;
		}
	}

	for (int i = 0; i < n; ++i)
	{
		if(indegrees[i]==0){
			enQueue(i);
		}
	}

	int visitedNodes=0;
	while(!isEmpty()){
		int snode=deQueue();
		sorted[k++]=snode;
		for(int i=0;i<n;i++){
			if(arr[snode][i]==1){
				if(--indegrees[i]==0){
					enQueue(i);
				}
			}
		}
		visitedNodes++;
	}
	if(visitedNodes!=n){
		printf("\nError!! Graph has a cycle\n");
		return;
	}

	for (int i = 0; i < n; ++i)
	{
		printf("%d ",sorted[i]);
	}
}

int main(){
	int arr[10][10];
	int n,m;
	int visited[10];
	printf("Enter number of Vertices :");
	scanf("%d",&n);
	printf("Enter number of Edges :");
	scanf("%d",&m);
	for(int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j)
		{
			arr[i][j]=0;
		}
	}
	for (int i = 0; i < m; ++i)
	{
		int a,b;
		printf("Enter the Edge %d :",(i+1));
		scanf("%d %d",&a,&b);
		arr[a][b]=1;
	}
	topoLogicalSorting(arr,n);
}
