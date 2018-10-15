#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=55,maxx=505;
int n;
char s1[maxn],s2[maxn],ls[maxx],rs[maxx];
inline char Build(int s_1,int t_1,int s_2,int t_2){
    if (s_1>t_1) return 0;
    if (t_1==s_1) return s1[s_1];
    for (int i=0;i<=t_2-s_2;i++) if (s1[s_1]==s2[s_2+i]){
        ls[s1[s_1]]=Build(s_1+1,s_1+i,s_2,s_2+i-1);
        rs[s1[s_1]]=Build(s_1+i+1,t_1,s_2+i+1,t_2);
        break;
    }
    return s1[s_1];
}
inline void DFS(char x){
    if (ls[x]) DFS(ls[x]);
    if (rs[x]) DFS(rs[x]);
    putchar(x);
}
int main(){
    scanf("%s",s1+1);
    scanf("%s",s2+1);
    n=strlen(s1+1);
    Build(1,n,1,n);
    DFS(s1[1]);
    return 0;
}