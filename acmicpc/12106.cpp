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

const int MAX = 111;
const lld mod = 1e9 + 9;
int fail[MAX],go[MAX][26],dp[MAX][MAX];
void solve(int tc){
	memset(fail,-1,sizeof(fail));
	int n;
	string a;
	cin >> n >> a;
	int j = -1;
	for(int e=1;e<sz(a);e++){
		while(a[j+1]!=a[e]&&j!=-1) j = fail[j];
		if(a[j+1]==a[e]) fail[e] = ++j;
	}
	for(int e=1;e<sz(a);e++){
		for(int p=0;p<26;p++){
			if(a[e]-'a'==p) continue;
			char xx = p + 'a';
			int x = e - 1;
			while(a[x+1]!=xx&&x!=-1) x = fail[x];
			if(a[x+1]==xx) x++;
			go[e+1][p] = x + 1;
		}
	}
	dp[0][0] = 1;
	for(int e=1;e<=n;e++){
		for(int p=1;p<=sz(a);p++){
			for(int q=0;q<26;q++){
				if(a[p-1]==q+'a') dp[e][p] = (dp[e][p]+dp[e-1][p-1])%mod;
				else dp[e][go[p][q]] = (dp[e][go[p][q]]+dp[e-1][p-1])%mod;
			}
		}
		for(int p=0;p<26;p++) dp[e][sz(a)] = (dp[e][sz(a)]+dp[e-1][sz(a)])%mod;
	}
	printf("%d\n",dp[n][sz(a)]);
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