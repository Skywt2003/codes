void Ins(int l,int r,int&o,int las,int v)
{
	o=++tot;++num[o];
	if(v>mid)
		Ins(mid+1,r,rc[o],rc[las],v),lc[o]=lc[las];
	else
		Ins(l,mid,lc[o],lc[las],v),rc[o]=rc[las];
}
for(int i=1;i<=n;++i)
	Ins(1,n,rt[i],rt[i-1],a[i]);
slove(l,r)
rt[r] rt[l-1];

Que(int l,int r,int now_l,int now_r){
	num[now_l]-num[now_r];
}