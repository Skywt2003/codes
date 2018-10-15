#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=1005,maxlen=80;
char stk[maxn][maxlen],opt[maxlen],st[23]={"http://www.hzxjhs.com/"};
int stk_top=1,max_top=1;
int main(){
    for (int i=0;i<23;i++) stk[stk_top][i]=st[i];
    // stk[stk_top][22]=0;
    while (1){
        scanf("%s",opt);
        if (opt[0]=='V'){
            scanf("%s",stk[++stk_top]);
            printf("%s\n",stk[stk_top]);
            max_top=stk_top;
        } else if (opt[0]=='B'){
            if (stk_top==1) printf("Ignored\n"); else printf("%s\n",stk[--stk_top]);
        } else if (opt[0]=='F'){
            if (max_top<=stk_top) printf("Ignored\n"); else printf("%s\n",stk[++stk_top]);
        } else if (opt[0]=='Q') break;
    }
    return 0;
}