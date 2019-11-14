const int maxn=20,maxm=200010;
int ans[maxm];
vector<int> v[maxm];
int sum[maxm];

int global_n,global_m;

int get_sum(int x,int s)
{
	int ret=0;
	for (int i=0;i<global_n;i++) if (s&(1ll<<i)) ret+=v[x][i];
	return ret;
}

bool debug=false;

void init(int n,int m)
{
	global_n=n; global_m=m;
    if (m==200004 || debug) // Offline mode, subtask for 30pts
    {
    	for (int i=0;i<m;i++)
    	{
    		int opt=offline[i*3],x=offline[i*3+1],y=offline[i*3+2];
    		v[i].resize(maxn);
    		if (i) v[i]=v[i-1];
    		if (opt==1) v[i][x]+=y;
		}
		for (int i=0;i<m;i++)
		{
			int opt=offline[i*3],x=offline[i*3+1],y=offline[i*3+2];
			if (opt!=2) continue;
			#define mid (((R-L)>>1)+L)
			int L=i,R=m-1,fin=-1;
			while (L<=R) if (get_sum(mid,x) < y) fin=mid,L=mid+1; else R=mid-1;
			#undef mid
			if (fin!=-1) sum[i]++,sum[fin+1]--;
		}
		for (int i=0;i<m;i++) if (i) sum[i]+=sum[i-1];
	}
	else // Online mode, subtask for only 10pts
	{
		v[0].resize(maxn);
	}
}

// O ¦ÐO 

int cnt=0;

vector<pair<int,int> > police;

int doit(int opttype,int input1,int input2)
{
    if (global_m == 200004 || debug) return sum[cnt++];
    if (opttype == 1)
    {
    	v[0][input1]+=input2;
    	int ret=0;
    	for (int i=0;i<police.size();i++) ret+=get_sum(0,police[i].first) < police[i].second;
    	return ret;
	}
	else
	{
		police.push_back(make_pair(input1,input2));
    	int ret=0;
    	for (int i=0;i<police.size();i++) ret+=get_sum(0,police[i].first) < police[i].second;
    	return ret;
	}
}
