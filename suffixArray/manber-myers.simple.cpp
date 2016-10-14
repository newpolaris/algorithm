// 맨버-마이어스
// Manber-Myers, suffix array : A new method for on-line string searches

#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>

using namespace std;

// O(nlog^2(n)) s의 접미사 배열을 계산한다.
vector<int> getSuffixArray(const string& s) {
	int n = s.size();
	// group[i] = 접미사들을 첫 t 글자를 기준으로 정렬했을 때,
	// s[i:]가 들어가는 그룹 번호.
	// t = 1 일 때는 정렬할 것 없이 s[i:]의 첫 글자로 그룹 번호를
	// 정해 줘도 같은 효가가 있다.
	int t = 1;

	vector<int> group(n+1);
	group[n] = -1;
	for (int i = 0; i < n; i++) group[i] = s[i];

	vector<int> perm(n);
	for (int i = 0; i < n; i++) perm[i] = i;

	while (t < n) {
		// group[]은 첫 t글자를 기준으로 계산해 뒀다.
		// 첫 2*t 글자를 기준으로 perm을 다시 정렬한다.
		
		// 각 접미사들의 첫 t 글자를 기준으로 한 그룹 번호가 주어질 때,
		// 주어진 두 접미사를 첫 2*t 글자를 기준으로 비교한다.
		// group[]은 길이가 0인 접미사도 포함한다.
		auto compareUsing2T = [t, &group](int a, int b) {
			// 첫 t 글자가 다르면 이들을 이용해 비교한다
			if (group[a] != group[b])
				return group[a] < group[b];
			// 아니라면 s[a+t:]와 s[b+t:]의 첫 t글자를 비교한다
			return group[a+t] < group[b+t];
		};

		sort(perm.begin(), perm.end(), compareUsing2T);

		// 2*t 글자가 n을 넘는다면 이제 접미사 배열 완성
		t *= 2;
		if (t > n) break;

		// 2t 글자를 기준으로 한 그룹 정보를 만든다.
		vector<int> newGroup(n+1);
		newGroup[perm[0]] = 0;
		newGroup[n] = -1;

		for (int i = 1; i < n; i++) {
			int nextGroup = compareUsing2T(perm[i-1], perm[i]);
			newGroup[perm[i]] = newGroup[perm[i-1]] + nextGroup;
		}
		group = newGroup;

	}
	return perm;
}

// s[a:]와 s[b:]의 공통 접두사의 최대 길이를 계산한다.
int commonPrefix(const string& s, int a, int b) {
	int i = 0, n = s.size();
	for (i = 0; i < n - max(a, b); i++) 
		if (s[a+i] != s[b+i]) break;
	return i;
}

// s의 서로 다른 부분 문자열의 수를 센다.
int countSubstrings(const string& s) {
	vector<int> a = getSuffixArray(s);
	int ret = 0;
	int n = s.size();
	for (int i = 0; i < a.size(); ++i) {
		int cp = 0;
		if (i > 0) cp = commonPrefix(s, a[i-1], a[i]);
		// a[i]의 (n-a[i]) 개의 접두사들 중에서 cp개는 중복이다.
		ret += s.size() - a[i] - cp;
	}
	return ret;
}

// k번 이상 출현하는 s의 부분 문자열 중 최대 길이를 찾는다.
int longestFrequent(int k, const string& s) {
	vector<int> a = getSuffixArray(s);
	int ret = 0;
	for (int i = 0; i + k <= s.size(); ++i)
		ret = max(ret, commonPrefix(s, a[i], a[i + k - 1]));
	return ret;
}

