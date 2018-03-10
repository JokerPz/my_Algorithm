#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<math.h>
using namespace std;

double *x,*y;

double mindis(int n){
	double dis,min=100000;
	int i,j;
	for(i=0;i<n-1;i++){
		for(j=i+1;j<=n-1;j++){
			dis=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
			if(dis<=min){
				min=dis;
			}
		}
	}
	return min;	
	
}

int main(){
	double start,finish,min;
	srand((unsigned)time(NULL));
	int n;
	int i;
	for(n=100000;n<=1000000;n+=100000){
		cout<<"n="<<n<<endl;
		x=new double[n];
		y=new double[n];
		for(int j=0;j<10;j++){
			for(i=0;i<n;i++){
				x[i]=rand()/100.0;
				y[i]=rand()/100.0;
			}
			start=clock();
			min=mindis(n);
			finish=clock();
			cout<<"第"<<j+1<<"次测试"<<endl
				<<"最短路径："<<min<<endl
				<<"消耗时间："<<((finish-start)/CLOCKS_PER_SEC)<<'s'<<endl<<endl; 
		} 
	} 
}
