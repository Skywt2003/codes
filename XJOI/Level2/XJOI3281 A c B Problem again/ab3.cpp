#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=2005;
struct Bigint{
    int len,a[maxn];
    Bigint (){len=0;memset(a,0,sizeof(a));}
    void read(){
        len=0;memset(a,0,sizeof(a));
        char ch=getchar();
        while (ch<'0'||ch>'9') ch=getchar();
        while (ch>='0'&&ch<='9'){
            a[++len]=ch-'0';
            ch=getchar();
        }
        for (int i=1;i<=len/2;i++) swap(a[i],a[len-i+1]);
    }
    Bigint operator *(Bigint b){
        Bigint c;
        memset(c.a,0,sizeof(c.a));
        c.len=len+b.len;
        for (int i=1;i<=len;i++)
        for (int j=1;j<=b.len;j++){
            c.a[i+j-1]+=a[i]*b.a[j];
            c.a[i+j]+=c.a[i+j-1]/10;
            c.a[i+j-1]%=10;
        }
        while (c.a[c.len+1]) c.len++;
        while (c.a[c.len]==0&&c.len>1) c.len--;
        return c;
    }
    void write(){
        for (int i=len;i>=1;i--) printf("%d",a[i]);
    }
};
int main(){
    Bigint a,b;
    a.read();b.read();
    Bigint c;
    c=a*b;
    c.write();
    return 0;
}
