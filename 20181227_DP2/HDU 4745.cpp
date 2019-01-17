#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <algorithm>

using namespace std;

int dpArray[2020][2020];
int value[2020];
int n;

//dpArray[i][j]=max{dpArray[i+1][j],dpArray[i][j-1],dpArray[i-1][j-1]+2(if(value[i]==value[j]))}
//special case 
//4
//1 1 2 1 + 1 1 2 1
int main()
{
	while (cin >> n)
	{
		if (n == 0)
			return 0;
		memset(dpArray, 0, sizeof(dpArray));
		for (int i = 1; i <= n; i++)
		{
			int tmp;
			cin >> tmp;
			value[i] = value[n + i] = tmp;
		}
		for (int i = 1; i <= 2 * n; i++)
		{
			dpArray[i][i] = 1;
		}
		for (int l = 1; l < n * 2 ; l++)
		{
			for (int i = 1; i <= n * 2; i++)
			{
				int j = i + l;
				if (j <= 2 * n)
				{
					if (value[i] == value[j])
					{
						if (i + 1 == j)
						{
							dpArray[i][j] = 2;
						}
						else {
							dpArray[i][j] = dpArray[i + 1][j - 1] + 2;
						}
					}
					dpArray[i][j] = max(max(dpArray[i + 1][j], dpArray[i][j - 1]),dpArray[i][j]);
				}
			}
		}
		int res = 1;
		for (int i = 2; i <= n; i++)
		{
			int j = i + n - 2;
			if (value[i - 1] == value[j + 1] && dpArray[i][j] + 1 > res)
			{
				res = dpArray[i][j] + 1;
			}
		}
		for (int i = 1; i <= n; i++)
		{
			int j = i + n - 1;
			if (dpArray[i][j] > res)
			{
				res = dpArray[i][j];
			}
		}
		
		cout << res << endl;
	}
}