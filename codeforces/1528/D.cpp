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

const int MAX = 606;
vector<pil> v[MAX];
lld ans[MAX][MAX],val[MAX],have[MAX];
int n,m;
void dik(int st){
	for(int e=0;e<n;e++){
		val[e] = 1e18;
		have[e] = 0;
	}
	for(int e=0;e<sz(v[st]);e++){
		int nx = v[st][e].x;
		int dist = v[st][e].y;
		val[nx] = dist;
	}
	for(int e=0;e<=n;e++){
		int pos = -1;
		for(int p=0;p<n;p++){
			if(have[p]) continue;
			if(pos==-1) pos = p;
			else if(val[pos]>val[p]) pos = p;
		}
		if(pos==-1) break;
		have[pos] = 1;
		val[(pos+1)%n] = min(val[(pos+1)%n],val[pos]+1);
		for(int p=0;p<sz(v[pos]);p++){
			int nx = (val[pos]+v[pos][p].x)%n;
			lld dist = v[pos][p].y + val[pos];
			val[nx] = min(val[nx],dist);
		}
	}
	for(int p=0;p<n;p++) ans[st][p] = val[p];
	ans[st][st] = 0;
}
void solve(int tc){
	cin >> n >> m;
	for(int e=0;e<m;e++){
		int x,y,w;
		cin >> x >> y >> w;
		v[x].push_back(mk(y,w));
	}
	for(int e=0;e<n;e++){
		for(int p=0;p<n;p++){
			ans[e][p] = 1e18;
		}
	}
	for(int e=0;e<n;e++) dik(e);
	for(int e=0;e<n;e++){
		for(int p=0;p<n;p++) cout << ans[e][p] << " ";
		cout << "\n";
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