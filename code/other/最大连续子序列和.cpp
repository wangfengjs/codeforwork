/************************************************************************
* 最大连续子序列和
* 参考: http://blog.csdn.net/hcbbt/article/details/10454947

* Feng Wang, wangfengjs@gmail.com
* Computer Science and Technology, BIT
* Copyright (c) 2006-2013. All rights reserved.                                                                    
************************************************************************/


#include <iostream>
using namespace std;

// 最大连续子串和

// 3-level loop  
int maxSubstringSum_1(int *a, int n)
{
	int maxSum = a[0], sum;
	for (int i=0; i<n; i++)
	{
		for (int j=i; j<n; j++)
		{
			sum = 0;
			for (int k=i; k<j+1; k++)
			{
				sum += a[k];
			}
			if (sum > maxSum)
			{
				maxSum = sum;
			}
		}
	}
	return maxSum;
}

// 2-level loop  
int maxSubstringSum_2(int *a, int n)
{
	int maxSum = 0, sum;
	for (int i=0; i<n; i++)
	{
		sum = 0;
		for (int j=i; j<n; j++)
		{
			sum += a[j];
			if (sum > maxSum)
			{
				maxSum = sum;
			}
		}
	}
	return maxSum;
}

// divide-and-conquer
int maxSubstringSum_3(int *a, int lo, int hi)
{
	if (lo == hi)
	{
		return max(a[lo],0);
	}

	int mid = (lo+hi)/2;

	int lmax = a[mid], sum = 0;
	for (int i=mid; i>=lo; i--)
	{
		sum += a[i];
		if (sum > lmax)
		{
			lmax = sum;
		}
	}

	int rmax = a[mid+1];
	for (int i=mid+1, sum=0; i<=hi; i++)
	{
		sum += a[i];
		if (sum > rmax)
		{
			rmax = sum;
		}
	}

	return max(lmax+rmax, max(maxSubstringSum_3(a, lo, mid), maxSubstringSum_3(a, mid+1, hi)));
}

// dp
int maxSubstringSum_4(int *a, int n)
{
	int *b = new int[n];
	b[0] = a[0];
	int max = 0;

	for (int i=1; i<n; i++)
	{
		b[i] = (b[i-1]+a[i]>a[i])?b[i-1]+a[i]:a[i];
		if (max < b[i])
		{
			max = b[i];
		}
	}
	return max;
}

// dp, without extra array
int maxSubstringSum_5(int *a, int n)
{
	
	int max = 0, current=0;

	for (int i=0; i<n; i++)
	{
		current += a[i];
		if (current < 0)
		{
			current = 0;
		}
		else if(current > max)
		{
			max = current;
		}
	}
	return max;
}

int main(int argc, char **argv)
{
	int a[] = {-2, -4, 7};
	cout << maxSubstringSum_5(a, 3) << endl;
	return 0;

}
