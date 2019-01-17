#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string.h>
#include <limits.h>

using namespace std;

long long dpArray[2020];
int s[2020];
int  len[2020];
int n, m;

int main()
{
	while (scanf("%d%d", &n, &m) != EOF)
	{
		int counter = 0;
		for (int i = 1; i <= n; i++)
		{
			dpArray[i] = LLONG_MAX;
			scanf("%d", &len[i]);
			counter += len[i];
			s[i] = counter;
		}
		dpArray[0] = 0;
		s[0] = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = i; j >= 1; j--)
			{
				long long res = m - i + j;
				res =res- (long long)(s[i]-s[j-1]);
				if (res < 0)
				        continue;
				else {
					long long res2 = res * res*res;
					if (i == n) res2 = 0;
					if (dpArray[j-1]!=LLONG_MAX&&res2 + dpArray[j - 1] <= dpArray[i])
					{
						dpArray[i] = res2 + dpArray[j - 1];
					}
				}
			}
		}
		printf("%lld\n", dpArray[n]);
	}
}