#include<iostream>
#include "SortProject.h"
#include<fstream>
#include<string>
using namespace std;

SortProject::SortProject()
{
	element1 = NULL;
	element2 = NULL;
	element3 = NULL;
	element4 = NULL;
	element5 = NULL;
	sum = NULL;
	sumRank = NULL;
	left = NULL;
	right = NULL;
	qcount1 = 0;
	qcount2 = 0;
	qcount3 = 0;
	qcount4 = 0;
	qcount5 = 0;
	max = 0;
	mid1, mid2, mid3, mid4, mid5 = 0;
}

SortProject::~SortProject()
{
	element1;
	element2;
	element3;
	element4;
	element5;
	sum;
	sumRank;
	left;
	right;
}

void SortProject::CopyFile()
{
	int i = 0;
	int number = 0;
	max = 0;

	ifstream in_file("source1.txt");
	ifstream in_file2("source2.txt");
	ifstream in_file3("source3.txt");
	ifstream in_file4("source4.txt");
	ifstream in_file5("source5.txt");

	if (!in_file)
	{
		cout << "File not found." << endl;
		exit(-1);
	}

	element1 = new int[10000];
	element2 = new int[10000];
	element3 = new int[10000];
	element4 = new int[10000];
	element5 = new int[10000];

	while (in_file >> number)
	{
		element1[i] = number;
		i++;
	}

	in_file.close();
	i = 0;

	while (in_file2 >> number)
	{
		element2[i] = number;
		i++;
	}

	in_file2.close();
	i = 0;

	while (in_file3 >> number)
	{
		element3[i] = number;
		i++;
	}

	in_file3.close();
	i = 0;

	while (in_file4 >> number)
	{
		element4[i] = number;
		i++;
	}

	in_file4.close();
	i = 0;

	while (in_file5 >> number)
	{
		element5[i] = number;
		i++;
		max++;
	}

	in_file5.close();
}

void SortProject::Sum()
{
	int i = 0;
	sum = new int[10000];

	while (i < max)
	{
		sum[i] = element1[i] + element2[i] + element3[i] + element4[i] + element5[i];
		i++;
	}
}

void SortProject::Rank()
{
	int i, j, tempSum, temp1, temp2, temp3, temp4, temp5;
	for (i = 1; i < max; i++)
	{
		tempSum = sum[i];
		temp1 = element1[i];
		temp2 = element2[i];
		temp3 = element3[i];
		temp4 = element4[i];
		temp5 = element5[i];
		j = i - 1;

		while (j >= 0 && sum[j] > tempSum)
		{
			sum[j + 1] = sum[j];
			element1[j + 1] = element1[j];
			element2[j + 1] = element2[j];
			element3[j + 1] = element3[j];
			element4[j + 1] = element4[j];
			element5[j + 1] = element5[j];
			j = j - 1;
		}

		sum[j + 1] = tempSum;
		element1[j + 1] = temp1;
		element2[j + 1] = temp2;
		element3[j + 1] = temp3;
		element4[j + 1] = temp4;
		element5[j + 1] = temp5;
	}
}

