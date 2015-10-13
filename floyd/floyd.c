#include <stdio.h>
#include <stdlib.h>

int n;
int i, j;
int weight[10][10];
int distance[10][10];

void floyd(int n, int (*w)[10], int (*d)[10]);
int min(int a, int b);
void copy_arr(int (*dest)[10], int (*src)[10], int size);
void print_arr(int (*arr)[10], int size);
int main(void)
{
	printf("Enter the number of nodes : ");
	scanf("%d", &n);
	printf("Enter the adjacency matrix : \n");

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			scanf("%d", &weight[i][j]);
			if (weight[i][j] == 0)
				weight[i][j] = 999;
		}
	}

	floyd(n, weight, distance);
	print_arr(distance, n);

	return 0;
}

void floyd(int n, int (*w)[10], int (*d)[10])
{
	int i, j, k;

	copy_arr(distance, weight, 3);

	for (k = 1; k <= n; k++) {
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= n; j++) {
				distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
				printf("%d ", distance[i][j]);
			}
		}
	}
	
}

int min(int a, int b)
{
	if (a < b)
		return a;
	else 
		return b;
}

void copy_arr(int (*dest)[10], int (*src)[10], int size)
{
	int i, j;

	for (i = 1; i <= size; i++) {
		for (j = 1; j <= size; j++) {
			dest[i][j] = src[i][j];	
		}
	}
}

void print_arr(int (*arr)[10], int size) 
{
	int i, j;
	for (i = 1; i <= size; i++) {
		for (j = 1; j <= size; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}
