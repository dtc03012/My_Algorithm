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
set<int> s[MAX];
int uf[MAX],pos[MAX];
int find(int x){
	if(uf[x]!=x) return uf[x] = find(uf[x]);
	return x;
}
void solve(int tc){
	int n,k;
	cin >> n >> k;
	for(int e=1;e<=n;e++){
		s[e].insert(e);
		uf[e] = e;
		pos[e] = e;
	}
	for(int e=1;e<=k;e++){
		int a,b;
		cin >> a >> b;
		s[pos[a]].insert(b);
		s[pos[b]].insert(a);
		swap(pos[a],pos[b]);
	}
	for(int e=1;e<=n;e++){
		int nx = pos[e];
		int f1 = find(e);
		int f2 = find(nx);
		if(f1!=f2){
			if(sz(s[f1])<sz(s[f2])){
				for(auto x : s[f1]) s[f2].insert(x);
				s[f1].clear();
				uf[f1] = f2;
			}else{
				for(auto x : s[f2]) s[f1].insert(x);
				s[f2].clear();
				uf[f2] = f1;
			}
		}
	}
	for(int e=1;e<=n;e++) cout << sz(s[find(e)]) << "\n";
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