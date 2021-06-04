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
int uf[MAX];
lld dist[MAX];
set<int> s[MAX];
int find(int x){
	if(uf[x]!=x) return uf[x] = find(uf[x]);
	return x;
}
bool solve(int tc){
	int n,m;
	cin >> n >> m;
	if(n==0&&m==0) return false;
	for(int e=1;e<=n;e++){
		s[e].clear();
		uf[e] = e;
		s[e].insert(e);
		dist[e] = 0;
	}
	for(int e=0;e<m;e++){
		string k;
		int a,b;
		cin >> k >> a >> b;
		if(k[0]=='!'){
			int c;
			cin >> c;
			int ra = find(a);
			int rb = find(b);
			if(ra!=rb){
				lld tot = dist[b] - dist[a] - c;
				if(sz(s[ra])>sz(s[rb])){
					swap(ra,rb);
					tot *= -1;
				}
				for(auto x : s[ra]){
					dist[x] += tot;
					s[rb].insert(x);
				}
				uf[ra] = rb;
				s[ra].clear();
			}
		}else{
			int ra = find(a);
			int rb = find(b);
			if(ra!=rb){
				cout << "UNKNOWN" << "\n";
			}else{
				cout << dist[b] - dist[a] << "\n";
			}
		}
	}
	return true;
}


int main(void){
	
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	while(solve(1));
	return 0;
}