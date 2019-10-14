#include<bits/stdc++.h>

using namespace std;

const char ch[13]={'3','4','5','6','7','8','9','0','J','Q','K','A','2'}; // 0 means 10
const string yes="Yes",no="No";

int n;
int cnt[255];
int b[255];

bool normal_check(){
	for (int i=0;i<13;i++){
		if (cnt[ch[i]] == 4){
			int sub1=-1,sub2=-1;
			for (int j=0;j<13;j++) if (j!=i && cnt[ch[j]] == 1){
				sub1=j; break;
			}
			for (int j=0;j<13;j++) if (j!=i && cnt[ch[j]] == 1 && j!=sub1){
				sub2=j; break;
			}
			cnt[ch[i]]-=4;
			if (sub1!=-1) cnt[ch[sub1]]--;
			if (sub2!=-1) cnt[ch[sub2]]--;
		} else if (cnt[ch[i]] == 3){
			bool flg=false;
			for (int j=0;j<13;j++) if (j!=i && cnt[ch[j]] == 1){
				flg=true; cnt[ch[i]]-=3; cnt[ch[j]]--; break;
			}
			if (!flg) cnt[ch[i]]-=3;
		} else if (cnt[ch[i]] == 2) cnt[ch[i]]=0;
	}
	int one_num=0;
	for (int i=0;i<13;i++) if (cnt[ch[i]] == 1) one_num++;

	return one_num <= 1;
}

signed main(){
	scanf("%d",&n);
	string now; char c;
	for (int i=1;i<=n;i++){
		cin>>now;
		if (now=="10") c='0'; else c=now[0];
		b[c]++;
	}

	// It is obvious that there are three Shunzis at most.

	// No shunzi condition
	for (int i=0;i<13;i++) cnt[ch[i]]=b[ch[i]];
	if (normal_check()){
		cout<<yes<<endl;
		return 0;
	}

	// Single shunzi condition
	for (int i=0;i<12;i++)
		for (int j=i+4;j<12;j++){
			for (int k=0;k<13;k++) cnt[ch[k]]=b[ch[k]];
			bool flg=true;
			for (int k=i;k<=j;k++){cnt[ch[k]]--;if (cnt[ch[k]] < 0) {flg=false;break;} }
			if (!flg) break;

			if (normal_check()){
				cout<<yes<<endl;
				return 0;
			}
		}
	
	// Double shunzis condition
	for (int i=0;i<12;i++)
		for (int j=i+4;j<12;j++)
			for (int k=i+1;k<12;k++)
				for (int t=k+4;t<12;t++){
					for (int w=0;w<13;w++) cnt[ch[w]]=b[ch[w]];
					bool flg=true;
					for (int w=i;w<=j;w++){cnt[ch[w]]--;if (cnt[ch[w]] < 0) {flg=false;break;} }
					for (int w=k;w<=t;w++){cnt[ch[w]]--;if (cnt[ch[w]] < 0) {flg=false;break;} }
					if (!flg) break;

					if (normal_check()){
						cout<<yes<<endl;
						return 0;
					}
				}

	// Th??ble shunzis condition
	for (int i=0;i<12;i++)
		for (int j=i+4;j<12;j++)
			for (int k=0;k<12;k++)
				for (int t=k+4;t<12;t++)
					for (int ii=0;ii<12;ii++)
						for (int jj=ii+4;jj<12;jj++){
							for (int w=0;w<13;w++) cnt[ch[w]]=b[ch[w]];
							bool flg=true;
							for (int w=i;w<=j;w++){cnt[ch[w]]--;if (cnt[ch[w]] < 0) {flg=false;break;} }
							for (int w=k;w<=t;w++){cnt[ch[w]]--;if (cnt[ch[w]] < 0) {flg=false;break;} }
							for (int w=ii;w<=jj;w++){cnt[ch[w]]--;if (cnt[ch[w]] < 0) {flg=false;break;} }
							if (!flg) break;

							if (normal_check()){
								cout<<yes<<endl;
								return 0;
							}
						}

	// All conditions OK
	cout<<no<<endl;
	return 0;
}