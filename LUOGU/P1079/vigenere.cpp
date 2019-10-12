#include<bits/stdc++.h>

using namespace std;

const int maxlen=1005;

char k[maxlen],s[maxlen];
int lenk,lens;

int mp[26][26];
bool upcase[maxlen];

signed main(){
    for (int i=0;i<26;i++)
        for (int j=0;j<26;j++)
            mp[i][j]=(j+i+26)%26;

    scanf("%s",k); scanf("%s",s);
    lenk=strlen(k); lens=strlen(s);

    for (int i=0;i<lenk;i++) if (k[i]>='A' && k[i]<='Z') k[i]+='a'-'A';
    for (int i=0;i<lens;i++) if (s[i]>='A' && s[i]<='Z') upcase[i]=true,s[i]+='a'-'A';

    for (int i=0;i<lens;i++){
        for (int j=0;j<26;j++) if (mp[k[i%lenk]-'a'][j] == s[i]-'a'){
            s[i]=j+'a';
            if (upcase[i]) s[i]-='a'-'A';
            break;
        }
    }
    printf("%s\n",s);
    return 0;
}