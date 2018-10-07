/*
 * XJOI CONTEST1002 T2 棍子
 * 180921 By SkyWT
 */

#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<string>

using namespace std;

#define memset_clear(_) memset(_,0,sizeof(_))
#define memset_clear_reg(_) memset(_,-1,sizeof(_))
#define memset_clear_max(_) memset(_,0x3f,sizeof(_))
#define memset_clear_min(_) memset(_,0x80,sizeof(_))
#define sqr(_) ((_)*(_))

#define write(_) cout<<#_<<" = "<<_<<endl
#define write_2(_,__) cout<<#_<<" = "<<_<<" , "<<#__<<" = "<<__<<endl
#define write_3(_,__,___) cout<<#_<<" = "<<_<<" , "<<#__<<" = "<<__<<" , "<<#___<<" = "<<___<<endl

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=55;
int n,a[maxn];
queue <vector <int> > que;
queue <int> answer;

inline void BFS(){
	vector<int> s;s.clear();
	for (int i=1;i<=n;i++) s.push_back(a[i]);
	que.push(s);answer.push(0);
	while (!que.empty()){
		vector<int> now;now=que.front();que.pop();
		int ansnow=answer.front();answer.pop();
		int maxnum=-(1<<30),k=-1;
		bool flg=true;
		for (int i=0;i<now.size();i++){
			if (now[i]>maxnum) maxnum=now[i],k=i;
			if (i>0&&now[i]!=now[i-1]) flg=false;
		}
		if (flg){
			printf("%d\n",ansnow);
			return;
		}
		if (maxnum<2) continue;
		if (now[k]&1){
			int x=(now[k]-1)>>1,y=(now[k]+1)>>1;
			vector<int> nxt1,nxt2; nxt1=now,nxt2=now;
			nxt1[k]=x;nxt2[k]=y;
			que.push(nxt1);que.push(nxt2);
			answer.push(ansnow+1);answer.push(ansnow+1);
		} else {
			vector<int> nxt; nxt=now;
			nxt[k]=now[k]>>1;nxt.push_back(now[k]>>1);
			que.push(nxt);
			answer.push(ansnow+1);
		}

		// int cmaxnum=-(1<<30);
		// for (int i=0;i<now.size();i++){
		// 	if (now[i]!=maxnum&&now[i]>cmaxnum) cmaxnum=now[i],k=i;
		// }
		// if (cmaxnum<2) continue;
		// if (now[k]&1){
		// 	int x=(now[k]+1)>>1,y=(now[k]-1)>>1;
		// 	vector<int> nxt1,nxt2;nxt1=nxt2=now;
		// 	nxt1[k]=x;nxt2[k]=y;
		// 	que.push(nxt1);que.push(nxt2);
		// 	answer.push(ansnow+1);answer.push(ansnow+1);
		// } else {
		// 	vector<int> nxt;nxt=now;
		// 	nxt[k]=now[k]/2;nxt.push_back(nxt[k]);
		// 	que.push(nxt);
		// 	answer.push(ansnow+1);
		// }

	}
}

int main(){
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	BFS();
	return 0;
}