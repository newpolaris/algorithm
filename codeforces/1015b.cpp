#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int n;
std::string s, t;
std::vector<int> order;

int findc(int i)
{
	for (int k = i+1; k < n; k++)
		if (t[k] == s[i])
			return k;
	return -1;
}

void swapchar(int i, int k)
{
	for (int l = k - 1; l >= i; l--)
	{
		std::swap(t[l], t[l+1]);
		order.push_back(l+1);
	}
}

bool test()
{
	for (int i = 0; i < n; i++)
	{
		if (s[i] == t[i]) continue;
		int k = findc(i);
		if (k < 0) return false;
		swapchar(i, k);
	}
	return true;
}

int main()
{
	std::cin >> n;
	std::cin >> t >> s;

	if (!test())
	{
		std::cout << "-1\n" << std::endl;
	}
	else
	{
		std::cout << order.size() << std::endl;
		for (auto c : order)
			std::cout << c << " ";
		std::cout << std::endl;
	}
	return 0;
}
