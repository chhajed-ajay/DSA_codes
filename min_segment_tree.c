#include<stdio.h>
#include<limits.h>

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
		ST[n - 1 + i] = i;

	for(i = n - 2; i > -1; i--)
	{
		if(A[ST[(2 * i) + 1]] > A[ST[(2 * i) + 2]])
			ST[i] = ST[(2 * i) + 2];
		else
			ST[i] = ST[(2 * i) + 1];
	}
}

void update(int ST[], int A[], float i, int x, int n)
{
	A[(int)i] = x;
	i = ((n - 1 + i) - 1) / 2;

	while(i >= 0)
	{
		if(A[ST[(2 * (int)i) + 1]] > A[ST[(2 * (int)i) + 2]])
			ST[(int)i] = ST[(2 * (int)i) + 2];
		else
			ST[(int)i] = ST[(2 * (int)i) + 1];
		i = (i - 1) / 2;
	}
}

int RMQ1(int ST[], int A[], int i, int j, int s, int e, int p, int n)// range_minimum_query1
{
	if(j < s || i > e)
		return n;
	if(i <= s && e <= j)
		return ST[p];

	int m = (s + e) / 2, l1, l2;

	l1 = RMQ1(ST, A, i, j, s, m, (2 * p) + 1, n);
	l2 = RMQ1(ST, A, i, j, m + 1, e, (2 * p) + 2, n);

	if(A[l1] < A[l2])
		return l1;
	else
		return l2;
}

int RMQ(int ST[], int A[], int i, int j, int n)// range_minimum_query
{
	return RMQ1(ST, A, i, j, 0, n - 1, 0, n);
}

int NextRightMin(int ST[], int A[], int i, int n)// don't put i = n - 1. if there is no num less than A[i] to the right of it then it returns 1
{
	int p = 0, s = 0, e = n - 1, j = n, m;

	while(p < n - 1)
	{
		m = (s + e) / 2;

		if(i <= m)
		{
			if(A[ST[(2 * p) + 2]] < A[i])
				j = (2 * p) + 2;
			p = (2 * p) + 1;
			e = m;
		}

		else
		{
			p = (2 * p) + 2;
			s = m + 1;
		}
	}

	//printf("%d %d %d %d %d ", m, j, p, s, e);

	while(j < n - 1)
	{
		if(A[ST[(2 * j) + 1]] < A[i])
			j = (2 * j) + 1;
		else
			j = (2 * j) + 2;
	}
	if(j - n + 1 == 1)
	{
		if(i >= 1)
			return -1;

		else if(A[1] > A[0])
			return -1;

		else
			return 1;
	}

	else
		return j - n + 1;
}

int NextLeftMin(int ST[], int A[], int i, int n)// don't put i = 0.if there is no num less than A[i] to the left of it then it returns 1
{
	int p = 0, s = 0, e = n - 1, j = n, m;

	while(p < n - 1)
	{
		m = (s + e) / 2;

		if(i >= m)
		{
			if(A[ST[(2 * p) + 1]] < A[i])
				j = (2 * p) + 1;
			p = (2 * p) + 2;
			s = m + 1;
		}

		else
		{
			p = (2 * p) + 1;
			e = m;
		}
	}

	while(j < n - 1)
	{
		if(A[ST[(2 * j) + 2]] < A[i])
			j = (2 * j) + 2;
		else
			j = (2 * j) + 1;
	}
	return j - n + 1;
}

int LastMin(int ST[], int A[], int i, int n)
{
	int p = 0;
	while(p < n - 1)
	{
		if(A[ST[(2 * p) + 2]] <= A[i])
			p = (2 * p) + 2;
		else
			p = (2 * p) + 1;
	}
	return p - n + 1;
}

int MinFromBegin(int ST[], int A[], int i, int n)
{
	int p = 0;
	while(p < n - 1)
	{
		if(A[ST[(2 * p) + 1]] <= A[i])
			p = (2 * p) + 1;
		else
			p = (2 * p) + 2;
	}
	return p - n + 1;
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
			A[i] = INT_MAX;
	}

	build_seg_tree(A, ST, n);
	// printf("%d\n", A[n]);
	// for(i = 0; i < (2 * n) - 1; i++)
	// 	printf("%d ", ST[i]);
	// printf("\n\n");
	// update(ST, A, 1, 1, n);
	// update(ST, A, 6, 14, n);

	// for(i = 0; i < (2 * n) - 1; i++)
	// 	printf("%d ", ST[i]);

	// result = RMQ(ST, A, 4, 6, n);
	// printf("%d ", result);

	result = NextRightMin(ST, A, 3, n);
	printf("%d ", result);
	
	// result = NextLeftMin(ST, A, 0, n);
	// printf("%d ", result);

	// result = LastMin(ST, A, 10, n);
	// printf("%d ", result);

	// result = MinFromBegin(ST, A, 5, n);
	// printf("%d ", result);

	return 0;
}