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
int go[MAX],arr[MAX],dp[MAX][20],can[MAX],rx[MAX];
vector<int> v[MAX];
map<int,int> mm;
void solve(int tc){
	memset(dp,-1,sizeof(dp));
	for(int e=2;e<MAX;e++){
		if(can[e]==0){
			for(int p=e;p<MAX;p+=e){
				v[p].push_back(e);
				can[p] = 1;
			}
		}
	}
	int n,q;
	cin >> n >> q;
	for(int e=1;e<=n;e++){
		cin >> arr[e];
		int rrx = 0;
		for(int p=0;p<sz(v[arr[e]]);p++){
			int nx = v[arr[e]][p];
			rrx = max(rrx,rx[nx]);
		}
		go[e] = max(go[e-1],rrx + 1);
		for(int p=0;p<sz(v[arr[e]]);p++){
			int nx = v[arr[e]][p];
			rx[nx] = e;
		}
		dp[e][0] = go[e];
	}
	for(int e=1;e<20;e++){
		for(int p=n;p>=1;p--){
			if(dp[p][e-1]!=-1){
				dp[p][e] = dp[dp[p][e-1]-1][e-1];
			}
		}
	}
	for(int e=0;e<q;e++){
		int l,r;
		cin >> l >> r;
		int num = 0;
		for(int p=19;p>=0;p--){
			if(dp[r][p]>l){
				num += (1<<p);
				r = dp[r][p] - 1;
			}
		}
		num++;
		cout << num << "\n";
	}
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