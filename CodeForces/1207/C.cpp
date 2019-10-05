    // C
     
    #include <bits/stdc++.h>
     
    using namespace std;
    #define int long long
     
    inline int read(){
        int ret=0,f=1;char ch=getchar();
        while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
        while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
        return ret*f;
    }
     
    const int INF=0x3f3f3f3f3f3f3f3f;
    const int maxn=2e5+5;
     
    int T;
    int n,num1,num2;
    char a[maxn];
     
    int f[maxn][2];
     
    signed main(){
        T=read();
        while (T--){
            memset(f,0x3f,sizeof(f));
            n=read(); num1=read(); num2=read();
            f[0][0]=num2;
            scanf("%s",a+1);
            for (int i=1;i<=n;i++){
                if (a[i]=='0'){
                    f[i][0]=min(f[i-1][1]+2*num1+num2,f[i-1][0]+num1+num2);
                    f[i][1]=min(f[i-1][1]+num1+2*num2,f[i-1][0]+2*num1+2*num2);
                } else {
                    f[i][1]=f[i-1][1]+num1+2*num2;
                }
            }
            printf("%lld\n",f[n][0]);
        }
        return 0;
    }