#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int INF=1e9+7;

namespace Treap{
	struct Treap_Node{
		Treap_Node *left,*right;
		int value,fix,size;
	};

	Treap_Node *root=NULL;

	int size(Treap_Node *&x){
		if (x) return x->size; else return 0;
	}

	void leftRotate(Treap_Node *&aa){
		Treap_Node *bb=aa->right;
		aa->size = aa->size - size(aa->right) + size(bb->left);
		aa->right = bb->left;
		bb->size = bb->size - size(bb->left) + size(aa);
		bb->left = aa;
		aa=bb;
	}

	void rightRotate(Treap_Node *&aa){
		Treap_Node *bb=aa->left;
		aa->size = aa->size - size(aa->left) + size(bb->right);
		aa->left = bb->right;
		bb->size = bb->size - size(bb->right) + size(aa);
		bb->right = aa;
		aa=bb;
	}

	void insertNode(Treap_Node *&now,int value){
		if (!now){
			now=new Treap_Node;
			now->left=now->right=NULL;
			now->value=value;
			now->fix=rand();
			now->size=1;
		} else if (value <= now->value){
			insertNode(now->left,value);
			now->size=size(now->left)+size(now->right)+1;
			if (now->left->fix < now->fix) rightRotate(now);
		} else {
			insertNode(now->right,value);
			now->size=size(now->left)+size(now->right)+1;
			if (now->right->fix < now->fix) leftRotate(now);
		}
	}

	void deleteNode(Treap_Node *&now,int value){
		if (now->value == value){
			if ((!now->left) || (!now->right)){
				Treap_Node *tmp=now;
				if (now->left) now=now->left; else now=now->right;
				delete tmp; tmp=NULL;
			} else {
				if (now->left->fix < now->right->fix){
					rightRotate(now);
					deleteNode(now->right,value);
				} else {
					leftRotate(now);
					deleteNode(now->left,value);
				}
			}
		} else if (now->value > value) deleteNode(now->left,value);
		else deleteNode(now->right,value);
		if (now) now->size=size(now->left)+size(now->right)+1;
	}

	int searchNodeRank(Treap_Node *&now,int value){
		if (!now) return 0;
		if (value > now->value) return size(now->left)+1+searchNodeRank(now->right,value);
		else return searchNodeRank(now->left,value);
	}
	
	int searchKth(Treap_Node *&now,int k){
		Treap_Node *x=now;
		for (;;){
			if ((x->left) && k <= size(x->left)) x=x->left; else
			if ((x->right) && k > size(x->left)+1) k-=size(x->left)+1,x=x->right; else
			return x->value;
		}
	}

	int searchPre(Treap_Node *&now,int value){
		if (!now) return -INF;
		int ret=-INF;
		if (value <= now->value) ret=searchPre(now->left,value); else ret=searchPre(now->right,value);
		if (ret!=-INF && ret>=value) ret=-INF;
		return ((ret!=-INF)?ret:(now->value));
	}

	int searchSuf(Treap_Node *&now,int value){
		if (!now) return INF;
		int ret=INF;
		if (value >= now->value) ret=searchSuf(now->right,value); else ret=searchSuf(now->left,value);
		if (ret!=INF && ret<=value) ret=INF;
		return ((ret!=INF)?ret:(now->value));
	}

	void printTree(Treap_Node *&now){
		printf("Value=%lld, size=%lld. ",now->value,now->size);
		if (now->left) printf("left=%lld ",now->left->value);
		if (now->right) printf("right=%lld ",now->right->value);
		printf("\n");
		if (now->left) printTree(now->left);
		if (now->right) printTree(now->right);
	}
}

int n;

signed main(){
	srand(19260817);
	int opt=-1;
	n=read();
	for (int i=1;i<=n;i++){
		opt=read();int x=read();
		switch(opt){
			case 1:
				Treap::insertNode(Treap::root,x); break;
			case 2:
				Treap::deleteNode(Treap::root,x); break;
			case 3:
				printf("%lld\n",Treap::searchNodeRank(Treap::root,x)+1); break;
			case 4:
				printf("%lld\n",Treap::searchKth(Treap::root,x)); break;
			case 5:
				printf("%lld\n",Treap::searchPre(Treap::root,x)); break;
			case 6:
				printf("%lld\n",Treap::searchSuf(Treap::root,x)); break;
			case 7:
				printf("Excited!!!\n");
				Treap::printTree(Treap::root);
				break;
		}
	}
	return 0;
}
