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
struct inf{
	int l,r,z;
	inf(int l,int r,int z) : l(l),r(r),z(z){
	}
	inf() : inf(0,0,0){
	}
	bool operator<(const inf& a){
		if(l!=a.l) return l < a.l;
		return r < a.r;
	}
};
bool comp(const inf& a,const inf& b){
	if(a.l!=b.l) return a.l < b.l;
	return a.r < b.r;
}
vector<inf> v[MAX];
pi par[MAX];
int uf[MAX],go[MAX];
pi vv[MAX];
int find(int x){
	if(uf[x]!=x) return uf[x] = find(uf[x]);
	return x;
}
bool isin(int x,int y){
	if(sz(v[x])==0) return false;
	int wh = lower_bound(all(v[x]),inf(y+1,-1,-1),comp) - v[x].begin();
	if(wh==0) return false;
	wh--;
	if(y>=v[x][wh].l&&y<=v[x][wh].r) return true;
	return false;
}
void solve(int tc){
	int n;
	scanf("%d",&n);
	for(int e=0;e<MAX;e++) uf[e] = e;
	for(int e=2;e<=n+1;e++){
		int h,l,r;
		scanf("%d%d%d",&h,&l,&r);
		v[h].push_back({l,r,e});
		vv[e] = mk(l,r);
	}
	for(int e=1;e<=n;e++) sort(all(v[e]));
	int xx = 1;
	par[1] = mk(-1,0);
	go[0] = -1;
	for(int p=0;p<sz(v[1]);p++){
		par[v[1][p].z] = mk(1,xx);
		go[xx] = v[1][p].z;
		xx++;
	}
	for(int e=2;e<=n;e++){
		for(int p=0;p<sz(v[e]);p++){
			int wh = lower_bound(all(v[e-1]),inf(v[e][p].l+1,-1,-1),comp) - v[e-1].begin();
			wh--;
			int f1 = v[e-1][wh].z,f2 = v[e][p].z;
			par[f2] = mk(f1,xx);
			go[xx] = f2;
			xx++;
		}
	}
	int q;
	scanf("%d",&q);
	while(q--){
		int x,p;
		scanf("%d%d",&x,&p);
		int ll = 1,rr = n,mid,ans = 0;
		while(ll<=rr){
			mid = (ll+rr)/2;
			if(isin(mid,x)){
				ans = max(ans,mid);
				ll = mid + 1;
			}else rr = mid - 1;
		}
		if(ans==0){
			printf("0 ");
			continue;
		}
		int now = lower_bound(all(v[ans]),inf(x+1,-1,-1),comp) - v[ans].begin();
		now--;
		now = v[ans][now].z;
		int tot = 0;
		for(int e=0;e<p;e++){
			now = go[find(par[now].y)];
			if(now==-1) break;
			tot++;
			uf[par[now].y] = find(par[par[now].x].y);
		}
		printf("%d ",tot);
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