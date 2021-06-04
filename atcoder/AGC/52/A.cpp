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

bool can(string& x,string& y){
	int st = 0;
	for(int p=0;p<sz(x);p++){
		if(st==sz(y)) return true;
		if(x[p]==y[st]) st++;
	}
	return (st==sz(y));
}
void solve(int tc){
	int n;
	string a[3],b[3];
	cin >> n >> a[0] >> a[1] >> a[2];
	b[0] = a[0] + a[0];
	b[1] = a[1] + a[1];
	b[2] = a[2] + a[2];
	string f1 = "";
	string f2 = "";
	for(int e=0;e<n;e++) f1 += "0";
	for(int e=0;e<n;e++) f1 += "1";
	for(int e=0;e<n;e++) f2 += "1";
	for(int e=0;e<n;e++) f2 += "0";
	{
		string f3 = "0" + f1;
		bool suc = true;
		for(int p=0;p<3;p++) if(!can(b[p],f3)) suc = false;
		if(suc){
			cout << f3 << "\n";
			return;
		}
	}
	{
		string f3 = f1 + "0";
		bool suc = true;
		for(int p=0;p<3;p++) if(!can(b[p],f3)) suc = false;
		if(suc){
			cout << f3 << "\n";
			return;
		}
	}
	{
		string f3 = "1" + f2;
		bool suc = true;
		for(int p=0;p<3;p++) if(!can(b[p],f3)) suc = false;
		if(suc){
			cout << f3 << "\n";
			return;
		}
	}
	{
		string f3 = f2 + "1";
		bool suc = true;
		for(int p=0;p<3;p++) if(!can(b[p],f3)) suc = false;
		if(suc){
			cout << f3 << "\n";
			return;
		}
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