#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
using namespace std;

const int SIZE=10000;
const int LENGTH=10;

int n,m,a[SIZE][LENGTH];

int h(int u,int v)
{
    int ans,i;
    ans=0;
    for(i=1;i<=n;i++)
       if( a[u][i]!=a[v][i])
           ans++;
    return ans;
}

int main()
{
    int sum,i,j;
    cin>>n;
    memset(a,0,sizeof(a));
    m=1;
    while(1)
    {
        i=1;
        while( (i<=n) && (a[m][i]==1) )
            i++;
        if(i>n)
           break;
        m++;
        a[m][i]=1;
        for(j=i+1;j<=n;j++)
           a[m][j]=a[m-1][j];
    }
    
		for (int i=1;i<=n;i++){
			for (int j=1;j<=m;j++) printf("%d",a[i][j]);
			printf("\n");
		}
    sum=0;
    for(i=1;i<=m;i++)
       for(j=1;j<=m;j++)
          sum+=h(i,j);
    cout<<sum<<endl;
    return 0;
}