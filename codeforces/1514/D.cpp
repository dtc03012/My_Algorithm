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

const int MAX = 303030;
int arr[MAX];
vector<int> v[MAX];
int ck(int l,int r,int x){
	int near = lower_bound(all(v[x]),l) - v[x].begin();
	int far = lower_bound(all(v[x]),r+1) - v[x].begin() - 1;
	int count = far - near + 1;
	return count;
}
void solve(int tc){
	std::random_device rd; std::mt19937 mersenne(rd()); // Create a mersenne twister, seeded using the random device // Create a reusable random number generator that generates uniform numbers between 1 and 6 std::uniform_int_distribution<> die(1, 6);
	std::uniform_int_distribution<> die(1,MAX*200);
	int n,q;
	cin >> n >> q;
	for(int e=1;e<=n;e++){
		cin >> arr[e];
		v[arr[e]].push_back(e);
	}
	for(int e=1;e<=q;e++){
		int l,r;
		cin >> l >> r;
		int pos = -1,cnt = -1;
		for(int t=0;t<30;t++){
			int diff = r - l + 1;
			int wh = l + (die(mersenne)%diff);
			int xx = ck(l,r,arr[wh]);
			if(xx>cnt){
				cnt = xx;
				pos = arr[wh];
			}
		}
		int diff = r - l + 1;
		int lim = diff / 2;
		if(diff%2) lim++;
		if(lim>=cnt){
			cout << "1\n"; 
		}else{
			int ff = diff - cnt + 1;
			cnt -= ff;
			int tot = 1 + cnt;
			cout << tot << "\n";
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