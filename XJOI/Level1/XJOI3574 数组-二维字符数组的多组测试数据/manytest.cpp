#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
char a[5][10];
inline char read_ch(){
    char ch=getchar();while (ch==10||ch==13) ch=getchar();
    return ch;
}
int main(){
    char ch=read_ch();
    while (ch!=-1){
        a[1][1]=ch;
        for (int i=1;i<=3;i++)
        for (int j=1;j<=5;j++) if (i-1||j-1) a[i][j]=read_ch();
        for (int i=1;i<=3;i++){
            for (int j=1;j<=5;j++) putchar(a[i][j]);
            printf("\n");
        }
        ch=read_ch();
    }
    return 0;
}