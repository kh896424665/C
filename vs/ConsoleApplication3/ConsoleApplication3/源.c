#include <stdio.h>
#define N 200000
int main()
{
	int n, length;
	int a[N], sum[N] = { 0 }, b[50];
	int i, j, k, s = 20000, t, r = 0, p = 0;
	int *q;
	q = a;
	for (i = 0; scanf_s("%d%d", &n, &length); i++)
	{

		for (j = 0; j<n; j++)
		{
			scanf_s("%d", q++);
		}

		for (k = 0, t = 0; k<n; k++)
		{
			sum[t] += a[k];
			p++;
			if (p == length) { k -= length - 1; p = 0; t++; }

		}
		for (i = 0; i<t; i++)
			if (s>sum[i]) s = sum[i];
		b[r++] = s;

	}
	for (i = 0; i<r; i++)
		printf("%d\n", b[i]);
}