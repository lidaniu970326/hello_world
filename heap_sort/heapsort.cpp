#include<iostream>
#include<stdio.h>
#include<stdlib.h>
void adjustheap(int A[], int len, int i)
{
	A[0] = A[i];
	for (int j = 2 * i; j <= len; j = j * 2)
	{
		if (j < len&&A[j] < A[j + 1])
			j++;//挑出3个里面最大的
		if (A[0] > A[j])//假如最大的是根节点的话 那么退出
			break;
		else
			A[i] = A[j];
			i = j;//i也得向下移动啊 要不然怎么回头赋值
	}
	A[i] = A[0];
}

void buildheap(int A[], int len)
{
	for (int i = len / 2; i >= 1; i--)
	{
		adjustheap(A, len, i);
	}
}

void heapsort(int A[], int len)
{
	buildheap(A, len);
	for (int i = len; i > 1; i--)
	{
		int regist = A[1];
		A[1] = A[i];
		A[i] = regist;
		adjustheap(A, i-1, 1);
	}
}

int main() {
	int A[] = { 0,53,17,78,9,45,65,87,32 };
	heapsort(A, 8);
	std::cin.get();
	std::cin.get();
	return 0;
}