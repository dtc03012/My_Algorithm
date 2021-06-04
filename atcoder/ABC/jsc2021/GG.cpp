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

const int MAX = 505050;
int dp[MAX][26],vis[MAX],go[MAX];
int k;
string s;
void dfs(int wh,int lim,int l,int r,int x){
	if(lim==0){
		dp[x][s[x]-'a'] = 1;
		return;
	}
	if(wh==lim){
		vis[l+x] = 1;
		vis[r-x] = 1;
		dp[x][s[l+x]-'a']++;
		if(l+x!=(r-x))dp[x][s[r-x]-'a']++;
		return;
	}else{
		if((r-l+1)%2){
			int mid = (r-l)/2;
			dfs(wh+1,lim,l,l+mid-1,x);
			dfs(wh+1,lim,l+mid+1,r,x);
		}else{
			int mid = (r-l)/2;
			dfs(wh+1,lim,l,l+mid,x);
			dfs(wh+1,lim,l+mid+1,r,x);
		}
	}
}
void solve(int tc){
	cin >> k;
	cin >> s;
	int nn = 0;
	int nk = sz(s),rns,flag = 0;
	while(true){
		if(nn==k){
			rns = nk;
			flag = 1;
		}
		if(nk==0&&!flag){
			cout << "impossible" << "\n";
			return;
		}
		if(nk==0) break;
		nn++;
		if(nk%2&&!flag) go[nk/2] = 1;
		nk/=2;
	}
	int ans = 0,lim = k;
	for(int p=0;p<sz(s);p++){
		if(go[p]) lim--;
		cout << go[p] << endl;
		if(vis[p]==0){
			dfs(1,lim,0,sz(s)-1,p);
			vis[p] = 0;
		}
	}
	if(rns==1){
		cout << "impossible" << "\n";
	}else{
		if(rns==0){
			int ans = 0;
			for(int p=0;p<sz(s);p++){
				if(vis[p]==0){
					int tot = 0,mx = 0;
					for(int q=0;q<26;q++){
						tot += dp[p][q];
						mx = max(mx,dp[p][q]);
					}
					ans += tot - mx;
				}
			}
			cout << ans << '\n';
		}else{
			string xx = "";
			int ans = 0;
			for(int p=0;p<rns;p++){
				if(vis[p]==0){
					int tot = 0,mx = 0,wh = -1;
					for(int q=0;q<26;q++){
						tot += dp[p][q];
						if(mx<dp[p][q]){
							mx = dp[p][q];
							wh = q;
						}
					}
					xx += char(wh+'a');
					ans += tot - mx;
				}
			}
			for(int p=rns;p<sz(s);p++){
				if(vis[p]==0){
					int tot = 0,mx = 0;
					for(int q=0;q<26;q++){
						tot += dp[p][q];
						mx = max(mx,dp[p][q]);
					}
					ans += tot - mx;
				}
			}
			bool suc = true;
			for(int e=0;e<sz(xx);e++){
				int f1 = e;
				int f2 = sz(xx) - e - 1;
				if(f1>=f2) break;
				if(xx[f1]!=xx[f2]) suc = false;
			}
			if(!suc){
				cout << ans << "\n";
			}else{
				int ddd = 1e9;
				for(int p=0;p<rns;p++){
					int f1 = p;
					int f2 = sz(xx) - p - 1;
					if(f1==f2) break;
					int tot = 0,org = 0;
					for(int q=0;q<26;q++){
						tot += dp[p][q];
					}
					org = tot - dp[p][xx[p]-'a'];
					for(int q=0;q<26;q++){
						if(q==(xx[p]-'a')) continue;
						int norg = tot - dp[p][q];
						ddd = min(ddd,norg-org);
					}
				}
				ans += ddd;
				cout << ans << "\n";
			}
		}
	}
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