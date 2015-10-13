#include <stdio.h>
#include <stdlib.h>

int bin(int n, int k);
int minimum(int a, int b);
int main(void)
{
	int n, k;	
	printf("input n : ");
	scanf("%d", &n);
	printf("input k : ");
	scanf("%d", &k);

	printf("%dC%d is ... %d\n", n, k, bin(n, k));

	return 0;
}

int bin(int n, int k)
{
	int i, j;
	int **arr;

	arr = (int **)malloc(sizeof(int *) * n+1);
	for (i = 0; i <= n; i++) {
		arr[i] = (int *)malloc(sizeof(int) * k);
	}

	for (i = 0; i <= n; i++) {
		for (j = 0; j <= minimum(i, k); j++) {
			if (j == 0 || j == i)
				arr[i][j] = 1;
			else 
				arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
		}
	}
	return arr[n][k];
}

int minimum(int a, int b)
{
	if (a > b)
		return b;
	else 
		return a;
}
