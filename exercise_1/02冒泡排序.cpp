#include<iostream>

#include <time.h>
#include<stdlib.h>
using namespace std;

int main(){
	srand((unsigned)time(NULL));
	int i,j,min,n,h;
	int *key;
	double start,finish;
	n=100;
	cout<<"n="<<n<<endl;
	key=new int[n];
	 
	for(h=0;h<20;h++){
	
		for(i=0;i<n;i++){
			key[i]=rand()%100001;
		}
		start=clock();
		for(i=0;i<n;i++){
			for(j=0;j<n-i+1;j++){
				if(key[j]>key[j+1]){
					min=key[j+1];
					key[j+1]=key[j];
					key[j]=min;
				}
			}	
		}
		finish=clock();

		cout<<"ตฺ"<<h+1<<"ื้:"<<(finish-start)<<"s"<<endl;
		//cout<<'a'<<endl;
	}
}
	
	
