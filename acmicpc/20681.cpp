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

const int MAX = 101010;
int val[MAX],ans[MAX],seg[MAX*4],start = 1;
vector<int> v[MAX];
vector<pi> que[MAX];
void add(int x,int v){
	x += start;
	seg[x] += v;
	for(int e=(x/2);e>=1;e/=2) seg[e] = seg[e*2] + seg[e*2+1];
}
int getn(int l,int r){
	l += start;
	r += start;
	int ans = 0;
	while(l<=r){
		if(l&1) ans += seg[l++];
		if(!(r&1)) ans += seg[r--];
		l >>= 1;
		r >>= 1;
	}
	return ans;
}
void solve(int tc){
	while(start<MAX) start *= 2;
	int n,m;
	scanf("%d%d",&n,&m);
	for(int e=1;e<=n;e++) scanf("%d",&val[e]);
	for(int e=2;e<=n;e++){
		int r;
		scanf("%d",&r);
		v[r].push_back(e);
	}
	for(int e=0;e<m;e++){
		int l,r;
		scanf("%d%d",&l,&r);
		que[l].push_back(mk(r,e));
	}
	for(int e=n;e>=1;e--){
		int xx = 0;
		for(int p=0;p<sz(v[e]);p++){
			int vv = getn(v[e][p],v[e][p]);
			add(v[e][p],-vv);
			xx += vv;
		}
		xx += val[e];
		add(e,xx);
		for(int q=0;q<sz(que[e]);q++){
			int r = que[e][q].x;
			int pos = que[e][q].y;
			ans[pos] = getn(e,r);
		}
	}
	for(int e=0;e<m;e++) printf("%d\n",ans[e]);
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