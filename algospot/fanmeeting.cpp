#include <algorithm>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

vector<int> refan, idol;

vector<int> convert(const string& A)
{ 
	vector<int> B(A.size());
	for (int i = 0; i < A.size(); i++)
		B[i] = A[i] == 'F' ? 0 : 1;

	return B;
}

vector<int> multi(const vector<int>& Fan, const vector<int>& Idol)
{
	vector<int> C(Fan.size()+Idol.size());

	for (int i = 0; i < Idol.size(); i++)
	{
		if (Idol[i] == 0) 
			continue;

		for (int j = 0; j < Fan.size(); j++)
			C[i+j] += Fan[j];
	}

	return C;
}

int solve(const string& Fan, const string& Idol)
{
	idol = convert(Idol);
	auto fan = convert(Fan);
	refan = vector<int>(fan.rbegin(), fan.rend());

	vector<int> C = multi(refan, idol);

	int ret = 0;
	for (int i = Idol.size() - 1; i >= Fan.size() - 1; i--)
		ret += C[i] == 0;

	return ret;
}

int main()
{
#if 1 //_DEBUG
	ifstream fin("fanmeeting-large.in");
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

