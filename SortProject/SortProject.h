#ifndef SORTPROJECT_H
#define SORTPROJECT_H

class SortProject
{
private:
	int* element1;
	int* element2;
	int* element3;
	int* element4;
	int* element5;
	int* sum;
	int* sumRank;
	int* left;
	int* right;
	int qcount1;
	int qcount2;
	int qcount3;
	int qcount4;
	int qcount5;
	int max;
	int mid1, mid2, mid3, mid4, mid5;

public:
	SortProject();
	~SortProject();
	void CopyFile();
	void Sum();
	void Rank();
	void QuickSort(int, int);
	void MergeArray(int first, int middle, int last);
	void MergeSort(int first, int last);
	void ShellSort();
	void Display();
};

#endif