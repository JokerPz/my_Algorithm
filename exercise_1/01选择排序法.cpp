#include<iostream>
#include<stdlib.h>
#include <time.h>
#include<iomanip>
using namespace std;

int main(){
	srand((unsigned)time(NULL));
	
	
	int i,k,j,min,n,h,l;
	int *key;
	double start,finish;
	
	n=10000;
	cout<<"n="<<n<<endl;
	key=new int[n];
	for(h=0;h<20;h++){
	
		for(i=0;i<n;i++){
			key[i]=rand()%10000001;
		}
		start=clock();
		for(i=0;i<n;i++){
			k=i;
			for(j=i+1;j<=n;j++){
				if(key[k]>key[j]){
					k=j;
				}
			}
			min=key[k];
			key[k]=key[i];
			key[i]=min;
		}
		finish=clock();
		for(i=0;i<20;i++){
			cout<<key[i]<<' ';
		} 
		cout<<fixed<<setprecision(3)<<"ตฺ"<<h+1<<"ื้:"<<(finish-start)/CLOCKS_PER_SEC<<"s"<<endl;
	}
}




//	for(i=0;i<n;i++){
//		cout<<key[i]<<' ';
//	}
