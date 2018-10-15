#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=1000005;
int top=0,stk[maxn],ans=0;
inline int getnum(char ch){
    if (ch=='('||ch==')') return 0; else
    if (ch=='['||ch==']') return 1; else
    if (ch=='{'||ch=='}') return 2; else
    if (ch=='<'||ch=='>') return 3; else return -1;
}
inline int getf(char ch){
    if (ch=='('||ch=='['||ch=='{'||ch=='<') return 0; else return 1;
}
int main(){
    char ch=getchar();int now=0;
    while (getnum(ch)!=-1){
        now=getnum(ch);
        int f=getf(ch);
        if (f){
            if (top>=1) {if (stk[top]!=now) ans++;top--;} else {printf("Impossible\n");return 0;}
        } else stk[++top]=now;
        ch=getchar();
    }
    printf("%d\n",ans);
    return 0;
}