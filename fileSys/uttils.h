#pragma once
using namespace std;
int occur(int x[], int size, int n)
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (n == x[i])
			count++;
	}
	return count;

}

int occur2(int x[], int size, int n)
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (n < x[i])
			break;
		else if (n == x[i])
			count++;
	}
	return count;

}

