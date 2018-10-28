#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=20,maxx=32800;
int t,n,s,f[maxx][maxn],pre[maxx][maxn];
struct WorkInfo{
    int t,d;
    string s;
}a[maxn];
vector <string> rst[maxn];

inline bool cmp(vector <string> aa,vector <string> bb){
    int cnt=aa.size();
    if (cnt!=n||cnt!=bb.size()) printf("ERROR: THe size of Vector AA and the size of Vector bb is DIFFERENT!\n");
    for (int i=0;i<n;i++){
        if (aa[i]<bb[i]) return true; else
        if (aa[i]>bb[i]) return false;
    }
    printf("ERROR: There are two SAME Vectors.\n");
    return true;
}
int main(){
    scanf("%d",&t);
    while (t--){
        memset(pre,0,sizeof(pre));
        scanf("%d",&n);
        s=1<<n;
        for (int i=0;i<n;i++){
            cin>>a[i].s;
            scanf("%d%d",&a[i].d,&a[i].t);
        }
        memset(f,63,sizeof(f));
        for (int i=0;i<n;i++) f[0][i]=0;
        for (int j=1;j<s;j++)
        for (int i=0;i<n;i++) if (j&(1<<i)){
            int lst_dyn=j-(1<<i);
            for (int k=0;k<n;k++) if (lst_dyn==0||lst_dyn&(1<<k)){
                int x=lst_dyn,sum=0,cnt=0;
                while (x){
                    if (x&1) sum+=a[cnt].t;
                    x>>=1;cnt++;
                }
                if (f[lst_dyn][k]+max(0,sum+a[i].t-a[i].d)<f[j][i]||(f[j][i]==f[lst_dyn][k]+max(0,sum+a[i].t-a[i].d)&&a[k].s>a[pre[j][i]].s)){
                    f[j][i]=f[lst_dyn][k]+max(0,sum+a[i].t-a[i].d);
                    pre[j][i]=k;
                }
            }
        }
        int ans=1<<30;
        for (int i=0;i<n;i++) if (f[s-1][i]<ans) ans=f[s-1][i];
        printf("%d\n",ans);
        int rst_cnt=0;
        for (int i=0;i<n;i++) if (f[s-1][i]==ans){
            // printf("Break Poinr 1 ===========\n");
            rst_cnt++;rst[rst_cnt].clear();
            int x=s-1,y=i;
            while (x){
                rst[rst_cnt].push_back(a[y].s);
                int tmpy=y;y=pre[x][y];x-=1<<tmpy;
            }
            // printf("Break Poinr 2 ===========\n");
        }
        reverse(rst[rst_cnt].begin(),rst[rst_cnt].end());
        sort(rst+1,rst+1+rst_cnt,cmp);
        for (int i=0;i<n;i++) cout<<rst[1][i]<<endl;

        // printf("====All Answers:=====\n");
        // for (int ii=1;ii<=rst_cnt;ii++){
        //     for (int i=0;i<n;i++) cout<<rst[ii][i]<<endl;
        //     printf("\n");
        // }
        // printf("=====================\n");
    }
    return 0;
}