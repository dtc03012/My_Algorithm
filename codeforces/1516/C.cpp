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

const int MAX = 2020;
int cnt[MAX],dp[MAX*100];
vector<pi> v;
bool can(int tot){
	memset(dp,0,sizeof(dp));
	dp[0] = 1;
	for(int e=0;e<sz(v);e++){
		for(int p=MAX*100-1;p>=v[e].x;p--){
			dp[p] += dp[p-v[e].x];
		}
	}
	if(tot%2) return false;
	if(dp[tot/2]==0) return false;
	return true;
}
void solve(int tc){
	int n;
	cin >> n;
	int tot = 0;
	for(int e=1;e<=n;e++){
		int r;
		cin >> r;
		v.push_back(mk(r,e));
		tot += r;
	}
	if(!can(tot)){
		cout << "0\n";
		return;
	}
	vector<int> ans;
	while(tot%2==0){
		bool flag = false;
		for(int p=0;p<sz(v);p++){
			if(v[p].x%2){
				ans.push_back(v[p].y);
				flag = true;
				break;
			}
		}
		if(flag) break;
		tot /= 2;
		for(int p=0;p<sz(v);p++) v[p].x /= 2;
	}
	cout << sz(ans) << "\n";
	for(int e=0;e<sz(ans);e++) cout << ans[e] << " ";
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