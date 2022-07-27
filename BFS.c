#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

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

void bfs(int arr[10][10], int start, int visited[], int n){
	visited[start]=1;
	enQueue(start);

	while(!isEmpty()){
		int pending=deQueue();
		printf("%d ",pending);
		for(int i=0;i<n;i++){
			if(arr[pending][i]==1 && visited[i]==0){
				enQueue(i);
				visited[i]=1;
			}
		}
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
		arr[b][a]=1;
	}
	for (int i = 0; i < n; ++i)
	{
		visited[i]=0;
	}
	int start;
	printf("Enter the starting vertex :");
	scanf("%d",&start);

	bfs(arr,start,visited,n);
}