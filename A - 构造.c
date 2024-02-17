#include<stdio.h>
int main()
{
	int n_sum = 0;
	int n1, k1,n,k;
	int re[150];
	for (int i = 0; i < 150; i++)re[i] = -1;
	int now = 1;
	scanf("%d", &n_sum);
	for (int i = 0; i < n_sum; i++)
	{
		scanf("%d%d", &n1, &k1);
		now = 1;
	begin:
		n = n1; k = k1;
		for (int q = 1; q <= n-1; q++)
		{
			for (int q2 = q + 1; q2 <= n; q2++)
			{
				if (re[q] == re[q2])
				{
					k--;
				}
				if (k < 0)
				{
					re[now++] = 1;
					if (now > n1+1)
					{
						
						goto end;
					}
					else
					{
						goto begin;
					}
					
				}
			}
		}
	end:
		if (k == 0)
		{
			printf("YES\n");
			for (int r = 1; r <= n1; r++)
			{
				printf("%d ", re[r]);
			}
			printf("\n");
			for (int t = 0; t < 150; t++) { re[t] = -1; }
		}
		else
		{
			printf("NO\n");
			for (int t = 0; t < 150; t++) { re[t] = -1; }

		}
	}
}