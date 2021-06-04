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

const int MAX = (1<<20);
int cnt[MAX],dp[MAX];
void solve(int tc){
	int n,q;
	cin >> n >> q;
	for(int e=0;e<n;e++){
		int r;
		cin >> r;
		cnt[r]++;
	}
	for(int e=0;e<MAX;e++){
		cnt[e] = min(cnt[e],1);
		if(e) dp[e] = dp[e-1];
		dp[e] += cnt[e];
	}
	int rt = 0;
	for(int e=0;e<q;e++){
		int x;
		cin >> x;
		rt ^= x;
		int tot = 0;
		for(int p=20;p>=0;){
			if(cnt[tot^rt]==0) break;
			int xx = (rt/(1<<p))*(1<<p);
			int ll = (tot^xx),rr = (tot^xx) + (1<<p) - 1;
			int vv = dp[rr];
			if(ll) vv -= dp[ll-1];
			if(vv==(rr-ll+1)) tot ^= (1<<p);
			else p--;
		}
		cout << tot << "\n";
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