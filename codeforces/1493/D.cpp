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
const lld mod = 1e9 + 7;
set<pi> s[MAX];
map<int,int> num[MAX];
void solve(int tc){
	int n,q;
	scanf("%d%d",&n,&q);
	lld yy = 0;
	for(int e=1;e<=n;e++){
		int r;
		scanf("%d",&r);
		yy = __gcd(yy,(lld)r);
		int tmp = r;
		for(int p=2;p*p<=r;p++){
			if(tmp%p==0){
				int cnt = 0;
				while(tmp%p==0){
					tmp/=p;
					cnt++;
				}
				s[p].insert(mk(cnt,e));
				num[e][p] = cnt;
			}
		}
		if(tmp!=1){
			s[tmp].insert(mk(1,e));
			num[e][tmp] = 1;
		}
	}
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		int tmp = y;
		for(int p=2;p*p<=y;p++){
			if(tmp%p==0){
				int cnt = 0;
				while(tmp%p==0){
					tmp/=p;
					cnt++;
				}
				int rbg = 0;
				if(sz(s[p])==n) rbg = (*s[p].begin()).x;
				if(num[x].count(p)){
					int rcnt = num[x][p];
					s[p].erase(mk(rcnt,x));
					rcnt += cnt;
					num[x][p] = rcnt;
					s[p].insert(mk(rcnt,x));
				}else{
					s[p].insert(mk(cnt,x));
					num[x][p] = cnt;
				}
				if(sz(s[p])==n){
					int nbg = (*s[p].begin()).x;
					for(int q=rbg;q<nbg;q++) yy = (yy*p)%mod;
				}
			}
		}
		if(tmp!=1){
			int p = tmp;
			int rbg = 0;
			if(sz(s[p])==n) rbg = (*s[p].begin()).x;
			if(num[x].count(p)){
				int rcnt = num[x][p];
				s[p].erase(mk(rcnt,x));
				rcnt += 1;
				num[x][p] = rcnt;
				s[p].insert(mk(rcnt,x));
			}else{
				s[p].insert(mk(1,x));
				num[x][p] = 1;
			}
			if(sz(s[p])==n){
				int nbg = (*s[p].begin()).x;
				for(int q=rbg;q<nbg;q++) yy = (yy*p)%mod;
			}
		}
		printf("%lld\n",yy);
	}
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