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

struct inf{
	int x,y,z;
	bool operator<(const inf& O){
		return y < O.y;
	}
};
const int MAX = 50505;
const int NMAX = 55;
int ck[MAX],pos[NMAX];
void solve(int tc){
	int n;
	scanf("%d",&n);
	vector<inf> v;
	for(int e=1;e<=n;e++){
		int st = 1;
		while(true){
			int r;
			scanf("%d",&r);
			if(r==0) break;
			v.push_back({e,r,st++});
		}
	}
	sort(all(v));
	map<pi,int> vm;
	while(true){
		vm.clear();
		bool suc = false;
		for(int e=1;e<=n;e++) pos[e] = e;
		for(int e=0;e<sz(v);e++){
			if(ck[e]) continue;
			int a = pos[v[e].x];
			int b = pos[v[e].x+1];
			if(vm.count(mk(b,a))){
				suc = true;
				int f2 = vm[mk(b,a)];
				ck[e] = 1;
				ck[f2] = 1;
				break;
			}
			swap(pos[v[e].x],pos[v[e].x+1]);
			vm[mk(a,b)] = e;
		}
		if(!suc) break;
	}
	vector<pi> ans;
	for(int e=0;e<sz(v);e++) if(ck[e]==0){
		ans.push_back(mk(v[e].x,v[e].z));
	}
	printf("%d\n",sz(ans));
	for(int e=0;e<sz(ans);e++) printf("%d %d\n",ans[e].x,ans[e].y);
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