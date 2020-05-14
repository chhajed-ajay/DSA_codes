#include<stdio.h>
#define DUMMY 0

int decide_n(int no_of_inputs)
{
	int temp = 2;
	while(no_of_inputs > temp)
		temp *= 2;

	return temp;
}

void build_seg_tree(int A[], int ST[], int n)
{
	int i;
	for(i = 0; i < n; i++)
		ST[n - 1 + i] = A[i];

	for(i = n - 2; i > -1; i--)
		ST[i] = ST[(2 * i) + 1] + ST[(2 * i) + 2];
}

void update(int ST[], int A[], float i, int x, int n)
{
	A[(int)i] = x;
	ST[n - 1 + (int)i] = x;
	i = ((n - 1 + i) - 1) / 2;

	while(i >= 0)
	{
		ST[(int)i] = ST[(2 * (int)i) + 1] + ST[(2 * (int)i) + 2];
		i = (i - 1) / 2;
	}
}

int RSQ1(int ST[], int A[], int i, int j, int s, int e, int p, int n)// range_sum_query1
{
	if(j < s || i > e)
		return A[n];
	if(i <= s && e <= j)
		return ST[p];

	int m = (s + e) / 2, l1, l2;

	l1 = RSQ1(ST, A, i, j, s, m, (2 * p) + 1, n);
	l2 = RSQ1(ST, A, i, j, m + 1, e, (2 * p) + 2, n);

	return(l1 + l2);
}

int RSQ(int ST[], int A[], int i, int j, int n)// range_sum_query
{
	return RSQ1(ST, A, i, j, 0, n - 1, 0, n);
}

int main()
{
	int i, no_of_inputs, n, result;
	scanf("%d", &no_of_inputs);
	n = decide_n(no_of_inputs);
	int A[n + 1], ST[2 * n];
	for(i = 0; i < n + 1; i++)
	{
		if(i < no_of_inputs)
			scanf("%d", &A[i]);
		else
			A[i] = DUMMY;
	}

	build_seg_tree(A, ST, n);
	// for(i = 0; i < (2 * n) - 1; i++)
	// 	printf("%d ", ST[i]);

	// update(ST, A, 1, 2, n);

	// for(i = 0; i < (2 * n) - 1; i++)
	// 	printf("%d ", ST[i]);

	result = RSQ(ST, A, 1, 4, n);
	printf("%d ", result);
	return 0;
}

