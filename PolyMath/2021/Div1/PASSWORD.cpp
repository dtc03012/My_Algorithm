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

const lld F1 = 3;
const lld F2 = 7;
const lld MOD1 = 1e9 + 7;
const lld MOD2 = 998244353;
const int MAX = 101010;
lld dp1[MAX],dp2[MAX];
string a,b;
map<pl,int> ck,ck2;
void solve(int tc){
	int n,k;
	cin >> n >> k >> a >> b;
	dp1[0] = dp2[0] = 1;
	for(int e=1;e<MAX;e++){
		dp1[e] = (dp1[e-1]*F1)%MOD1;
		dp2[e] = (dp2[e-1]*F2)%MOD2;
	}
	lld x1 = 0,x2 = 0;
	for(int e=0;e<k;e++){
		x1 = (x1+dp1[k-e-1]*(b[e]-'0'))%MOD1;
		x2 = (x2+dp2[k-e-1]*(b[e]-'0'))%MOD2;
		ck[mk(x1,x2)] = 1;
	}
	for(int e=k;e<n;e++){
		x1 = ((x1-dp1[k-1]*(b[e-k]-'0'))%MOD1+MOD1)%MOD1;
		x2 = ((x2-dp2[k-1]*(b[e-k]-'0'))%MOD2+MOD2)%MOD2;
		x1 = (x1*F1)%MOD1;
		x2 = (x2*F2)%MOD2;
		x1 = (x1+b[e]-'0')%MOD1;
		x2 = (x2+b[e]-'0')%MOD2;
		ck[mk(x1,x2)] = 1;
	}
	lld y1 = 0,y2 = 0,ans = 0;
	for(int e=0;e<k;e++){
		y1 = (y1+dp1[k-e-1]*(a[e]-'0'))%MOD1;
		y2 = (y2+dp2[k-e-1]*(a[e]-'0'))%MOD2;
	}
	if(ck[mk(y1,y2)]) ans++;
	ck2[mk(y1,y2)] = 1;
	for(int e=k;e<n;e++){
		y1 = ((y1-dp1[k-1]*(a[e-k]-'0'))%MOD1+MOD1)%MOD1;
		y2 = ((y2-dp2[k-1]*(a[e-k]-'0'))%MOD2+MOD2)%MOD2;
		y1 = (y1*F1)%MOD1;
		y2 = (y2*F2)%MOD2;
		y1 = (y1+a[e]-'0')%MOD1;
		y2 = (y2+a[e]-'0')%MOD2;
		if(ck2[mk(y1,y2)]) continue;
		if(ck[mk(y1,y2)]) ans++;
		ck2[mk(y1,y2)] = 1;
	}
	printf("%lld\n",ans);
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