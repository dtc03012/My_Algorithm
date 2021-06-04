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

const int MAX = 5050;
const lld mod = 998244353;
vector<int> v[MAX];
int dp[MAX][MAX];
lld tot[MAX];
lld fact[MAX];
lld calc(lld now,lld num){
	if(num==0) return 1;
	if(num==1) return now;
	lld now2 = calc(now,num/2);
	if(num%2==0) return (now2*now2)%mod;
	return (((now2*now2)%mod)*now)%mod;
}
lld nCr(lld a,lld b){
	lld f1 = fact[a];
	lld f2 = (fact[b]*fact[a-b])%mod;
	return (f1*calc(f2,mod-2))%mod;
}
int ck[MAX][MAX];
void solve(int tc){
	int n,m;
	scanf("%d%d",&n,&m);
	fact[1] = 1;
	for(int e=2;e<MAX;e++) fact[e] = (fact[e-1]*e)%mod;
	for(int e=0;e<m;e++){
		int a,b;
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	lld res = 1,f1 = 0,f2 = 0;
	int k = 0;
	for(int e=1;e<=n;e++){
		for(int p=0;p<sz(v[e]);p++){
			int nx = v[e][p];
			if(ck[e][nx]) continue;
			ck[e][nx] = 1;
			ck[nx][e] = 1;
			if((sz(v[e])%2)!=(sz(v[nx])%2)) res = (res*2)%mod;
			else{
				if((sz(v[e])%2)==0) f1++;
				else f2++;
			}
		}
		if(sz(v[e])%2) k++;
	}
	printf("%d\n",k);
	printf("%lld\n",res);
	printf("%d : %d\n",f1,f2);
	for(int e=0;e<=f1;e++){
		for(int p=0;p<=f2;p++){
			lld k1 = nCr(f1,e);
			lld k2 = nCr(f2,p);
			lld k3 = (k1*k2)%mod;
			int nk = k + 2*e - 2*p;
			tot[nk] = (k3*res)%mod;
		}
	}
	for(int e=0;e<=n;e++) printf("%lld\n",tot[e]);

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