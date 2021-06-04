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

const int MAX = 101010;
const lld mod = 235813;
lld calc(lld now,lld num){
	if(num==0) return 1;
	if(num==1) return now;
	lld now2 = calc(now,num/2);
	if(num%2==0) return (now2*now2)%mod;
	return (((now2*now2)%mod)*now)%mod;
}
lld dp[MAX];
lld nCr(int n,int r){
	lld f1 = dp[n];
	lld f2 = (dp[r]*dp[n-r])%mod;
	return (f1*calc(f2,mod-2))%mod;
}
lld arr[MAX];
void solve(int tc){
	int n;
	cin >> n;
	lld tot = 0;
	dp[0] = 1;
	for(int e=1;e<MAX;e++) dp[e] = (dp[e-1]*e)%mod;
	for(int e=0;e<n;e++){
		cin >> arr[e];
		arr[e] = (arr[e]*nCr(n-1,e))%mod;
	}
	reverse(arr,arr+n);
	for(int e=0;e<n;e++){
		if(e%2==0){
			tot = (tot+arr[e])%mod;
		}else{
			tot -= arr[e];
			tot = (tot%mod+mod)%mod;
		}
	}
	if(tot==0){
		cout << "0";
		return;
	}
	int ans = 0;
	for(int e=0;e<n;e++){
		if(e%2==0){
			tot -= arr[e];
			tot = (tot%mod+mod)%mod;
		}else{
			tot = (tot+arr[e])%mod;
		}
		lld ntot = -tot;
		if(ntot<0) ntot += mod;
		lld kk = nCr(n-1,e);
		ntot = (ntot*calc(kk,mod-2))%mod;
		if(ntot>=-100000&&ntot<=100000) ans++;
		else if(ntot-mod>=-100000&&ntot-mod<=100000) ans++;
		else if(ntot+mod>=-100000&&ntot+mod<=100000) ans++;
		if(e%2){
			tot -= arr[e];
			tot = (tot%mod+mod)%mod;
		}else{
			tot = (tot+arr[e])%mod;
		}
	}
	cout << ans << "\n";
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