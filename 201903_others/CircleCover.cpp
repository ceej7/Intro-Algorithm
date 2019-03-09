#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include <algorithm>

using namespace::std;
const int INF = 0x3f3f3f3f;
const double bias = 1e-8;
int n; double r;

class Point
{
public:
	double x;
	double y;
	Point(double _x, double _y)
		:x(_x), y(_y)
	{

	}
};

vector<Point> points;
double dis(Point& a, Point &b)
{
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

int search(int a, int b)
{
	if (dis(points[a], points[b]) > 2 * r)
	{
		return 1;
	}
	Point mid((points[a].x + points[b].x) / 2, (points[a].y + points[b].y) / 2);

	double ang = atan2(points[b].y - points[a].y,points[a].x - points[b].x);
	double t = dis(points[a], mid);
	double tempDis = sqrt(r*r - t * t);
	//center1
	Point c1(mid.x + tempDis * sin(ang), mid.y + tempDis * cos(ang));
	int count1 = 0;
	for (int i = 0; i < points.size(); i++)
	{
		if (dis(c1, points[i]) < r + bias)
		{
			count1++;
		}
	}

	//center2
	Point c2(mid.x - tempDis * sin(ang), mid.y - tempDis * cos(ang));
	int count2 = 0;
	for (int i = 0; i < points.size(); i++)
	{
		if (dis(c2, points[i]) < r + bias)
		{
			count2++;
		}
	}

	if (count1 == count2 && count1 == 0)
	{
		return 1;
	}
	else if (count1 < count2)
	{
		return count2;
	}
	else {
		return count1;
	}
}

int main()
{
	int cnt;
	cin >> cnt;

	while (cnt--)
	{
		//initial
		points.clear();
		cin >> n ;
		cin >> r;
		int maxCount = 1;
		for (int i = 0; i < n; i++)
		{
			double x, y;
			cin >> x >> y;
			Point p(x, y);
			points.push_back(p);
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				int temp = search(i, j);
				if (temp > maxCount)
				{
					maxCount = temp;
				}
			}
		}
		cout << maxCount << endl;
	}
}