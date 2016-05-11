#include <algorithm>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

vector<int> convert(const string& A)
{ 
	vector<int> B(A.size());
	for (int i = 0; i < A.size(); i++)
		B[i] = A[i] == 'F' ? 0 : 1;

	return B;
}

vector<int> multi(const vector<int>& a, const vector<int>& b)
{
	vector<int> C(a.size()+b.size()+1);

	for (int i = 0; i < b.size(); i++)
	{
		for (int j = 0; j < a.size(); j++)
			C[i+j] += a[j]*b[i];
	}

	return C;
}

vector<int> add(const vector<int>& a, const vector<int>& b, int shift = 0)
{
	vector<int> c(max(a.size(), b.size()+shift)+1);
	
	for (int i = 0; i < a.size(); i++)
		c[i] = a[i];

	for (int i = 0; i < b.size(); i++)
		c[i+shift] += b[i];

	return c;
}

vector<int> sub(const vector<int>& a, const vector<int>& b)
{
	vector<int> c(max(a.size(), b.size())+1);

	for (int i = 0; i < a.size(); i++)
		c[i] = a[i];

	for (int i = 0; i < b.size(); i++)
		c[i] -= b[i];

	return c;
}

vector<int> karatsuba(const vector<int>& a, const vector<int>& b)
{
	if (a.size() == 0 || b.size() == 0)
		return vector<int>();

	if (a.size() < b.size()) 
		return karatsuba(b, a);

	if (a.size() <= 2)
		return multi(a, b);

	auto half = a.size() / 2;

	vector<int> a0(a.begin(), a.begin()+half);
	vector<int> a1(a.begin()+half, a.end());

	auto bh = b.begin()+min(half, b.size());

	vector<int> b0(b.begin(), bh);
	vector<int> b1(bh, b.end());

	vector<int> z0 = karatsuba(a0, b0);
	vector<int> z2 = karatsuba(a1, b1);

	vector<int> sumA = add(a0, a1);
	vector<int> sumB = add(b0, b1);
	
	vector<int> z1 = karatsuba(sumA, sumB);

	z1 = sub(z1, z0);
	z1 = sub(z1, z2);

	vector<int> ret;
	ret = add(ret, z0);
	ret = add(ret, z1, half);
	ret = add(ret, z2, half*2);

	return ret;
}

int solve(const string& Fan, const string& Idol)
{
	vector<int> refan, idol;

	idol = convert(Idol);
	auto fan = convert(Fan);
	refan = vector<int>(fan.rbegin(), fan.rend());

	vector<int> C = karatsuba(refan, idol);

	int ret = 0;
	for (int i = Idol.size() - 1; i >= Fan.size() - 1; i--)
		ret += C[i] == 0;

	return ret;
}

int main()
{
#if _DEBUG
	ifstream fin("fanmeeting.in");
	// ifstream fin("fanmeeting-large.in");
	istream& in = fin;
#else
	istream& in = cin;
#endif

	int C;
	in >> C;

	while (C--)
	{
		string Fan, Idol;
		in >> Fan;
		in >> Idol;

		cout << solve(Fan, Idol) << endl;
	}
	
	return 0;
}

