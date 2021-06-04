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

const int NMAX = 350505;
const int MMAX = 60606;
const int SIZE = 6000;
struct Building{
	int x,y,l,c,pos;
};
struct Antena{
	int r,c,pos;
};
Building arrb[NMAX];
Antena arra[MMAX];
bool compare_with_x(Building& A,Building B){
	return A.x < B.x;
}
int cnt[SIZE][SIZE];
int what_num(int ry,int rx,int ly,int lx){
	return cnt[ry][rx] - cnt[ry][lx-1] - cnt[ly-1][rx] + cnt[ly-1][lx-1];
}
bool tmr1(Building& A,Building& B){
	return A.c > B.c;
}
bool tmr2(Antena& A,Antena& B){
	return A.c > B.c;
}
int can_get_antena(int y,int x,int dist){

}
void solve(int tc){
	freopen("data_scenarios_e_metropolis.in","r",stdin);
	freopen("c_output.txt","w",stdout);
	int w,h;
	cin >> w >> h;
	int n,m,r;
	cin >> n >> m >> r;
	for(int e=0;e<n;e++){
		int x,y,l,c;
		cin >> y >> x >> l >> c;
		arrb[e] = {x,y,l,c,e};
	}
	vector<int> vv;
	for(int e=0;e<m;e++){
		int r,c;
		cin >> r >> c;
		arra[e] = {r,c,e};
		vv.push_back(r);
	}
	sort(arrb,arrb+n,tmr1);
	sort(arra,arra+m,tmr2);
	cout << m << "\n";
	for(int e=0;e<m;e++){
		cout << arra[e].pos << " " << arrb[e].y << " " << arrb[e].x << "\n";
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