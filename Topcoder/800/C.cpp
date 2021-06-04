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

class PoisonedSwamp{
public:
	int vis[22][22][11];
	string cross(vector <string> swamp){
		int n = sz(swamp);
		int m = sz(swamp[0]);
		memset(vis,0,sizeof(vis));
		queue<pair<int,pi> > q;
		q.push(mk(0,mk(0,0)));
		while(!q.empty()){
			int dmg = q.front().x;
			int y = q.front().y.x;
			int x = q.front().y.y;
			vis[y][x][dmg] = 1;
			q.pop();
			for(int p=0;p<4;p++){
				int nx = x + dx[p];
				int ny = y + dy[p];
				if(isrange(ny,nx,n,m)&&swamp[ny][nx]!='#'){
					int ndmg = dmg;
					if(swamp[ny][nx]=='S') ndmg = 0;
					else if(swamp[ny][nx]>='0'&&swamp[ny][nx]<='9'){
						ndmg += swamp[ny][nx] - '0';
						if(ndmg<10&&vis[ny][nx][ndmg]==0){
							vis[ny][nx][ndmg] = 1;
							q.push(mk(ndmg,mk(ny,nx)));
						}
					}
				}
			}
		}
		bool suc = false;
		for(int e=0;e<10;e++){
			if(vis[n-1][m-1][e]) suc = true;
		}
		if(suc){
			return "possible";
		}else{
			return "impossible";
		}
	}
};
void solve(int tc){
	
}


int main(void){
	/*
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	*/
	int tc = 1;
	/*
		scanf("%d",&tc);
	*/
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}