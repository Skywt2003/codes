#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=1005;
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
    Bigint operator +(Bigint b){
        Bigint c;
        memset(c.a,0,sizeof(c.a));
        c.len=max(len,b.len);
        for (int i=1;i<=c.len;i++){
            c.a[i]+=a[i]+b.a[i];
            c.a[i+1]+=c.a[i]/10;
            c.a[i]%=10;
        }
        return c;
    }
    void write(){
        for (int i=len;i>=1;i--) printf("%d",a[i]);
    }
};
int main(){
    Bigint a,b;
    a.read();b.read();
    Bigint c;c=a+b;
    c.write();
    return 0;
}