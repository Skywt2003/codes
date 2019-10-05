    // B
     
    #include <bits/stdc++.h>
     
    using namespace std;
    //#define int long long
     
    inline int read(){
        int ret=0,f=1;char ch=getchar();
        while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
        while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
        return ret*f;
    }
     
    const int maxn=55;
     
    int n,m;
    int a[maxn][maxn];
    int b[maxn][maxn];
     
    vector<pair<int,int> > ans;
     
    void set_value(int x,int y){
        b[x][y]=b[x+1][y]=b[x][y+1]=b[x+1][y+1]=1;
    }
     
    signed main() {
        n=read(); m=read();
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                a[i][j]=read();
        
        for (int i=1;i<n;i++)
            for (int j=1;j<m;j++){
                if (a[i][j] && a[i+1][j] && a[i][j+1] && a[i+1][j+1]){
                    set_value(i,j);
                    ans.push_back(make_pair(i,j));
                }
            }
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++){
                if (a[i][j]!=b[i][j]){
                    printf("-1\n");
                    return 0;
                }
            }
        printf("%d\n",(int)ans.size());
        for (int i=0;i<ans.size();i++) printf("%d %d\n",ans[i].first,ans[i].second);
        return 0;
    }