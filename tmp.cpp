#include<iostream>   
using namespace std;
int a[10000];
int gcd(int m,int n){
 while(n){
 	int r=m%n;m=n;n=r;
 }
 return m;
}
int main(){
	int n=1000,r=202;
	for(int i=1;i<=n-r;i++) a[i]=n-i+1;
	for(int i=2;i<=r;i++){
		int k=i;
		for(int j=1;j<=n-r;j++)
		if(gcd(k,a[j])>1){
			int g=gcd(k,a[j]);
			k/=g; a[j]/=g;
			if(k==1) break;
		}
}
int p=1,g=0;
	for(int i=1;i<=n-r;i++){
		p*=a[i];
		while(p%5==0){
			p/=5; g++;
		}
		p%=5;
	}
	cout<<g<<endl;
	return 0;
}