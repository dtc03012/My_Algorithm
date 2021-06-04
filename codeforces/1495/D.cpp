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

const int MAX = 404;
const lld mod = 998244353;
vector<int> v[MAX];
lld ans[MAX][MAX];
int vis[MAX][MAX],val[MAX][MAX],con[MAX][MAX];
int nvis1[MAX],nvis2[MAX];
struct inf{
	int x,f1,f2;
};
void solve(int tc){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int e=0;e<m;e++){
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
		con[x][y] = 1;
		con[y][x] = 1;
	}
	if(m==n-1){
		for(int e=1;e<=n;e++){
			for(int p=1;p<=n;p++) printf("1 ");
			printf("\n");
		}
		return;
	}
	for(int e=1;e<=n;e++){
		queue<int> q;
		q.push(e);
		vis[e][e] = 1;
		val[e][e] = 1;
		while(!q.empty()){
			int x = q.front();q.pop();
			for(int p=0;p<sz(v[x]);p++){
				int nx = v[x][p];
				if(vis[e][nx]==0){
					vis[e][nx] = 1;
					val[e][nx] = val[e][x] + 1;
					q.push(nx);
				}else if(val[e][nx]==val[e][x]+1) vis[e][nx]++;
			}
		}
		lld xx = 1;
		for(int p=1;p<=n;p++) xx = (xx*vis[e][p])%mod;
		ans[e][e] = xx;
	}
	for(int e=1;e<=n;e++){
		for(int p=e+1;p<=n;p++){
			memset(nvis1,0,sizeof(nvis1));
			queue<int> q;
			for(int r=1;r<=n;r++) if(val[e][r]+val[p][r]-1==val[e][p]){
				q.push(r);
				nvis1[r] = 1;
			}
			if(sz(q)>val[e][p]) continue;
			while(!q.empty()){
				int x = q.front();q.pop();
				for(int r=0;r<sz(v[x]);r++){
					int nx = v[x][r];
					if(val[e][nx]==val[e][x]+1&&val[p][nx]==val[p][x]+1){
						if(nvis1[nx]==0){
							q.push(nx);
						}
						nvis1[nx]++;
					}
				}
			}
			lld xx = 1;
			for(int p=1;p<=n;p++) xx = (xx*nvis1[p])%mod;
			ans[e][p] = xx;
			ans[p][e] = xx;
		}
	}
	for(int e=1;e<=n;e++){
		for(int p=1;p<=n;p++) printf("%lld ",ans[e][p]);
		printf("\n");
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
		cin >> tc;
	*/
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}