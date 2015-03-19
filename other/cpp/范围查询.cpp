/******************************************************************************************
 * 范围查询
 * 来源: http://dsa.cs.tsinghua.edu.cn/oj/problem.shtml?id=400

 * Feng Wang, wangfengjs@gmail.com
 * Computer Science and Technology, BIT
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#include <cstdio>
using namespace std;


int partition(int *point, int lo, int hi)
{
	int key = point[lo];

	while (lo < hi)
	{
		while (lo < hi && point[hi] >= key)
		{
			hi--;
		}
		point[lo] = point[hi];
		while (lo < hi && point[lo] <= key)
		{
			lo++;
		}
		point[hi] = point[lo];
	}
	point[lo] = key;

	return lo;
}

void quickSort(int *point, int lo, int hi)
{
	if (lo < hi)
	{
		int k = partition(point, lo, hi);
		quickSort(point, lo, k-1);
		quickSort(point, k+1, hi);
	}
}

// 二分查找
void binarysearch(int &a, int &b, int *A, int n)
{
	int lo = 0, hi = n-1;
	while(1 < hi - lo)
	{
		int mi = (lo+hi) >> 1;
		a < A[mi] ? hi = mi : lo = mi;
	}
	a = a <= A[lo]? lo : hi;

	lo = 0, hi = n-1;
	while(1 < hi - lo)
	{
		int mi = (lo+hi) >> 1;
		b < A[mi] ? hi = mi : lo = mi;
	}
	b = b >= A[hi]? hi : lo;
}

int main(int argc, char **argv)
{
	int n, m;
	scanf("%d%d", &n, &m);

	int *point = new int[n];
	for (int i=0; i<n; i++)
	{
		scanf("%d", &point[i]);
	}

	quickSort(point, 0, n-1);

	int a, b;
	for (int i=0; i<m; i++)
	{
		scanf("%d%d", &a, &b);

		if ((a > point[n-1] && b > point[n-1]) || (a < point[0] && b < point[0]))
		{
			printf("0\n");
			continue;
		}

		binarysearch(a, b, point, n);

		printf("%d\n", b-a+1);

	}
	return 0;
}
