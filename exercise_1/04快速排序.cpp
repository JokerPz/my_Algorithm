#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<iomanip> 

using namespace std;

int *key;
QuickSort(int low,int high){
	int i,j,pivotkey;
	i=low;
	j=high;
	pivotkey=key[low];
	while(low<high){
		while((low<high)&&(pivotkey<key[high])){
			high--;
		}
		if(low<high){
			key[low]=key[high];
			low++;
		}
		while((low<high&&key[low]<pivotkey)){
			low++;
		} 
		if(low<high){
			key[high]=key[low];
			high--;
		}
	}
	key[low]=pivotkey;
	if(i<low-1){
		QuickSort(i,low-1);
	}
	if(j>high+1){
		QuickSort(high+1,j);
	}
}


int main(){
	srand((unsigned)time(NULL));
	double start,finish;
	int n,i,j;
	n=50000;
	cout<<"n="<<n<<endl;
	for(j=1;j<=20;j++){
	
		key=new int[n];
		for(i=0;i<n;i++){
			key[i]=rand()%101;
		}
		start=clock();
		QuickSort(0,n-1);
		finish=clock();
		cout<<fixed<<setprecision(3)<<"ตฺ"<<j<<"ื้:"<<((finish-start)/CLOCKS_PER_SEC)<<'s'<<endl;
	}
//	for(i=0;i<n;i++){
//		cout<<key[i]<<' ';
//	}
} 
