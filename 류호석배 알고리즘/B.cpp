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
int go[MAX][MAX];
void solve(int tc){
	int n,m;
	cin >> n >> m;
	for(int e=1;e<=n;e++) for(int p=1;p<=n;p++) go[e][p] = 1e9;
	for(int e=0;e<m;e++){
		int a,b;
		cin >> a >> b;
		go[a][b] = 1;
		go[b][a] = 1;
	}
	for(int e=1;e<=n;e++) go[e][e] = 0;
	for(int p=1;p<=n;p++){
		for(int e=1;e<=n;e++){
			for(int r=1;r<=n;r++){
				go[e][r] = min(go[e][r],go[e][p]+go[p][r]);
			}
		}
	}
	int ans = 1e9,x,y;
	for(int e=1;e<=n;e++){
		for(int p=1;p<=n;p++){
			if(e==p) continue;
			int tot = 0;
			for(int r=1;r<=n;r++){
				tot += min(go[e][r]*2,go[p][r]*2);
			}
			if(ans>tot){
				ans = tot;
				x = min(e,p);
				y = max(e,p);
			}else if(ans==tot){
				if(x>min(e,p)){
					x = min(e,p);
					y = max(e,p);
				}else if(x==min(e,p)&&y>max(e,p)){
					x = min(e,p);
					y = max(e,p);
				}
			}
		}
	}
	cout << x << " " << y << " " << ans << "\n";
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