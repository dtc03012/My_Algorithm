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

const int MAX = 101010;
int vv[18][MAX],n,m,org[MAX],pos[18],bit[(1<<18)][18];
vector<int> v[MAX];
void dik(int x){
	int wh = pos[x];
	for(int e=0;e<MAX;e++) vv[x][e] = -1;
	queue<int> q;
	vv[x][wh] = 0;
	q.push(wh);
	while(!q.empty()){
		int xx = q.front();q.pop();
		for(int p=0;p<sz(v[xx]);p++){
			int nx = v[xx][p];
			if(vv[x][nx]==-1){
				vv[x][nx] = vv[x][xx] + 1;
				q.push(nx);
			}
		}
	}
}
void solve(int tc){
	scanf("%d%d",&n,&m);
	for(int e=0;e<m;e++){
		int a,b;
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	int k;
	scanf("%d",&k);
	for(int e=0;e<(1<<k);e++) for(int p=0;p<k;p++) bit[e][p] = 1e9;
	for(int e=0;e<k;e++){
		int r;
		scanf("%d",&r);
		org[r] = e;
		pos[e] = r;
		dik(e);
		bit[(1<<e)][e] = 1;
	}
	for(int e=0;e<(1<<k);e++){
		for(int p=0;p<k;p++){
			if(e&(1<<p)){
				int xx = e^(1<<p);
				if(xx==0) continue;
				for(int q=0;q<k;q++){
					if(xx&(1<<q)){
						if(vv[q][pos[p]]!=-1){
							bit[e][p] = min(bit[e][p],bit[xx][q]+vv[q][pos[p]]);
						}
					}
				}
			}
		}
	}
	int ans = 1e9;
	for(int e=0;e<k;e++) ans = min(ans,bit[(1<<k)-1][e]);
	if(ans==(int)1e9) ans = -1;
	printf("%d\n",ans);
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