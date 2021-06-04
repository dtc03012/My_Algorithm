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

const int MAX = 1010;
set<int> v[MAX];
struct inf{
	int a,b,c,d;
};
int len[MAX];
int dist,where;
void dfs(int x,int lx,int val){
	if(val>dist){
		dist = val;
		where = x;
	}
	for(auto nx : v[x]){
		if(nx!=lx) dfs(nx,x,val+1);
	}
}
bool checking(){
	dist = 0;
	dfs(1,-1,0);
	dist = 0;
	dfs(where,-1,0);
	if(dist>4) return true;
	return false;
}
int ck[MAX],ck2[MAX];
void make(int x,int lx){
	int xx = 0;
	for(auto nx : v[x]){
		if(nx!=lx){
			make(nx,x);
			xx = 1;
		}
	}
	if(xx==0) ck[x] = 1;
	if(xx==1&&x==1) ck[x] = 1;
}
void make2(int x,int lx){
	int xx = 0;
	for(auto nx : v[x]){
		if(nx!=lx){
			make2(nx,x);
		}
	}
	if(ck[x]==0){
		for(auto nx : v[x]){
			if(nx!=lx){
				if(!ck[nx]) xx++;
			}
		}
		if(xx<=2) ck2[x] = 1;
	}
}
pi make3(int x,int lx){
	if(lx!=-1){
		if(ck2[x]&&ck2[lx]){
			return mk(x,lx);
		}
	}
	for(auto nx : v[x]){
		if(nx!=lx) {
			pi xx = make3(nx,x);
			if(xx.x!=-1) return xx;
		}
	}
	return mk(-1,-1);
}
void change(int a,int b,int c,int d){
	v[a].erase(b);
	v[b].erase(a);
	v[b].erase(c);
	v[c].erase(b);
	v[d].erase(c);
	v[c].erase(d);
	v[a].insert(d);
	v[d].insert(a);
	v[a].insert(c);
	v[c].insert(a);
	v[b].insert(d);
	v[d].insert(b);
}
void solve(int tc){
	int n;
	scanf("%d",&n);
	for(int e=0;e<n-1;e++){
		int a,b;
		scanf("%d%d",&a,&b);
		v[a].insert(b);
		v[b].insert(a);
	}
	vector<inf> ans;
	while(checking()){
		memset(ck,0,sizeof(ck));
		memset(ck2,0,sizeof(ck2));
		make(1,-1);
		make2(1,-1);
		pi xx = make3(1,-1);
		if(xx.x==-1){
			printf("-1");
			return;
		}
		int b = xx.x,c = xx.y;
		int a = -1,d = -1;
		for(auto nx : v[b]){
			if(nx!=c){
				if(ck[nx]==0) a = nx;
				if(a==-1) a = nx;
			}
		}
		for(auto nx : v[c]){
			if(nx!=b){
				if(ck[nx]==0) d = nx;
				if(d==-1) d = nx;
			}
		}
		ans.push_back({a,b,c,d});
		change(a,b,c,d);
	}
	printf("%d\n",sz(ans));
	for(int e=0;e<sz(ans);e++) printf("%d %d %d %d\n",ans[e].a,ans[e].b,ans[e].c,ans[e].d);
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