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
const int SIZE = 6006;
const int MDIST = 100;
struct Building{
	int x,y,l,r,pos;
};
struct Antena{
	int r,c,pos;
};
struct Anspos{
	int pos,y,x;
};
bool compare_with_x(Building& A,Building B){
	return A.x < B.x;
}
bool compare_with_c(Antena& A,Antena& B){
	return A.c > B.c;
}
map<int,int> cnt[SIZE][SIZE];
unsigned int cnt[MDIST][SIZE][SIZE],have[SIZE][SIZE],check[SIZE][SIZE];
vector<Antena> dist[222];
vector<Anspos> ansv;
vector<pair<int,pi> > distB;
Building arrb[NMAX];
Antena arra[MMAX];
void solve(int tc){
	freopen("data_scenarios_d_polynesia.in","r",stdin);
	freopen("d_output.txt","w",stdout);
	int w,h;
	cin >> h >> w;
	int n,m,r;
	cin >> n >> m >> r;
	for(int e=0;e<n;e++){
		int x,y,l,c;
		cin >> y >> x >> l >> c;
		arrb[e] = {x,y,l,c,e};
		x++;y++;
		have[y][x] = c;
	}
	for(int e=1;e<=w;e++){
		for(int p=1;p<=h;p++){
			cnt[1][e][p] = cnt[0][e][p] = have[e][p];
		}
	}
	for(int r=2;r<MDIST;r++){
		for(int e=1;e<=w;e++){
			for(int p=1;p<=h;p++){
				if(r%2==0){
					int ans = cnt[r/2][e][max(0,p-(r/2))] + cnt[(r/2)][e][min(w,p+(r/2))];
					ans += cnt[r/2][min(h,e+(r/2))][p] + cnt[r/2][max(0,e-(r/2))][p];
					cnt[r][e][p] = ans;
				}else{
					int ans = cnt[(r-1)/2][e][max(0,p-1-(r-1)/2)] + cnt[(r-1)/2][e][min(w,p+1+(r-1)/2)];
					ans += cnt[(r-1)/2][min(h,e+1+(r-1)/2)][p] + cnt[(r-1)/2][max(0,e-1-(r-1)/2)][p];
					cnt[r][e][p] = ans;
				}
			}
		}
	}
	for(int e=0;e<m;e++){
		int r,c;
		cin >> r >> c;
		arra[e] = {r,c,e};
		dist[r].push_back(arra[e]);
	}
	for(int r=200;r>=0;r--){
		if(sz(dist[r])==0) continue;
		sort(all(dist[r]),compare_with_c);
		distB.clear();
		for(int e=1;e<=h;e++){
			for(int p=1;p<=w;p++){
				if(check[e][p]==0){
					distB.push_back(mk(cnt[r][e][p],mk(e,p)));
				}
			}
		}
		sort(all(distB));
		int last = 0;
		for(int q=sz(distB)-1;q>=0;q--){
			int X = distB[q].y.y , Y = distB[q].y.x;
			int pos = dist[r][last].pos;
			last++;
			ansv.push_back({pos,Y,X});
			check[Y][X] = 1;
			if(last==sz(dist[r])) break;
		}
	}
	cout << sz(ansv) << "\n";
	for(int e=0;e<sz(ansv);e++) cout << ansv[e].pos << " " << ansv[e].y-1 << " " << ansv[e].x-1 << "\n";
}


int main(void){
	
	// ios_base :: sync_with_stdio(false);
	// cin.tie(NULL);
	// cout.tie(NULL);
	
	int tc = 1;
	/*
		cin >> tc;
	*/
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}