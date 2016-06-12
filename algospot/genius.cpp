#include <iostream>
#include <queue>
#include <algorithm>
#include <iomanip>

using namespace std;

typedef vector<double> vd;
typedef vector<vd> vvd;

class SquareMatrix
{
public:
	SquareMatrix(int L) {
		data = vvd(L, vd(L));
	}

	vd& operator[](int k) {
		return data[k];
	}

	const vd& operator[](int k) const {
		return data[k];
	}

	SquareMatrix pow(int k) const {
		if (k == 2) return *this * *this;
		if (k % 2 == 0) {
			SquareMatrix half = pow(k/2);
			return half * half;
		}
		return *this * pow(k - 1);
	}

	SquareMatrix operator*(const SquareMatrix& A) const {
		int N = data.size();
		SquareMatrix R(N);
		for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			double& v = R[r][c] ;
			for (int k = 0; k < N; k++) {
				v += data[r][k] * A[k][c];
			}
		}
		}
		return R;
	}
	vvd data;
};

int main()
{
#ifdef _DEBUG
	freopen("genius.in", "r", stdin);
#endif
	int C, N, K, M;
	cin >> C;
	while (C--) {
		cin >> N >> K >> M;
		vector<int> L(N);
		for (auto& l : L) cin >> l;
		vector<vd> T(N, vd(N));
		for (auto& t : T)
			for (auto& tt : t)
				cin >> tt;
		vector<double> Pref(M);
		for (auto& p : Pref) cin >> p;

		SquareMatrix matrix(4*N);
		for (int i = 0; i < 3*N; i++)
			matrix[i][i+N] = 1.0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				int t = (4 - L[j])*N + j;
				matrix[3*N+i][t] = T[j][i];
			}
		}
		auto Wk = matrix.pow(K);
		vd ret(Pref.size());
		for (int i = 0; i < Pref.size(); i++)
			for (int l = 0; l < L[Pref[i]]; l++) {
				int t = (3 - l)*N + Pref[i];
				ret[i] += Wk[t][3*N];
			}
		cout << fixed << setprecision(8);
		for (auto r : ret)
			cout << r << " ";
		cout << endl;
	}
}

