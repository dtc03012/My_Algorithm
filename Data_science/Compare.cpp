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

struct association_rule{
	vector<int> ls,als;
	int support,confidence;
	association_rule(){

	}
	association_rule(vector<int> _ls,vector<int> _als,int _support,int _confidence) : ls(_ls), als(_als), support(_support), confidence(_confidence){
	};
};

association_rule parsing(string a){
	vector<int> number_arr;
	int string_len = (int)a.size() + 10;
	char *str_buff = (char*)malloc(string_len*sizeof(char*));
	strcpy(str_buff,a.c_str());
	char *tok = strtok(str_buff,"\t");
	vector<int> ls,als;
	int f1 = 0,f2 = 0,ty = 0;
	while(tok!=nullptr){
		int xx = 0,len = strlen(tok);
		if(ty==0){
			int xx = 0;
			for(int p=1;p<len-1;p++){
				if(tok[p]==','){
					ls.push_back(xx);
					xx = 0;
				}else{
					xx = xx*10 + tok[p] - '0';
				}
			}
			ls.push_back(xx);
			ty++;
		}else if(ty==1){
			int xx = 0;
			for(int p=1;p<len-1;p++){
				if(tok[p]==','){
					als.push_back(xx);
					xx = 0;
				}else{
					xx = xx*10 + tok[p] - '0';
				}
			}
			als.push_back(xx);
			ty++;
		}else if(ty==2){
			for(int e=0;e<5;e++){
				if(e>=len){
					f1*=10;
				}else{
					if(tok[e]=='.') continue;
					else{
						f1 = f1*10 + tok[e] - '0';
					}
				}
			}
			ty++;
		}else if(ty==3){
			for(int e=0;e<5;e++){
				if(e>=len){
					f2*=10;
				}else{
					if(tok[e]=='.') continue;
					else{
						f2 = f2*10 + tok[e] - '0';
					}
				}
			}
			ty++;
		}
		tok = strtok(nullptr,"\t");
	}
	free(str_buff);
	sort(all(ls));
	sort(all(als));
	return association_rule(ls,als,f1,f2);
}
vector<association_rule> ck;
bool find_v(association_rule x){
	for(int p=0;p<sz(ck);p++){
		bool suc = true;
		for(int e=0;e<sz(ck[p].ls);e++){
			if(ck[p].ls[e]!=x.ls[e]) suc = false;
		}
		for(int e=0;e<sz(ck[p].als);e++){
			if(ck[p].als[e]!=x.als[e]) suc = false;
		}
		if(ck[p].support!=x.support) suc = false;
		if(ck[p].confidence!=x.confidence) suc = false;
		if(suc) return false;
	}
	return true;
}
void solve(int tc,int argc,char **argv){
	char* input_file_1 = argv[1];
	char* input_file_2 = argv[2];
	ifstream in1,in2;
	ofstream out;
	in1.open(input_file_1);
	in2.open(input_file_2);
	out.open("compare.txt");
	int len1 = 0,len2 = 0;
	while(!in1.eof()){
		len1++;
		string line;
		getline(in1,line);
		if(line=="") continue;
		association_rule xx = parsing(line);
		ck.push_back(xx);
	}
	int err = 0;
	while(!in2.eof()){
		len2++;
		string line;
		getline(in2,line);
		if(line=="") continue;
		association_rule xx = parsing(line);
		if(find_v(xx)){
			out << "you don't have " << line << endl;
			err++;
		}else{
			out << line << " Accept" << endl;
		}
	}
	if(len1!=len2){
		out << "line doesn't match "<< endl;
	}
	out << "err count : " << err << endl;
}


int main(int argc,char** argv){
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
		solve(test_number,argc,argv);
	}
	return 0;
}