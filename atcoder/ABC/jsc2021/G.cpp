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

const int MAX = 505050;
int dp[MAX][26],vis[MAX];
int k;
string s;
void dfs(int wh,int l,int r,int x){
	// cout << wh << " " << k << endl;
	if(wh==k){
		vis[l+x] = 1;
		vis[r-x] = 1;
		dp[x][s[l+x]-'a']++;
		if(l+x!=(r-x))dp[x][s[r-x]-'a']++;
		return;
	}else{
		if((r-l+1)%2){
			int mid = (r-l+1)/2;
			dfs(wh+1,l,l+mid-1,x);
			dfs(wh+1,l+mid+1,r,x);
		}else{
			int mid = (r-l+1)/2;
			dfs(wh+1,l,l+mid-1,x);
			dfs(wh+1,l+mid,r,x);
		}
	}
}
void solve(int tc){
	cin >> k;
	cin >> s;
	int nn = 0;
	int nk = sz(s);
	while(true){
		if(nk==0){
			cout << "impossible" << "\n";
			return;
		}
		nn++;
		nk/=2;
		if(k==nn) break;
	}
	cout << k << endl;
	int ans = 0;
	for(int p=0;p<sz(s);p++){
		if(vis[p]==0){
			dfs(1,0,sz(s)-1,p);
			int tot = 0,mx = 0;
			for(int q=0;q<26;q++){
				tot += dp[p][q];
				mx = max(mx,dp[p][q]);
			}
			ans += tot - mx;
		}
	}
	cout << ans << '\n';
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