#include<bits/stdc++.h>

const int maxlen=105;

char s1[maxlen],s2[maxlen],t[maxlen];
int map[256],used[255];
int len;

signed main(){
	scanf("%s",s1+1);
	scanf("%s",s2+1);
	scanf("%s",t+1);

	len=strlen(s1+1);
	for (int i=1;i<=len;i++){
		if (map[s1[i]]!=0 && map[s1[i]]!=s2[i]){puts("Failed");return 0;}
		map[s1[i]]=s2[i]; used[s2[i]]=true;
	}
	for (int i='A';i<='Z';i++) if (map[i]==0 || used[i]==0){puts("Failed");return 0;}

	int lent=strlen(t+1);
	for (int i=1;i<=lent;i++) putchar(map[t[i]]);
	putchar('\n');
	return 0;
}