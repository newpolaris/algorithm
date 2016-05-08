#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <assert.h>

using namespace std;

const bool TurnX = true;

int ConvertBase3(vector<string> matrix)
{
	int cnt = 1;
	int sum = 0;
	for (auto& str : matrix)
	{
		for (auto& c : str)
		{
			int v = 0;
			if (c == '.')
				v = 0;
			else if (c == 'x')
				v = 1;
			else if (c == 'o')
				v = 2;
			sum += v * cnt;
			cnt *= 3;
		}
	}
	return sum;
}

bool GetTurn(int IntMatrix)
{
	int team[3] = {0,};

	int N = 9;
	while (N--)
	{
		team[IntMatrix % 3]++;
		IntMatrix /= 3;
	}

	if (team[1] == team[2])
		return TurnX;
	return (team[1] > team[2]) ? !TurnX : TurnX;
}

const vector<vector<int>> checker = {
	{0,1,2}, {3,4,5}, {6,7,8},
	{0,3,6}, {1,4,7}, {2,5,8},
	{0,4,8}, {2,4,6}
};

int CheckWin(const vector<int>& matrix)
{
	auto it = find_if(checker.begin(), checker.end(), [&matrix]
			(const vector<int>& k) {
				return matrix[k[0]] == matrix[k[1]] 
					&& matrix[k[1]] == matrix[k[2]] 
					&& matrix[k[0]] != 0;
			});

	if (it == checker.end())
	{
		auto bit = find_if(matrix.begin(), matrix.end(), [](int i) { return i == 0; });
		return (bit != matrix.end()) ? -1 : 0;
	}
	return matrix[(*it)[0]];
}

const int length = 3*3*3*3*3*3*3*3*3+1;
int Cache[length];

int bijection(const vector<int>& board)
{
	int ret = 0;
	int N = 9;
	int pow = 1;
	for (int i = 0; i < N; i++)
	{
		ret += board[i] * pow;
		pow *= 3;
	}
	return ret;
}

vector<int> GetDecodeMatrix(int IntMatrix)
{
	vector<int> stack;
	int N = 9;
	while (N--)
	{
		stack.push_back(IntMatrix % 3);
		IntMatrix /= 3;
	}
	return stack;
}


int Match(vector<int>& Matrix, bool bTurnX)
{
	int& ret = Cache[bijection(Matrix)];
	if (ret != -2)
		return ret;

	int Team = bTurnX ? 1 : 2;
	int EnemyTeam = bTurnX ? 2 : 1;

	int WinTeam = CheckWin(Matrix);
	if (WinTeam == Team)
		return 1;
	else if (WinTeam == EnemyTeam)
		return -1;
	else if (WinTeam == 0)
		return 0;

	int TurnTeamWin = 2;
	int N = 9;
	for (int i = 0; i < N; i++)
	{
		if (Matrix[i] == 0)
		{
			Matrix[i] = Team;
			TurnTeamWin = min(TurnTeamWin, Match(Matrix, !bTurnX));
			Matrix[i] = 0;
		}
	}

	if (TurnTeamWin == 2 || TurnTeamWin == 0) 
		return ret = 0;

	ret = -TurnTeamWin;
	return ret;
}

int main()
{
	int C;
	cin >> C;

	while (C--)
	{
		for (int i = 0; i < length; i++)
			Cache[i] = -2;
		vector<string> matrix;
		for (int i = 0; i < 3; i++)
		{
			string str;
			cin >> str;
			matrix.push_back(str);
		}

		int IntMatrix = ConvertBase3(matrix);

		bool bTurnX = GetTurn(IntMatrix);
		vector<int> Matrix = GetDecodeMatrix(IntMatrix);
		int TurnTeamWin = Match(Matrix, bTurnX);

		if (!bTurnX) TurnTeamWin *= -1;
		vector<string> C = { "o", "TIE", "x" };
			cout << C[TurnTeamWin + 1] << endl;
	}

	return 0;
}


