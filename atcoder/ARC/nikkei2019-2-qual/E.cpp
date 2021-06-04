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
	int x,y,z,d;
};
void solve(int tc){
	int n,k;
	scanf("%d%d",&n,&k);
	if(n<k) printf("-1\n");
	else{
		vector<inf> v;
		set<int> s;
		int lx = k+((n-1)/2),rx = k + 2*n - 1,tt = k + 3*n - 1;
		for(int e=k;e<k+2*n;e++) s.insert(e);
		while(lx+rx<=tt){
			s.erase(lx);
			s.erase(rx);
			v.push_back({lx,rx,tt,tt-lx-rx});
			lx++;
			rx--;
			tt--;
		}
		vector<int> k1;
		for(auto x : s) k1.push_back(x);
		int lv = 0,rv = sz(k1)-1,rt = k+2*n;
		while(lv<=rv){
			v.push_back({k1[lv++],k1[rv--],rt++});
		}
		bool suc = true;
		for(int e=0;e<sz(v);e++) if(v[e].x+v[e].y>v[e].z) suc = false;
		if(suc){
			for(int e=0;e<sz(v);e++) printf("%d %d %d\n",v[e].x,v[e].y,v[e].z);
		}else{
			printf("-1");
		}
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