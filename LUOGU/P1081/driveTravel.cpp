#include<bits/stdc++.h>
// #define int long long
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

int Abs(int x){return (x<0)?-x:x;}

const int maxn=100005;
const double INF=1.0e9;

int n,m,glb;

struct city{
    int h,id,pre,nxt;
} a[maxn];

bool compare_height(city aa,city bb){return aa.h < bb.h;}
bool compare_id(city aa,city bb){return aa.id<bb.id;}
bool compare_distance(city aa,city bb){
    return (Abs(aa.h-glb)<Abs(bb.h-glb))||((Abs(aa.h-glb)==Abs(bb.h-glb))&&(aa.h<bb.h));
}

int Aw[maxn],Bw[maxn];
int f[maxn][22],A[maxn][22],B[maxn][22];

void build_chain(){
    sort(a+1,a+1+n,compare_height);
    for (int i=1;i<=n;i++) a[i].pre=a[i-1].id,a[i].nxt=a[i+1].id;
    sort(a+1,a+1+n,compare_id);
}
void delete_node(int x){
    a[a[x].pre].nxt=a[x].nxt;
    a[a[x].nxt].pre=a[x].pre;
}

void pre_build(){
    build_chain();
    for (int i=1;i<=n;i++){
        if (a[i].nxt==0) Bw[i]=a[i].pre; else
        if (a[i].pre==0) Bw[i]=a[i].nxt; else
        Bw[i]=(Abs(a[a[i].nxt].h-a[i].h) < Abs(a[a[i].pre].h-a[i].h) || ((Abs(a[a[i].nxt].h-a[i].h) == Abs(a[a[i].pre].h-a[i].h)&&(a[a[i].nxt].h < a[a[i].pre].h))))?
        a[i].nxt:a[i].pre;
        delete_node(i);
    }
    build_chain();
    for (int i=1;i<=n;i++){
        vector<city> vec; vec.clear();
        if (a[i].pre) vec.push_back(a[a[i].pre]);
        if (a[a[i].pre].pre) vec.push_back(a[a[a[i].pre].pre]);
        if (a[i].nxt) vec.push_back(a[a[i].nxt]);
        if (a[a[i].nxt].nxt) vec.push_back(a[a[a[i].nxt].nxt]);
        glb=a[i].h;
        sort(vec.begin(),vec.end(),compare_distance);
        if (vec.size()>=2) Aw[i]=vec[1].id; else Aw[i]=0;
        delete_node(i);
    }
    for (int i=1;i<n;i++){
        f[i][0]=Bw[Aw[i]];
        if (f[i][0]==0) continue;
        A[i][0]=Abs(a[Aw[i]].h-a[i].h);
        B[i][0]=Abs(a[Bw[Aw[i]]].h-a[Aw[i]].h);
    }
}

void build(){
    for (int j=1;j<=21;j++)
    for (int i=1;i<n;i++){
        f[i][j]=f[f[i][j-1]][j-1];
        A[i][j]=A[f[i][j-1]][j-1] + A[i][j-1];
        B[i][j]=B[f[i][j-1]][j-1] + B[i][j-1];
    }
}

pair<int,int> query2(int s,int x){
    pair<int,int> ret=make_pair(0,0);
    int now=s;
    for (int i=21;i>=0;i--) if (f[now][i]!=0 && ret.first+ret.second + A[now][i] + B[now][i] <= x){
        ret.first+=A[now][i]; ret.second+=B[now][i];
        now=f[now][i];
    }
    if (now<=n-2 && Aw[now]!=0 && Abs(a[Aw[now]].h-a[now].h)+ret.first+ret.second <= x) ret.first+=Abs(a[Aw[now]].h-a[now].h),now=Aw[now];
    return ret;
}

int query1(int x0){
    double ret=INF;
    int k=-1;
    for (int i=1;i<=n;i++){
        pair<int,int> now=query2(i,x0);
        if (now.second==0){
            if (INF<ret || (INF==ret && (k==-1||a[i].h>a[k].h))) ret=INF,k=i;
        } else if ((double)now.first/now.second < ret || ((double)now.first/now.second==ret && (k==-1||a[i].h>a[k].h))) ret=(double)now.first/now.second,k=i;
    }
    return k;
}

signed main(){
    n=read();
    for (int i=1;i<=n;i++) a[i].h=read(),a[i].id=i;
    
    pre_build();
    build();

    int x0=read();
    printf("%d\n",query1(x0));
    m=read();
    while (m--){
        int si=read(),xi=read();
        pair<int,int> ans=query2(si,xi);
        printf("%d %d\n",ans.first,ans.second);
    }
    return 0;
}