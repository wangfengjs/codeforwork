/************************************************************************
* 排序
* 冒泡排序、选择排序、插入排序、归并排序、快速排序、堆排序、希尔排序、桶排序、计数排序、基数排序

* Feng Wang, wangfengjs@gmail.com
* Computer Science and Technology, BIT
* Copyright (c) 2006-2013. All rights reserved.                                                                    
************************************************************************/


#include <iostream>
using namespace std;

// 冒泡排序 - 稳定
void bubbleSort(int *a, int n)
{
	for (bool flag=false; flag = !flag; n--)
		for (int i=0; i<n-1; i++)
			if (a[i] > a[i+1])
			{
				//swap
				flag = false;
				a[i] ^= a[i+1];
				a[i+1] ^= a[i];
				a[i] ^= a[i+1];
			}
}

// 选择排序 - 不稳定
void selectSort(int *a, int n)
{
	for (int i=0; i<n-1; i++)
	{
		int p = i;
		for (int j = i+1; j < n; j++)
		{
			if (a[j] < a[p])
			{
				p = j;
			}
		}
		if (p != i)
		{
			swap(a[p], a[i]);
		}
	}
}

// 插入排序 - 稳定
void insertSort(int *a, int n)
{
	int tmp;
	for (int i=1; i<n; i++)
	{
		tmp = a[i];
		int j;
		for (j=i; j>0&&a[j-1] > tmp; j--)
		{
			a[j] = a[j-1];
		}
		a[j] = tmp;
	}
}

// 归并排序
void mergeSort()
{

}

// 快速排序 - 不稳定
int partition_1(int *a, int lo, int hi)
{
	int key = a[hi];
	int i = lo - 1;
	for (int j=lo; j<hi; j++)
	{
		if (a[j] <= key)
		{
			i++;
			swap(a[i], a[j]);
		}
	}
	swap(a[i+1], a[hi]);

	return i+1;
}

int partition_2(int *a, int lo, int hi)
{
	int key = a[lo];

	while (lo < hi)
	{
		while (lo < hi && a[hi] >= key)
		{
			hi--;
		}
		a[lo] = a[hi];
		while (lo < hi && a[lo] <= key)
		{
			lo++;
		}
		a[hi] = a[lo];
	}
	a[lo] = key;

	return lo;
}

void quickSort(int *a, int lo, int hi)
{
	if (lo < hi)
	{
		int k = partition_2(a, lo, hi);
		quickSort(a, lo, k-1);
		quickSort(a, k+1, hi);
	}
}


int main(int argc, char **argv)
{
	float sum = 0;
	for (int i=0; i<40; i++)
	{
		float r = 1.0*i/39;
		cout << pow(1-r, 2) << endl;
		sum += (1-r)*(1-r);
	}

	cout << sum*40 << endl;

	int a[] = {1, 3, 5, 2};
	insertSort(a, 4);

	for (int i=0; i<4; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;

}
