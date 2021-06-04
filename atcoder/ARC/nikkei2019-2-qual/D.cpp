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
vector<pi> v[MAX];
struct lazySeg{
	lld lazy[MAX*4],arr[MAX*4];
	int start = 1;
	lazySeg(){
		while(start<MAX) start *= 2;
		for(int e=0;e<MAX*4;e++){
			arr[e] = 1e18;
			lazy[e] = 1e18;
		}
	}
	void propagate(int node){
		if(lazy[node]!=1e18){
			if(node<start){
				lazy[node*2] = min(lazy[node*2],lazy[node]);
				lazy[node*2+1] = min(lazy[node*2+1],lazy[node]);
			}
			arr[node] = min(arr[node],lazy[node]);
			lazy[node] = 1e18;
		}
	}
	void add(int l,int r,lld x){
		add(1,0,start,l,r,x);
	}
	void add(int node,int ns,int ne,int l,int r,lld x){
		propagate(node);
		if(ne<=l||r<=ns) return;
		if(ns>=l&&ne<=r){
			lazy[node] = min(lazy[node],(lld)x);
			propagate(node);
			return;
		}
		int mid = (ns+ne)/2;
		add(node*2,ns,mid,l,r,x);
		add(node*2+1,mid,ne,l,r,x);
		arr[node] = min(arr[node*2],arr[node*2+1]);
	}
	lld sum(int l,int r){
		return sum(1,0,start,l,r);
	}
	lld sum(int node,int ns,int ne,int l,int r){
		propagate(node);
		if(ne<=l||r<=ns) return (lld)1e18;
		if(ns>=l&&ne<=r) return arr[node];
		int mid = (ns+ne)/2;
		return min(sum(node*2,ns,mid,l,r),sum(node*2+1,mid,ne,l,r));
	}
};
lazySeg seg;
void solve(int tc){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int e=0;e<m;e++){
		int l,r,c;
		scanf("%d%d%d",&l,&r,&c);
		v[r].push_back(mk(l,c));
	}
	seg.add(n,n+1,0);
	for(int e=n;e>=1;e--){
		lld xx = seg.sum(e,e+1);
		for(int p=0;p<sz(v[e]);p++){
			int nx = v[e][p].x;
			lld nxx = xx + v[e][p].y;
			seg.add(nx,e,nxx);
		}
	}
	lld ans = seg.sum(1,2);
	if(ans==1e18) ans = -1;
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
		scanf("%d",&tc);
	*/
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}