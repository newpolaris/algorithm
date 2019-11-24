#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  char s[50];
  char in[1 << 18], out[1 << 18];
  set<pair<int, string>> a;
  
  setvbuf(stdin, in, _IOFBF, 1 << 18);
  setvbuf(stdout, out, _IOFBF, 1 << 18);

  scanf("%d\n", &n);
  while(n--)
    a.insert({strlen(gets(s)), string(s)});
  
  for(auto& t : a)
    puts(t.second.data());
}
