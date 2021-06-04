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

const int MAX = 20202;
int uf[MAX*2];
map<string,int> mm;
int find(int x){
	if(uf[x]!=x) return uf[x] = find(uf[x]);
	return x;
}
void solve(int tc){
	int n;
	cin >> n;
	int cnt = 1;
	priority_queue<pair<int,pi> > q;
	for(int e=1;e<=n;e++){
		string a,b;
		int c;
		cin >> a >> b >> c;
		if(!mm.count(a)){
			mm[a] = cnt++;
		}
		if(!mm.count(b)){
			mm[b] = cnt++;
		}
		int a1 = mm[a];
		int a2 = mm[b];
		q.push(mk(-c,mk(a1,a2)));
	}
	for(int e=1;e<=cnt;e++) uf[e] = e;
	lld ans =0 ;
	while(!q.empty()){
		pair<int,pi> vv = q.top();q.pop();
		lld val = -vv.x;
		int x = vv.y.x;
		int y = vv.y.y;
		x = find(x);
		y = find(y);
		if(x!=y){
			ans += val;
			uf[x] = y;
		}
	}
	cout << ans << "\n";
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