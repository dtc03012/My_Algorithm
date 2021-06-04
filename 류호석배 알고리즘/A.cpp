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
vector<pi> v[MAX];
bool comp(pi a,pi b){
	return a.y < b.y;
}
void solve(int tc){
	int n,c;
	cin >> n >> c;
	for(int e=0;e<n;e++){
		int x,y,k;
		cin >> x >> y >> k;
		v[x].push_back(mk(y,k));
	}
	for(int e=0;e<MAX;e++) sort(all(v[e]),comp);
	lld ans = 0,tot = 0;
	int rmax = MAX-1;
	priority_queue<pi> q;
	for(int e=0;e<MAX;e++){
		for(int p=0;p<sz(v[e]);p++){
			if(v[e][p].x<=rmax){
				q.push(mk(v[e][p].x,v[e][p].y));
				tot += v[e][p].y;
			}
		}
		while(!q.empty()){
			int yy = q.top().x;
			int val = q.top().y;
			if(sz(q)>c){
				q.pop();
				rmax = yy - 1;
				tot -= val;
			}else if(yy>rmax){
				q.pop();
				tot -= val;
			}else{
				break;
			}
		}
		ans = max(ans,tot);
	}
	cout << ans << "\n";
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