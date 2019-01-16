#include <cstdio>
int n,a[1111111],b,c;
long long cnt;
int main(){
  scanf("%d",&n);
  for(int i=0;i<n;i++)scanf("%d",a+i);
  scanf("%d%d",&b,&c);
  for(int i=0;i<n;i++)cnt+=a[i]>b?(a[i]-b+c-1)/c+1:1;
  printf("%lld",cnt);
  return 0;
}
