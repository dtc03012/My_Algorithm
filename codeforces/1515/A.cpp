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

const int MAX = 111;
int arr[MAX];
void solve(int tc){
	int n,x;
	cin >> n >> x;
	int vv = 0;
	for(int e=0;e<n;e++){
		cin >> arr[e];
		vv += arr[e];
	}
	if(vv==x){
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	sort(arr,arr+n);
	if(arr[n-1]>x){
		cout << arr[n-1] << " ";
		for(int e=0;e<n-1;e++) cout << arr[e] << " ";
		cout << "\n";
	}else{
		int tot = 0;
		vector<int> v;
		for(int p=n-1;p>=0;p--){
			if(arr[p]+tot==x){
				v.push_back(arr[p]);
				continue;
			}else{
				cout << arr[p] << " ";
				tot += arr[p];
			}
		}
		for(int e=0;e<sz(v);e++) cout << v[e] << " ";
		cout << "\n";
	}
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