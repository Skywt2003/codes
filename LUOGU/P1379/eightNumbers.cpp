#include<bits/stdc++.h>

using namespace std;

#define pii pair<int,int>

const int INF=0x3f3f3f3f;

const int flg[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
const int maxlen=15;
const int n=3;

string s;
string fin="123804765";

int get_number(int x,int y){
	return 3*(x-1)+y-1;
}

pii get_coord(int x){
	x++;
	if (1<=x && x<=3) return make_pair(1,x); else
	if (4<=x && x<=6) return make_pair(2,x-3); else
	if (7<=x && x<=9) return make_pair(3,x-6); else
	printf("get_coord(%d) | ERROR!\n",x);
	return make_pair(0,0);
}

int get_diff(string now){
	int ret=0;
	for (int i=0;i<9;i++) ret+=fin[i]!=now[i];
	return ret;

}
struct status{
	int diff,step,bx,by;
	string now;
	
	bool operator <(status bb)const{
		return diff+step > bb.diff+bb.step;
	}
	bool operator >(status bb)const{
		return diff+step < bb.diff+bb.step;
	}
};

priority_queue<status> que;
map<string,bool> vis;


bool check(int x,int y){
	if (x<1||y<1||x>n||y>n) return false;
	return true;
}

signed main(){
	cin>>s;
	if (s==fin){puts("0");return 0;}
	
	status st;
	for (int i=0;i<9;i++) if (s[i]=='0'){
		pii blank=get_coord(i);
		st=(status){get_diff(s),0,blank.first,blank.second,s};
		break;
	}
	
	que.push(st);// vis[s]=true; // Why??? unsolved.
	while (!que.empty()){
		status head=que.top(); que.pop();
		if (head.now==fin){printf("%d\n",head.step);return 0;}
		for (int i=0;i<4;i++){
			int xx=head.bx+flg[i][0],yy=head.by+flg[i][1];
			if (!check(xx,yy)) continue;
			
			int nowBlank=get_number(head.bx,head.by);
			int toSwap=get_number(xx,yy);
			swap(head.now[toSwap],head.now[nowBlank]);
			if (!vis[head.now]) vis[head.now]=true,que.push((status){get_diff(head.now),head.step+1,xx,yy,head.now});
			swap(head.now[toSwap],head.now[nowBlank]);
		}
	}
	
	return 0;
}
