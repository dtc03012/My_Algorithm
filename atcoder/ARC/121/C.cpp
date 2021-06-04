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
int arr[MAX];
vector<int> v;
void f(int x){
	v.push_back(x);
	swap(arr[x],arr[x+1]);
}
void solve(int tc){
	v.clear();
	int n;
	cin >> n;
	for(int e=1;e<=n;e++) cin >> arr[e];
	int cnt = 1,flag = 0;
	for(int e=1;e<=n;e++){
		while(arr[e]!=e){
			int pos = -1;
			for(int p=e+1;p<=n;p++) if(arr[p]==e) pos = p;
			if((pos-1)%2==(cnt%2)){
				f(pos-1);
				cnt++;
			}else{
				if(pos-2<e){
					f(pos-2);
					f(pos-1);
					f(pos-2);
					f(pos-1);
					f(pos-2);
					cnt += 5;
				}else{
					f(pos-2);
					f(pos-1);
					cnt += 2;
				}
			}
		}
	}
	cout << sz(v) << "\n";
	for(int e=0;e<sz(v);e++) cout << v[e] << " ";
	cout << "\n";
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