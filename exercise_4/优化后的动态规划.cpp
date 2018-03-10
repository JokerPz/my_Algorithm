#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<iomanip>
#define m 10
#define n 10
using namespace std;
int **Way;
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
	Way=new int*[n+1];
	for(i=0;i<n+1;i++){
		Way[i]=new int[m+1];
	}
	for(i=0;i<=n;i++){
		Sum1[i]=0;
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
//	k=n;
//	for(j=m;j>0;j--){
//		cout<<Way[k][j]<<' ';
//		k=k-Way[k][j];
//	}	
//	cout<<endl;
	cout<<n<<"个设备分配给"<<m<<"个工厂"<<endl; 
	cout<<"最大收益:"<<Sum2[n]<<",需要时间:"<<fixed<<setprecision(3)<<((finish-start)/CLOCKS_PER_SEC)<<"s"<<endl;
} 
