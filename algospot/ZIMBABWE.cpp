#include <iostream>
#include <algorithm>
#include <bitset>
#include <string.h>

using namespace std;

const int MOD = 1000000007;

int m, n;
string e, digits;
int cache[1<<14][20][2];

int price(bitset<15> taken, int mod, bool bEqual)
{
	int& ret = cache[taken.to_ulong()][mod][bEqual];
	if (ret != -1) 
		return ret;

	int c = taken.count();
	if (c >= digits.size())
		return !bEqual && (mod == 0);

	ret = 0;
	for (int i = 0; i < digits.size(); i++)
	{
		if (taken[i]) 
			continue;

		if (bEqual && e[n] < digits[i]) 
			continue;

		if (i == 0 || digits[i - 1] != digits[i] || taken[i - 1])
		{
			auto bNextEqual = bEqual && (e[c] == digits[i]);
			auto nextTaken = taken;
			nextTaken[i] = true;
			auto nextMod = (mod*10 + digits[i]-'0') % m;
			ret += price(nextTaken, nextMod, bNextEqual);
			ret %= MOD;
		}
	}

	return ret;
}

int main()
{
	int C;
	cin >> C;
	while (C--)
	{
		cin >> e >> m;

		digits = e;
		sort(digits.begin(), digits.end());
		memset(&cache, -1, sizeof(cache));

		cout << price(bitset<15>(), 0, true) << endl;
	}
	return 0;
}

