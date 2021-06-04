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
int arr[MAX];
struct inf{
	int a,b,c,d;
};
void solve(int tc){
	int n;
	cin >> n;
	for(int e=1;e<=n;e++) cin >> arr[e];
	if(n==1){
		cout << "0\n";
	}else{
		vector<inf> v;
		for(int p=1;p<=n;p+=2){
			if(p==n) break;
			int xx = min(arr[p],arr[p+1]);
			v.push_back({p,p+1,xx,xx});
			arr[p] = xx;
			arr[p+1] = xx;
		}
		for(int p=2;p<=n;p+=2){
			if(p==n){
				if(__gcd(arr[p],arr[p-1])!=1){
					v.push_back({p-1,p,arr[p],arr[p]+1});
				}
				break;
			}
			int f1 = arr[p];
			int f2 = arr[p+1];
			int st = min(f1,f2);
			while(true){
				if(__gcd(f1,st)==1&&__gcd(f2,st)==1) break;
				st++;
			}
			if(f1<f2){
				v.push_back({p-1,p,f1,st});
			}else{
				v.push_back({p,p+1,st,f2});
			}
		}
		cout << sz(v) << "\n";
		for(int e=0;e<sz(v);e++) cout << v[e].a << " " << v[e].b << " " << v[e].c << " " << v[e].d << "\n";
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