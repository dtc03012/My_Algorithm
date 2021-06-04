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

const int MAX = 2555;
double dp[MAX][11],nuk[MAX][MAX],arr[MAX];
double eps = 0.00000001;
int ck[MAX][MAX];
bool eq(double x,double y){
	if(abs(x-y)<eps) return true;
	return false;
}
void solve(int tc){
	int n,k;
	scanf("%d%d",&n,&k);	
	for(int e=1;e<=n;e++){
		scanf("%lf",&arr[e]);
		arr[e] += eps;
	}
	ck[0][0] = 1;
	double ans = 0.0;
	for(int e=1;e<=n;e++){
		for(int p=1;p<=k;p++){
			bool suc = false;
			double xx = arr[e],yy = 1;
			if()
			for(int q=e-1;q>=1;q--){
				xx *= (1-arr[q]);
				xx /= yy;
				yy++;
				xx *= yy;
				if(ck[q-1][p-1]){
					suc = true;
					dp[e][p] += xx + dp[q-1][p-1];
				}
				if(q==0) break;
			}
			if(suc) ck[e][p] = 1;
		}
	}
	double mx = 0;
	for(int e=1;e<=n;e++){
		mx = max(mx,dp[e][k]);
		printf("%.9lf\n",dp[e][k]);
	}
	printf("%.9lf",mx);
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