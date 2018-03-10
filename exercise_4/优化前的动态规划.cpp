#include<iostream>
#include<iomanip>
#include<time.h>
#include<stdlib.h>
#include<iomanip>
#define m 100
#define n 100
using namespace std;
int **count;
int	h=0;

int main(){
//	创建一个二维数组    n台设备，m个车间 
//	Ci j(i台设备提供给j号车间将得到的利润，1≤i≤n，1≤j≤m)
	int **C;
	int **Sum;	
	double start,finish;
	srand((unsigned)time(NULL));
	int i,j,k;	
	Sum=new int*[n+1];
	count=new int*[n+1];
	C=new int*[n+1];//最少0个设备，最多n个设备 
//	a=new int[n+1];
	for(i=0;i<n+1;i++){//m个车间 
		C[i]=new int[m+1];	
		Sum[i]=new int[m+1];
		count[i]=new int[m+1];
	}

	for(i=0;i<n+1;i++){
		if(i==0){
			for(j=0;j<m+1;j++){
				C[i][j]=0;
				Sum[i][j]=0;
				count[i][j]=0;
			}
		}
		else{
			for(j=0;j<m+1;j++){
				if(j==0){
					C[i][j]=0;
					Sum[i][j]=0;
					count[i][j]=0;
				}
				else{
					C[i][j]=rand()%10+C[i-1][j]+1;//动态规划需要删去后面 
					Sum[i][j]=0;
					count[i][j]=0;
				}
			}
		}
	}
//	for(i=0;i<n+1;i++){
//		for(j=0;j<m+1;j++){
//			cout<<setw(4)<<C[i][j]<<' ';
//		}
//		cout<<endl;
//	}
	
	//动态规划开始
	
	start=clock(); 
	for(j=1;j<=m;j++){//从第j个厂开始	
		for(i=1;i<=n;i++){//从第i个设备开始
			for(k=0;k<=i;k++){//第i个厂分配k个设备 
				if(Sum[i][j]<Sum[i-k][j-1]+C[k][j]){
					Sum[i][j]=Sum[i-k][j-1]+C[k][j];
					count[i][j]=k;//第j个厂分配k个设备 
				}
			} 
		}
	}
	finish=clock();
	cout<<n<<"个设备分配给"<<m<<"个工厂"<<endl; 
	cout<<"最大收益:"<<Sum[n][m]<<",需要时间:"<<fixed<<setprecision(3)<<((finish-start)/CLOCKS_PER_SEC)<<"s"<<endl;
	k=0;
//	cout<<"逆序输出方案:"; 
//	for(j=m;j>=0;j--){
//		cout<<count[n-k][j]<<" ";
//		k+=count[n-k][j];
//	}
//	cout<<endl;

	

}
 
