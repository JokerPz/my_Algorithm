//本代码功能两个，输入时，要选输入0或非0来选择功能，选择0为测试N皇后的遍历节点数目，输入非0数字，则进行八皇后的点集判断。
//进行点集判断时的输入如下
//1 
//1 4
//2 7
//3 3
//4 8
//5 2
//6 5
//7 1
//8 6
//进行N皇后节点判断时，直接输入0
//0 
//另外需要进行其他皇后，可以修改19行的n的值，以及66行导出结果的txt文件名 
#include<iostream>
#include <time.h>
#include<stdlib.h>
#include<fstream>
#define n 8
using namespace std;
ofstream outfile;


int *queen;
unsigned  long cut=0;
int  peace(){
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(queen[i]==queen[j]){
				
				return 0;
			}
			if(queen[i]-i==queen[j]-j){
				return 0;
			}
			if(queen[i]+i==queen[j]+j){
				return 0;
			}
		}
	}
	return 1;
}
	

void findqueen(int num){//下八皇后
	int i;
	if(num<n)
		for(i=0;i<n;i++){
			queen[num]=i;
			cut++;
			if(num==n-1){
				if(peace()){
					for(int j=0;j<n;j++){
						outfile<<queen[j]+1<<' ';
					}
					outfile<<endl;
				}
			}
			
			findqueen(num+1);		
		}
}


int main(){
	outfile.open("蛮力法_8皇后.txt");
	srand((unsigned)time(NULL));
	queen = new int[n];
	int select;
	cin>>select;
	if(select){
		int i;
		int r[8];
		for(i=0;i<8;i++){
			cin>>r[i]>>queen[i];

		}
		if(peace()){
			cout<<"yes"<<endl;
		}
		else{
			cout<<"no"<<endl;
		}
	}
	
	else{		
		double start,finish;
		cut=0;
		start=clock();
		findqueen(0);
		finish=clock();
		cout<<n<<"皇后耗时:"<<(finish-start)/CLOCKS_PER_SEC<<"s"<<endl;
		cout<<"count"<<cut<<endl<<endl<<endl;
		return 0;
	}
}
