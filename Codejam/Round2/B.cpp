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

const int MAX = 1010101;
vector<int> prime[MAX];
void solve(int tc){
	int N;
	cin >> N;
	int tot = 0;
	queue<pi> q;
	q.push(mk(N,0));
	while(!q.empty()){ 
		int x = q.front().x;
		int y = q.front().y;
		q.pop();
		tot = max(tot,y+1);
		for(int e=0;e<sz(prime[x]);e++){
			int nx = x / prime[x][e];
			nx--;
			if(y==0&&prime[x][e]==2) continue;
			if(nx>1){
 				q.push(mk(nx,y+1));
			}
		}
	}
	cout << "Case #" << tc << ": " << tot << "\n";
}

void init(){
	for(int p=2;p<MAX;p++){
		for(int q=p*2;q<MAX;q+=p){
			prime[q].push_back(p);
		}
	}
}
int main(void){
	init();
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