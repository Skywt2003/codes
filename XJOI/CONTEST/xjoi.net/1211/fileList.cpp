#include<bits/stdc++.h>
using namespace std;

const int maxn=55,maxe=105;

int n;
int cnt=1;
map<string,int> to[10];

struct node{
    int type,id; // 0: dir;  1: file
    string s;
}a[maxn];

vector<node> lnk[maxn];

bool compare_string(node aa,node bb){
    return aa.s<bb.s;
}

void write(int x,int deep){
    if (x!=1){
        for (int i=1;i<deep;i++) printf("|    ");
        if (deep!=0) printf("|----");
        cout<<a[x].s<<endl;
    }
    sort(lnk[x].begin(),lnk[x].end(),compare_string);
    for (int i=0;i<lnk[x].size();i++) write(lnk[x][i].id,deep+1);
}

signed main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        string s; cin>>s;
        int lst=1,deep=0;
        string now="";
        for (int i=0;i<s.length();i++){
            if (s[i]=='/'){
                int num=to[deep][now]; if (num==0) to[deep][now]=num=++cnt;
                a[num].s=now;
                a[num].type=0; a[num].id=num;
                bool flg=true;
                for (int j=0;j<lnk[lst].size();j++) if (lnk[lst][j].s==now) flg=false;
                if (flg) lnk[lst].push_back(a[num]);
                now=""; lst=num; deep++;
            } else now+=s[i];
        }
        int num=to[deep][now]; if (to[deep][now]==0) to[deep][now]=num=++cnt;
        a[num].s=now;
        a[num].type=1; a[num].id=num;
        lnk[lst].push_back(a[num]);
    }
    write(1,-1);
    return 0;
}