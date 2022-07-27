//4.Write program to do the following:
	//b. Check whether a given graph is connectedor not using DFS method.
#include<stdio.h>
#include<stdlib.h>

void dfs(int arr[10][10],int start,int visited[], int n){
	visited[start]=1;
	// printf("%d ",start);
	for(int i=0;i<n;i++){
		if(arr[start][i]==1 && visited[i]==0){
			dfs(arr,i,visited,n);
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

	for (int i = 0; i < n; ++i)
	{
		if(i!=0 && visited[i]==0){
			printf("\nDisconnected Graph\n");
			return 0;
		}
		if(visited[i]==0)
			dfs(arr,i,visited,n);
	}
	printf("\nConnected Graph\n");
}
