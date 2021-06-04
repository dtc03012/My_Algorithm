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


const int MAX = 111;
int vis[MAX][MAX],ck[MAX],ans[MAX][MAX],arr[MAX][MAX];
void solve(int tc){
	memset(vis,-1,sizeof(vis));
	memset(ck,-1,sizeof(ck));
	int n,m;
	cin >> n >> m;
	priority_queue<pair<int,pi> > q;
	for(int e=1;e<=n;e++){
		for(int p=1;p<=m;p++){
			int r;
			cin >> r;
			arr[e][p] = r;
			q.push(mk(-r,mk(e,p)));
		}
	}
	for(int e=1;e<=m;e++){
		pair<int,pi> xx = q.top();q.pop();
		int y = xx.y.x;
		int x = xx.y.y;
		vis[y][x] = e;
		ans[y][e] = -xx.x;
		ck[e] = y;
	}
	for(int p=1;p<=m;p++){
		for(int q=1;q<=n;q++){
			if(ck[p]==q) continue;
			for(int r=1;r<=m;r++){
				if(vis[q][r]==-1){
					vis[q][r] = p;
					ans[q][p] = arr[q][r];
					break;
				}
			}
		}
	}
	for(int e=1;e<=n;e++){
		for(int p=1;p<=m;p++) cout << ans[e][p] << " ";
		cout << "\n";
	}
}


int main(void){
	
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int tc = 1;
	
		cin >> tc;
	
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}