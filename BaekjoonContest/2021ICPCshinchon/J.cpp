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

pi query(int x,int y){
	cout << "? A " << x << endl;
	int f,s;
	cin >> f;
	cout << "? B " << y << endl;
	cin >> s;
	return mk(f,s);
}
void ans(int x){
	cout << "! " << x << endl;
	exit(0);
}
void dfs(int fl,int fr,int sl,int sr){
	if(fl==fr){
		pi xx = query(fl,sl);
		ans(min(xx.x,xx.y));
	}
	int fmid = (fl+fr)/2;
	int smid = (sl+sr)/2;
	pi xx = query(fmid,smid);
	if(xx.x==xx.y){
		ans(xx.x);
	}
	if(xx.x<xx.y) dfs(fmid+1,fr,sl,smid);
	else dfs(fl,fmid,smid+1,sr);
}
void solve(int tc){
	int n;
	cin >> n;
	dfs(1,n,1,n);
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