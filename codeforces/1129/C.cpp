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
const int MAX = 3030;
const lld mod = 1e9 + 7;

int go[MAX*MAX][2],rt = 2;
lld dp[MAX];
string vv = "";
void solve(int tc){
	memset(go,-1,sizeof(go));
	int n;
	scanf("%d",&n);
	lld ans = 0;
	for(int e=0;e<n;e++){
		string k;
		cin >> k;
		vv += k;
		reverse(all(vv));
		int now = 1,wh = -1;
		for(int p=0;p<sz(vv);p++){
			if(go[now][vv[p]-'0']==-1){
				wh = p;
				break;
			}else{
				now = go[now][vv[p]-'0'];
			}
		}
		if(wh==-1){
			printf("%lld\n",ans);
			continue;
		}
		memset(dp,0,sizeof(dp));
		dp[0] = 1;
		for(int p=1;p<sz(vv);p++){
			for(int q=1;q<=3;q++){
				if(p-q>=0) dp[p] = (dp[p] + dp[p-q])%mod;
			}
			if(p>=3){
				string kk = vv.substr(p-3,4);
				if(kk!="1100"&&kk!="1010"&&kk!="0111"&&kk!="1111"){
					if(p==3) dp[p] = (dp[p]+1)%mod;
					else dp[p] = (dp[p]+dp[p-4])%mod;
				}
			}else{
				dp[p] = (dp[p]+1)%mod;
			}
		}
		for(int p=wh;p<sz(vv);p++) ans = (ans+dp[p])%mod;
		printf("%lld\n",ans);
		now = 1;
		for(int p=0;p<sz(vv);p++){
			if(go[now][vv[p]-'0']==-1) go[now][vv[p]-'0'] = rt++;
			now = go[now][vv[p]-'0'];
		}
		reverse(all(vv));
	}
}


int main(void){
	/*
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	*/
	int tc = 1;
	/*
		scanf("%d",&tc);
	*/
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}