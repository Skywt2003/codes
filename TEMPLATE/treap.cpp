//https://blog.csdn.net/acdreamers/article/details/11309971

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
struct Treap
{
    int size;
    int key, fix;
    Treap *ch[2];
    Treap(int key)
    {
        size=1;
        fix=rand();
        this->key=key;
        ch[0]=ch[1]=NULL;
    }
    int compare(int x) const
    {
        if(x==key) return -1;
        return x<key? 0:1;
    }
    void Maintain()
    {
        size=1;
        if(ch[0]!=NULL) size+=ch[0]->size;
        if(ch[1]!=NULL) size+=ch[1]->size;
    }
};
void Rotate(Treap* &t, int d)
{
    Treap *k=t->ch[d^1];
    t->ch[d^1]=k->ch[d];
    k->ch[d]=t;
    t->Maintain();  
    k->Maintain();
    t=k;
}
void Insert(Treap* &t, int x)
{
    if(t==NULL) t=new Treap(x);
    else
    {
        int d=x < t->key ? 0 : 1;  
        Insert(t->ch[d], x);
        if(t->ch[d]->fix > t->fix)
            Rotate(t, d^1);
    }
    t->Maintain();
}
void Delete(Treap* &t, int x)
{
    int d=t->compare(x);
    if(d==-1)
    {
        Treap *tmp=t;
        if(t->ch[0]==NULL)
        {
            t=t->ch[1];
            delete tmp;
            tmp=NULL;
        }
        else if(t->ch[1]==NULL)
        {
            t=t->ch[0];
            delete tmp;
            tmp=NULL;
        }
        else
        {
            int k=t->ch[0]->fix > t->ch[1]->fix ? 1:0;
            Rotate(t, k);
            Delete(t->ch[k], x);
        }
    }
    else Delete(t->ch[d], x);
    if(t!=NULL) t->Maintain();
}
bool Find(Treap *t, int x)
{
    while(t!=NULL)
    {
        int d=t->compare(x);
        if(d==-1) return true;
        t=t->ch[d];
    }
    return false;
}
int Kth(Treap *t, int k)
{
    if(t==NULL||k<=0||k>t->size)
        return -1;
    if(t->ch[0]==NULL&&k==1)
        return t->key;
    if(t->ch[0]==NULL)
        return Kth(t->ch[1], k-1);
    if(t->ch[0]->size>=k)
        return Kth(t->ch[0], k);
    if(t->ch[0]->size+1==k)
        return t->key;
    return Kth(t->ch[1], k-1-t->ch[0]->size);
}
int Rank(Treap *t, int x)
{
    int r;
    if(t->ch[0]==NULL) r=0;
    else  r=t->ch[0]->size;
    if(x==t->key) return r+1;
    if(x<t->key)
        return Rank(t->ch[0], x);
    return r+1+Rank(t->ch[1], x);
}
void DeleteTreap(Treap* &t)
{
    if(t==NULL) return;
    if(t->ch[0]!=NULL) DeleteTreap(t->ch[0]);
    if(t->ch[1]!=NULL) DeleteTreap(t->ch[1]);
    delete t;
    t=NULL;
}
void Print(Treap *t)
{
    if(t==NULL) return;
    Print(t->ch[0]);
    cout<<t->key<<endl;
    Print(t->ch[1]);
}
int val[1000005];
int main()
{
    int n, x, m;
    while(~scanf("%d%d", &n, &m))
    {
        for(int i=1; i<=n; i++)
            scanf("%d", &val[i]);
        int idx=1;
        Treap *root=NULL;
        for(int i=1; i<=m; i++)
        {
            scanf("%d", &x);
            for(int j=idx; j<=x; j++)
                Insert(root, val[j]);
            idx=x+1;
            printf("%d\n", Kth(root, i));
        }
        DeleteTreap(root);
    }
    return 0;
}