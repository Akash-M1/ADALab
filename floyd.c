#include<stdio.h>
#include<stdlib.h>

int min(int x,int y) {
	if(x<y){
		return x; 
	}
	else {
		return y; 
	}
}

void floyd(int p[][10],int n){
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				p[i][j]=min(p[i][j],p[i][k]+p[k][j]);
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
			arr[i][j]=9999;
		}
	}
	for (int i = 0; i < m; ++i)
	{
		int a,b,w;
		printf("Enter the Edge with weights %d :",(i+1));
		scanf("%d %d %d",&a,&b,&w);
		arr[a][b]=w;
	}
	floyd(arr,n);


	printf("Path Matrix :\n");
	for(int i = 0; i < n; i++){
		for(int j=0; j<n; j++){
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}


}