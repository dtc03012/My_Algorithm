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
int ck[MAX];
void solve(int tc){
	int n,m;
	cin >> n >> m;
	long double ans = 0.0;
	for(int e=1;e<=n;e++) ck[e] = 1e9;
	for(int e=0;e<m;e++){
		int k;
		cin >> k;
		for(int p=0;p<k;p++){
			int d;
			cin >> d;
			ck[d] = min(ck[d],k);
		}
	}
	for(int e=1;e<=n;e++){
		ans = max(ans,(ld)(ck[e]-1)/(ld)(ck[e]));
	}
	cout << fixed;
	cout.precision(8);
	cout << ans;
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