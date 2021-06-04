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

const int MAX = 303030;
set<pli> s[MAX];
int uf[MAX];
lld ton[MAX];
int find(int x){
	if(uf[x]!=x) return uf[x] = find(uf[x]);
	return x;
}
void solve(int tc){
	int n,m,k;
	cin >> n >> m >> k;
	lld tot = 0;
	for(int e=1;e<=n;e++){
		uf[e] = e;
		cin >> ton[e];
		tot += ton[e];
	}
	priority_queue<pair<pli,pi> > q;
	for(int e=1;e<=m;e++){
		int a,b;
		cin >> a >> b;
		q.push(mk(mk(ton[a]+ton[b],e),mk(a,b)));
	}
	vector<int> ans;
	while(!q.empty()){
		lld dist = q.top().x.x;
		int pos = q.top().x.y;
		int a = q.top().y.x;
		int b = q.top().y.y;
		int x = find(a);
		int y = find(b);
		q.pop();
		if(x==y) continue;
		else{
			uf[x] = y;
			ans.push_back(pos);
		}
	}
	if(tot>=1ll*(n-1)*k){
		cout << "YES\n";
		for(int e=0;e<sz(ans);e++) cout <<ans[e] << "\n";
	}else{
		cout << "NO\n";
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