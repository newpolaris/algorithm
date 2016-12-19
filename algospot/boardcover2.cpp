#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int h, w, bh, bw, blockSize, best, blanks;
int covered[10][10];
vector<vector<pair<int,int>>> rotations;

vector<string> rotate(const vector<string>& arr) {
	vector<string> ret(arr[0].size(), string(arr.size(), ' '));
	for (int i = 0; i < arr.size(); i++)
		for (int j = 0; j < arr[0].size(); j++)
			ret[j][arr.size()-i-1] = arr[i][j];
	return ret;
}

void generateRotations(vector<string> block)  {
	rotations.clear();
	rotations.resize(4);
	for (int rot = 0; rot < 4; rot++) {
		int oy = -1, ox = -1;
		for (int i = 0; i < block.size(); i++) {
			for (int j = 0; j < block[i].size(); j++) {
				if (block[i][j] == '#') {
					if (oy == -1) {
						oy = i;
						ox = j;
					}
					rotations[rot].push_back({i-oy, j-ox});
				}
			}
		}
		block = rotate(block);
	}
	sort(rotations.begin(), rotations.end());
	rotations.erase(unique(rotations.begin(), rotations.end()), rotations.end());
	blockSize = rotations[0].size();
}

bool set(int y, int x, const vector<pair<int,int>>& block, int delta) {
	auto bRet = true;
	for (auto& b : block) {
		auto yy = y + b.first;
		auto xx = x + b.second;
		if (xx < 0 || xx >= w || yy < 0 || yy >= h) {
			return false;
		} else {
			covered[yy][xx] += delta;
			if (covered[yy][xx] > 1)
				bRet = false;
		}
	}
	return bRet;
}

void search(int placed, int marked) {
	auto used = placed*blockSize + marked;
	if ((blanks - used)/blockSize + placed <= best)
		return;
	int y = -1, x = -1;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (covered[i][j] == 0) {
				y = i;
				x = j;
				break;
			}
		}
		if (y != -1) 
			break;
	}
	if (y == -1) {
		best = max(placed, best);
		return;
	}
	for (int i = 0; i < rotations.size(); i++) {
		if (set(y, x, rotations[i], 1))
			search(placed+1, marked);
		set(y, x, rotations[i], -1);	
	}
	covered[y][x] = 1;
	search(placed, marked+1);
	covered[y][x] = 0;
}

int main() {
#ifdef _DEBUG
	freopen("boardcover2.in", "r", stdin);
#endif
	int c;
	string str;
	cin >> c;
	while (c--) {
		cin >> h >> w >> bh >> bw;
		vector<string> board(h);
		for (int i = 0; i < h; i++) 
			cin >> board[i];
		vector<string> block(bh);
		for (int i = 0; i < bh; i++) 
			cin >> block[i];
		generateRotations(block);
		best = 0, blanks = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) { 
				covered[i][j] = (board[i][j] == '#' ? 1 : 0);
				blanks += (covered[i][j] == 0);
			}
		}
		search(0, 0);
		cout << best << endl;
	}
	return 0;
}
