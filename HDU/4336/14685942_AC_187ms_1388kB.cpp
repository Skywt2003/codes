#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=25;
int n;
double ans,a[maxn];
int main(){
    while (scanf("%d",&n)!=-1){
        for (int i=0;i<n;i++) scanf("%lf",&a[i]);
        int s=1<<n;ans=0.0;
        for (int j=1;j<s;j++){
            int cnt=0;double now=0.0;
            for (int i=0;i<n;i++) if (j&(1<<i)) cnt++,now+=a[i];
            now=1.0/now;
            if (cnt&1) ans+=now; else ans-=now;
        }
        printf("%.5lf\n",ans);
    }
    return 0;
}
