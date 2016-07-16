/*
 http://www.geeksforgeeks.org/find-the-next-lexicographically-greater-word-than-a-given-word/
 */
#include <iostream>
#include <string>

using namespace std;

void swap(char *a,char *b)
{
    if( *a == *b )
        return;
    *a^=*b;
    *b^=*a;
    *a^=*b;
}

void rev(string& s,int l,int r)
{
    while(l<r)
        swap(&s[l++],&s[r--]);
}
 
int bsearch (string& s,int l,int r,int key)
{
    int index = -1;
    while(l<=r)
    {
        int mid = l+(r-l)/2;
        if(s[mid]<=key)
            r=mid-1;
        else
        {
            l=mid+1;
            if(index == -1 || s[index]<=s[mid])
                index = mid;
        }
    }
	return index;
}
 
bool nextpermutation(string& s)
{
    int len = s.length(), i=len-2;
    while(i>=0 && s[i]>=s[i+1])
       --i;
    if(i<0)
        return false;
    else
    {
        int index=bsearch(s,i+1,len-1,s[i]); // i + 1, last까지의 l > s[i] 인것을 찾아라
		if (index != -1)
			return false;
		swap(&s[i],&s[index]);
		// iter_swap(&s[i],&s[index]); possible?
		rev(s,i+1,len-1);
		return true;
    }
}

int main ()
{
    string s = {"gfg"};
    bool val = nextpermutation(s);
    if (val == false)
        cout << "No Word Possible" << endl;
    else
        cout << s << endl;
    return 0;
}

// This code is contributed by Mysterious Mind
/* 

http://stackoverflow.com/questions/11483060/stdnext-permutation-implementation-explanation

Let's look at some permutations:

1 2 3 4
1 2 4 3
1 3 2 4
1 3 4 2
1 4 2 3
1 4 3 2
2 1 3 4
...
How do we go from one permutation to the next? Firstly, let's look at things a little differently. We can view the elements as digits and the permutations as numbers. Viewing the problem in this way we want to order the permutations/numbers in "ascending" order.

When we order numbers we want to "increase them by the smallest amount". For example when counting we don't count 1, 2, 3, 10, ... because there are still 4, 5, ... in between and although 10 is larger than 3, there are missing numbers which can be gotten by increasing 3 by a smaller amount. In the example above we see that 1 stays as the first number for a long time as there are many reorderings of the last 3 "digits" which "increase" the permutation by a smaller amount.

So when do we finally "use" the 1? When there are only no more permutations of the last 3 digits.
And when are there no more permutations of the last 3 digits? When the last 3 digits are in descending order.

Aha! This is key to understanding the algorithm. We only change the position of a "digit" when everything to the right is in descending order because if it isn't in descending order then there are still more permutations to go (ie we can "increase" the permutation by a smaller amount).

Let's now go back to the code:

while (true)
{
	It j = i;
	--i;

	if (*i < *j)
	{ // ...
	}

	if (i == begin)
	{ // ...
	}
}
From the first 2 lines in the loop, j is an element and i is the element before it.
Then, if the elements are in ascending order, (if (*i < *j)) do something.
Otherwise, if the whole thing is in descending order, (if (i == begin)) then this is the last permutation.
Otherwise, we continue and we see that j and i are essentially decremented.

We now understand the if (i == begin) part so all we need to understand is the if (*i < *j) part.

Also note: "Then if the elements are in ascending order ..." which supports our previous observation that we only need to do something to a digit "when everything to the right is in descending order". The ascending order if statement is essentially finding the leftmost place where "everything to the right is in descending order".

Let's look again at some examples:

	...
	1 4 3 2
	2 1 3 4
	...
	2 4 3 1
	3 1 2 4
	...

We see that when everything to the right of a digit is in descending order, we find the next largest digit and put it in front and then put the remaining digits in ascending order.

Let's look at the code:

	It k = end;

	while (!(*i < *--k))
		; // pass

	iter_swap(i, k);
	reverse(j, end);
	return true;

Well, since the things to the right are in descending order, to find the "next largest digit" we just have to iterate from the end, which we see in the first 3 lines of code.

Next, we swap the "next largest digit" to the front with the iter_swap() statement and then since we know that digit was the next largest, we know that the digits to the right are still in descending order, so to put it in ascending order, we just have to reverse() it.
*/

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

template<typename It>
bool next_permutation(It begin, It end)
{
	if (begin == end)
		return false;

	It i = begin;
	++i;
	if (i == end)
		return false;

	i = end;
	--i;

	while (true)
	{
		It j = i;
		--i;

		if (*i < *j)
		{
			It k = end;

			while (!(*i < *--k))
				/* pass */;

			iter_swap(i, k);
			reverse(j, end);
			return true;
		}

		if (i == begin)
		{
			reverse(begin, end);
			return false;
		}
	}
}

int main2()
{
	vector<int> v = { 1, 2, 3, 4 };

	do
	{
		for (int i = 0; i < 4; i++)
		{
			cout << v[i] << " ";
		}
		cout << endl;
	}
	while (::next_permutation(v.begin(), v.end()));

	return 0;
}

