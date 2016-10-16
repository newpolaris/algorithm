#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <initializer_list>
#include <random>

using namespace std;

// To heapify a subtree rooted with node i which is
// ans index in v
void heapify(vector<int>& v, int n, int i)
{
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	// Initialize largest as root
	int largest = i;

	if (left < n && v[largest] < v[left])
		largest = left;

	if (right < n && v[largest] < v[right])
		largest = right;

	// If largest is not root
	if (i != largest)
	{
		swap(v[i], v[largest]);

		// Recursively heapify the affected sub-tree
		heapify(v, n, largest);
	}
}

// main function to do heap sort
void heapSort(vector<int>& arr)
{
	int n = arr.size();

    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    // One by one extract an element from heap
    for (int i = n-1; i >= 0; i--)
    {
        // Move current root to end
        swap(arr[0], arr[i]);
 
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

int main()
{
	vector<int> arr = { 13, 8, 10, 14, 7, 9, 3, 2, 4 };

	// Build heap (rearrange array)
	int n = arr.size();
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	copy(begin(arr), end(arr), ostream_iterator<int>(cout, " "));
	cout << endl;

	random_device rd;
	mt19937 g(rd());
	shuffle(arr.begin(), arr.end(), g);

	heapSort(arr);

	copy(begin(arr), end(arr), ostream_iterator<int>(cout, " "));

	return 0;
}
