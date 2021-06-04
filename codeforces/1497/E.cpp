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

const int MAX = 202020;
const int NMAX = 1e7 + 100;
int arr[MAX],pri[NMAX];
pi dp[2][21][21];
int leftv[MAX],wh[MAX];
vector<int> idx;
vector<pi> vk[21];
bool comp(pi a,pi b){
	if(a.x!=b.x) return a.x < b.x;
	return a.y > b.y;
}
void solve(int tc){
	idx.clear();
	int n,k;
	scanf("%d%d",&n,&k);
	for(int e=1;e<=n;e++) scanf("%d",&arr[e]);
	for(int e=1;e<=n;e++) idx.push_back(pri[arr[e]]);
	for(int e=0;e<=n;e++){
		wh[e] = -1;
		leftv[e] = -1;
	}
	for(int p=0;p<=k;p++){
		for(int q=0;q<=k;q++){
			dp[0][p][q] = dp[1][p][q] =  mk(1e9,1e9);
		}
	}
	sort(all(idx));
	idx.erase(unique(all(idx)),idx.end());
	for(int e=1;e<=n;e++) arr[e] = lower_bound(all(idx),pri[arr[e]]) - idx.begin();
	for(int e=1;e<=n;e++){
		if(wh[arr[e]]==-1) wh[arr[e]] = e;
		else{
			leftv[e] = wh[arr[e]];
			wh[arr[e]] = e;
		}
	}
	dp[0][0][0] = mk(1,0); 
	for(int e=1;e<=n;e++){
		for(int p=0;p<=k;p++) vk[p].clear();
		int fx = (e%2);
		int lx = ((e+1)%2);
		for(int p=0;p<=k;p++){
			for(int q=0;q<=p;q++){
				dp[fx][p][q] = mk(1e9,1e9);
				pi xx = dp[lx][p][q];
				if(xx.x==1e9) continue;
				if(leftv[e]>=xx.y){
					vk[p].push_back(mk(xx.x+1,e));
					if(p+1<=k) vk[p+1].push_back(mk(xx.x,xx.y));
				}else{
					vk[p].push_back(mk(xx.x,xx.y));
				}
			}
		}
		for(int p=0;p<=k;p++){
			sort(all(vk[p]),comp);
			for(int q=0;q<sz(vk[p]);q++){
				if(q&&vk[p][q].x==vk[p][q-1].x) continue;
				dp[fx][p][q] = mk(vk[p][q].x,vk[p][q].y);
			}
		}
	}
	int ans = 1e9;
	for(int e=0;e<=k;e++){
		for(int p=0;p<=e;p++){
			ans = min(ans,dp[n%2][e][p].x);
		}
	}
	printf("%d\n",ans);
}


int main(void){
	/*
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	*/
	pri[1] = 1;
	for(int e=2;e<NMAX;e++){
		if(pri[e]==0){
			pri[e] = e;
			for(int p=e*2;p<NMAX;p+=e){
				int cnt = 0,org = p;
				while(org%e==0){
					org/=e;
					cnt++;
				}
				if(pri[p]==0) pri[p] = 1;
				if(cnt%2) pri[p] *= e;
			}
		}
	}
	int tc = 1;
	
		cin >> tc;
	
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}