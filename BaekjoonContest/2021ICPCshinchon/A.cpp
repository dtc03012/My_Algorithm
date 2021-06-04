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

map<string,int> mm;
bool tmr(pair<string,int> a,pair<string,int> b){
	if(a.y!=b.y) return a.y > b.y;
	if(sz(a.x)!=sz(b.x)) return sz(a.x) > sz(b.x);
	return a.x < b.x;
}
void solve(int tc){
	int n,m;
	cin >> n >> m;
	for(int e=0;e<n;e++){
		string a;
		cin >> a;
		if(sz(a)>=m) mm[a]++;
	}
	vector<pair<string,int> > v;
	for(auto x : mm){
		v.push_back(mk(x.x,x.y));
	}
	sort(all(v),tmr);
	for(int e=0;e<sz(v);e++) cout << v[e].x << "\n";
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