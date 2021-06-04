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
pl arr[MAX];
pl go[MAX][2];
int ret[MAX];
void solve(int tc){
	int n;
	scanf("%d",&n);
	for(int e=1;e<=n;e++){
		scanf("%lld%lld",&arr[e].x,&arr[e].y);
	}
	go[0][0] = mk(1,0);
	go[0][1] = mk(1,0);
	int m;
	scanf("%d",&m);
	for(int e=1;e<=m;e++){
		int ty;
		scanf("%d",&ty);
		ret[e] = ret[e-1];
		go[e][0] = go[e-1][0];
		go[e][1] = go[e-1][1];
		if(ty==1){
			if(ret[e]%2==0){
				go[e][0].x *= -1;
				go[e][0].y *= -1;
			}else{
				go[e][1].x *= -1;
				go[e][1].y *= -1;
			}
			ret[e]++;
		}else if(ty==2){
			if(ret[e]%2==0){
				go[e][1].x *= -1;
				go[e][1].y *= -1;
			}else{
				go[e][0].x *= -1;
				go[e][0].y *= -1;
			}
			ret[e]++;
		}else if((ty==3&&ret[e]%2==0)||(ty==4&&ret[e]%2)){
			lld p;
			scanf("%lld",&p);
			go[e][0].x *= -1;
			go[e][0].y = p*2 - go[e][0].y;
		}else{
			lld p;
			scanf("%lld",&p);
			go[e][1].x *= -1;
			go[e][1].y = p*2 - go[e][1].y;
		}
	}
	int q;
	scanf("%d",&q);
	while(q--){
		int a,b;
		scanf("%d%d",&a,&b);
		lld x = go[a][0].x*arr[b].x + go[a][0].y;
		lld y = go[a][1].x*arr[b].y + go[a][1].y;
		if(ret[a]%2) swap(x,y);
		printf("%lld %lld\n",x,y);
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
		scanf("%d",&tc);
	*/
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}