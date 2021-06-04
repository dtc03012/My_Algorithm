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
vector<lld> v[MAX],sum[MAX];
int A[MAX],B[MAX];
lld ans[MAX];
bool tmr(int a,int b){
	return a > b;
}
void solve(int tc){
	int n;
	cin >> n;
	for(int e=1;e<=n;e++){
		v[e].clear();
		ans[e] = 0;
		sum[e].clear();
	}
	for(int e=1;e<=n;e++) cin >> A[e];
	for(int e=1;e<=n;e++) cin >> B[e];
	for(int e=1;e<=n;e++) v[A[e]].push_back(B[e]);
	for(int e=1;e<=n;e++) sort(all(v[e]),tmr);
	for(int e=1;e<=n;e++){
		lld xx = 0;
		for(int p=0;p<sz(v[e]);p++){
			xx += v[e][p];
			sum[e].push_back(xx);
		}
		for(int p=1;p<=sz(v[e]);p++){
			int last = (sz(v[e])/p)*p;
			ans[p] += sum[e][last-1];
		}
	}
	for(int e=1;e<=n;e++) cout << ans[e] << " ";
	cout << "\n";
}


int main(void){
	
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int tc = 1;
	
		cin >> tc;
	
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}