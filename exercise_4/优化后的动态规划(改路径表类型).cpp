#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<iomanip>
#include<iomanip>
#define m 1000
#define n 1000
using namespace std;
unsigned short **Way;
//改进后的动态规划
 
int main(){
	int *C;
	int *Sum1,*Sum2;
	
	int i,j,k,max=0;
	double start,finish;
	srand((unsigned)time(NULL));
//	srand(45);
	C=new int[n+1];
	Sum1=new int[n+1];
	Sum2=new int[n+1];
	Way=new unsigned short*[n+1];
	for(i=0;i<n+1;i++){
		Way[i]=new unsigned short[m+1];
	}
	for(i=0;i<=n;i++){
		Sum1[i]=0;
	}
	for(j=0;j<=m;j++){
		Way[0][j]=0;
	}
	Sum2[0]=0;
	C[0]=0;
	start=clock();
	for(j=1;j<=m;j++){
		for(i=1;i<=n;i++){
			
		}
		for(i=1;i<=n;i++){
			C[i]=rand()%10+C[i-1]+1;
			
			max=0;
			
			for(k=0;k<=i;k++){
				if(C[k]+Sum1[i-k]>max){
					max=C[k]+Sum1[i-k];
					Way[i][j]=k;
				}	
			}
			Sum2[i]=max;	
		}
		for(i=1;i<=n;i++){
			Sum1[i]=Sum2[i];
		}
	}
	finish=clock();
//	cout<<Sum2[n]<<endl;
//	k=n;*/
//	for(j=m;j>0;j--){
//		cout<<Way[k][j]<<' ';
//		k=k-Way[k][j];
//	}	
	cout<<n<<"个设备分配给"<<m<<"个工厂"<<endl; 
	cout<<"最大收益:"<<Sum2[n]<<fixed<<setprecision(3)<<",需要时间:"<<((finish-start)/CLOCKS_PER_SEC)<<"s"<<endl;
} 
