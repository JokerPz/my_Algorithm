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
//	����һ����ά����    n̨�豸��m������ 
//	Ci j(į�豸�ṩ��j�ų��佫�õ�������1��i��n��1��j��m)
	int **C;
	int **Sum;	
	double start,finish;
	srand((unsigned)time(NULL));
	int i,j,k;	
	Sum=new int*[n+1];
	count=new int*[n+1];
	C=new int*[n+1];//����0���豸�����n���豸 
//	a=new int[n+1];
	for(i=0;i<n+1;i++){//m������ 
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
					C[i][j]=rand()%10+C[i-1][j]+1;//��̬�滮��Ҫɾȥ���� 
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
	
	//��̬�滮��ʼ
	
	start=clock(); 
	for(j=1;j<=m;j++){//�ӵ�j������ʼ	
		for(i=1;i<=n;i++){//�ӵ�i���豸��ʼ
			for(k=0;k<=i;k++){//��i��������k���豸 
				if(Sum[i][j]<Sum[i-k][j-1]+C[k][j]){
					Sum[i][j]=Sum[i-k][j-1]+C[k][j];
					count[i][j]=k;//��j��������k���豸 
				}
			} 
		}
	}
	finish=clock();
	cout<<n<<"���豸�����"<<m<<"������"<<endl; 
	cout<<"�������:"<<Sum[n][m]<<",��Ҫʱ��:"<<fixed<<setprecision(3)<<((finish-start)/CLOCKS_PER_SEC)<<"s"<<endl;
	k=0;
//	cout<<"�����������:"; 
//	for(j=m;j>=0;j--){
//		cout<<count[n-k][j]<<" ";
//		k+=count[n-k][j];
//	}
//	cout<<endl;

	

}
 
