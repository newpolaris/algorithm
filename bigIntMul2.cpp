#include <cstdio>

#if 0
    string s = to_string(pow(2, n));
    int idx = s.find('.');
    s = s.substr(0, idx);
    s[s.length() - 1] -= 1;
#endif

const int N = 35;
int str[N+10];

void f(int a, int b, int c, int n){
	if(n == 0) return;
	f(a, c, b, n-1);
	printf("%d %d\n", a, c);
	f(b, a, c, n-1);
}

int main(){
	int n, i, j;
	scanf("%d", &n);

	str[0] = 1;
	for(i = 0; i < n; i++){
		for(j = 0; j < N; j++)
			str[j] <<= 1;
		for(j = 0; j < N; j++){
			str[j+1] += str[j] / 10;
			str[j] %= 10;
		}
	}
	str[0]--;
	for(i = 0; str[i] < 0; i++){
		str[i] += 10, str[i+1]--;
	}
	for(i = N-1; !str[i]; i--);
	for(; i >= 0; i--) printf("%d", str[i]);
	puts("");

	if(n <= 20) f(1, 2, 3, n);
}
