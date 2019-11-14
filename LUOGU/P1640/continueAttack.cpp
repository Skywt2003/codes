#include<bits/stdc++.h>

#define int long long

inline int read()
{
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=10005,maxe=20005;
const int NN=10001;

int n,nn;

class uniset{
	private:
		int fa[maxn],num[maxn];
		bool in_circle[maxn];

	public:
		void init(int n)
		{
			for (int i=1;i<=n;i++) fa[i]=i,num[i]=1;
			memset(in_circle,false,sizeof(in_circle));
		}

		int getfa(int x){return (fa[x]==x)?x:fa[x]=getfa(fa[x]);}

		void merge(int x,int y)
		{
			x=getfa(x),y=getfa(y);
			if (x==y){in_circle[x]=true;return;}
			fa[y]=x; in_circle[x]|=in_circle[y]; num[x]+=num[y];
		}

		int get_answer(int n)
		{
			for (int i=1;i<=n;i++) if (!in_circle[this->getfa(i)])
			{
				if (num[this->getfa(i)]==1) return i-1;
				num[this->getfa(i)]--;
			}
			return 0;
		}
};

uniset u;

signed main()
{
	n=read(); u.init(NN+1);
	for (int i=1;i<=n;i++)
	{
		int x=read(),y=read();
		nn=std::max(nn,std::max(x,y));
		u.merge(x,y);
	}

	printf("%lld\n",u.get_answer(nn+1));

	return 0;
}