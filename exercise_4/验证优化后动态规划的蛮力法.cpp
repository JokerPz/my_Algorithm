#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<iomanip> 
#define m 5
#define n 10
using namespace std;

int **C;
int count=0;
int max_s=0;
int *a;
int *a1;

void Max(int b){
	if(b>max_s){
		max_s=b;
		for(int i=0;i<=m;i++)
			a1[i]=a[i];
	}
}
//sum_n����
int sum_n(int *a,int i){
	int sumn=0;
	for(int j=0;j<=i;j++){
		sumn+=a[j];
	}
	return sumn;
}

//sum_C���� 
int sum_C(int *a,int i){
	int sum=0;
	for(int j=0;j<=i;j++){
		sum+=C[a[j]][j];
	}
	return sum;
} 
void FindC(int *a,int k){//k�ǵڼ��ҳ���a[k]�ǵ�k�ҳ��Ļ�����Ŀ 
	if(k==m){
		for(a[k]=0;a[k]<=n;a[k]++){
			if(sum_n(a,k)==n){
				count++;
				
//				cout<<sum_C(a,k)<<endl; 
				Max(sum_C(a,k)); 
//				for(int i=0;i<=m;i++){
//					cout<<a[i]<<' ';
//					cout<<C[a[i]][i]<<endl;
//				}
			}		
		}	
	}
	else{
		for(a[k]=0;a[k]<=n;a[k]++){
			FindC(a,k+1);
		}
	}
	//return 0;

}
	
int main(){
//	����һ����ά����    n̨�豸��m������ 
//	Ci j(į�豸�ṩ��j�ų��佫�õ�������1��i��n��1��j��m)

	srand(45);
	int i,j;	
	C=new int*[n+1];//����0���豸�����n���豸 
	a=new int[m+1];
	a1=new int[m+1];
	for(i=0;i<n+1;i++){//m������ 
		C[i]=new int[m+1];	
	}

	for(j=0;j<m+1;j++){
		if(j==0){
			for(i=0;i<n+1;i++){
				C[i][j]=0;
			}
		}
		else{
			for(i=0;i<n+1;i++){
				if(i==0){
					C[i][j]=0;
				}
				else{
					C[i][j]=rand()%10+C[i-1][j]+1;
				}
			}
		}
		
	}
	for(i=0;i<n+1;i++){
		for(j=0;j<m+1;j++){
			cout<<setw(4)<<C[i][j]<<' ';
		}
		cout<<endl;
	}
	
		FindC(a,0); 
//	cout<<count<<endl;
	cout<<endl<<max_s<<endl;
	for(i=0;i<=m;i++){
		cout<<a1[i]<<' ';
	}
	cout<<endl;
//	

} 
