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

const int MAX = 555;
string arr[MAX];
void solve(int tc){
	int n,m;
	cin >> n >> m;
	for(int e=0;e<n;e++) cin >> arr[e];
	if(n==1){
		for(int p=0;p<m;p++) arr[0][p] = 'X';
		for(int e=0;e<n;e++) cout << arr[e] << '\n';
		return;
	}
	for(int e=0;e<n;e+=3){
		for(int p=0;p<m;p++) arr[e][p] = 'X';
	}
	for(int e=1;e<n;e+=3){
		int cnt = 0,wh = -1;
		for(int p=0;p<m;p++) if(arr[e][p]=='X'){
			wh = p;
			break;
		}
		if(wh!=-1){
			arr[e+1][wh] = 'X';
		}else{
			if(e+1<n){
				int wh = -1;
				for(int p=0;p<m;p++) if(arr[e+1][p]=='X'){
					wh = p;
					break;
				}
				if(wh==-1){
					arr[e][0] = 'X';
					arr[e+1][0] ='X';
				}else{
					arr[e][wh] = 'X';
				}
			}
		}
	}
	if(n%3==0){
		for(int p=0;p<m;p++){
			if(arr[n-2][p]=='X'){
				arr[n-1][p] = 'X';
			}else if(arr[n-1][p]=='X'){
				arr[n-2][p] = 'X';
			}
		}
	}
	for(int e=0;e<n;e++) cout << arr[e] << '\n';
}

int main(void){
	
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