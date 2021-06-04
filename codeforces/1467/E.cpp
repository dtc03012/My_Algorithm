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
vector<int> v[MAX];
int n,col[MAX],cnt[MAX],ck[MAX];
bool can[MAX],ncan[MAX];
map<int,int> mm[MAX];
set<int> s;
map<int,int> kk;
vector<int> vv;
int num = 1,tot = 0;
void dfs(int x,int lx){
	bool suc = true;
	int cnt = 0;
	for(int e=0;e<sz(v[x]);e++){
		int nx = v[x][e];
		if(nx!=lx){
			dfs(nx,x);
			if(!ncan[nx]) suc = false;
			if(sz(mm[x])<sz(mm[nx])) swap(mm[x],mm[nx]);
			for(auto k : mm[nx]){
				mm[k->x] += k->y;
				if(mm[k->x]>1) cnt++;
			}
		}
	}
	if(cnt[col[x]]>1) suc = false;
	if(ck[col[x]]) mm[col[x]]++;
	if(suc){
		int ntot = 0;
		for(auto& k : mm[x])
	}
	else can[x] = false;
	if(cnt||!suc) ncan[x] = false;
}
void solve(int tc){
	scanf("%d",&n);
	for(int e=1;e<=n;e++){
		scanf("%d",&col[e]);
		s.insert(col[e]);
	}
	for(set<int>::iterator it = s.begin();it!=s.end();it++) kk[*it] = num++;
	for(int e=1;e<=n;e++){
		col[e] = kk[col[e]];
		cnt[col[e]]++;
	}
	for(int e=1;e<num;e++) if(cnt[e]>1){
		vv.push_back(e);
		ck[e] = 1;
		tot++;
	}
	for(int e=0;e<n-1;e++){
		int a,b;
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
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