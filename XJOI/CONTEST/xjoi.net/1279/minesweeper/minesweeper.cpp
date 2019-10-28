// 血的教训：用 std::vector<opration>::size() 前面一定要加 (int) 强转！！
// (int)vec.size()
// 因为 size() 返回是 size_t 类型的！！！

#include<bits/stdc++.h>

// #define int long long

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=205;
const int flg[8][2]={{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};

int T;
int n,m,k,lft;
char a[maxn][maxn],mp[maxn][maxn];
bool o[maxn][maxn];

struct opration{
	int x,y;
	char ch;
};
vector<opration> ans;

int opt,x,y;

bool failed=false;

void init(){
	k=0; failed=false; lft=0;
	memset(o,false,sizeof(o));
	memset(mp,'_',sizeof(mp));
}

bool check(int x,int y){
	if (x<1||y<1||x>n||y>m) return false;
	return true;
}

#define nx (x+flg[i][0])
#define ny (y+flg[i][1])

void open(int x,int y){
	if (failed) return;
	if (a[x][y]=='*') {failed=true; return;}
	// if (o[x][y]) {printf("ERROR:Already opened\n");return;}

	o[x][y]=true; lft--;
	int cnt=0;
	for (int i=0;i<8;i++) if (check(nx,ny)) cnt+=a[nx][ny]=='*';
	mp[x][y]=cnt+'0';
	ans.push_back((opration){x,y,mp[x][y]});

	if (cnt==0){
		for (int i=0;i<8;i++) if (check(nx,ny) && o[nx][ny]==false && mp[nx][ny]!='P')
			open(nx,ny);
	}
}

void left_click(int x,int y){
	if (o[x][y] || mp[x][y]=='P') return; else
	open(x,y);
}

void right_click(int x,int y){
	if (o[x][y]) return; else
	if (mp[x][y]=='_') mp[x][y]='P',ans.push_back((opration){x,y,'P'}); else
	if (mp[x][y]=='P') mp[x][y]='?',ans.push_back((opration){x,y,'?'}); else
	if (mp[x][y]=='?') mp[x][y]='_',ans.push_back((opration){x,y,'_'});
}

void mid_click(int x,int y){
	if (!o[x][y]) return;
	int cnt=0;
	for (int i=0;i<8;i++) if (check(nx,ny)) cnt+=mp[nx][ny]=='P';
	if (mp[x][y]-'0' != cnt) return;
	for (int i=0;i<8;i++) if (check(nx,ny) && o[nx][ny]==false && mp[nx][ny]!='P') open(nx,ny);
}

#undef nx
#undef ny

bool compare_xy(opration aa,opration bb){
	return (aa.x<bb.x)||(aa.x==bb.x && aa.y<bb.y);
}

signed main(){
	#ifdef DEBUG
		freopen("minesweeper.in","r",stdin);
		// freopen("my.out","w",stdout);
	#endif

	T=read();
	while (T--){
		init();

		n=read(); m=read(); lft=n*m;
		for (int i=1;i<=n;i++){
			scanf("%s",a[i]+1);
			for (int j=1;j<=m;j++) k+=a[i][j]=='*';
		}

		opt=read();
		while (opt){
			x=read(),y=read();
			if (failed || lft==k) {printf("INVALID\n");opt=read();continue;}

			ans.clear();
			if (opt==1) left_click(x,y); else
			if (opt==2) right_click(x,y); else
			if (opt==3) mid_click(x,y);

			if (failed) {printf("LOSE\n");opt=read();continue;}

			sort(ans.begin(),ans.end(),compare_xy);
			printf("RUNNING: [");
			for (int i=0;i<(int)ans.size()-1;i++) printf("<%d, %d, %c>, ",ans[i].x,ans[i].y,ans[i].ch);
			if (ans.size()!=0) printf("<%d, %d, %c>]\n",ans[ans.size()-1].x,ans[ans.size()-1].y,ans[ans.size()-1].ch);
			else printf("]\n");
			
			if (lft==k) printf("WIN\n");

			opt=read();
		}
		if (!failed && lft!=k) printf("QUIT\n");

		if (T) puts("==========");
	}

	return 0;
}