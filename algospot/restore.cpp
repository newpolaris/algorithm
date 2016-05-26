#include <vector>
#include <cstdio>
#include <algorithm>
#include <bitset>
#include <string.h>

using namespace std;

typedef bitset<15> BS;
typedef const string cstr;
vector<string> L;
int K;
int cache[16][1 << 15];
int dupli[15][15];

int GetOverlap(int P, int S)
{
	if (P == -1 || S == -1) return 0;
	int& Len = dupli[P][S];
	if (Len != -1) return Len;
	cstr &p = L[P], &s = L[S];

	int MaxOver = min(p.size() - 1, s.size() - 1);
	Len = 0;
	for (int i = MaxOver; i >= 1; i--)
	{
		int PS = p.size() - i;
		if (p.substr(PS, i) == s.substr(0, i)) {
			Len = i; break;
		}
	}
	return Len;
}

int restore(int S, BS& used)
{
	int& Len = cache[S + 1][used.to_ulong()];
	if (Len != -1) return Len;

	Len = 0;
	for (int i = 0; i < K; i++) {
		if (used[i]) continue;
		used.set(i);
		int T = GetOverlap(S, i);
		Len = max(Len, T + restore(i, used));
		used.reset(i);
	}
	return Len;
}

string reconstruct(int S, BS& used)
{
	// cache는 used 가 주어졌을 때 절약한 최종 길이 합이므로 최소값을 계속 택함
	int maxL = -1, next = -1;
	for (int i = 0; i < K; i++) {
		if (used[i]) continue;
		used.set(i);
		int candL = restore(i, used);
		if (maxL < candL) {
			maxL = candL; next = i;
		}
		used.reset(i);
	}
	if (next == -1) return L[S];

	string pre = "";

	if (S != -1) {
		int D = GetOverlap(S, next);
		pre = L[S].substr(0, L[S].size() - D);
	}
	if (next != -1)
		used.set(next);
	return pre + reconstruct(next, used);
}

int main()
{
#ifdef _DEBUG
	freopen("restore.in", "r", stdin);
#endif
	char s[50];
	int C;
	scanf("%d", &C);
	while (C--)
	{
		scanf("%d", &K);
		L = vector<string>(K);
		for (auto& l : L)
		{
			scanf("%s", s);
			l = string(s);
		}

		memset(cache, -1, sizeof(cache));
		memset(dupli, -1, sizeof(dupli));

		while (true) {
			bool removed = false;
			for (int i = 0; i < K; i++) {
				for (int j = 0; j < K; j++) {
					if (i == j) continue;
					if (L[i].find(L[j]) != string::npos) {
						L[j] = L[K-1]; //끝에 것만 옮김
						K--;
						removed = true;
					}
				}
				if (removed) break;
			}
			if (!removed) break;
		}
		BS em1, em2;
		restore(-1, em1);
		string result = reconstruct(-1, em2);
		printf("%s\n", result.c_str());
	}
}

