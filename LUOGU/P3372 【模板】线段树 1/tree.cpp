//Go over Segment Tree...
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=2000005;
int n,m;
long long a[maxn],tree[maxn],tag[maxn];
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
inline long long llread(){
	long long ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=(long long)-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*(long long)10+(long long)(ch-'0'),ch=getchar();
	return (long long)ret*f;
}
inline void build(int p,int tl,int tr){  //����Segment Tree 
	tag[p]=0;
	if (tl==tr) {tree[p]=a[tl];return;}
	int mid=((tr-tl)>>1)+tl;
	build((p<<1)  ,tl,mid  );
	build((p<<1)+1,mid+1,tr);
	tree[p]=tree[p<<1]+tree[(p<<1)+1];
}
inline void push_down(int tl,int tr,int p){  //push_down�����������´��ݣ����洢��tag������������ 
	int mid=((tr-tl)>>1)+tl;
	tree[p<<1]+=(long long)tag[p]*(mid-tl+1);  //ֻ��Ҫ����һ�����Ҷ��ӣ�����Ҫһֱ���ݵ�Ҷ�ڵ� 
	tag[p<<1]+=tag[p];  //��Ϊû����������������Ҫ�Ѷ��ӵ�tag�ۼ��� 
	tree[(p<<1)+1]+=(long long)tag[p]*(tr-mid);
	tag[(p<<1)+1]+=tag[p];
	tag[p]=0;
}
inline void update(int sl,int sr,int tl,int tr,long long delta,int p){
	if (sl<=tl&&sr>=tr){  //p��Ͻ���������޸ķ�Χ�� 
		tree[p]+=delta*(long long)(tr-tl+1);
		tag[p]+=delta;  //tag�����¼ʣ�µ�δ���´��ݵģ�ʵ�֡�lazy tag��
		return;
	}
	push_down(tl,tr,p);  //���û����ȫ����p��Ͻ�����䣬��˵��Ӧ�����¡��ָ������Ӧ����tag���������������tree[] 
	int mid=((tr-tl)>>1)+tl;  //�ָ�[tl,tr]���� 
	if (sl<=mid) update(sl,sr,tl,mid,delta,p<<1);
	if (mid<sr)  update(sl,sr,mid+1,tr,delta,(p<<1)+1);
	tree[p]=tree[p<<1]+tree[(p<<1)+1];  //�����ۼ� 
}
inline long long query(int sl,int sr,int tl,int tr,int p){  //��ѯ���� 
	if (sl<=tl&&sr>=tr) return tree[p];  //�����ȫ����p����Ͻ��������ֱ�ӷ���tree[p] 
	long long ret=0;  //����͡��ָ 
	push_down(tl,tr,p);  //��Ҫ�ѵ�ǰ��tag�������������������ӣ��������ܱ�֤����query�õ���tree[]����ȷ�� 
	int mid=((tr-tl)>>1)+tl;
	if (sl<=mid) ret+=(long long)query(sl,sr,tl,mid,p<<1);
	if (mid<sr)  ret+=(long long)query(sl,sr,mid+1,tr,(p<<1)+1);
	return ret;
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	n=read();m=read();
	for (int i=1;i<=n;i++) a[i]=llread();
	build(1,1,n);
	for (int i=1;i<=m;i++){
		int c=read();
		if (c==1){
			int x=read(),y=read();
			long long z=llread();
			update(x,y,1,n,z,1);
		} else
		if (c==2){
			int x=read(),y=read();
			printf("%lld\n",query(x,y,1,n,1));
		}
	}
	return 0;
}
