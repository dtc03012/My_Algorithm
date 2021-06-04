// #include <bits/stdc++.h>

// using namespace std;

struct G2DLine;
struct G2DAxByC;
struct G2DPoint;
struct G2DVector;

struct G2DLine{
	double sx,sy,ex,ey;
	G2DLine(double sx,double sy,double ex,double ey) : sx(sx),sy(sy),ex(ex),ey(ey){

	}
};

struct G2DPoint{
	double x,y;
	G2DPoint(double x,double y) : x(x),y(y){

	}
	double DPoint(G2DPoint PT){
		return sqrt((x-PT.x)*(x-PT.x) + (y-PT.y)*(y-PT.y));
	}
};

struct G2DVector{
	double x,y;
	G2DVector(double x,double y) : x(x),y(y){

	}
	double operator+(G2DVector& k){
		return (this->x)*k.x + (this->y)*k.y;
	}
};

struct G2DAxByC{
	double A,B,C;
		// given A, B, C directly
	G2DAxByC(double A,double B,double C) : A(A),B(B),C(C){
	}
		// given sx,sy,ey,ex
	G2DAxByC(G2DLine X){
			// Line
		if(X.sx==X.ex){
			this->A = -1.0;
			this->B = 0.0;
			this->C = X.sx;
		}else{
			this->A = (X.ey-X.sy)/(X.ex-X.sx);
			this->B = -1.0;
			this->C = (X.ex*X.sy-X.sx*X.ey)/(X.ex-X.sx); 
		}
	}
	double value(double x,double y){
		return A*x + B*y + C;
	}
	double DPoint(G2DPoint Pt){
		return abs(value(Pt.x,Pt.y)/sqrt(A*A+B*B));
	}
};


double DLineToPoint(G2DLine LN,G2DPoint PT){
	G2DVector f1(PT.x-LN.sx,PT.y-LN.sy);	
	G2DVector f2(LN.ex-LN.sx,LN.ey-LN.sy);
	G2DVector s1(PT.x-LN.ex,PT.y-LN.ey);
	G2DVector s2(LN.sx-LN.ex,LN.sy-LN.ey);
	double v1 = f1 + f2;
	double v2 = s1 + s2;
	if(v1>0&&v2>0){
		G2DAxByC g = G2DAxByC(LN);
		return g.DPoint(PT);
	}else{
		double x1 = PT.DPoint(G2DPoint(LN.sx,LN.sy));
		double x2 = PT.DPoint(G2DPoint(LN.ex,LN.ey));
		return min(x1,x2);
	}
}

// int main(void){
// 	return 0;
// }