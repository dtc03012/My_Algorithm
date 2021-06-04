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
int arr[MAX],ck[MAX*30],prime[MAX*30];
vector<int> v[MAX*30];
void solve(int tc){
	int n;
	cin >> n;
	for(int e=2;e<MAX*30;e++){
		if(prime[e]==0){
			for(int p=e;p<MAX*30;p+=e){
				prime[p] = 1;
				v[p].push_back(e);
			}
		}
	}
	for(int e=0;e<n;e++) cin >> arr[e];
	int up = 0,lx = 0;
	for(int e=0;e<n;e++){
		int st = arr[e];
		if(up) st = lx;
		while(true){
			bool suc = true;
			for(int q=0;q<sz(v[st]);q++){
				int nx = v[st][q];
				if(ck[nx]){
					suc = false;
					break;
				}
			}
			if(suc){
				cout << st << " ";
				for(int q=0;q<sz(v[st]);q++){
					int nx = v[st][q];
					ck[nx] = 1;
				}
				if(st>arr[e]&&up==0){
					up = 1;
					lx = 2;
				}else if(up){
					lx = st + 1;
				}
				break;
			}
			st++;
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