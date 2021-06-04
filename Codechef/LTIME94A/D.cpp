#include <bits/stdc++.h>
using namespace std;
typedef long long int lld;
typedef pair<int,int> pi;
typedef pair<lld,lld> pl;
typedef pair<int,lld> pil;
typedef pair<lld,int> pli;
typedef vector<int> vit;
typedef vector<vit> vitt;
typedef vector<lld> vlt;
typedef vector<vlt> vltt;
typedef vector<pi> vpit;
typedef vector<vpit> vpitt;
typedef long double ld;
#define x first
#define y second
#define pb push_back
#define all(v) v.begin(), v.end()
#define sz(x) (int)x.size()
#define mk(a,b) make_pair(a,b)
bool isrange(int y,int x,int n,int m){
	 if(0<=y&&y<n&&0<=x&&x<m) return true;
	 return false;
}
int dy[4] = {1,0,-1,0},dx[4]={0,1,0,-1},ddy[8] = {1,0,-1,0,1,1,-1,-1},ddx[8] = {0,1,0,-1,1,-1,1,-1};

const int MAX = 101010;
vector<lld> v;
pl arr[MAX];
lld val[MAX];
int get_idx(lld x){
	return lower_bound(all(v),x) - v.begin();
}
struct lazySeg{
	lld lazy[MAX*2*4],arr[MAX*2*4];
	int start = 1;
	lazySeg(){
		while(start<MAX*2) start *= 2;
	}
	void propagate(int node){
		if(lazy[node]){
			if(node<start){
				lazy[node*2] += lazy[node];
				lazy[node*2+1] += lazy[node];
			}
			arr[node] += lazy[node];
			lazy[node] = 0;
		}
	}
	void add(int l,int r,lld k){
		add(1,0,start,l,r,k);
	}
	void add(int node,int ns,int ne,int l,int r,lld k){
		propagate(node);
		if(ne<=l||r<=ns) return;
		if(ns>=l&&ne<=r){
			lazy[node] += k;
			propagate(node);
			return;
		}
		int mid = (ns+ne)/2;
		add(node*2,ns,mid,l,r,k);
		add(node*2+1,mid,ne,l,r,k);
		arr[node] = max(arr[node*2],arr[node*2+1]);
	}
	lld sum(int l,int r){
		return sum(1,0,start,l,r);
	}
	lld sum(int node,int ns,int ne,int l,int r){
		propagate(node);
		if(ne<=l||r<=ns) return 0;
		if(ns>=l&&ne<=r) return arr[node];
		int mid = (ns+ne)/2;
		return max(sum(node*2,ns,mid,l,r),sum(node*2+1,mid,ne,l,r));
	}
};
lazySeg seg;
vector<pil> vv[MAX*2];
void solve(int tc){
	int n;
	lld k;
	scanf("%d%lld",&n,&k);
	for(int e=1;e<=n;e++){
		scanf("%lld%lld%lld",&arr[e].x,&arr[e].y,&val[e]);
		v.push_back(arr[e].x);
		v.push_back(arr[e].y);
	}
	sort(all(v));
	v.erase(unique(all(v)),v.end());
	for(int e=1;e<=n;e++){
		arr[e].x = get_idx(arr[e].x);
		arr[e].y = get_idx(arr[e].y);
		vv[arr[e].x].push_back(mk(arr[e].y,val[e]));
	}
	for(int e=1;e<sz(v);e++){
		lld diff = k*(v[e]-v[0]);
		seg.add(e,e+1,-diff);
	}
	for(int e=1;e<=n;e++) seg.add(arr[e].y,sz(v),val[e]);
	lld ans = 0;
	ans = max(ans,seg.sum(0,sz(v)));
	for(int e=1;e<sz(v);e++){
		for(int p=0;p<sz(vv[e-1]);p++){
			int rr = vv[e-1][p].x;
			lld kk = vv[e-1][p].y;
			seg.add(rr,sz(v),-kk);
		}
		lld diff = k*(v[e] - v[e-1]);
		seg.add(e,sz(v),diff);
		ans = max(ans,seg.sum(e,sz(v)));
	}
	printf("%lld\n",ans);
}


int main(void){
	/*
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	*/
	int tc = 1;
	/*
		cin >> tc;
	*/
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}