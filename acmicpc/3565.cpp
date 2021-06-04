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

class
const int MAX = 66;
lld dp1[MAX],dp2[MAX],dp3[MAX],dp4[MAX];
void solve(int tc){
	lld n;
	cin >> n;
	if(n<=1){
		cout << n;
		return;
	}
	dp1[0] = dp1[1] = dp4[1] = 1;
	dp2[0] = dp3[1] = 1;
	dp2[1] = 2;
	lld pos = 2,ans = 0;
	for(;pos<66;pos++){
		dp1[pos] = dp2[pos-2];
		dp2[pos] = dp2[pos-1] + dp1[pos];
		if(dp3[pos-1] + pos * dp1[pos] >= n){
			n -= dp3[pos-1];
			ans += dp4[pos-1];
			break;
		}
		dp3[pos] = dp3[pos-1] + pos * dp1[pos];
		dp4[pos] = dp4[pos-1] + dp1[pos] + dp4[pos-2];
	}
	lld diff = n / pos;
	if(n%pos) diff++;
	lld res = 1,bit = (1ll<<(pos-1));
	for(lld pos2 = pos-2;pos2>=0&&diff;pos2--){
		if(diff>dp2[pos2]){
			bit += (1ll<<pos2);
			ans += res * dp2[pos2] + dp4[pos2];
			diff -= dp2[pos2];
			res++;
		}
	}
	ans += res;
	if(n%pos){
		lld kk = pos - (n%pos);
		for(lld p=0;p<kk;p++){
			if(bit&(1ll<<p)) ans--;
		}
	}
	cout << ans;
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