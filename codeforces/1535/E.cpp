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
int par[MAX][20],dep[MAX];
pl arr[MAX];
int nearby(int x,int y){
	int dist = dep[x] - dep[y];
	if(dist==1) return x;
	dist--;
	for(int p=0;p<20;p++){
		if(dist&(1<<p)){
			x = par[x][p];
		}
	}
	return x;
}
void solve(int tc){
	memset(par,-1,sizeof(par));
	int q,a,c;
	cin >> q >> a >> c;
	arr[0] = mk(a,c);
	for(int id=1;id<=q;id++){
		int ty;
		cin >> ty;
		if(ty==1){
			int p,a,c;
			cin >> p >> a  >> c;
			arr[id] = mk(a,c);
			par[id][0] = p;
			for(int p=1;p<20;p++){
				if(par[id][p-1]!=-1){
					par[id][p] = par[par[id][p-1]][p-1];
				}
			}
			dep[id] = dep[p] + 1;
		}else{
			lld v,w,rw;
			cin >> v >> w;
			rw = w;
			lld ans = 0;
			int g = v;
			for(int p=19;p>=0;p--){
				if(par[g][p]!=-1){
					int nx = par[g][p];
					if(arr[nx].x){
						g = par[g][p];
					}
				}
			}
			while(true){
				if(w==0) break;
				if(arr[g].x<=w){
					w -= arr[g].x;
					ans += arr[g].x * arr[g].y;
					arr[g].x = 0;
					if(v==g) break;
					g = nearby(v,g);
				}else{
					ans += w * arr[g].y;
					arr[g].x -= w;
					w = 0;
					break;
				}
			}
			cout << rw - w  << " " << ans << endl;
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