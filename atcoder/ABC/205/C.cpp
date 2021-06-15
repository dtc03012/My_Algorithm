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

void d(){
	cout << "=";
}
void g(){
	cout << ">";
}
void s(){
	cout << "<";
}
void solve(int tc){
	int a,b,c;
	cin >> a >> b >> c;
	if(a>0&&b>0){
		if(a>b) g();
		else if(a==b) d();
		else s();
	}else{
		if(a==0&&b==0) d();
		else if(a==0){
			if(b>0) s();
			else{
				if(c%2) g();
				else s();
			}
		}else if(b==0){
			if(a>0) g();
			else{
				if(c%2) s();
				else g();
			}
		}else{
			if(a>0&&b<0){
				if(c%2){
					g();
				}else{
					if(abs(a)>abs(b)) g();
					else if(abs(a)==abs(b)) d();
					else s();
				}
			}else if(a<0&&b>0){
				if(c%2){
					s();
				}else{
					if(abs(a)>abs(b)) g();
					else if(abs(a)==abs(b)) d();
					else s();
				}
			}else{
				if(c%2){
					if(abs(a)>abs(b)) s();
					else if(abs(a)==abs(b)) d();
					else g();
				}else{
					if(abs(a)>abs(b)) g();
					else if(abs(a)==abs(b)) d();
					else s();
				}
			}
		}
	}
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