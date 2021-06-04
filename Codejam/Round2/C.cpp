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

const lld mod = 1e9 + 7;
const int MAX = 101010;
int arr[MAX],start = 1;
lld dp[MAX];
pi seg[MAX*4];
lld calc(lld now,lld num){
	if(num==0) return 1;
	if(num==1) return now;
	lld now2 = calc(now,num/2);
	if(num%2==0) return (now2*now2)%mod;
	return (((now2*now2)%mod)*now)%mod;
}
lld nCr(int a,int b){
	lld f1 = dp[a];
	lld f2 = (dp[b]*dp[a-b])%mod;
	return (f1*calc(f2,mod-2))%mod;
}
pi getn(int l,int r){
	l += start;
	r += start;
	int val = 1e9,posl = -1,vall = 1e9,posr = -1,valr = 1e9;;
	while(l<=r){
		if(l&1){
			if(vall>=seg[l].x){
				vall = seg[l].x;
				posl = seg[l].y;
			}
			l++;
		}
		if(!(r&1)){
			if(valr>seg[r].x){
				valr = seg[r].x;
				posr = seg[r].y;
			}
			r--;
		}
		l >>= 1;
		r >>= 1;
	}
	if(valr<=vall){
		return mk(posr,valr);
	}
	return mk(posl,vall);
}
lld dfs(int l,int r,int x){
	if(l>r) return 1;
	if(l==r){
		if(arr[l]==x) return 1;
		return 0;
	}
	pi pos = getn(l,r);
	if(pos.y!=x){
		return 0; 
	}
	lld tt = nCr(r-l,pos.x-l);
	tt = (tt*dfs(l,pos.x-1,x))%mod;
	tt = (tt*dfs(pos.x+1,r,x+1))%mod;
	return tt;
}
void solve(int tc){
	start = 1;
	while(start<MAX) start *= 2;
	for(int e=0;e<MAX*4;e++){
		seg[e] = mk(1e9,e);
	}
	int n;
	cin >> n;
	for(int e=0;e<n;e++) cin >> arr[e];
	for(int e=start;e<start+n;e++){
		seg[e] = mk(arr[e-start],e-start);
	}
	for(int e=start-1;e>=1;e--){	
		if(seg[e*2].x<seg[e*2+1].x) seg[e] = seg[e*2];
		else seg[e] = seg[e*2+1];
	}
	lld xx = dfs(0,n-1,1);
	cout << "Case #" << tc << ": " << xx << "\n";
}


int main(void){
	dp[0] = 1;
	for(int e=1;e<MAX;e++) dp[e] = (dp[e-1]*e)%mod;
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