#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
using namespace std;


int dpArray[2020][2020];
int m, n;
string x, y;

int main()
{
	while (cin >> m >> x >> n >> y)
	{
		memset(dpArray, 0, sizeof(dpArray));
		for (int i = 1; i <= m; i++) 
			dpArray[i][0] = i;
		for (int j = 1; j <= n; j++) 
			dpArray[0][j] = j;
		for (int i = 1; i <= m; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (x[i-1] == y[j-1])
				{
					dpArray[i][j] = dpArray[i - 1][j - 1];
				}
				else {
					dpArray[i][j] = dpArray[i - 1][j - 1]+1;
				}
				dpArray[i][j] = min(dpArray[i][j], min(dpArray[i - 1][j] + 1, dpArray[i][j - 1] + 1));
			}
		}
		cout << dpArray[m][n] << endl;
	}
}