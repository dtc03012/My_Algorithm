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
vector<int> v[MAX];
int par[MAX],cnt,start = 1,cnt2;
lld seg1[MAX*2*4],seg2[MAX*2*4];
pi len[MAX],len2[MAX];
lld sta[MAX][22],sz[MAX],dep[MAX][22];
void add(lld* seg,int x,lld v){
	x += start;
	seg[x] += v;
	for(int e=(x/2);e>=1;e/=2) seg[e] = seg[e*2] + seg[e*2+1];
}
lld getn(lld* seg,int l,int r){
	l += start;
	r += start;
	lld ans = 0;
	while(l<=r){
		if(l&1) ans += seg[l++];
		if(!(r&1)) ans += seg[r--];
		l >>= 1;
		r >>= 1;
	}
	return ans;
}
int dfs(int x){
	sz[x] = 1;
	dep[x][0] = 1;
	len[x].x = cnt++;
	len2[x].x = cnt2;
	for(int e=0;e<sz(v[x]);e++){
		int nx = v[x][e];
		sz[x] += dfs(nx);
		for(int p=0;p<21;p++) dep[x][p+1] += dep[nx][p];
	}
	len[x].y = cnt++;
	len2[x].y = cnt2++;
	return sz[x];
}
main()
{
	while(start<MAX*2) start *= 2;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,q;
	cin >> n >> q;
	par[1] = -1;
	for(int e=2;e<=n;e++){
		int x;
		cin >> x;
		v[x].push_back(e);
		par[e] = x;
	}
	dfs(1);
	for(int e=0;e<q;e++){
		int ty;
		cin >> ty;
		if(ty==1){
			int x,val,k;
			cin >> x >> val >> k;
			lld xx = 0;
			if(k==1){
				add(seg1,len[x].x,val);
				add(seg1,len[x].y,-val);
				xx += sz[x] * val;
			}else{
				int rval = val;
				for(int p=0;p<22;p++){
					sta[x][p] += rval;
					rval /= k;
				}
				rval = val;
				for(int p=0;p<22;p++){
					xx += dep[x][p] * rval;
					rval /= k;
				}
			}
			add(seg2,len2[x].y,xx);
		}else{
			int x;
			cin >> x;
			lld ans = getn(seg1,0,len[x].x-1)*sz[x];
			ans += getn(seg2,len2[x].x,len2[x].y);
			int xx = par[x];
			for(int p=1;p<22;p++){
				if(xx==-1) break;
				for(int q=0;q<22;q++){
					if(p+q>=22) break;
					ans += sta[xx][p+q]*dep[x][q];
				}
				xx = par[xx];
			}
			cout << ans << "\n";
		}
	}
}