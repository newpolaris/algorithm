#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;
#define PB push_back
#define ZERO (1e-10)
#define INF (1<<29)
#define CL(A,I) (memset(A,I,sizeof(A)))
#define DEB printf("DEB!\n");
#define D(X) cout<<"  "<<#X": "<<X<<endl;
#define EQ(A,B) (A+ZERO>B&&A-ZERO<B)
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
#define IN(n) int n;scanf("%d",&n);
#define FOR(i, m, n) for (int i(m); i < n; i++)
#define REP(i, n) FOR(i, 0, n)
#define F(n) REP(i, n)
#define FF(n) REP(j, n)
#define FT(m, n) FOR(k, m, n)
#define aa first
#define bb second
void ga(int N,ll *A){F(N)scanf("%lld",A+i);}
#define MX (6)//100009)
int N;

ll dp[MX][3][2],g[4][MX];

// u is col
// I is row
// y is flag on/off
ll dyn(int u, int I, bool y){
	if(u > N) 
		return -1e18;
	if(u == N) {
		ll r = (y || I^2) ? -1e18 : 0;
		return r;
	}
	ll& v = dp[u][I][y];
	if (~v) 
		return v;
	v = -1e18;
	if (y) 
		return v = g[3][u] + max(dyn(u+1, I, 1), dyn(u+1, I, 0));

	// u 현재 col 을 따라 target y 까지 내려간 후 오른쪽으로 1칸을 진행했을 때의 cost 계산
	ll S = 0;
	FOR(k, I, 3) {
		S += g[k][u];
		v = max(v, dyn(u+1, k, 0) + S);
	}
	// u 현재 col 을 따라 target y 까지 올라간 후 오른쪽으로 1칸을 진행했을 때의 cost 계산
	S = 0;
	for (int k = I; ~k; --k) {
		S += g[k][u];
		v = max(v, dyn(u+1, k, 0) + S);
	}

	// if I != 1 일 때 I 가 0 이면 2로, 2면 0로 보내는데 y flag를 switch 시킴
	if (I ^ 1)
		v = max(v, dyn(u+1, I ? 0 : 2, 1) + g[3][u]);
	return v;
}

int main(void){
#ifdef _DEBUG
	freopen("762d.in", "r", stdin);
#endif
	scanf("%d",&N),CL(dp,-1);
	REP(i, 3)
		ga(N,g[i]);
	REP(i, N) {
		REP(j, 3) 
			g[3][i] += g[j][i];
	}
	cout << dyn(0,0,0) << endl;
	return 0;
}
