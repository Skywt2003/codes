#include<bits/stdc++.h>

using namespace std;

const int maxn=10005,maxe=10005;

int T,n;

int cnt=0;
map<string,int> id;

int tot=0,lnk[maxn],nxt[maxe],to[maxe],f[maxn];
int val[maxn],sum[maxn];
bool vis[maxn];
int ans=0;

void add_edge(int x,int y){
//	printf("build edge: %d -> %d\n",x,y);
	tot++; to[tot]=y; f[y]++;
	nxt[tot]=lnk[x]; lnk[x]=tot;
}

bool CE=false,RE=false;

void init(){
	CE=RE=false;
	tot=0;
	memset(lnk,0,sizeof(lnk));
	memset(nxt,0,sizeof(nxt));
	memset(to,0,sizeof(to));
	memset(f,0,sizeof(f));
	memset(val,0,sizeof(val));
	memset(sum,0,sizeof(sum));
	memset(vis,0,sizeof(vis));
	id.clear(); cnt=1; id["A"]=1; sum[1]=val[1]=1;
	ans=0;
}

int get_func_build(char *s){
	int len=strlen(s);
	string now="";
	for (int j=5;j<len;j++){
		if (s[j]=='(') break;
		now=now+s[j];
	}
	if (!id[now]) return id[now]=++cnt; else {
		CE=true;
		return 0;
	}
}

int get_func_use(char *s){
	int len=strlen(s);
	string now="";
	for (int j=4;j<len;j++){
		if (s[j]=='(') break;
		now=now+s[j];
	}
	if (!id[now]) {
		CE=true;
		return 0;
	} else return id[now];
}

void build_tree(int x){
	if (CE || RE || sum[x]) return;
	sum[x]=val[x];
	for (int i=lnk[x];i;i=nxt[i]){
		if (vis[to[i]]) {sum[x]=-1;return;}
		if (!sum[to[i]]){
			vis[to[i]]=true;
			build_tree(to[i]);
			vis[to[i]]=false;
		}
		if (sum[to[i]]==-1) {sum[x]=-1;break;}
		sum[x]+=sum[to[i]];
	}
}

string to_string(char *s){
	string ret=""; int len=strlen(s);
	for (int i=0;i<len;i++) ret+=s[i];
	return ret;
}

signed main(){
	freopen("program.in","r",stdin);
	freopen("program.out","w",stdout);

	scanf("%d",&T);
	while (T--){
		init();
		
		scanf("%d",&n);
		for (int i=1;i<=n;i++){
			char ss[maxn]; cin.getline(ss,35);
			string s=to_string(ss);
			
			if (s[0] == 'v' && s!="void A() { __=__+1; }"){
				int now_fa = get_func_build(ss);
				
				for (;;){
					i++;
					cin.getline(ss,35);
					s=to_string(ss);
					
					if (s == "}") break;
					if (s == "    A();") {val[now_fa]++;continue;}
					int now_son = get_func_use(ss);
					add_edge(now_fa,now_son);
				}
			} else if (s == "int main(){"){
				for (int i=1;i<=cnt;i++){
					vis[i]=true;
					build_tree(i);
					vis[i]=false;
				}
				
				for (;;){
					i++;
					cin.getline(ss,35);
					s=to_string(ss);
					
					if (s == "}") break;
					if (s=="    __ = 0;" || s=="    printf(\"%llu\\n\", __);") continue;
					int now=get_func_use(ss);
					if (sum[now]<0) RE=true;
					else ans+=sum[now];
				}
			}
		}
		if (CE) printf("Compile error\n"); else
		if (RE) printf("Segmentation fault\n"); else
		printf("%d\n",ans);
	}
	return 0;
}
