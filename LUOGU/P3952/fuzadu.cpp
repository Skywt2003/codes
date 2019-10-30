#include<bits/stdc++.h>

// #define int long long
using namespace std;

const int maxlen=105;

int T,n;

char s[maxlen];
bool used[255];
int gave;

int get_number(char *s){
	int i=1,ret=0;
	while (s[i]<'0'||s[i]>'9') i++;
	while (s[i]>='0'&&s[i]<='9') ret=ret*10+s[i]-'0',i++;
	return ret;
}

pair<int,int> get_number_pair(char *s){
	int i=1; pair<int,int> ret=make_pair(0,0);
	while (s[i]<'0'||s[i]>'9') {if (s[i]=='n') {ret.first =-1;i++;break;} i++;}
	if (ret.first !=-1) while (s[i]>='0'&&s[i]<='9') ret.first=ret.first*10+s[i]-'0',i++;
	while (s[i]<'0'||s[i]>'9') {if (s[i]=='n') {ret.second=-1;i++;break;} i++;}
	if (ret.second!=-1) while (s[i]>='0'&&s[i]<='9') ret.second=ret.second*10+s[i]-'0',i++;
	return ret;
}

int flg[maxlen];// -1: Don't do;  0: O(1);  1: O(n);
char let[maxlen];

signed main(){
	#ifdef DEBUG
		freopen("data.in","r",stdin);
	#endif
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n); //scanf("%s",s+1);
		cin.getline(s+1,100);
		#ifdef DEBUG
			// printf("Given string is s=%s\n",s+1);
		#endif
		if (s[4]=='1') gave=0; else gave=get_number(s);
		#ifdef DEBUG
			// printf("gave=%d\n",gave);
		#endif

		memset(flg,0,sizeof(flg));
		memset(let,0,sizeof(let));
		memset(used,0,sizeof(used));
		bool ce=false;
		int level=0,cnt=0,ans=0,dont=0;

		for (int i=1;i<=n;i++){
			// scanf("%s",s+1);
			cin.getline(s+1,100);
			if (ce) continue;
			#ifdef DEBUG
				printf("Processing s=%s\n",s+1);
			#endif
			if (s[1]=='F'){
				level++;
				if (used[s[3]]){ce=true;continue;}
				used[s[3]]=true; let[level]=s[3];

				pair<int,int> num=get_number_pair(s);
				#ifdef DEBUG
					// printf("Getting pair: %d %d\n",num.first,num.second);
				#endif
				if (level>0 && flg[level-1]==-1) flg[level]=-1; else
				if (num.first==-1 && num.second!=-1) flg[level]=-1; else
				if (num.first!=-1 && num.second==-1) flg[level]=1,cnt+=(dont==0); else
				if (num.first==-1 && num.second==-1) flg[level]=0; else
				if (num.first > num.second) flg[level]=-1; else
				flg[level]=0;

				if (flg[level]==-1) dont++;
			} else if (s[1]=='E'){
				used[let[level]]=false;
				if (flg[level]==1) cnt--; else
				if (flg[level]==-1) dont--;
				level--;
			}
			if (level<0) {ce=true;continue;}
			ans=max(ans,cnt);
		}
		if (level!=0 || ce==true) printf("ERR\n"); else
		if (gave==ans) printf("Yes\n"); else
		printf("No\n");
		#ifdef DEBUG
			printf("===============\n");
		#endif
	}
	return 0;
}