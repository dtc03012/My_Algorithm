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
string a,b;
bool dp[MAX][7];
void solve(int tc){
	int n;
	cin >> n >> b >> a;
	dp[n][0] = true;
	for(int e=n-1;e>=0;e--){
		if(a[e]=='T'){
			for(int p=0;p<7;p++){
				if(dp[e+1][(p*10)%7]||dp[e+1][(p*10+b[e]-'0')%7]){
					dp[e][p] = 1;
				}
			}
		}else{
			for(int p=0;p<7;p++){
				if(dp[e+1][(p*10)%7]&&dp[e+1][(p*10+b[e]-'0')%7]){
					dp[e][p] = 1;
				}
			}
		}
	}
	printf("%s",(dp[0][0]?"Takahashi":"Aoki"));
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