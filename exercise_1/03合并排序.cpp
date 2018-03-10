#include<iostream>
#include<time.h>
#include<stdlib.h>

using namespace std;

int main(){
	int n,i,j,k,h,min,step,left=0,right,mid,a,b,c;
	int *key,*son;
	double start,finish;
	n=30000;
	cout<<"n="<<n<<endl; 
	key=new int[n];
	son=new int[n];
	srand((unsigned)time(NULL));
	for(h=1;h<=20;h++){
		for(i=0;i<n;i++){
			key[i]=rand()%10000001;
			son[i]=key[i];
		}
		//cout<<"aaa"<<endl;
		start=clock();
		
		for(step=1;step<n;step*=2){
			for(left=1;left<n;left+=2*step){
				mid=left+step-1;
				if(mid>n)
					break;
				right=left+2*step-1;
				if(right>n)
					right=n;
				a=left;b=mid+1;k=left;
				while(a<=mid&&b<=right){
					if(son[a]<son[b]){
						key[k]=son[a];
						a++;
						k++;
					}
					else{
						key[k]=son[b];
						b++;
						k++;
					}
					
					//cout<<"aaa"<<endl;
				}
				while(a<=mid){
					key[k]=son[a];
					a++;
					k++;
				}
				while(b<right){
					key[k]=son[b];
					b++;
					k++;
				}
			}
			//cout<<"aaa"<<endl;
			for(i=1;i<=n;i++){
				son[i]=key[i];
			}
			
		}
		finish=clock();
		
		
		cout<<"ตฺ"<<h<<"ื้:"<<((finish-start)/CLOCKS_PER_SEC)<<'s'<<endl;
	} 
//	for(i=1;i<n;i++){
//			cout<<key[i]<<' ';
//		}
	

	
		
}


//void merge(int left,int mid,int right){
//	int i=left;j=mid+1;k=left;
//	while(i<=mid&&j<=right){
//		if()
//	}
//}
	
