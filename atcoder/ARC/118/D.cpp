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

lld mod;
lld calc(lld now,lld num){
	if(num==0) return 1;
	if(num==1) return now;
	lld now2 = calc(now,num/2);
	if(num%2==0) return (now2*now2)%mod;
	return (((now2*now2)%mod)*now)%mod;
}
void solve(int tc){
	cin >> mod;
	lld a,b;
	cin >> a >> b;
	if(a%b==0||b%a==0){
		cout << "NO";
		return;
	}
	cout << "YES\n";
	lld a1 = calc(a,mod-2);
	lld b1 = calc(b,mod-2);
	int lim = (mod - 1);
	vector<int> v;
	cout << "1 ";
	int tot = 0;
	lld st = 1;
	while(true){
		lld nst = (st*b)%mod;
		if(nst==1) break;
		st = nst;
		cout << st << " ";
		tot++;
	}
	if(tot==lim) return;
	st = (st*a1)%mod;
	cout << st << " ";
	st = (st*b)%mod;
	cout << st << " ";
	tot += 2;
	while(true){
		st = (st*a1)%mod;
		if(st==1ll) break;
		tot++;
		cout << st <<" ";
	}
	cout << sz(v) << endl;
}


int main(void){
	/*
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	*/
	int tc = 1;
	/*
		cin >> tc;
	*/
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}