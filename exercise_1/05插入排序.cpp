#include<iostream>
#include<time.h>
#include<stdlib.h>

using namespace std;

int main(){
	srand((unsigned)time(NULL));
	double start,finish;
	int i,j,temp,h;
	int *key;
	int n=10000;
	cout<<"n="<<n<<endl; 
	key=new int[n];
	for(h=1;h<21;h++){	
		for(i=0;i<n;i++){
			key[i]=rand()%10000001;
		}
		start=clock();
		for(i=1;i<=n;i++){
			temp=key[i];
			for(j=i-1;j>=0;j--){
				if(temp>=key[j]){ 
					break;
				}
				key[j+1]=key[j]; 
			}
			key[j+1]=temp;
		}
		finish=clock();
		cout<<"ตฺ"<<h<<"ื้:"<<((finish-start)/CLOCKS_PER_SEC)<<'s'<<endl;
	}
		
//		
//		for(i=0;i<n;i++){
//			cout<<key[i]<<' ';
//		}
}
