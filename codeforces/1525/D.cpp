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


const int MAX = 5050;
int arr[MAX],dp[MAX][MAX],dp2[MAX][MAX];
void solve(int tc){
	int n;
	cin >> n;
	for(int e=0;e<n;e++) cin >> arr[e];
	int ans = 0;
	vector<int> st1,st2;
	for(int e=0;e<n;e++){
		if(arr[e]==1) st1.push_back(e);
		else st2.push_back(e);
	}
	if(sz(st1)==0){
		cout << "0";
		return;
	}
	for(int e=0;e<n;e++){
		for(int p=0;p<n;p++){
			dp[e][p] = dp2[e][p] = 1e9;
		}
	}
	for(int e=0;e<sz(st1);e++){
		for(int p=e;p<sz(st2);p++){
			if(e==0){
				dp[e][p] = abs(st1[e]-st2[p]);
			}else{
				dp[e][p] = abs(st1[e]-st2[p]) + dp2[e-1][p-1];
			}
			if(p) dp2[e][p] = min(dp2[e][p-1],dp[e][p]);
			else dp2[e][p] = dp[e][p];
		}
	}
	cout << dp2[sz(st1)-1][sz(st2)-1];
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