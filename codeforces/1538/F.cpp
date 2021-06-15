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


void solve(int tc){
	lld x,y,a,b;
	cin >> x >> y >> a >> b;
	if(b>a) swap(a,b);
	if(a==b){
		cout << lld(min(x,y)/a) << "\n";
		return;
	}
	lld ll = 0,rr = 1e9,mid,ans = 0;
	while(ll<=rr){
		mid = (ll+rr)/2;
		lld lx = (a*mid - y) / (a - b);
		if(((a*mid - y)%(a - b))&&(a*mid - y)>=0) lx++;
		lld rx = (x - b*mid) / (a - b);
		if(rx>=lx&&(x-b*mid)>=0ll&&lx<=mid){
			ans = max(ans,mid);
			ll = mid + 1;
		}else rr = mid - 1;
	}
	cout << ans << "\n";
}


int main(void){
	
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int tc = 1;
	
		cin >> tc;
	
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}