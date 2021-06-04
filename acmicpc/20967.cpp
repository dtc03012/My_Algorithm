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

const int NMAX = 101010;
const int MAX = 20;
int arr[NMAX],go[MAX][MAX],dp[MAX][(1<<MAX)],dp2[(1<<MAX)];
void solve(int tc){
	string s;
	cin >> s;
	vector<int> v;
	for(int e=0;e<sz(s);e++) v.push_back(s[e]-'a');
	sort(all(v));
	v.erase(unique(all(v)),v.end());
	for(int e=1;e<=sz(s);e++) arr[e] = lower_bound(all(v),s[e-1]-'a') - v.begin();
	int len = sz(v);
	for(int e=2;e<=sz(s);e++) go[arr[e-1]][arr[e]]++;
	for(int e=0;e<len;e++){
		int xx = 0,kk = 2;
		for(int p=1;p<(1<<len);p++){
			if(p==kk){
				xx++;
				kk *= 2;
			}
			dp[e][p] = go[e][xx] + dp[e][p^(1<<xx)];
		}
	}
	for(int p=1;p<(1<<len);p++){
		dp2[p] = 1e9;
		for(int q=0;q<len;q++){
			if(p&(1<<q)){
				dp2[p] = min(dp2[p],dp[q][p]+dp2[p^(1<<q)]);
			}
		}
	}
	cout << dp2[(1<<len)-1] + 1;
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