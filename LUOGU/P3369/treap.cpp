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

	void left_rotate(Treap_Node *&aa){
		Treap_Node *bb=aa->right;
		aa->size = aa->size - size(aa->right) + size(bb->left);
		aa->right = bb->left;
		bb->size = bb->size - size(bb->left) + size(aa);
		bb->left = aa;
		aa=bb;
	}

	void right_rotate(Treap_Node *&aa){
		Treap_Node *bb=aa->left;
		aa->size = aa->size - size(aa->left) + size(bb->right);
		aa->left = bb->right;
		bb->size = bb->size - size(bb->right) + size(aa);
		bb->right = aa;
		aa=bb;
	}

	void insert_node(Treap_Node *&now,int value){
		if (!now){
			now=new Treap_Node;
			now->left=now->right=NULL;
			now->value=value;
			now->fix=rand();
			now->size=1;
		} else if (value <= now->value){
			insert_node(now->left,value);
			now->size=size(now->left)+size(now->right)+1;
			if (now->left->fix < now->fix) right_rotate(now);
		} else {
			insert_node(now->right,value);
			now->size=size(now->left)+size(now->right)+1;
			if (now->right->fix < now->fix) left_rotate(now);
		}
	}

	void delete_node(Treap_Node *&now,int value){
		if (now->value == value){
			if ((!now->left) || (!now->right)){
				Treap_Node *tmp=now;
				if (now->left) now=now->left; else now=now->right;
				delete tmp; tmp=NULL;
			} else {
				if (now->left->fix < now->right->fix){
					right_rotate(now);
					delete_node(now->right,value);
				} else {
					left_rotate(now);
					delete_node(now->left,value);
				}
			}
		} else if (now->value > value) delete_node(now->left,value);
		else delete_node(now->right,value);
		if (now) now->size=size(now->left)+size(now->right)+1;
	}

	int search_node_rank(Treap_Node *&now,int value){
		if (!now) return 0;
		if (value > now->value) return size(now->left)+1+search_node_rank(now->right,value);
		else return search_node_rank(now->left,value);
	}
	
	int search_kth(Treap_Node *&now,int k){
		Treap_Node *x=now;
		for (;;){
			if ((x->left) && k <= size(x->left)) x=x->left; else
			if ((x->right) && k > size(x->left)+1) k-=size(x->left)+1,x=x->right; else
			return x->value;
		}
	}

	int search_pre(Treap_Node *&now,int value){
		if (!now) return -INF;
		int ret=-INF;
		if (value <= now->value) ret=search_pre(now->left,value); else ret=search_pre(now->right,value);
		if (ret!=-INF && ret>=value) ret=-INF;
		return ((ret!=-INF)?ret:(now->value));
	}

	int search_suf(Treap_Node *&now,int value){
		if (!now) return INF;
		int ret=INF;
		if (value >= now->value) ret=search_suf(now->right,value); else ret=search_suf(now->left,value);
		if (ret!=INF && ret<=value) ret=INF;
		return ((ret!=INF)?ret:(now->value));
	}

	void print_tree(Treap_Node *&now){
		printf("Value=%lld, size=%lld. ",now->value,now->size);
		if (now->left) printf("left=%lld ",now->left->value);
		if (now->right) printf("right=%lld ",now->right->value);
		printf("\n");
		if (now->left) print_tree(now->left);
		if (now->right) print_tree(now->right);
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
				Treap::insert_node(Treap::root,x); break;
			case 2:
				Treap::delete_node(Treap::root,x); break;
			case 3:
				printf("%lld\n",Treap::search_node_rank(Treap::root,x)+1); break;
			case 4:
				printf("%lld\n",Treap::search_kth(Treap::root,x)); break;
			case 5:
				printf("%lld\n",Treap::search_pre(Treap::root,x)); break;
			case 6:
				printf("%lld\n",Treap::search_suf(Treap::root,x)); break;
			case 7:
				printf("Excited!!!\n");
				Treap::print_tree(Treap::root);
				break;
		}
	}
	return 0;
}