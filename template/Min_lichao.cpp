struct line{
	lld x,y;
	lld getx(lld v){
		return x*v + y;
	}
};
struct Node{
	int lc,rc;
	lld s,e;
	line v;
};
struct lichao{
	vector<Node> v;
	void init(lld s,lld e){
		v.push_back({-1,-1,s,e,{0,(lld)1e18}});
	}
	void update(line now){
		update(0,now);
	}
	void update(int node,line now){
		line low = v[node].v;
		line high = now;
		lld ll = v[node].s,rr = v[node].e;
		if(low.getx(ll)>high.getx(ll)) swap(low,high);
		if(low.getx(rr)<high.getx(rr)){
			v[node].v = low;
			return;
		}
		lld mid = (ll+rr)/2;
		if(low.getx(mid)<high.getx(mid)){
			v[node].v = low;
			if(v[node].rc==-1){
				v[node].rc = sz(v);
				v.push_back({-1,-1,mid+1,rr,{0,(lld)1e18}});
			}
			update(v[node].rc,high);
		}else{
			v[node].v = high;
			if(v[node].lc==-1){
				v[node].lc = sz(v);
				v.push_back({-1,-1,ll,mid,{0,(lld)1e18}});
			}
			update(v[node].lc,low);
		}
	}
	lld query(lld x){
		return query(0,x);	
	}
	lld query(int node,lld x){
		if(node==-1) return 1e18;
		lld ll = v[node].s,rr = v[node].e;
		lld mid = (ll+rr)/2;
		line now = v[node].v;
		if(x<=mid) return min(query(v[node].lc,x),now.getx(x));
		else return min(query(v[node].rc,x),now.getx(x));
	}
};