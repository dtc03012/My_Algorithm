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
string a[3];
lld dp[10],ans,n;
int vis[3][3];
void dfs(int y,int x,int c){
	if(x==3){
		y++;
		x = 0;
	}
	if(y==3){
		bool suc = true;
		for(int e=0;e<3;e++){
			for(int p=0;p<3;p++){
				if(vis[e][p]==0) continue;
				for(int q=1;q<=2;q++){
					if(e+q==3) break;
					if(vis[e+q][p]==vis[e][p]){
						suc = false;
					}else{
						if(vis[e+q][p]) break;
					}
				}
				for(int q=1;q<=2;q++){
					if(e-q==-1) break;
					if(vis[e-q][p]==vis[e][p]){
						suc = false;
					}else{
						if(vis[e-q][p]) break;
					}
				}
				for(int q=1;q<=2;q++){
					if(p+q==3) break;
					if(vis[e][p+q]==vis[e][p]){
						suc = false;
					}else{
						if(vis[e][p+q]) break;
					}
				}
				for(int q=1;q<=2;q++){
					if(p-q==-1) break;
					if(vis[e][p-q]==vis[e][p]){
						suc = false;
					}else{
						if(vis[e][p-q]) break;
					}
				}
			}
		}
		if(suc){
			ans = (ans+dp[c])%mod;
		}
		return;
	}
	int ny = y,nx = x + 1;
	if(nx==3){
		nx = 0;
		ny++;
	}
	if(a[y][x]=='x'){
		for(int p=1;p<=min(c+1,(int)n);p++){
			vis[y][x] = p;
			dfs(ny,nx,max(c,p));
		}
	}else{
		dfs(ny,nx,c);
	}
}
void solve(int tc){
	memset(vis,0,sizeof(vis));
	ans = 0;
	scanf("%lld",&n);
	for(int e=0;e<3;e++) cin >> a[e];
	lld last = n;
	dp[1] = last--;
	for(int e=2;e<10;e++){
		dp[e] = (dp[e-1] * (last--))%mod;
	}
	bool suc = false;
	for(int e=0;e<3;e++){
		for(int p=0;p<3;p++){
			if(a[e][p]=='x'){
				suc = true;
				vis[e][p] = 1;
				dfs(e,p+1,1);
				break;
			}
		}
		if(suc) break;
	}
	if(suc) printf("%lld\n",ans);
	else printf("1\n");
}


int main(void){
	/*
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	*/
	int tc = 1;
	
		scanf("%d",&tc);
	
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}