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
const lld mod = 1e9 + 7;
lld dp[MAX][MAX];
char S[MAX];
void solve(int tc){
	scanf("%s",S+1);
	dp[0][0] = 1;
	lld ans = 0;
	int len = strlen(S+1);
	for(int e=0;e<=len;e++){
		int f1 = -1,f2 = -1;
		for(int p=e+1;p<=len;p++){
			if(S[p]=='('&&f1==-1) f1 = p;
			if(S[p]==')'&&f2==-1) f2 = p;
		}
		for(int p=0;p<MAX-1;p++){
			if(f1!=-1){
				dp[f1][p+1] = (dp[f1][p+1]+dp[e][p])%mod;
			}
			if(f2!=-1){
				if(p) dp[f2][p-1] = (dp[f2][p-1]+dp[e][p])%mod;
			}
		}
		if(e) ans = (ans+dp[e][0])%mod;
	}
	printf("%lld",ans);
}


int main(void){
	/*
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	*/
	int tc = 1;
	/*
		scanf("%d",&tc);
	*/
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}