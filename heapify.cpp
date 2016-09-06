#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <initializer_list>

using namespace std;

void heapify(vector<int>& v, int i)
{
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	int largest = i;

	if (left < v.size() && v[largest] < v[left])
		largest = left;

	if (right < v.size() && v[largest] < v[right])
		largest = right;

	if (i != largest)
	{
		swap(v[i], v[largest]);
		heapify(v, largest);
	}
}

int main()
{
	vector<int> arr = { 1, 14, 10, 8, 7, 9, 3, 2, 4 };
	heapify(arr, 0);

	copy(begin(arr), end(arr), ostream_iterator<int>(cout, " "));

	return 0;
}
