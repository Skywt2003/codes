#include<bits/stdc++.h>
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

struct task{
    int id,s,t,v;

    bool operator <(task bb)const{
        return (v<bb.v)||((v==bb.v)&&(s>bb.s));
    }
};

priority_queue<task> que;

task make_task(int id,int s,int t,int v){
    task ret; ret.id=id; ret.s=s; ret.t=t; ret.v=v;
    return ret;
}

signed main(){
    // freopen("testdata.in","r",stdin);
    int id,s,t,v,allt=0;
    while (scanf("%d%d%d%d",&id,&s,&t,&v)!=-1){
        task now=make_task(id,s,t,v);
        if (que.empty()) {allt=now.s;que.push(now);continue;}
        
        while ((!que.empty()) && allt<s){
            task now_top=que.top(); que.pop();
            if (allt < now_top.s) allt=now_top.s;
            if (allt+now_top.t <= s) allt+=now_top.t,printf("%d %d\n",now_top.id,allt);
            else {now_top.t-=s-allt,allt=s,que.push(now_top);break;}
        }

        que.push(now);
    }
    while (!que.empty()){
        task now_top=que.top(); que.pop();
        allt+=now_top.t;
        printf("%d %d\n",now_top.id,allt);
    }
    return 0;
}