#include<bits/stdc++.h>
// #define int long long
using namespace std;

#define sqr(_) ((_)*(_))

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=20,maxs=262144+5;
const int INF=1<<30;
const double eps=1e-10;

int T,n,m,alls;
pair<double,double> pig[maxn];
int f[maxs];
int g[maxn][maxn];

double getA(double x1,double y1,double x2,double y2){return (y1*x2-y2*x1)/(x1*x2*(x1-x2));}
double getB(double a,double x,double y){return (y-a*sqr(x))/x;}
double aabbss(double x){return (x<0)?-x:x;}
bool equal(double aa,double bb){return aabbss(aa-bb)<=eps;}
bool cross(double a,double b,double x,double y){return equal(a*sqr(x)+b*x, y);}

int popcount(int x){
    int ret=0;
    while (x) ret+=x&1,x>>=1;
    return ret;
}

signed main(){
    T=read();
    while (T--){
        memset(f,63,sizeof(f));
        memset(g,0 ,sizeof(g));

        n=read();m=read();
        for (int i=0;i<n;i++){
            double x,y;scanf("%lf%lf",&x,&y);
            pig[i]=make_pair(x,y);
        }
        
        for (int i=0;i<n;i++)
        for (int j=0;j<n;j++) if (i!=j && pig[i].first!=pig[j].first){
            double a=getA(pig[i].first,pig[i].second,pig[j].first,pig[j].second);
            if (a>=0) continue;
            double b=getB(a,pig[i].first,pig[i].second);
            g[i][j]=(1<<i)|(1<<j);
            for (int k=0;k<n;k++) if ((g[i][j]&(1<<k))==0 && cross(a,b,pig[k].first,pig[k].second)) g[i][j]|=(1<<k);
        }

        alls=1<<n;
        f[0]=0;
        for (int s=0;s<alls;s++){
            for (int i=0;i<n;i++) if ((s&(1<<i))==0)
            for (int j=0;j<n;j++) if ((s&(1<<j))==0 && g[i][j]){
                int ns=s|g[i][j];
                f[ns]=min(f[ns],f[s]+1);
            }
        }
        int ans=INF;
        for (int i=0;i<alls;i++) ans=min(ans,f[i]+n-popcount(i));
        printf("%d\n",ans);
    }
    return 0;
}