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
int A[MAX],B[MAX],P[MAX],vis[MAX];
void solve(int tc){
	int n;
	scanf("%d",&n);
	for(int e=1;e<=n;e++) scanf("%d",&A[e]);
	for(int e=1;e<=n;e++) scanf("%d",&B[e]);
	for(int e=1;e<=n;e++) scanf("%d",&P[e]);
	bool suc = true;
	for(int e=1;e<=n;e++) if(P[e]!=e&&B[P[e]]>=A[e]) suc = false;
	if(!suc){
		printf("-1\n");
		return;
	}
	vector<pi> v;
	for(int e=1;e<=n;e++){
		if(e==P[e]) continue;
		if(vis[e]) continue;
		vector<int> g;
		int st = e;
		int mx = -1,wh = 0;
		while(true){
			vis[st] = 1;
			g.push_back(st);
			if(A[st]>mx){
				mx = A[st];
				wh = st;
			}
			st = P[st];
			if(st==e) break;
		}
		int now = wh;
		for(int e=0;e<sz(g);e++){
			if(g[e]==wh) continue;
			v.push_back(mk(now,P[now]));
			P[now] = P[P[now]];
		}
	}
	printf("%d\n",sz(v));
	for(int e=0;e<sz(v);e++) printf("%d %d\n",v[e].x,v[e].y);
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