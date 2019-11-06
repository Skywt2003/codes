#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
struct edge{
	int next,to;
}a[N<<1];
int head[N],cnt;
inline void add(int u,int v){
	a[++cnt].to=v;
	a[cnt].next=head[u];
	head[u]=cnt;
}
int n,m,ans;
int dep[N];
char str1[25],str2[25];
void dfs(int x,int fa){
	for (int i=head[x];i;i=a[i].next){
		int y=a[i].to;
		if (y==fa) continue;
		dep[y]=dep[x]+1,dfs(y,x);
	}	
}
int main(int argc,char *argv[]){
    FILE *fin=fopen(argv[1],"r");
    FILE *fout=fopen(argv[2],"r");
    FILE *fstd=fopen(argv[3],"r");
    FILE *score=fopen(argv[5],"w");
    FILE *msg=fopen(argv[6],"w");
    fscanf(fout,"%s",str1+1);
    fscanf(fstd,"%s",str2+1);
    if ((str1[1]=='N')^(str2[1]=='N')){
    	fprintf(score,"0\n");
    	fprintf(msg,"WA\n");
    	return 0;
    }
    if (str1[1]=='N'){
    	fprintf(score,"10\n");
    	fprintf(msg,"AC\n");
    	return 0;
    }
    fscanf(fin,"%d%d",&n,&m);
    for (int i=1;i<=strlen(str1+1);++i){
    	assert(str1[i]>='0' && str1[i]<='9');
    	ans=(ans<<1)+(ans<<3)+str1[i]-'0';
    }
    assert(ans>0 && ans<=n);
    for (int i=1;i<n;++i){
    	int u,v;
    	fscanf(fin,"%d%d",&u,&v);
    	add(u,v),add(v,u);
    }
    dfs(ans,0);
    for (int i=1;i<=m;++i){
    	int u,v,w;
    	fscanf(fin,"%d%d%d",&u,&v,&w);
		if (dep[u]+dep[v]>w){
			fprintf(score,"0\n");
    		fprintf(msg,"WA\n");
    		return 0;
		}
    }
    fprintf(score,"10\n");
    fprintf(msg,"AC\n");
    return 0;
}
