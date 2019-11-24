#include <cstdio>
#include <cstdlib>
int n,k,x,y,v[10];
void f(int l, int s){
	if(l>6) return;
	if(x>l+abs(k-s) &&l)x=l+abs(k-s);
	for(int i=0; i<10;i++) if(!v[i]) f(l+1,s*10+i);
}
int main(){
	scanf("%d %d",&k,&n);
	while(n--)scanf("%d",&y),v[y]=1;
	x=abs(k-100);
	f(0,0);
	printf("%d",x);
}
