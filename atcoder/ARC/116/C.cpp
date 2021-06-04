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
const lld mod = 998244353;
vector<pil> v;
lld dp[MAX],ck[MAX],ck2[MAX],fact[MAX];
lld calc(lld now,lld num){
	if(num==0) return 1;
	if(num==1) return now;
	lld now2 = calc(now,num/2);
	if(num%2==0) return (now2*now2)%mod;
	return (((now2*now2)%mod)*now)%mod;
}
lld nCr(int a,int b){
	lld f1 = fact[a];
	lld f2 = (fact[b]*fact[a-b])%mod;
	return (f1*calc(f2,mod-2))%mod;
}
void solve(int tc){
	fact[1] = 1;
	for(int e=2;e<MAX;e++) fact[e] = (fact[e-1]*e)%mod;
	lld ans = 0;
	int n,m;
	scanf("%d%d",&n,&m);
	for(int e=1;e<=m;e++){
		v.push_back(mk(e,1));
		ans++;
	}
	for(int e=2;e<=n;e++){
		vector<pil> v1,v3;
		vector<int> v2;
		for(int p=0;p<sz(v);p++){
			lld nx = v[p].x;
			for(int q=2;q<=m;q++){
				if(nx*q>m) break;
				v1.push_back(mk(nx*q,v[p].y));
				if(ck2[nx*q]!=e){
					ck2[nx*q] = e;
					v2.push_back(nx*q);
				}
			}
		}
		for(int p=0;p<sz(v1);p++){
			int nx = v1[p].x;
			lld vv = v1[p].y;
			if(ck[nx]!=e){
				ck[nx] = e;
				dp[nx] = 0;
			}
			dp[nx] = (dp[nx]+vv)%mod;
		}
		lld xx = nCr(n-1,n-e);
		for(int p=0;p<sz(v2);p++){
			int nx = v2[p];
			ans = (ans+dp[nx]*xx)%mod;
			v3.push_back(mk(nx,dp[nx]));
		}
		v = v3;
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