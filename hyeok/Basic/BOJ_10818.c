#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int n;
	int min, max = 0;
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		if (i == 0)
		{
			min = x;
			max = x;
		}
		else
		{
			if (min > x)
				min = x;
			if (max < x)
				max = x;
		}
	}
	printf("%d %d", min, max);
	return 0;
}