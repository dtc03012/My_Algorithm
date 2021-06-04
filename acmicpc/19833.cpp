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
const lld mod = 1e9 + 7;
int arr[MAX],seg[MAX*4],start = 1;
vector<int> g[MAX];
void upd(int x){
	x += start;
	seg[x] = 1;
	for(int e=(x/2);e>=1;e/=2) seg[e] = seg[e*2] + seg[e*2+1];
}
int getn(int l,int r){
	l += start;
	r += start;
	int ans = 0;
	while(l<=r){
		if(l&1) ans += seg[l++];
		if(!(r&1)) ans += seg[r--];
		l >>= 1;
		r >>= 1;
	}
	return ans;
}
int find(int node,int ns,int ne,int k){
	if(ns+1==ne) return node - start;
	int mid = (ns+ne)/2;
	if(seg[node*2]>=k) return find(node*2,ns,mid,k);
	return find(node*2+1,mid,ne,k-seg[node*2]);
}
lld nC3(lld a){
	lld f1 = a * (a-1) * (a-2);
	lld f2 = 6;
	f1 /= f2;
	f1 %= mod;
	return f1;
}
void solve(int tc){
	while(start<MAX) start *= 2;
	int n;
	cin >> n;
	vector<int> v;
	for(int e=0;e<n;e++) {
		cin >> arr[e];
		v.push_back(arr[e]);
	}
	sort(all(v));
	v.erase(unique(all(v)),v.end());
	for(int e=0;e<n;e++){
		arr[e] = lower_bound(all(v),arr[e]) - v.begin();
		g[arr[e]].push_back(e+1);
	}
	lld ans = 0;
	for(int e=sz(v)-1;e>=0;e--){
		lld lv = 0,f1 = 0,f2 = 0,tot = 0;
		for(int p=0;p<sz(g[e]);p++){
			int x = g[e][p];
			if(p){
				if(getn(g[e][p-1],g[e][p])){
					lv = (lv + tot)%mod;
					f1 = f2 = tot = 0;
				}
			}
			int vv = getn(0,x);
			lld ll = find(1,0,start,vv) + 1,rr = min(n,find(1,0,start,vv+1)-1);
			if(p<sz(g[e])-1) rr = min(rr,1ll*g[e][p+1]-1);
			ll = x - ll + 1;
			rr = rr - x + 1;
			lld k1 = (ll*rr)%mod;
			tot = (tot + k1)%mod;
			ans = (ans + lv*k1)%mod;
			lld xx = (ll*rr*(rr+1))/2;
			xx %= mod;
			if(p==0){
				f1 = k1;
				f2 = xx;
			}
			else{
				ans = (ans + f2*rr)%mod;
				f2 = (f2 + f1 * rr + xx)%mod;
				f1 = (f1 + k1)%mod;
			}
		}
		for(int p=0;p<sz(g[e]);p++) upd(g[e][p]);
	}
	cout << ans << "\n";
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