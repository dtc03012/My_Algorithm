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
int vis[MAX],ck[26];
vector<pair<char,char> > v;
void solve(int tc){
	int n,m;
	string a;
	cin >> n >> m >> a;
	for(int e=0;e<m;e++){
		string a,b;
		cin >> a >> b;
		v.push_back(mk(a[0],b[0]));
	}
	int ll = 1,rr = n,mid,ansL = 0;
	while(ll<=rr){
		 mid = (ll+rr)/2;
		 int xx = mid - 1;
		 for(int e=0;e<m;e++){
		 	if(xx==-1||xx==n) break;
		 	if(v[e].x==a[xx]){
		 		if(v[e].y=='R') xx++;
		 		else xx--;
		 	}
		 }
		 if(xx==-1){
		 	ll = mid + 1;
		 	ansL = max(ansL,mid);
		 }else{
		 	rr = mid - 1;
		 }
	}
	ll = 1;rr = n;
	int ansR = 0;
	while(ll<=rr){
		mid = (ll+rr)/2;
		int xx = n - mid;
		for(int e=0;e<m;e++){
			if(xx==n||xx==-1) break;
			if(v[e].x==a[xx]){
				if(v[e].y=='R') xx++;
				else xx--;
			}
		}
		if(xx==n){
			ll = mid + 1;
			ansR = max(ansR,mid);
		}else{
			rr = mid - 1;
		}
	}
	printf("%d\n",n-min(n,ansL+ansR));
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