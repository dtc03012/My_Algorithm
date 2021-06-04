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

const int MAX = 1010101;
int start = 1,seg[MAX*4];
void add(int x,int v){
	x += start;
	seg[x] = v;
	for(int e=(x/2);e>=1;e/=2) seg[e] = min(seg[e*2],seg[e*2+1]);
}
vector<int> v,st[MAX];
void solve(int tc){
	while(start<MAX) start *= 2;
	int n,m;
	cin >> n >> m;
	for(int e=0;e<MAX*4;e++) seg[e] = 1e9;
	int tot = 0;
	for(int e=0;e<n;e++){
		int ty;
		cin >> ty;
		if(ty==3){
			if(tot!=m||m>MAX) cout << "-1\n";
			else cout << sz(v) - seg[1]  << "\n";
		}else if(ty==1){
			int r;
			cin >> r;
			if(m>MAX) continue;
			r %= m;
			add(r,sz(v));
			if(sz(st[r])==0) tot++;
			st[r].push_back(sz(v));
			v.push_back(r);
		}else{
			if(m>MAX) continue;
			if(sz(v)==0) continue;
			int r = v[sz(v)-1];
			st[r].pop_back();
			int xx = 1e9;
			if(sz(st[r])) xx = st[r][sz(st[r])-1];
			else tot--;
			add(r,xx);
			v.pop_back();
		}
	}
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