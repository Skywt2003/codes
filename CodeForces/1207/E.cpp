    // E
     
    #include <bits/stdc++.h>
     
    using namespace std;
    //#define int long long
     
    inline int read(){
        int ret=0,f=1;char ch=getchar();
        while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
        while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
        return ret*f;
    }
     
    const int maxn=15;
     
    int a[maxn];
    int x,num;
     
    signed main(){
        num=0;
        for (int i=0;i<=6;i++) num+=1<<i;
        putchar('?');putchar(' ');
        for (int i=0;i<100;i++) printf("%d ",num+(i<<7)); printf("\n");
        fflush(stdout);
        x=read();
        for (int i=0;i<=6;i++) a[i]=(x&(1<<i))?0:1;
     
        num=0;
        for (int i=7;i<=13;i++) num+=1<<i;
        putchar('?');putchar(' ');
        for (int i=0;i<100;i++) printf("%d ",num+i); printf("\n");
        fflush(stdout);
        x=read();
        for (int i=7;i<=13;i++) a[i]=(x&(1<<i))?0:1;
     
        int ans=0;
        for (int i=0;i<14;i++) if (a[i]) ans+=1<<i;
        printf("! %d\n",ans);
        return 0;
    }