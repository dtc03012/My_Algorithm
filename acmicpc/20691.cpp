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
int arr[MAX];
vector<int> que[MAX],v;
int getn(int x){
	return lower_bound(all(v),x) - v.begin();
}
int seg1[MAX*3*4],start = 1,seg2[MAX*3*4];
void upd(int *seg,int x,int v){
	x += start;
	seg[x] += v;
	for(int e=(x/2);e>=1;e/=2) seg[e] = seg[e*2] + seg[e*2+1];
}
int getn(int *seg,int l,int r){
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
main()
{
	while(start<MAX*3) start *= 2;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin >> n >> m;
	for(int e=1;e<=n;e++){
		cin >> arr[e];
		v.push_back(arr[e]);
	}
	for(int e=0;e<m;e++){
		int k;
		cin >> k;
		for(int p=0;p<k;p++){
			int r;
			cin >> r;
			que[e].push_back(r);
			v.push_back(r);
		}
	}
	sort(all(v));
	v.erase(unique(all(v)),v.end());
	lld res1 = 0;
	for(int e=1;e<=n;e++){
		arr[e] = getn(arr[e]);
		res1 += getn(seg1,arr[e]+1,sz(v));
		upd(seg1,arr[e],1);
	}
	for(int e=0;e<m;e++){
		lld res2 = res1;
		for(int p=0;p<sz(que[e]);p++){
			que[e][p] = getn(que[e][p]);
			res2 += getn(seg2,que[e][p]+1,sz(v));
			upd(seg2,que[e][p],1);
		}
		lld ans = 1e18;
		int len = sz(que[e]);
		vector<lld> dp(len+1,0);
		lld vv = 0;
		for(int p=0;p<len;p++){
			vv += getn(seg1,0,que[e][p]-1);
			dp[p+1] += vv;
		}
		vv = 0;
		for(int p=len-1;p>=0;p--){
			vv += getn(seg1,que[e][p]+1,sz(v));
			dp[p] += vv;
		}
		for(int e=0;e<=len;e++) ans = min(ans,res2+dp[e]);
		cout << ans << "\n";
		for(int p=0;p<sz(que[e]);p++){
			upd(seg2,que[e][p],-1);
		}
	}
}