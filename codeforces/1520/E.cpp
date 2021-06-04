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

const int MAX = 1010101;
int cnt[MAX];
lld dp[MAX];
void solve(int tc){
	int n;
	string a;
	cin >> n >>  a;
	cnt[0] = 0;
	dp[0] = 0;
	for(int e=1;e<=n;e++){
		cnt[e] = cnt[e-1];
		dp[e] = dp[e-1];
		if(a[e-1]=='*'){
			cnt[e]++;
			dp[e] += e;
		}
	}
	if(cnt[n]==0){
		cout << "0\n";
		return;
	}
	lld ans = 1e18;
	for(int e=1;e<=n;e++){
		if(e+cnt[n]-1>n) break;
		int ll = 0,rr = n,mid,pos=0;
		while(ll<=rr){
			mid = (ll+rr)/2;
			if(e+mid<=n&&cnt[e+mid]>=mid+1){
				pos = max(pos,mid);
				ll = mid + 1;
			}else rr = mid - 1;
		}
		pos += e;
		lld f1 = cnt[pos];
		lld f2 = cnt[n] - f1;
		lld vv1 = f1*e + ((f1)*(f1-1))/2;
		lld vv2 = f2*e + ((f1+f2)*(f1+f2-1))/2 - ((f1)*(f1-1))/2;
		vv1 -= vv2;
		vv1 += dp[n];
		vv1 -= dp[pos]*2;
		ans = min(ans,vv1);
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