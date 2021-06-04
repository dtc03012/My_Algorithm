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
lld arr[MAX];
struct lazySeg{
	lld arr[MAX*4],lazy[MAX*4],start = 1;
	lazySeg(){
		while(start<MAX) start *= 2;
		memset(arr,0,sizeof(arr));
		memset(lazy,0,sizeof(lazy));
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
	void add(int l,int r,int k){
		add(1,0,start,l,r,k);
	}
	void add(int node,int ns,int ne,int l,int r,int k){
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
		arr[node] = min(arr[node*2],arr[node*2+1]);
	}
	lld sum(int l,int r){
		return sum(1,0,start,l,r);
	}
	lld sum(int node,int ns,int ne,int l,int r){
		propagate(node);
		if(ne<=l||r<=ns) return 1e9;
		if(ns>=l&&ne<=r) return arr[node];
		int mid = (ns+ne)/2;
		return min(sum(node*2,ns,mid,l,r),sum(node*2+1,mid,ne,l,r));
	}
};
void solve(int tc){
	lazySeg seg;
	int n;
	cin >> n;
	lld tot = 0,ans = 0;	
	for(int e=0;e<n;e++){
		cin >> arr[e];
		if(arr[e]>=0){
			seg.add(e,n,arr[e]);
			ans++;
		}
	}
	vector<pair<lld,int> > v;
	lld res = 0;
	for(int e=n-1;e>=0;e--){
		if(arr[e]<0){
			v.push_back(mk(-arr[e],e));
		}
	}
	sort(all(v));
	for(int e=0;e<sz(v);e++){
		seg.add(v[e].y,n,arr[v[e].y]);
		if(seg.sum(0,n)<0){
			seg.add(v[e].y,n,-arr[v[e].y]);
			continue;
		}
		ans++;
	}
	cout << ans;
}


int main(void){
	
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int tc = 1;
	/*
		cin >> tc;
	*/
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}