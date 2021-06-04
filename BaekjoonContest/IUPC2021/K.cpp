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
int dy[4] = {1,0,-1,0},dx[4]={0,1,0,-1},ddy[8] = {1,0,-1,0,1,1,-1,-1},ddx[8] = {0,1,0,-1,1,-1,1,-1};

const int MAX = 55;
int go[MAX][MAX],n;
bool isrange(int y,int x){
	 if(0<=y&&y<MAX&&0<=x&&x<MAX) return true;
	 return false;
}
pi x1[8] = {mk(1,2),mk(2,1),mk(2,-1),mk(1,-2),mk(-1,-2),mk(-2,-1),mk(-2,1),mk(-1,2)}; 
void solve(int tc){
	scanf("%d",&n);
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	int x,y;
	scanf("%d%d",&x,&y);
	int m;
	scanf("%d",&m);
	pi g[4];
	for(int e=0;e<m;e++){
		scanf("%d%d",&g[e].x,&g[e].y);
	}
	int ans = 1e9;
	vector<int> vv;
	for(int e=0;e<m;e++) vv.push_back(e);
	do{
		int tot = 0;
		int yy = y,xx = x;
		for(int t1=0;t1<m;t1++){
			for(int e=0;e<MAX;e++) for(int p=0;p<MAX;p++) go[e][p] = 1e9;
			priority_queue<pair<int,pi> > q;
			q.push(mk(0,mk(yy,xx)));
			go[yy][xx] = 0;
			while(!q.empty()){
				int dist = -q.top().x;
				int y = q.top().y.x;
				int x = q.top().y.y;
				q.pop();
				if(n>=3){
					for(int e=0;e<8;e++){
						int ny = y + x1[e].y;
						int nx = x + x1[e].x;
						if(isrange(ny,nx)&&go[ny][nx]>dist+a){
							go[ny][nx] = dist + a;
							q.push(mk(-go[ny][nx],mk(ny,nx)));
						}
					}
				}
				for(int nx=x;nx<n;nx++){
					if(go[y][nx]>dist+c){
						go[y][nx] = dist+c;
						q.push(mk(-go[y][nx],mk(y,nx)));
					}
				}
				for(int nx=x;nx>=0;nx--){
					if(go[y][nx]>dist+c){
						go[y][nx] = dist+c;
						q.push(mk(-go[y][nx],mk(y,nx)));
					}
				}
				for(int ny=y;ny<n;ny++){
					if(go[ny][x]>dist+c){
						go[ny][x] = dist+c;
						q.push(mk(-go[ny][x],mk(ny,x)));
					}
				}
				for(int ny=y;ny>=0;ny--){
					if(go[ny][x]>dist+c){
						go[ny][x] = dist+c;
						q.push(mk(-go[ny][x],mk(ny,x)));
					}
				}
				for(int nx=x,ny=y;nx<n&&ny<n;nx++,ny++){
					if(go[ny][nx]>dist+b){
						go[ny][nx] = dist + b;
						q.push(mk(-go[ny][nx],mk(ny,nx)));
					}
				}
				for(int nx=x,ny=y;nx<n&&ny>=0;nx++,ny--){
					if(go[ny][nx]>dist+b){
						go[ny][nx] = dist + b;
						q.push(mk(-go[ny][nx],mk(ny,nx)));
					}
				}
				for(int nx=x,ny=y;nx>=0&&ny<n;nx--,ny++){
					if(go[ny][nx]>dist+b){
						go[ny][nx] = dist + b;
						q.push(mk(-go[ny][nx],mk(ny,nx)));
					}
				}
				for(int nx=x,ny=y;nx>=0&&ny>=0;nx--,ny--){
					if(go[ny][nx]>dist+b){
						go[ny][nx] = dist + b;
						q.push(mk(-go[ny][nx],mk(ny,nx)));
					}
				}
			}
			tot += go[g[vv[t1]].y][g[vv[t1]].x];
			xx = g[vv[t1]].x;
			yy = g[vv[t1]].y;
		}
		ans = min(ans,tot);
	}while(next_permutation(all(vv)));
	printf("%d",ans);
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