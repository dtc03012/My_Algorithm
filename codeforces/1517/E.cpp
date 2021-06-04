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
const lld mod = 998244353;
lld arr[MAX];
void solve(int tc){
	int n;
	cin >> n;
	lld tot = 0;
	for(int e=1;e<=n;e++){
		cin >> arr[e];
		tot += arr[e];
	}
	lld ans = 1,left = 0;
	for(int e=1;e<=n;e++){
		left += arr[e];
		if(left<tot-left) ans++;
		lld vv = left;
		for(int q=e+2;q<=n;q+=2){
			vv += arr[q];
			if(vv<tot-vv) ans++;
			if(n-q>2){
				if(vv+arr[n]<tot-(vv+arr[n])) ans++;
			}
		}
		if(n-e>2){
			if(left+arr[n]<tot-(left+arr[n])) ans++;
		}
	}
	if(n>=2){
		lld left = 0;
		for(int e=2;e<=n;e++){
			left += arr[e];
			if(left<tot-left) ans++;
			lld vv = left;
			for(int q=e+2;q<=n;q+=2){
				vv += arr[q];
				if(vv<tot-vv) ans++;
				if(n-q>2){
					if(vv+arr[n]<tot-(vv+arr[n])) ans++;
				}
			}
			if(n-e>2){
				if(left+arr[n]<tot-(left+arr[n])){
					ans++;
				}
			}
		}
	}
	lld vv = arr[1];
	for(int p=2;p<n;p++){
		vv += arr[p];
		{
			if(vv>tot-vv) ans++;
		}
	}
	cout << ans%mod << "\n";
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