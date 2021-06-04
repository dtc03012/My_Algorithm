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

const int MAX = 1010;
vector<pi> go[26];
vector<int> v[MAX*MAX];
int vis[MAX*MAX];
int can[MAX][MAX];
void solve(int tc){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int e=0;e<m;e++){
		int a,b;
		char c[2];
		scanf("%d%d%s",&a,&b,c);
		can[a][b] = 1;
		can[b][a] = 1;
		go[c[0]-'a'].push_back(mk(a,b));
	}
	for(int e=0;e<26;e++){
		for(int p=0;p<sz(go[e]);p++){
			for(int r=p+1;r<sz(go[e]);r++){
				int f[2],s[2];
				f[0] = go[e][p].x;
				f[1] = go[e][p].y;
				s[0] = go[e][r].x;
				s[1] = go[e][r].y;
				{
					int k1 = f[0]*MAX + s[0];
					int k2 = f[1]*MAX + s[1];
					v[k1].push_back(k2);
					v[k2].push_back(k1);
				}
				{
					int k1 = f[0]*MAX + s[1];
					int k2 = f[1]*MAX + s[0];
					v[k1].push_back(k2);
					v[k2].push_back(k1);
				}
			}
		}
	}
	queue<pi> q;
	q.push(mk(MAX+n,0));
	int ans = 1e9;
	while(!q.empty()){
		int x1 = q.front().x;
		int f1 = q.front().x/MAX;
		int f2 = q.front().x%MAX;
		int val = q.front().y;
		q.pop();
		vis[x1] = 1;
		if(f1==f2){
			ans = min(ans,val);
			continue;
		}
		if(can[f1][f2]){
			ans = min(ans,val+1);
			continue;
		}
		for(int e=0;e<sz(v[x1]);e++){
			int nx = v[x1][e];
			if(vis[nx]==0){
				vis[nx] = 1;
				q.push(mk(nx,val+2));
			}
		}
	}
	if(ans==1e9) ans = -1;
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
		cin >> tc;
	*/
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}