#include <stdio.h>
#include <stdlib.h>

void warshall(int p[][10],int n){
	for(int k=0; k<n; k++){
		for(int i=0; i<n; i++){
			for (int j = 0; j < n; ++j)
			{
				p[i][j]=p[i][j]|(p[i][k]&p[k][j]);
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
	}
	warshall(arr,n);


	printf("Path Matrix :\n");
	for(int i = 0; i < n; i++){
		for(int j=0; j<n; j++){
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}


}