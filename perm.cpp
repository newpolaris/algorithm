#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <numeric>

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
	int factorial = 1;
	// factorial 배열을 만들지 않기 위해 역순으로 뒤집음. 
	// -1 은 k 가 size 넘어가므로 -2 부터
	for (int i = in.size() - 2; i >= 0; i--) {
		int count = 0;
		for (int k = i + 1; k < in.size(); k++)
			// >= 일 경우 오류남
			if (in[i] > in[k])
				count++;
		index += count*factorial;
		factorial *= ++position;
	}
	return index;
}

/* NOTE: kcm's */
int factorial[9];
int numberit(vi& perm) {
	int i, j, cnt, ret_val = 0;
	int size = perm.size();
	for(i=0; i < size; i++){
		cnt = 0;
		for(j = i+1; j < size; j++) {
			if (perm[j] < perm[i]) {
				cnt++;
			}
		}
		ret_val += cnt*factorial[size-i-1];
	}
	return ret_val;
}

/* 
 * 1 2 3 4 
 * 1 2 4 3 
 * 1 3 2 4 : 3보다 작은거 1개 앞에 있을 것 같은거 2! 
 * 1 3 4 2 : 3보다 작은거 1개 * 2 + 4보다 작은거 1개 * 1 
 * 1 4 2 3 
 * 1 4 3 2
 * 2 1 3 4 : 2는 2번째 뒤에 3개 있으니, 3개 가능한 모두 3!
 * 2 1 4 3
 */

// p.317 순열의 사전순 번호 찾기
int factorials[12];
void setFactorials() {
	factorials[0] = 1; //0!
	for (int i = 1; i < 12; ++i) {
		factorials[i] = factorials[i - 1] * i;
	}
}

int getIndex(const vector<int>& X) {
	int ret = 0;
	for (int i = 0; i < X.size(); ++i)
	{
		int less = 0;
		for (int j = i + 1; j < X.size(); ++j) {
			if (X[i] > X[j])
				less++;
		}
		ret +=  factorials[X.size() - i - 1] * less;
	}
	return ret;
}

int main() {
	factorial[0] = 1;
	for(int i=1; i<=8; i++){
		factorial[i] = factorial[i-1]*i;
	}

	vector<int> v(8);
	iota(v.begin(), v.end(), 1);
	v[1] = 1;
	v[4] = 4;
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	do {
		auto a = numberit(v), b = perm(v);
		if (a != b) {
			cout << a << " " << b << endl;
		}
	} while (next_permutation(v.begin(), v.end()));


	string Num;
	cin >> Num;
	vector<int> numVector(Num.size());
	for (int i = 0; i < Num.size(); ++i) {
		numVector[i] = Num[i] - '0';
	}
	setFactorials();
	int index = getIndex(numVector);

	return 0;
}
