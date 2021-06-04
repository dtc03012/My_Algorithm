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

const int MAX = 5050;
vector<pil> v[MAX];
lld dfs(int x,int lx){
	lld xx = 0;
	for(int e=0;e<sz(v[x]);e++){
		int nx = v[x][e].x;
		int dist = v[x][e].y;
		if(nx!=lx){
			xx = max(xx,dist+dfs(nx,x));
		}
	}
	return xx;
}
void solve(int tc){
	int n;
	cin >> n;
	for(int e=0;e<n-1;e++){
		int a,b,c;
		cin >> a >> b >> c;
		v[a].push_back(mk(b,c));
		v[b].push_back(mk(a,c));
	}
	cout << dfs(1,-1);
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