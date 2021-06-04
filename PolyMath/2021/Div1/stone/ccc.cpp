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

int investigate(vector<int> x){
	return 0;
}
void solve(int tc){
	std::random_device rd;
    std::default_random_engine rng(rd());
    vector<int> loc;
    vector<int> xx;
    for(int e=-5;e<=-1;e++) xx.push_back(e);
    for(int e=1;e<=5;e++){
    	for(int p=-5;p<=-1;p++){
    		shuffle(all(xx),rng);
    		for(int e=0;e<5;e++) printf("%d ",xx[e]);
    			printf("\n");
    		vector<int> k;
    		k.push_back(xx[0]);
    		k.push_back(xx[1]);
    		k.push_back(xx[2]);
    		k.push_back(e);
    		int rr = investigate(k);
    		if(rr==4){
    			vector<int> k;
    			k.push_back(xx[3]);
    			k.push_back(e);
    			int rr = investigate(k);
    			if(rr==1) loc.push_back(xx[3]);
    			else loc.push_back(xx[4]);
    		}else{
    			vector<int> k;
    			k.push_back(xx[0]);
    			k.push_back(xx[1]);
    			k.push_back(e);
    			int rr = investigate(k);
    			if(rr==3){
    				loc.push_back(xx[2]);
    			}else{
    				vector<int> k;
    				k.push_back(xx[0]);
    				k.push_back(e);
    				int rr = investigate(k);
    				if(rr==1) loc.push_back(xx[0]);
    				else loc.push_back(xx[1]);
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