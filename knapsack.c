#include <stdio.h>
 
int max(int a, int b) { return (a > b) ? a : b; }

int knapSack(int W, int wt[], int val[], int n)
{
    
    if (n == 0 || W == 0)
        return 0;
 
    if (wt[n - 1] > W)
        return knapSack(W, wt, val, n - 1);
 
    else
        return max(
            val[n - 1]
                + knapSack(W - wt[n - 1],
                           wt, val, n - 1),
            knapSack(W, wt, val, n - 1));
}
 
int main()
{
    int wt[10],n,val[10],W;
    printf("Enter the value of n :");
    scanf("%d",&n);
    printf("Enter the weights :");
    for(int i=0;i<n;i++){
        scanf("%d",&wt[i]);
    }
    printf("Enter the values of each weights :");
    for(int i=0;i<n;i++){
        scanf("%d",&val[i]);
    }
    printf("Max capacity of the sack:");
    scanf("%d",&W);
    // int val[] = { 60, 100, 120 };
    // int wt[] = { 10, 20, 30 };
    // int W = 50;
    // int n = sizeof(val) / sizeof(val[0]);
    printf("%d", knapSack(W, wt, val, n));
    return 0;
}