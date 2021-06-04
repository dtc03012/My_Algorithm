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
	 if(1<=y&&y<=n&&1<=x&&x<=m) return true;
	 return false;
}
int dy[4] = {1,0,-1,0},dx[4]={0,1,0,-1},ddy[8] = {1,0,-1,0,1,1,-1,-1},ddx[8] = {0,1,0,-1,1,-1,1,-1};

const int MAX = 505;
int yy[MAX][MAX],xx[MAX][MAX];
lld cnt[MAX][MAX][22];
void solve(int tc){
	for(int e=0;e<MAX;e++){
		for(int p=0;p<MAX;p++){
			for(int q=1;q<22;q++) cnt[e][p][q] = 1e18;
		}
	}
	int n,m,k;
	cin >> n >> m >> k;
	priority_queue<pair<int,pair<pi,pi> > > q;
	for(int e=1;e<=n;e++){
		for(int p=1;p<n;p++){
			cin >> yy[e][p];
			q.push(mk(-yy[e][p],mk(mk(e,p),mk(e,p+1))));
		}
	}
	for(int e=1;e<n;e++){
		for(int p=1;p<=m;p++){
			cin >> xx[e][p];
			q.push(mk(-xx[e][p],mk(mk(e,p),mk(e+1,p))));
		}
	}
	if(k%2){
		for(int e=1;e<=n;e++){
			for(int p=1;p<=m;p++) cout << "-1 ";
			cout << "\n";
		}
		return;
	}
	while(!q.empty()){
		int dist = -q.top().x;
		int y1 = q.top().y.x.x;
		int x1 = q.top().y.x.y;
		int y2 = q.top().y.y.x;
		int x2 = q.top().y.y.y;
		q.pop();
		for(int q=2;q<=k;q+=2){
			for(int r=0;r<=q-2;r+=2){
				cnt[y1][x1][q] = min(cnt[y1][x1][q],cnt[y2][x2][r]+(q-r)*dist);
				cnt[y1][x1][q] = min(cnt[y1][x1][q],cnt[y1][x1][r]+cnt[y1][x1][q-r]);
			}
		}
		for(int q=2;q<=k;q+=2){
			for(int r=0;r<=q-2;r+=2){
				cnt[y2][x2][q] = min(cnt[y2][x2][q],cnt[y1][x1][r]+(q-r)*dist);
				cnt[y2][x2][q] = min(cnt[y2][x2][q],cnt[y2][x2][r]+cnt[y2][x2][q-r]);
			}
		}
	}
	for(int e=1;e<=n;e++){
		if(cnt[e][p][k]==1e18) cnt[e][p][k] = -1;
		for(int p=1;p<=m;p++) cout << cnt[e][p][k] << " ";
		cout << "\n";
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
		cin >> tc;
	*/
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}