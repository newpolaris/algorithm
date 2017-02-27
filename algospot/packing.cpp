#include <algorithm>
#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

struct Object
{
	string name;
	float W;
	float V;
};

vector<Object> List;
int Cache[1001][101];

int Optimize(int BagSize, int Idx)
{
	if (BagSize == 0) 
		return 0;
	if (Idx >= List.size())
		return 0;
	int& caR = Cache[BagSize][Idx];
	if (caR > 0)
		return caR;
	int L = 0;
	if (BagSize - List[Idx].W >= 0)
		L = List[Idx].V + Optimize(BagSize - List[Idx].W, Idx+1);
	int R = Optimize(BagSize, Idx+1);

	int MaxV = max(L, R);
	caR = MaxV;
	return caR;
}

vector<int> Select;

void Recontruct(int w, int i)
{
	if (i >= List.size())
		return;

	bool bCurrentSelected = true;
	if (w - List[i].W < 0)
		bCurrentSelected = false;
	else
		bCurrentSelected = !(Cache[w][i] == Cache[w][i+1]);

	if (bCurrentSelected)
	{
		Select.push_back(i);
		Recontruct(w-List[i].W, i+1);
	}
	else
	{
		Recontruct(w, i+1);
	}
}

int main() {
#ifdef _DEBUG
	freopen("packing.in", "r", stdin);
#endif
	int T, C, V;
	int B;
	cin >> T;

	while (T--) {
		cin >> C >> B;

		memset(&Cache, 0, sizeof(Cache));

		Select.clear();
		List.clear();

		while (C--) {
			Object obj;

			cin >> obj.name;
			cin >> obj.W;
			cin >> obj.V;

			List.push_back(obj);
		}

		int MaxV = Optimize(B, 0);
		Recontruct(B, 0);

		cout << MaxV << " " << Select.size() << endl;

		for (int i = 0; i < Select.size(); i++)
		{
			cout << List[Select[i]].name << endl;
		}
	}

	return 0;
}
