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
string arr[MAX];
int dp[MAX][MAX];
void solve(int tc){
	int n,m;
	cin >> n >> m;
	for(int e=0;e<n;e++) cin >> arr[e];
	for(int e=n-1;e>=0;e--){
		for(int p=m-1;p>=0;p--){
			if(e==n-1&&p==m-1) continue;
			dp[e][p] = -1e9;
			if(e+1<n){
				int xx = 1;
				if(arr[e+1][p]=='-') xx = -1;
				dp[e][p] = max(dp[e][p],-dp[e+1][p]+xx);
			}
			if(p+1<m){
				int xx = 1;
				if(arr[e][p+1]=='-') xx = -1;
				dp[e][p] = max(dp[e][p],-dp[e][p+1]+xx);
			}
		}
	}
	if(dp[0][0]==0) cout << "Draw";
	else if(dp[0][0]>0) cout << "Takahashi";
	else cout << "Aoki";
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