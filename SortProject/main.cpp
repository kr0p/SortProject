#include <iostream>
#include "SortProject.h"
using namespace std;

int main()
{
	SortProject sort;

	sort.CopyFile();
	sort.Sum();
	sort.Rank();
	sort.QuickSort(0, 9999);
	sort.Display();
}
