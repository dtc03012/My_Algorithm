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

const int MAX = 100100;
int ck[MAX];
vector<lld> v;
void solve(int tc){
	int n;
	scanf("%d",&n);
	int ll = 0,rr = sz(v) - 1,mid,ans = sz(v) - 1;
	while(ll<=rr){
		mid = (ll+rr)/2;
		if(v[mid]-1>=n){
			ans = min(ans,mid);
			rr = mid - 1;
		}else ll = mid + 1;
	}
	ll = 0;rr = sz(v)-1;
	int ans2 = sz(v) - 1;
	while(ll<=rr){
		mid = (ll+rr)/2;
		if(v[mid]-v[ans]>=n){
			ans2 = min(ans2,mid);
			rr = mid - 1;
		}else ll = mid + 1;
	}
	lld kk = v[ans] * v[ans2];
	printf("%lld\n",kk);
}


int main(void){
	/*
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	*/
	for(int e=2;e<MAX;e++) 
	{
		if(ck[e]==0){
			for(int p=e*2;p<MAX;p+=e){
				 ck[p] = 1;
			}
			v.push_back(e);
		}
	}
	int tc = 1;
	
		scanf("%d",&tc);
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}