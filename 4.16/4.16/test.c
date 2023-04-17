#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//相对位置
// 统计每个数据出现的次数
// 绝对映射--不行--0对0 最大值对应最大
// 前面就浪费空间
// 我们就开范围--range相对映射   a[i]-min
// 相对位置映射计数当range与n接近很快
// 计数排序适合范围集中，且范围不大的整形数组排序
// 范围分散和非整形的排序，如：字符串浮点数，不适合
//1.计数--计数相对位置出现的次数 计数数组开辟的空间大小为max-min+1
//2.排序--对计数数组排序--遍历一遍计数数组--适合max不大的数据
//空间复杂度O(range)
void Countsort(int *a,int n)//计数排序O(N+range)
{
	int i = 0;
	int max = a[i], min = a[i];
	for (i = 1; i < n; i++)//遍历一遍原数组
	{
		if (a[i] > max)
		{
			max = a[i];
		}
		if (a[i] < min)
		{
			min = a[i];
		}
	}
	int range = max - min + 1;

	int* counta = (int*)calloc(range,sizeof(int));//初始化计数数组都为0
	//memset(counta, 0, sizeof(int) * range);
	for (int i = 0; i < n; i++)
	{
		counta[a[i] - min]++;
	}
	//对计数数组排序,覆盖原数组
	//这个位置的值，代表了这个值出现了几次 1代表出现一次，2代表出现两次
	int j = 0;
	for (int i = 0; i  < range; i++)
	{
		while (counta[i]--)
		{
			a[j++] = i + min;//出现几次就往原数组放几次
		}
	}
}
int main()
{
	int a[] = { 90,92,96,93,98,99,100,92,93,90 };
	int n = sizeof(a) / sizeof(a[0]);
	Countsort(a,n);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}