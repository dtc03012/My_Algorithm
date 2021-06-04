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

const int NMAX = 100;
const int MMAX = 10000;
string arr[NMAX];
void solve(int tc,int p){
	int mx = -1;
	if(p==10){
		vector<int> k;
		for(int e=0;e<NMAX;e++){
			cin >> arr[e];
			int tot = 0;
			for(int p=0;p<MMAX;p++){
				if(arr[e][p]=='1') tot++;
			}
			mx = max(mx,tot);
		}
		for(int e=0;e<NMAX;e++){
			int tot = 0;
			for(int p=0;p<MMAX;p++){
				if(arr[e][p]=='1') tot++;
			}
			if(mx==tot) k.push_back(e);
		}
		cout << "Case #" << tc << ": " << k[0] + 1 << endl;
	}else{
		int mx = 0;
		for(int e=0;e<NMAX;e++){
			cin >> arr[e];
			int tot1 = 0,mx1 = 0;
			for(int p=0;p<MMAX;p++){
				if(arr[e][p]=='1'){
					tot1++;
				}else{
					mx1 = max(mx1,tot1);
					tot1 = 0;
				}
			} 
			mx1 = max(mx1,tot1);
			mx = max(mx,mx1);
		}
		int wh = -1;
		for(int e=0;e<NMAX;e++){
			int tot1 = 0,mx1 = 0;
			for(int p=0;p<MMAX;p++){
				if(arr[e][p]=='1'){
					tot1++;
				}else{
					mx1 = max(mx1,tot1);
					tot1 = 0;
				}
			}
			mx1 = max(mx1,tot1);
			if(mx1==mx) wh = e;
		}
		cout << "Case #" << tc << ": " << wh + 1 << endl;
	}
}


int main(void){
	freopen("E_input.txt","r",stdin);
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int tc = 1,p;
	
		cin >> tc >> p ;
	
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number,p);
	}
	return 0;
}