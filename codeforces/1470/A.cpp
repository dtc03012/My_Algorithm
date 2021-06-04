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
const int MAX = 303030;
int n,m;
lld arr[MAX],g[MAX];
void solve(){
	scanf("%d%d",&n,&m);
	for(int e=1;e<=n;e++) scanf("%lld",&arr[e]);
	for(int e=1;e<=m;e++) scanf("%lld",&g[e]);
	sort(arr+1,arr+n+1);
	lld ans = 0;
	for(int e=1;e<=n;e++) ans += g[arr[e]];
	for(int e=1,p=n;e<=m,p>=1;e++,p--){
		if(e>arr[p]) break;
		ans -= g[arr[p]];
		ans += g[e];
	}
	cout << ans << "\n";
}
int main(void){
	int tc;
	scanf("%d",&tc);
	while(tc--){
		solve();
	}
	return 0;
}