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

const int MAX = 150101 * 4;

lld arr[4][MAX];
map<int,int> go[4][MAX];
vector<pli> dp[4];
void solve(int tc){
	int n[4];
	scanf("%d%d%d%d",&n[0],&n[1],&n[2],&n[3]);
	for(int e=0;e<4;e++){
		for(int p=1;p<=n[e];p++) scanf("%lld",&arr[e][p]);
	}
	for(int e=0;e<3;e++){
		int k;
		scanf("%d",&k);
		for(int p=0;p<k;p++){
			int a,b;
			scanf("%d%d",&a,&b);
			go[e][a][b] = 1;
		}
	}
	for(int e=1;e<=n[3];e++) dp[3].push_back(mk(arr[3][e],e));
	sort(all(dp[3]));
	for(int e=2;e>=0;e--){
		for(int p=1;p<=n[e];p++){
			for(int q=0;q<sz(dp[e+1]);q++){
				int xx = dp[e+1][q].y;
				if(go[e][p][xx]) continue;
				dp[e].push_back(mk(dp[e+1][q].x+arr[e][p],p));
				break;
			}
		}
		sort(all(dp[e]));
	}
	if(sz(dp[0])==0) printf("-1\n");
	else printf("%lld\n",dp[0][0].x);
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