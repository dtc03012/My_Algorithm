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

const int MAX = 150505;
pil par[MAX][20];
void solve(int tc){
	memset(par,-1,sizeof(par));
	int q;
	int st = 1;
	cin >> q;
	lld lastans = 0;
	while(q--){
		string x;
		lld a,b;
		cin >> x >> a >> b;
		if(x[0]=='a'){
			lld lx = (a+lastans) % st;
			par[st][0] = mk(lx,b);
			lld now = st;
			for(int p=1;p<20;p++){
				if(par[now][p-1].x!=-1){
					par[now][p].x = par[par[now][p-1].x][p-1].x;
					par[now][p].y = par[par[now][p-1].x][p-1].y + par[now][p-1].y;
				}
			}
			st++;
		}else{
			lld now = a,dist = 0;
			for(int p=19;p>=0;p--){
				if(par[now][p].x!=-1&&par[now][p].y+dist<=b){
					dist += par[now][p].y;
					now = par[now][p].x;
				}
			}
			printf("%lld\n",now);
			lastans = now;
		}
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