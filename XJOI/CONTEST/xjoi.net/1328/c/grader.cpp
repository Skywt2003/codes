#include<bits/stdc++.h>
using namespace std;

vector<int>offline;

void init(int n,int m);
int doit(int opttype,int input1,int input2);

#include"program.cpp"

int main(){
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	
    int n, m;
    vector<int>tmp;
    cin>>n>>m;
    tmp.resize(m*3);
    for (int i=0;i<m*3;++i) scanf("%d",&tmp[i]);
    int debug=1;
    if (debug){
        offline=tmp;
    }else{
        if (m%10==4) offline=tmp;
    }
    init(n,m);
    for (int i=0;i<m;++i){
        printf("%d\n",doit(tmp[i*3],tmp[i*3+1],tmp[i*3+2]));
    }
}
