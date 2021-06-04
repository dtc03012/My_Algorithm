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
const int MAX = 202020;
vector<int> v[MAX];
int arr[MAX],vis[MAX],sz[MAX],tt[MAX];
void solve(int tc){
	int n;
	scanf("%d",&n);
	for(int e=0;e<n-1;e++){
		int a,b;
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for(int e=1;e<=n;e++) scanf("%d",&arr[e]);
	queue<int> q;
	q.push(1);
	vis[1] = 1;
	sz[1] = 1;
	while(!q.empty()){
		int x = q.front();q.pop();
		for(int e=0;e<sz(v[x]);e++){
			int nx = v[x][e];
			if(vis[nx]==0){
				vis[nx] = vis[x] + 1;
				sz[vis[nx]]++;
				q.push(nx);
			}
		}
	}
	bool suc = true;
	int st = 1,st2 = 1;
	tt[1] = 1;
	for(int e=1;e<=n;e++){
		if(sz[vis[arr[e]]-1]){
			suc = false;
			break;
		}
		if(vis[arr[e]]!=vis[arr[e-1]]){
			st = 1;
			st2 = 1;
		}
		else{
			st++;
			st2 += sz(v[arr[e-1]]) - 1;
		}
		if(tt[arr[e]]>st){
			suc = false;
			break;
		}
		sz[vis[arr[e]]]--;
		for(int p=0;p<sz(v[arr[e]]);p++){
			if(tt[v[arr[e]][p]]==0){
				tt[v[arr[e]][p]] = st2;
			}
		}
	}
	if(suc) printf("Yes\n");
	else printf("No\n");
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