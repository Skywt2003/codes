// XJOI CONTEST 1265 T1

class PST{
	#define mid (((tr-tl)>>1)+tl)

	private:
		int ls[maxn],rs[maxn];
		int pre[maxn],suf[maxn],sum[maxn];
		int tot;

	public:
		int root[maxn];

		PST(){
			tot=0;
			memset(root,0,sizeof(root));
		}

		void build(int tl,int tr,int &p,int init_value){
			p=++tot;
			if (tl==tr){
				sum[p]=pre[p]=suf[p] = init_value;
				#ifdef EBUG
					printf("p=%lld init_value=%lld\n",p,init_value);
				#endif
				return;
			}
			build(tl,mid,ls[p],init_value);
			build(mid+1,tr,rs[p],init_value);
			sum[p]=sum[ls[p]]+sum[rs[p]];
			pre[p]=max(pre[ls[p]],sum[ls[p]]+pre[rs[p]]);
			suf[p]=max(suf[rs[p]],suf[ls[p]]+sum[rs[p]]);
			#ifdef EBUG
				printf("sum[%lld] = %lld\n",p,sum[p]);
			#endif
		}

		void update(int tl,int tr,int &p,int lastp,int x,int delta){
			p=++tot;
			ls[p]=ls[lastp];
			rs[p]=rs[lastp];
			if (tl==tr){
				sum[p]=pre[p]=suf[p] = sum[lastp]+((tl==x)?delta:0);
				return;
			}
			if (x<=mid  ) update(tl,mid,ls[p],ls[lastp],x,delta);
			if (mid+1<=x) update(mid+1,tr,rs[p],rs[lastp],x,delta);
			sum[p]=sum[ls[p]]+sum[rs[p]];
			pre[p]=max(pre[ls[p]],sum[ls[p]]+pre[rs[p]]);
			suf[p]=max(suf[rs[p]],suf[ls[p]]+sum[rs[p]]);
		}

		int query_sum(int sl,int sr,int tl,int tr,int p){
			if (sl<=tl && tr<=sr) return sum[p];
			int ret=0;
			if (sl<=mid  ) ret+=query_sum(sl,sr,tl,mid,ls[p]);
			if (mid+1<=sr) ret+=query_sum(sl,sr,mid+1,tr,rs[p]);
			return ret;
		}

		int query_pre(int sl,int sr,int tl,int tr,int p){
			if (sl<=tl && tr<=sr) return pre[p];
			if (sl<=mid && mid+1<=sr){
				int sum1=query_sum(sl,sr,tl,mid,ls[p]);
				int pre1=query_pre(sl,sr,tl,mid,ls[p]);
				int pre2=query_pre(sl,sr,mid+1,tr,rs[p]);
				return max(sum1+pre2,pre1);
			} else if (sl<=mid) return query_pre(sl,sr,tl,mid,ls[p]);
			else if (mid+1<=sr) return query_pre(sl,sr,mid+1,tr,rs[p]);
		}

		int query_suf(int sl,int sr,int tl,int tr,int p){
			if (sl<=tl && tr<=sr) return suf[p];
			if (sl<=mid && mid+1<=sr){
				int suf1=query_suf(sl,sr,tl,mid,ls[p]);
				int suf2=query_suf(sl,sr,mid+1,tr,rs[p]);
				int sum2=query_sum(sl,sr,mid+1,tr,rs[p]);
				return max(suf1+sum2,suf2);
			} else if (sl<=mid) return query_suf(sl,sr,tl,mid,ls[p]);
			else if (mid+1<=sr) return query_suf(sl,sr,mid+1,tr,rs[p]);
		}

	#undef mid
};