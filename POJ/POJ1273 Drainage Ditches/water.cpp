#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int maxn=205,maxe=405;
int n,m,tot=-1,ans=0,lnk[maxn],son[maxe],nxt[maxe],cur[maxn],w[maxe],deep[maxn],que[maxn];//w[]��������cur[]����ǰ���� 
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch==-1) return -1;if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
inline void add(int x,int y,int z){
	tot++;son[tot]=y;w[tot]=z;nxt[tot]=lnk[x];lnk[x]=tot;
}
inline bool BFS(){//����ֲ�ͼ�������Ƿ��������· 
	memset(que,0,sizeof(que));
	memset(deep,0,sizeof(deep));
	int head=0,tail=0;
	deep[1]=1;que[++tail]=1;
	while (head!=tail){
		head++;
		for (int i=lnk[que[head]];i!=-1;i=nxt[i]){
			if (w[i]&&(deep[son[i]]==0)){
				deep[son[i]]=deep[que[head]]+1;
				que[++tail]=son[i];
			}
		}
	}
	if (deep[n]==0) return false;
	return true;
}
inline int DFS(int x,int flw){//flw����ǰ������flow�� 
	if (x==n) return flw;
	for (int i=cur[x];i!=-1;i=cur[x]=nxt[i]){
		if ((deep[son[i]]==deep[x]+1)&&w[i]){
			int nxtflw=DFS(son[i],min(flw,w[i]));
			if (nxtflw){//nxtflw>0˵������ɹ� 
				w[i]-=nxtflw;
				w[i^1]+=nxtflw;//����߼��ϱ������������������������������ڴ洢������i^1��Ϊi�ķ���� 
				return nxtflw;//���ϴ��� 
			}
		}
	}
	return 0;//û��return˵��û������· 
}
inline void Dinic(){
	ans=0;
	while (BFS()){//�������������· 
		for (int i=1;i<=n;i++) cur[i]=lnk[i];
		while (int now=DFS(1,1<<30)) ans+=now;
	}
}
int main(){
	m=read();
	while (m!=-1){
		tot=-1;
		memset(lnk,-1,sizeof(lnk));//Ϊ�����ķ��㣬�ߺŴ�0��ʼ�� 
		memset(cur,-1,sizeof(cur));
		memset(nxt,-1,sizeof(nxt));
		n=read();
		for (int i=1;i<=m;i++){
			int x=read(),y=read(),z=read();
			add(x,y,z);add(y,x,0);
		}
		Dinic();
		printf("%d\n",ans);
		m=read();
	}
	return 0;
}
