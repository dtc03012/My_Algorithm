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

const lld mod = 998244353;
map<int,lld> ck;
string arr[10];
int n,m;
lld dp[10][10];
vector<vector<int> > infor[10];
lld dfs(int x){
	if(x==0) return 1;
	if(ck.count(x)) return ck[x];
	if(x==1){
		int tot = 0;
		for(int p=0;p<n;p++){
			if(sz(arr[p])==1){
				tot++;
			}
		}
		ck[x] =  tot;
		return tot;
	}
	lld tot = 0;
	int mid = (x/2);
	int rmid = x - mid;
	lld f1 = dfs(mid);
	lld f2 = dfs(rmid);
	f1 = (f1*f2)%mod;
	tot = (tot+f1)%mod;
	for(int q=0;q<n;q++){
		int len = sz(arr[q]);
		if(len==x) tot = (tot+dp[q][0])%mod;
		for(int p=1;p<len;p++){
			if(mid-p>=0&&rmid-(len-p)>=0){
				lld k1 = dfs(mid-p);
				lld k2 = dfs(rmid-(len-p));
				k1 = (k1*k2)%mod;
				k1 = (k1*dp[q][p])%mod;
				tot = (tot+k1)%mod;
			}
		}
	}
	return ck[x] = tot;
}
void go(int rt,string vv,vector<int> ck){
	if(sz(arr[rt])<sz(vv)) return;
	if(sz(arr[rt])==sz(vv)){
		if(vv==arr[rt]){
			infor[rt].push_back(ck);
		}
		return ;
	}
	for(int p=0;p<n;p++){
		string nvv = vv + arr[p];
		vector<int> nck = ck;
		nck.push_back(sz(arr[p]));
		go(rt,nvv,nck);
	}
	return;
}
void solve(int tc){
	cin >> n >> m;
	for(int e=0;e<n;e++) cin >> arr[e];
	for(int e=0;e<n;e++){
		go(e,"",vector<int>());
		int len = sz(infor[e]);
		int tot = 0;
		dp[e][0] = len*2 - 1;
		for(int p=0;p<len;p++){
			for(int q=0;q<len;q++){
				int f1 = sz(infor[e][p]);
				int st = 0;
				int tot1 = 0,tot2 = 0,err = 0;
				for(int r=0;r<f1;r++){
					tot1 += infor[e][p][r];
					while(tot2<tot1&&st<sz(infor[e][q])){
						tot2 += infor[e][q][st++];
					}
					if(tot2!=tot1){
						dp[e][tot1] += 2;
					}
				}
			}
		}
		for(int p=0;p<sz(arr[e]);p++) cout << p << " : " << dp[e][p] << "\n";
		cout << "\n";
	}
	cout << dfs(m);
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