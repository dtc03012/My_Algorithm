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

const int MAX = 20202;
pi vis[MAX];
int dp[MAX];
void solve(int tc){
	for(int e=0;e<MAX;e++) vis[e] = mk(-1,-1);
	int n;
	cin >> n;
	dp[0] = 1;
	for(int e=1;e<MAX;e++) dp[e] = (dp[e-1]*10)%n;
	queue<pi> q;
	q.push(mk(0,0));
	while(!q.empty()){
		int x = q.front().x;
		int k = q.front().y;q.pop();
		if((x+dp[k])%n==0){
			if(vis[n].x==-1) vis[n] = mk(k,x);
			continue;
		}
		if(vis[(x+dp[k])%n].x==-1){
			vis[(x+dp[k])%n] = mk(k,x);
			q.push(mk((x+dp[k])%n,k+1));
		}
		if(k+1<100){
			q.push(mk(x,k+1));
		}
	}
	int ll = -1,st = n;
	string ans = "";
	while(vis[st].x!=-1){
		if(ll==-1) ll = vis[st].x;
		else{
			for(int e=ll-1;e>vis[st].x;e--) ans += "0";
			ll = vis[st].x;
		}
		ans += "1";
		st = vis[st].y;
	}
	for(int e=ll-1;e>=0;e--) ans += "0";
	cout << ans << "\n";
}


int main(void){
	/*
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	*/
	int tc = 1;
	
		cin >> tc;
	
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}