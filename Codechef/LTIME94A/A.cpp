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

const int MAX = 1010;
const lld mod = 1e9 + 7;
string L;
char arr[MAX];
vector<int> v[MAX];
int dp[MAX][26],A[MAX],B[MAX],cnt1[MAX][MAX],cnt2[MAX][MAX],ck[MAX][MAX];
lld dfs(int x,int y){
	if(dp[x][y]!=-1) return dp[x][y];
	if(y==sz(L)-1) return 1;
	dp[x][y] = 0;
	for(int e=0;e<sz(v[x]);e++){
		int nx = v[x][e];
		if(arr[nx]==L[y+1]) dp[x][y] = (dp[x][y]+dfs(nx,y+1))%mod;
	}
	return dp[x][y];
}
void solve(int tc){
	int n,m,l;
	cin >> n >> m >> l;
	for(int e=1;e<=n;e++){
		memset(dp[e],-1,sizeof(dp[e]));
		v[e].clear();
	}
	string a;
	cin >> L >> a;
	for(int e=0;e<n;e++) arr[e+1] = a[e];
	for(int e=0;e<m;e++) cin >> A[e];
	for(int e=0;e<m;e++) cin >> B[e];
	for(int e=0;e<m;e++){
		v[A[e]].push_back(B[e]);
		v[B[e]].push_back(A[e]);
		if(cnt2[A[e]][B[e]]==tc) cnt1[A[e]][B[e]]++;
		else{
			cnt2[A[e]][B[e]] = tc;
			cnt1[A[e]][B[e]] = 1;
		}
		swap(A[e],B[e]);
		if(cnt2[A[e]][B[e]]==tc) cnt1[A[e]][B[e]]++;
		else{
			cnt2[A[e]][B[e]] = tc;
			cnt1[A[e]][B[e]] = 1;
		}
	}
	lld ans = 0;
	for(int e=1;e<=n;e++) if(arr[e]==L[0]) ans = (ans+dfs(e,0))%mod;
	bool suc = false;
	for(int e=1;e<l;e++) if(L[e]!=L[e-1]) suc = true;
	if(!suc){
		lld tot = 0;
		for(int e=1;e<=n;e++){
			for(int p=0;p<sz(v[e]);p++){
				int nx = v[e][p];
				int f1 = min(e,nx);
				int f2 = max(e,nx);
				if(arr[f1]==L[0]&&arr[f2]==L[0]&&ck[f1][f2]!=tc){
					ck[f1][f2] = tc;
					lld xx = 1;
					for(int p=0;p<l-1;p++) xx = (xx*cnt1[f1][f2])%mod;
					tot = (tot+xx)%mod;
				}
			}
		}
		ans -= tot;
		ans = (ans%mod+mod)%mod;
	}
	cout << ans << "\n";
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