#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef vector<int> vi;

/* http://stackoverflow.com/questions/12146910/finding-the-lexicographic-index-of-a-permutation-of-a-given-array
Let's look at the permutation dacb. Where does this come in lexicographic order among the 4! = 24 permutations of abcd?

Consider the first letter d. Among the remaining letters (acb) there are three letters smaller than d, and 3! = 6 permutations starting with each one of them, for a total of 18 permutations.
Consider the first two letters da. Among the remaining letters (cb) there are no letters smaller than a (if there were any there would be 2! = 2 permutations starting with d plus each one), for a total of 0 permutations.
Consider the first three letters dac. Among the remaining letters (b) there is one letter smaller than c, and 1! = 1 permutations starting with dab, for a total of 1 permutation.
So in total there are 19 permutations smaller than dacb. Let's check that.

>>> from itertools import permutations
>>> list(enumerate(''.join(p) for p in permutations('abcd')))
[(0, 'abcd'), (1, 'abdc'), (2, 'acbd'), (3, 'acdb'),
 (4, 'adbc'), (5, 'adcb'), (6, 'bacd'), (7, 'badc'),
 (8, 'bcad'), (9, 'bcda'), (10, 'bdac'), (11, 'bdca'),
 (12, 'cabd'), (13, 'cadb'), (14, 'cbad'), (15, 'cbda'),
 (16, 'cdab'), (17, 'cdba'), (18, 'dabc'), (19, 'dacb'),
 (20, 'dbac'), (21, 'dbca'), (22, 'dcab'), (23, 'dcba')]
Looks good. So there are 4! − 19 − 1 = 4 permutations that are greater than dacb.

It should be clear now how to generalize the method to make an algorithm. Here's an implementation in Python:

from math import factorial

def lexicographic_index(p):
    """
    Return the lexicographic index of the permutation `p` among all
    permutations of its elements. `p` must be a sequence and all elements
    of `p` must be distinct.

    >>> lexicographic_index('dacb')
    19
    >>> from itertools import permutations
    >>> all(lexicographic_index(p) == i
    ...     for i, p in enumerate(permutations('abcde')))
    True
    """
    result = 0
    for j in range(len(p)):
        k = sum(1 for i in p[j + 1:] if i < p[j])
        result += k * factorial(len(p) - j - 1)
    return result

def lexicographic_followers(p):
    """
    Return the number of permutations of `p` that are greater than `p`
    in lexicographic order. `p` must be a sequence and all elements
    of `p` must be distinct.
    """
    return factorial(len(p)) - lexicographic_index(p) - 1
*/
int perm(const vi& in)
{
	int index = 0;
	int position = 1;
	int factor = 1;
	for (int i = in.size() - 2; i >= 0; i--) {
		int count = 0;
		for (int k = i + 1; k < in.size(); k++)
			if (in[i] > in[k])
				count++;
		index += count*factor;
		factor *= ++position;
	}
	return index;
}
