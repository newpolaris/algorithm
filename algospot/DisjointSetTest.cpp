#include "DisjointSet.hpp"
#include <iostream>
#include <assert.h>
#include <cstdlib>

using namespace std;

int main()
{
	DisjointSet A(15);
	assert(A.find(0) == 0);
	assert(A.find(5) == 5);
	assert(A.merge(0, 5));
	assert(!A.merge(0, 5));
	assert(A.find(5) == A.find(0));
	assert(A.merge(1, 6));
	assert(A.find(1) != A.find(0));
	assert(A.merge(1, 5));
	assert(A.find(1) == A.find(0));
	return 0;
}

