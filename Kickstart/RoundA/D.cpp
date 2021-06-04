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

const int MAX = 505;
int arr[MAX][MAX],cost[MAX][MAX],uf[MAX*2];
int find(int x){
	if(uf[x]!=x) return uf[x] = find(uf[x]);
	return x;
}
void solve(int tc){
	int n;
	cin >> n;
	for(int e=0;e<n;e++){
		for(int p=0;p<n;p++){
			cin >> arr[e][p];
		}
	}
	for(int e=0;e<n;e++){
		for(int p=0;p<n;p++){
			cin >> cost[e][p];
		}
	}
	for(int e=0;e<n;e++){
		int r;
		cin >> r;
	}
	for(int e=0;e<n;e++){
		int r;
		cin >> r;
	}
	for(int e=0;e<n*2;e++){
		uf[e] = e;
	}
	priority_queue<pair<int,pi> > q;
	lld ans = 0;
	for(int e=0;e<n;e++){
		for(int p=0;p<n;p++){
			if(arr[e][p]==-1){
				int f1 = e;
				int f2 = n + p;
				ans += cost[e][p];
				q.push(mk(cost[e][p],mk(f1,f2)));
			}
		}
	}
	while(!q.empty()){
		int vv = q.top().x;
		int y = q.top().y.x;
		int x = q.top().y.y;
		q.pop();
		y = find(y);
		x = find(x);
		if(x!=y){
			ans -= vv;
			uf[y] = x;
		}
	}
	cout << "Case #" << tc << ": " << ans << "\n";
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