#include <stdio.h>
 
int max(int a, int b) { return (a > b) ? a : b; }

int knapSack(int W, int wt[], int val[],int n)
{
	int dp[100][100];
	for(int i = 0; i < n+1; i++){
		for(int j = 0; j < W+1; j++){
			dp[i][j]=0;
		}
	}
	int count=0;
	for(int i=n-1; i>=0; i--) {
		for(int w=0;w<=W;w++) {
			int ans;
			if(wt[i] <= w) {
				int ans1 = val[i] + dp[i+1][w-wt[i]];
				int ans2 = dp[i+1][w];
				ans = max(ans1, ans2);
			}
			else{
				ans = dp[i+1][w];
			}
			dp[i][w] = ans;
		}
	}
	for(int j = 0; j < W+1; j++){
		printf("%d ",dp[0][j]);
	}
	printf("\n");
	return dp[0][W];
}


int main()
{
    // int wt[10],n,val[10],W;
    // printf("Enter the value of n :");
    // scanf("%d",&n);
    // printf("Enter the weights :");
    // for(int i=0;i<n;i++){
    //     scanf("%d",&wt[i]);
    // }
    // printf("Enter the values of each weights :");
    // for(int i=0;i<n;i++){
    //     scanf("%d",&val[i]);
    // }
    // printf("Max capacity of the sack:");
    // scanf("%d",&W);
    int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    printf("%d", knapSack(W, wt, val, 3));
    return 0;
}