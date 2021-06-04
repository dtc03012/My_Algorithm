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

const int MAX = 111,KMAX = 10101;
lld arr[KMAX][MAX],go[MAX][KMAX],sumv[MAX];
void solve(int tc){
	int k,n;
	scanf("%d%d",&k,&n);
	for(int e=1;e<=n-1;e++){
		for(int p=1;p<=k;p++) scanf("%lld",&arr[p][e]);
		for(int p=1;p<=k;p++){
			scanf("%lld",&go[e][p]);
		}
	}
	for(int e=1;e<=k;e++) scanf("%lld",&arr[e][n]);
	for(int e=n;e>=1;e--) sumv[e] = sumv[e+1] + arr[k][e];
	lld ans = sumv[1];
	for(int e=1;e<=k-1;e++){
		lld vv = 0;
		for(int p=1;p<n;p++){
			vv += arr[e][p];
			ans = min(ans,vv+go[p][e]+sumv[p+1]);
		}
		vv += arr[e][n];
		ans = min(ans,vv);
	}
	printf("%lld\n",ans);
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