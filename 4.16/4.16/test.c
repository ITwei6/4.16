#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//���λ��
// ͳ��ÿ�����ݳ��ֵĴ���
// ����ӳ��--����--0��0 ���ֵ��Ӧ���
// ǰ����˷ѿռ�
// ���ǾͿ���Χ--range���ӳ��   a[i]-min
// ���λ��ӳ�������range��n�ӽ��ܿ�
// ���������ʺϷ�Χ���У��ҷ�Χ�����������������
// ��Χ��ɢ�ͷ����ε������磺�ַ��������������ʺ�
//1.����--�������λ�ó��ֵĴ��� �������鿪�ٵĿռ��СΪmax-min+1
//2.����--�Լ�����������--����һ���������--�ʺ�max���������
//�ռ临�Ӷ�O(range)
void Countsort(int *a,int n)//��������O(N+range)
{
	int i = 0;
	int max = a[i], min = a[i];
	for (i = 1; i < n; i++)//����һ��ԭ����
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

	int* counta = (int*)calloc(range,sizeof(int));//��ʼ���������鶼Ϊ0
	//memset(counta, 0, sizeof(int) * range);
	for (int i = 0; i < n; i++)
	{
		counta[a[i] - min]++;
	}
	//�Լ�����������,����ԭ����
	//���λ�õ�ֵ�����������ֵ�����˼��� 1�������һ�Σ�2�����������
	int j = 0;
	for (int i = 0; i  < range; i++)
	{
		while (counta[i]--)
		{
			a[j++] = i + min;//���ּ��ξ���ԭ����ż���
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