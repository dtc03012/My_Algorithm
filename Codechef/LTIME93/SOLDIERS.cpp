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

const int MAX = 202020;
struct lazySeg{
	int seg[MAX*4][2],lazy[MAX*4][2],start = 1;
	lazySeg(){

	}
	void init(int n){
		start = 1;
		while(start<=n) start *= 2;
		for(int e=0;e<start*2;e++){
			seg[e][0] = 1e9;
			seg[e][1] = -1e9;
			lazy[e][0] = 1e9;
			lazy[e][1] = -1e9;
		}
	}
	void propagate(int node){
		if(node<start){
			lazy[node*2][0] = min(lazy[node*2][0],lazy[node][0]);
			lazy[node*2+1][0] = min(lazy[node*2+1][0],lazy[node][0]);
			lazy[node*2][1] = max(lazy[node*2][1],lazy[node][1]);
			lazy[node*2+1][1] = max(lazy[node*2+1][1],lazy[node][1]);
		}
		seg[node][0] = min(seg[node][0],lazy[node][0]);
		seg[node][1] = max(seg[node][1],lazy[node][1]);
		lazy[node][0] = 1e9;
		lazy[node][1] = -1e9;
	}
	void add(int l,int r,int x){
		add(1,0,start,l,r,x);
	}
	void add(int node,int ns,int ne,int l,int r,int x){
		propagate(node);
		if(ne<=l||r<=ns) return;
		if(ns>=l&&ne<=r){
			lazy[node][0] = x;
			lazy[node][1] = x;
			propagate(node);
			return;
		}
		int mid = (ns+ne)/2;
		add(node*2,ns,mid,l,r,x);
		add(node*2+1,mid,ne,l,r,x);
		seg[node][0] = min(seg[node*2][0],seg[node*2+1][0]);
		seg[node][1] = max(seg[node*2][1],seg[node*2+1][1]);
	}
	pi sum(int l,int r){
		return sum(1,0,start,l,r);
	}
	pi sum(int node,int ns,int ne,int l,int r){
		propagate(node);
		if(ne<=l||r<=ns) return mk(1e9,-1e9);
		if(ns>=l&&ne<=r) return mk(seg[node][0],seg[node][1]);
		int mid = (ns+ne)/2;
		pi f1 = sum(node*2,ns,mid,l,r);
		pi f2 = sum(node*2+1,mid,ne,l,r);
		return mk(min(f1.x,f2.x),max(f1.y,f2.y));
	}
};
bool tmr(pi a,pi b){
	if(a.x!=b.x) return a.x < b.x;
	return a.y < b.y;
}
lazySeg seg;
map<pi,vector<int> > mv;
int ans[MAX];
void solve(int tc){
	int t,pp;
	scanf("%d%d",&t,&pp);
	while(t--){
		mv.clear();
		int n,m;
		scanf("%d%d",&n,&m);
		seg.init(n);
		vector<pi> v;
		for(int e=0;e<m;e++){
			int x,y;
			scanf("%d%d",&x,&y);
			v.push_back(mk(x,y));
		}
		if(pp==0){
			sort(all(v),tmr);
			for(int e=0;e<sz(v);e++){
				int l = v[e].x,r = v[e].y;
				seg.add(l,r+1,e);
			}
			for(int e=1;e<=n;e++){
				pi xx = seg.sum(e,e+1);
				if(xx.x==1e9){
					ans[e] = 1;
				}else{
					mv[xx].push_back(e);
				}
			}
			for(auto x : mv){
				vector<int> vv = x.y;
				for(int p=0;p<sz(vv);p++) ans[vv[p]] = vv[p];
			}
			for(int e=1;e<=n;e++) printf("%d ",ans[e]);
			printf("\n");
		}else{
			sort(all(v),tmr);
			for(int p=0;p<sz(v);p++){
				int l = v[p].x,r = v[p].y;
				seg.add(l,r+1,p);
			}
			for(int p=1;p<=n;p++){
				pi xx = seg.sum(p,p+1);
				if(xx.x==1e9){
					ans[p] = n;
				}else{
					mv[mk(xx.x,-1)].push_back(p);
				}
			}
			for(auto x : mv){
				vector<int> vv = x.y;
				for(int p=0;p<sz(vv);p++) ans[vv[p]] = vv[sz(vv)-p-1];
			}
			for(int e=1;e<=n;e++) printf("%d ",ans[e]);
			printf("\n");
		}
	}
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