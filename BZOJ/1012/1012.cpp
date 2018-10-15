#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=200005,maxs=524300; //length(maxs):2^deep -1 (Via: Geometric Progression); deep=log_2(maxn) +1.
//This problem is so easy that we don't even have to use Lazy Tag...
int n,tt,nst=0,tree[maxs],lgt=0;
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
inline int read_char(){
	char ch=getchar();
	while (ch!='A'&&ch!='Q') ch=getchar();
	return (ch=='A');
}
inline int max(int x,int y){
	if (x>y) return x; else return y;
}
inline void update(int tl,int tr,int p){
	if (tl>tr) return;
	if (tl!=tr){
		
	}
}
inline int query(int tl,int tr,int sl,int sr,int p){
	if (sl<=tl&&tr<=sr) return tree[p];
	int mid=((tr-tl)>>1)+tl;
	return max(query(tl,mid,sl,sr,p<<1),query[mid+1,tr,sl,sr,(p<<1)+1]);
}
int main(){
	freopen("maxnum.in","r",stdin);
	freopen("maxnum.out","w",stdout);
	n=read();tt=read();
	for (int i=1;i<=n;i++){
		if (read_char()){
			int x=read();lgt++;
			update(1,n,1);
		} else {
			int l=read();
			printf("%d\n",query(1,n,lgt-l+1,lgt,1));
		}
	}
	return 0;
}
