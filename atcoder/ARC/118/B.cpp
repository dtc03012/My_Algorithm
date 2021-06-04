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
lld arr[MAX];
void solve(int tc){
	lld k,n,m,tot = 0;
	cin >> k >> n >> m;
	vector<lld> v;
	for(int e=0;e<k;e++){
		lld r;
		cin >> r;
		arr[e] = r;
		r *= m;
		r /= n;
		v.push_back(r);
		tot += r;
	}
	lld diff = m - tot;
	priority_queue<pair<lld,int> > q;
	for(int e=0;e<sz(v);e++){
		lld xx = abs(n*v[e]-m*arr[e]);
		q.push(mk(xx,e));
	}
	for(int e=0;e<diff;e++){
		int wh = q.top().y;
		q.pop();
		v[wh]++;
	}
	for(int e=0;e<sz(v);e++) cout << v[e] << " ";
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