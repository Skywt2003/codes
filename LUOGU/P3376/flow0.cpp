//My first network-flows code.
//By: https://www.cnblogs.com/SYCstudio/p/7260613.html

//Dinic with cur.
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=10005,maxe=200005;
int n,m,s,t,tot=-1,ans=0,nxt[maxe],son[maxe],w[maxe],deep[maxn],lnk[maxn],que[maxn],cur[maxn];
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
inline void add(int x,int y,int z){
	tot++;son[tot]=y;w[tot]=z;nxt[tot]=lnk[x];lnk[x]=tot;
}
inline bool BFS(){//��������������ǹ���ֲ�ͼͬʱ������������· 
	memset(deep,0,sizeof(deep));
	deep[s]=1;//Դ������Ϊ1 
	int head=0,tail=1;que[tail]=s;
	while (head!=tail){
		head++;
		for (int i=lnk[que[head]];i!=-1;i=nxt[i]) if (w[i]>0&&deep[son[i]]==0) deep[son[i]]=deep[que[head]]+1,que[++tail]=son[i];
	}
	if (deep[t]==0) return 0;//���������Ϊ0˵��û�б���������Ҳ����˵û������· 
	return 1;
}
inline int DFS(int x,int now){//xΪ��ǰ�㣬nowΪ��ǰ���� 
	if (x==t) return now;
	for (int i=cur[x];i!=-1;i=cur[x]=nxt[i]) if (deep[son[i]]==deep[x]+1&&w[i]!=0){
		int nxtd=DFS(son[i],min(now,w[i]));
		if (nxtd>0){
			w[i]-=nxtd;
			w[i^1]+=nxtd;//����߼�  
			return nxtd;//���ϴ��� 
		}
	}
	return 0;
}
inline void Dinic(){
	while (BFS()){
		for (int i=1;i<=n;i++) cur[i]=lnk[i];
		while (int now=DFS(s,1<<30)) ans+=now;//��ʼ����Ϊ������ 
	}
}
int main(){
	memset(lnk,-1,sizeof(lnk));//��Ϊ�ߺŴ�0��ʼ�洢������-1��ʾû�б� 
	memset(nxt,-1,sizeof(nxt));
	n=read();m=read();s=read();t=read();
	for (int i=1;i<=m;i++){
		int x=read(),y=read(),z=read();
		add(x,y,z);add(y,x,0);//���췴��߲�����ߺ������������ 
	}
	Dinic();
	printf("%d\n",ans);
	return 0;
}
