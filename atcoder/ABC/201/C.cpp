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

int dp[5][(1<<4)];
void solve(int tc){
	string a;
	cin >> a;
	int tot = 0,tot1 = 0;
	for(int e=0;e<sz(a);e++){
		 if(a[e]=='o') tot++;
		 if(a[e]=='?') tot1++;
	}	
	if(tot>4) cout << "0";
	else{
		dp[0][0] = 1;
 		for(int p=1;p<=4;p++){
			for(int q=0;q<(1<<tot);q++){
				for(int r=0;r<tot;r++){
					if(q&(1<<r)){
						dp[p][q] += dp[p-1][q];
					}else{
						dp[p][q^(1<<r)] += dp[p-1][q];
					}
				}
				dp[p][q] += dp[p-1][q] * tot1;
			}
		}
		cout << dp[4][(1<<tot)-1];
	}
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