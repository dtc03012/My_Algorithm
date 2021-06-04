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
lld dp[32][2][2][2][2],tot;
int X,Y;
lld dfs(int pos,int f,int fpos,int s,int spos){
	if(dp[pos][f][fpos][s][spos]!=-1) return dp[pos][f][fpos][s][spos];
	if(pos==0){
		dp[pos][f][fpos][s][spos] = 1;
		if(f||s) tot = (tot+1)%mod;
		return 1;
	}
	lld ans = 0;
	for(int e=0;e<2;e++){
		for(int p=0;p<2;p++){
			if(e==1&&p==1) continue;
			if(fpos==0&&(X&(1<<(pos-1)))==0&&e==1) continue;
			if(spos==0&&(Y&(1<<(pos-1)))==0&&p==1) continue;
			int nfpos = fpos;
			if(X&(1<<(pos-1))&&e==0) nfpos = 1;
			int nspos = spos;
			if(Y&(1<<(pos-1))&&p==0) nspos = 1;
			lld xx = dfs(pos-1,e,nfpos,p,nspos);
			ans = (ans+xx)%mod;
		}
	}
	printf("%lld : %lld , %d\n",tot,ans,(1<<pos));
	if(f||s) tot = (tot+ans*(1<<pos))%mod;
	printf("%d : %d %d ( %d %d ) -> %lld %lld\n",pos,f,s,fpos,spos,ans,tot);
	return dp[pos][f][fpos][s][spos] = ans;
}
void solve(int tc){
	tot = 0;
	memset(dp,-1,sizeof(dp));
	cin >> X >> Y;
	dfs(31,0,0,0,0);
	tot--;
	tot = (tot%mod+mod)%mod;
	cout << tot << "\n";
}


int main(void){
	
	// ios_base :: sync_with_stdio(false);
	// cin.tie(NULL);
	// cout.tie(NULL);
	
	int tc = 1;
	
		cin >> tc;
	
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}