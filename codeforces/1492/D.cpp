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


void solve(int tc){
	int a,b,k;
	scanf("%d%d%d",&a,&b,&k);
	if(b==1){
		if(k==0){
			printf("Yes\n1");
			for(int p=0;p<a;p++) printf("0");
			printf("\n1");
			for(int p=0;p<a;p++) printf("0");
		}else{
			printf("No\n");
		}
		return;
	}
	if(a==0){
		if(k==0){
			cout << "Yes\n";
			for(int p=0;p<b;p++) printf("1");
			printf("\n");
			for(int p=0;p<b;p++) printf("1");
		}else{
			printf("No\n");
		}
		return;
	}
	if(k==a+b){
		printf("NO\n");
		return;
	}
	if(k==a+b-1){
		if(a==1){
			b--;
			string c = "1",d = "1";
			for(int p=0;p<b;p++) c += "1";
			c += "0";
			d += "0";
			for(int p=0;p<b;p++) d += "1";
			cout << "Yes\n" << c << "\n" << d << endl;
		}
		printf("No");
		return;
	}
	string c = "1",d = "1";
	b--;
	if(b<k){
		int diff = k - b + 1;
		c += "1";
		for(int p=0;p<diff;p++) c += "0";
		for(int p=0;p<diff;p++) d += "0";
		d += "1";
		a -= diff;
		k -= diff;
		b--;
	}
	for(;b>k;b--){
		c += "1";
		d += "1";
	}
	if(b){
		for(int p=0;p<b;p++) c += "1";
		c += "0";
		d += "0";
		for(int p=0;p<b;p++) d += "1";
		a--;
	}
	for(int p=0;p<a;p++){
		c += "0";
		d += "0";
	}
	cout << "Yes\n" << c << "\n" << d << endl;
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