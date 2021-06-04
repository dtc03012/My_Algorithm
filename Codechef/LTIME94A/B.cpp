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
int seg[MAX*4],start = 1,arr[MAX],ans[MAX];
void upd(int x){
	x += start;
	seg[x]++;
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
vector<int> go[MAX];
void solve(int tc){
	while(start<MAX) start *= 2;
	memset(seg,0,sizeof(seg));
	int n;
	scanf("%d",&n);
	vector<int> v;
	for(int e=0;e<=n;e++){
		go[e].clear();
		ans[e] = 0;
	}
	for(int e=1;e<=n;e++){
		scanf("%d",&arr[e]);
		v.push_back(arr[e]);
	}
	sort(all(v));
	v.erase(unique(all(v)),v.end());
	for(int e=1;e<=n;e++){
		arr[e] = lower_bound(all(v),arr[e]) - v.begin();
		go[arr[e]].push_back(e);
	}
	for(int e=n;e>=0;e--){
		if(sz(go[e])==0) continue;
		int ll = go[e][0],tot = 1,lst = 0;
		for(int p=1;p<sz(go[e]);p++){
			int now = go[e][p];
			if(getn(ll,now)==0) tot++;
			else{
				for(int q=lst;q<p;q++){
					ans[go[e][q]] = tot - 1;
				}
				ll = go[e][p];
				tot = 1;
				lst = p;
			}
		}
		for(int q=lst;q<sz(go[e]);q++){
			ans[go[e][q]] = tot - 1;
		}
		for(int p=0;p<sz(go[e]);p++) upd(go[e][p]);
	}
	for(int e=1;e<=n;e++) printf("%d ",ans[e]);
	printf("\n");
}


int main(void){
	
	// ios_base :: sync_with_stdio(false);
	// cin.tie(NULL);
	// cout.tie(NULL);
	
	int tc = 1;
	
		cin >> tc;
	
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}