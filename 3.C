#include<stdio.h>
#include<conio.h>
int max(int x, int y) {
    return (x > y) ? x : y;
}

int knapsack(int W, int wt[], int val[], int n) {
    int i, w;
    int k[20][20];
    
    for (i = 0; i < n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                k[i][w] = 0;
            } else if (wt[i - 1] <= w) {
                k[i][w] = max(val[i - 1] + k[i - 1][w - wt[i - 1]], k[i - 1][w]);
            } else {
                k[i][w] = k[i - 1][w];
            }
        }
    }
    
    return k[n][W];
}

void main() {
    int i, n, val[20], wt[30], W;
    clrscr();
    printf("Enter the number of items\n");
    scanf("%d", &n);

    printf("Enter value of items\n");
    for (i = 0; i < n; i++) {
	scanf("%d", &val[i]);
    }

    printf("Enter weights\n");
    for (i = 0; i < n; i++) {
	scanf("%d", &wt[i]);
    }

    printf("Enter the size of knapsack\n");
    scanf("%d", &W);

    printf("Optimal solution is: \n");
    printf("%d\n", knapsack(W, wt, val, n));

    getch();
}