/* 
 * LCP(Longest Common Prefix) find in O(n)
 *
 * http://codeforces.com/blog/entry/12796?#comment-175287
 * Kasai's algorithm is pretty easy and works in O(n).
 * Let's look at the two continuous suffixes in the suffix array. Let their indexes in 
 * suffix array be i1 and i1 + 1. If their lcp > 0, then if we delete first letter from
 * both of them. We can easily see that new strings will have the same relative order.
 * Also we can see that lcp of new strings will be exactly lcp - 1.
 * Let's now look at the string wich we have got from the i suffix by deleting its first character.
 * Obviously it is some suffix of the string too. Let its index be i2.
 * Let's look at the lcp of suffixes i2 and i2 + 1. We can see that it's lcp will be at
 * least already mentioned lcp - 1. This is associated with certain properties of lcp 
 * array, in particular, that lcp(i, j) = min(lcpi, lcpi + 1, ..., lcpj - 1).
 * And finally let's make the algorithm based on the mentioned above. 
 * We will need an additional array rank[n], wich will contain the index 
 * in the suffix array of the suffix starting in index i. 
 * Firstly we should calculate the lcp of the suffix with index rank[0].
 * Then let's iterate through all suffixes in order in which we meet them in the string 
 * and calculate lcp[rank[i]] in naive way, BUT starting it from lcp[rank[i - 1]] - 1.
 * Easy to see that now we have O(n) algorithm because on the each step our lcp decreasing 
 * not more than by 1 (except the case when rank[i] = n - 1).
 * Implementation:
 */
vector<int> kasai(string s, vector<int> sa)
{
    int n=s.size(),k=0;
    vector<int> lcp(n,0);
    vector<int> rank(n,0);

    for(int i=0; i<n; i++) rank[sa[i]]=i;

    for(int i=0; i<n; i++, k?k--:0)
    {
        if(rank[i]==n-1) {k=0; continue;}
        int j=sa[rank[i]+1];
        while(i+k<n && j+k<n && s[i+k]==s[j+k]) k++;
        lcp[rank[i]]=k;
    }
    return lcp;
}

/*
 * http://www.geeksforgeeks.org/%C2%AD%C2%ADkasais-algorithm-for-construction-of-lcp-array-from-suffix-array/
 */
vector<int> kasai2(string txt, vector<int> suffixArr)
{
    int n = suffixArr.size();
 
    // To store LCP array
    vector<int> lcp(n, 0);
 
    // An auxiliary array to store inverse of suffix array
    // elements. For example if suffixArr[0] is 5, the
    // invSuff[5] would store 0.  This is used to get next
    // suffix string from suffix array.
    vector<int> invSuff(n, 0);
 
    // Fill values in invSuff[]
    for (int i=0; i < n; i++)
        invSuff[suffixArr[i]] = i;
 
    // Initialize length of previous LCP
    int k = 0;
 
    // Process all suffixes one by one starting from
    // first suffix in txt[]
    for (int i=0; i<n; i++)
    {
        /* If the current suffix is at n-1, then we don’t
           have next substring to consider. So lcp is not
           defined for this substring, we put zero. */
        if (invSuff[i] == n-1)
        {
            k = 0;
            continue;
        }
 
        /* j contains index of the next substring to
           be considered  to compare with the present
           substring, i.e., next string in suffix array */
        int j = suffixArr[invSuff[i]+1];
 
        // Directly start matching from k'th index as
        // at-least k-1 characters will match
        while (i+k<n && j+k<n && txt[i+k]==txt[j+k])
            k++;
 
        lcp[invSuff[i]] = k; // lcp for the present suffix.
 
        // Deleting the starting character from the string.
        if (k>0)
            k--;
    }
 
    // return the constructed lcp array
    return lcp;
}

int main()
{
#ifndef _DEBUG
	freopen("manber-myers.simple.in", "r", stdin);
	int c, k;
	string s;

	cin >> c;
	while (c--)
	{
		cin >> k;
		cin >> s;
		cout << longestFrequent(k, s) << endl;
	}
#else
	string s("banana");
	auto sa = getSuffixArray(s);
	auto lcp = kasai3(s, sa);

	copy(begin(sa), end(sa), ostream_iterator<int>(cout, ", "));
	cout << endl;
	copy(begin(lcp), end(lcp), ostream_iterator<int>(cout, ", "));
	cout << endl;
#endif

	return 0;
}
