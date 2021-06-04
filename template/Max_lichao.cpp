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
		v.push_back({-1,-1,s,e,{0,(lld)-1e18}});
	}
	void update(line now){
		update(0,now);
	}
	void update(int node,line now){
		lld ll = v[node].s,rr = v[node].e;
		line low = now;
		line high = v[node].v;
		if(low.getx(ll)>high.getx(ll)) swap(low,high);
		if(low.getx(rr)<=high.getx(rr)){
			v[node].v = high;
			return;
		}
		lld mid = (ll+rr)/2;
		if(low.getx(mid)<high.getx(mid)){
			v[node].v = high;
			if(v[node].rc==-1){
				v[node].rc = sz(v);
				v.push_back({-1,-1,mid+1,rr,{0,(lld)-1e18}});
			}
			update(v[node].rc,low);
		}else{
			v[node].v = low;
			if(v[node].lc==-1){
				v[node].lc = sz(v);
				v.push_back({-1,-1,ll,mid,{0,(lld)-1e18}});
			}
			update(v[node].lc,high);
		}
	}
	lld query(lld x){
		return query(0,x);
	}
	lld query(int node,lld x){
		if(node==-1) return -1e18;
		lld ll = v[node].s,rr = v[node].e;
		line now = v[node].v;
		lld mid = (ll+rr)/2;
		if(x<=mid) return max(query(v[node].lc,x),now.getx(x));
		else return max(query(v[node].rc,x),now.getx(x));
	}
};