void SortProject::QuickSort(int left, int right)
{
	int i = left, j = right, k = left, l = right, m = left, n = right, o = left, p = right, q = left, r = right;
	int temp;
	mid1 = element1[(left + right) / 2];//pivot
	mid2 = element2[(left + right) / 2];//pivot
	mid3 = element3[(left + right) / 2];//pivot
	mid4 = element4[(left + right) / 2];//pivot
	mid5 = element5[(left + right) / 2];//pivot

	while (i <= j)
	{
		while (element1[i] < mid1)
			i++;
		while (element1[j] > mid1)
			j--;
		if (i <= j)
		{
			temp = element1[i];
			element1[i] = element1[j];
			element1[j] = temp;
			i++;
			j--;
		}
	}

	cout << "i: " << i << " " << "j: " << j << endl;

	if (left < j)
		QuickSort(left, j);
	if (i < right)
		QuickSort(i, right);

	while (k <= l)
	{
		while (element2[k] < mid2)
			k++;
		while (element2[l] > mid2)
			l--;
		if (k <= l)
		{
			temp = element2[k];
			element2[k] = element2[l];
			element2[l] = temp;
			k++;
			l--;
		}
	}

	cout << "k: " << k << " " << "l: " << l << endl;

	if (left < l)
		QuickSort(left, l);
	if (k < right)
		QuickSort(k, right);

	while (m <= n)
	{
		while (element3[m] < mid3)
			m++;
		while (element3[n] > mid3)
			n--;
		if (m <= n)
		{
			temp = element3[m];
			element3[m] = element3[n];
			element3[n] = temp;
			m++;
			n--;
		}
	}

	cout << "m: " << m << " " << "n: " << n << endl;

	if (left < n)
		QuickSort(left, n);
	if (m < right)
		QuickSort(m, right);

	while (o <= p)
	{
		while (element4[o] < mid4)
			o++;
		while (element4[p] > mid4)
			p--;
		if (o <= p)
		{
			temp = element4[o];
			element4[o] = element4[p];
			element4[p] = temp;
			o++;
			p--;
		}
	}

	cout << "o: " << o << " " << "p: " << p << endl;

	if (left < p)
		QuickSort(left, p);
	if (o < right)
		QuickSort(o, right);

	while (q <= r)
	{
		while (element5[q] < mid5)
			q++;
		while (element5[r] > mid5)
			r--;
		if (q <= r)
		{
			temp = element5[q];
			element5[q] = element5[r];
			element5[r] = temp;
			q++;
			r--;
		}
	}

	cout << "q: " << q << " " << "r: " << r << endl;

	if (left < r)
		QuickSort(left, r);
	if (q < right)
		QuickSort(q, right);
}

void SortProject::MergeArray(int first, int middle, int last)
{
	int i, j, k;

	int size1 = middle - first + 1;
	int size2 = last - middle;

	left = new int[size1];
	right = new int[size2];

	for (i = 0; i < size1; i++)
	{
		left[i] = element1[first + i];
		cout << element1[i] << endl;
	}

	for (j = 0; j < size2; j++)
	{
		right[j] = element1[middle + 1 + j];
		cout << element1[j] << endl;
	}

	i = 0;
	j = 0;
	k = first;
	while (i < size1 && j < size2)
	{
		if (left[i] <= right[j])
		{
			element1[k] = left[i];
			i++;
			cout << element1[k] << endl;
		}
		else
		{
			element1[k] = right[j];
			j++;
			cout << element1[k] << endl;
		}
		k++;
	}

	while (i < size1)
	{
		element1[k] = left[i];
		i++;
		k++;
	}

	while (j < size2)
	{
		element1[k] = right[j];
		j++;
		k++;
	}
}

void SortProject::MergeSort(int first, int last)
{
	if (first < last)
	{
		int middle = (first + last) / 2;

		MergeSort(first, middle);
		MergeSort(middle + 1, last);

		MergeArray(first, middle, last);
	}
}


void SortProject::ShellSort()
{
	int i, j, k, temp;

	//i = 'gap' variable. Different manipulations of the gap variable yields 
	//different running times. 
	for (i = (max / 2); i > 0; i /= 2)
	{
		for (j = i; j < max; j++)
		{
			temp = element1[j];
			for (k = j; (k >= i) && (element1[k - i] > temp); k -= i)
				element1[k] = element1[k - i];

			element1[k] = temp;
			cout << "     j: " << j << "      i: " << i << endl;
		}
	}
	/*
	//After the shell sort creates a mostly sorted list, a basic insertion sort
	//completes relatively quickly.
	for (i = 1; i < max; i++)
	{
	temp = element[i];
	j = i - 1;

	while ((j >= 0) && (element[j] > temp))
	{
	element[j + 1] = element[j];
	j = j - 1;
	}
	element[j + 1] = temp;
	cout << i << endl;
	}
	*/
}

void SortProject::Display()
{
	int i;

	for (i = 0; i < max; i++)
		cout << "E1: " << element1[i] << "    " << "E2: " << element2[i] << "    " << "E3: " << element3[i] << "    " << "E4: " << element4[i] << "    " << "E5: " << element5[i] << endl;

	//for (i = 0; i < max; i++)
		//cout << "Sum: " << sum[i] << endl;

	//cout << "Max: " << max << endl;
}