#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int lld;
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


void solve(int tc){
	string x;
	lld m;
	cin >> x >> m;
	if(sz(x)==1&&x[0]-'0'<=m){
		printf("1");
		return;
	}
	int mx = 0;
	for(int e=0;e<sz(x);e++) mx = max(mx,x[e]-'0');
	mx++;
	lld ll = mx,rr = 1e18,mid,ans = mx - 1;
	while(ll<=rr){
		mid = (ll+rr)/2;
		lld vv = 0,xx = 1;
		bool suc = true;
		for(int e=sz(x)-1;e>=0;e--){
			if(xx>m||vv>m){
				suc = false;
				break;
			}
			lld kk = (m/xx);
			if(m%xx) kk++;
			if((lld)(x[e]-'0')>kk){
				suc = false;
				break;
			}
			vv += xx*(x[e]-'0');
			kk = (m/xx);
			if(m%xx) kk++;
			if(mid>kk&&e){
				suc = false;
				break;
			}
			xx *= mid;
		}
		if(vv>m) suc = false;
		if(suc){
			ans = max(ans,mid);
			ll = mid + 1;
		}else rr = mid - 1;
	}
	printf("%llu",ans - mx + 1);
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