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

const int MAX = 6;
int Row[MAX],Col[MAX],n,m,Rx[MAX],Cx[MAX],Ry[MAX],Cy[MAX],vis[MAX][MAX];
bool dfs(int y,int x){
	if(y==n){
		cout << "POSSIBLE\n";
		for(int e=0;e<n;e++){
			for(int p=0;p<m;p++){
				if(vis[e][p]==0){
					cout << '/';
				}else{
					cout << '\\';
				}
			}
			cout << "\n";
		}
		return true;
	}
	int ny = y;
	int nx = x + 1;
	if(nx==m){
		nx = 0;
		ny++;
	}
	if(Rx[y]&&Cx[x]){
		bool flag = false;
		for(int p=1;p<=3;p++){
			bool flag2 = true;
			vis[y][x] = 0;
			for(int q=0;q<p;q++){
				if(x+q>=m||y-q<0) flag2 = false;
				else{
					if(vis[y-q][x+q]==1) flag2 = false;
				}
			}
			for(int q=1;q<=p;q++){
				if(x-q<0||y-q+1<0) flag2 = false;
				else{
					if(vis[y-q+1][x-q]==0) flag2 = false;
				}
			}
			for(int q=1;q<=p;q++){
				if(x-q<0||y-(p*2)+q<0) flag2 = false;
				else{
					if(vis[y-(p*2)+q][x-q]==1) flag2 = false;
				}
			}
			for(int q=0;q<=p;q++){
				if(x+q>=m||y-(p*2)+q+1<0) flag2 = false;
				else{
					if(vis[y-(p*2)+q+1][x+q]==0) flag2 = false;
				}
			}
			if(flag2) flag = true;
		}
		if(!flag){
			Rx[y]--;
			Cx[x]--;
			vis[y][x] = 0;
			bool xx = dfs(ny,nx);
			if(xx) return true;
			Rx[y]++;
			Cx[x]++;
		}
	}
	if(Ry[y]&&Cy[x]){
		Ry[y]--;
		Cy[x]--;
		vis[y][x] = 1;
		bool xx = dfs(ny,nx);
		if(xx) return true;
		Ry[y]++;
		Cy[x]++;
	}
	return false;
}
void solve(int tc){
	memset(Rx,0,sizeof(Rx));
	memset(Ry,0,sizeof(Ry));
	memset(Cx,0,sizeof(Cx));
	memset(Cy,0,sizeof(Cy));
	cin >> n >> m;
	for(int e=0;e<n;e++){
		cin >> Row[e];
		Rx[e] = Row[e];
		Ry[e] = m - Row[e];
	}
	for(int e=0;e<m;e++){
		cin >> Col[e];
		Cx[e] = Col[e];
		Cy[e] = n - Col[e];
	}
	cout << "Case #"<<tc<< ": ";
	bool flag = dfs(0,0);
	if(!flag){
		cout << "IMPOSSIBLE\n";
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