#include <stdio.h>
	void merge(int *output, int l, int m, int h)
	{
		int A[h];
		int low = l;
		int high = m;
		int k = m;
		int index = 0;
		while (low < k && high < h)
		{
			if (output[low] > output[high])
			{
				A[index++] = output[high++];
			}
			else
			{
				A[index++] = output[low++];
			}
		}
		while (low < k)
		{
			A[index++] = output[low++];
		}
		while (high < k)
		{
			A[index++] = output[high++];
		}
		for (int i = 0; i < h; i++)
		{
			output[i] = A[i];
		}
	}
int main()
{
	int seq;
	scanf("%d", &seq);
	int bigsize = 0, sizes = 0 ;
	for (int i = 0; i < seq; i++)
	{
		sizes = 0 ;
		scanf("%d", &sizes);
		bigsize += sizes ;
	}
	int output[bigsize] ;
	for (int i = 0; i < bigsize; i++)
		scanf("%d", &output[i]);

	int left = 0, mid = 1 , right = 1;
	while (1)
	{
		while (output[mid-1] < output[mid] && mid != bigsize - 1)
		{
			mid++;
		}
		
		if (mid == bigsize - 1)
		{
			break;
		}
		right = mid + 1;
		while (output[right - 1] < output[right] && right != bigsize)
		{
			right++;
		}   
		merge(output, left, mid, right);
	}
	for (int i = 0; i < bigsize; i++)
		printf("%d ",output[i]);
	return 0;
}