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
//另外需要进行其他皇后，可以修改19行的n的值，以及71行导出结果的txt文件名 
#include<iostream>
#include <time.h>
#include<stdlib.h>
#include<fstream>
#define n 8
using namespace std;

ofstream outfile;
int answers=0;
int *queen;
int cut=0; 
int cut_branches=0;
int peace(int row,int c){
	int c1=queen[row];
	for(int r1=0;r1<row;r1++){//跟前row个皇后进行对比 
		if(queen[r1]==c){
			return 0;
		} 
		if((queen[r1]-r1)==(c-row)){
			return 0;
		}
		if((queen[r1]+r1)==(c+row)){
			return 0;
		}
	} 
	return 1;
}

void buildQueen(int row){
	int i;	
	if(row<n){
		for(i=0;i<n;i++){
			queen[row]=i;//尝试第i列 
			if(peace(row,i)){
				cut++;
				if(row==n-1){
					answers++;
					
					for(int j=0;j<n;j++){
						outfile<<queen[j]+1<<' ';
					}
					outfile<<endl;
				}
				buildQueen(row+1);
			}
			else{
				cut_branches++;
			} 
			queen[row]=-1;//row行匹配不成功，回溯上一层，继续测试。 
		}
	}
}



int main(){
	outfile.open("回溯法_8皇后.txt");
	srand((unsigned)time(NULL));
	double start,finish; 
	queen=new int[n];
	queen[0]=0;
	int select;
	cin>>select;
	if(select){
		int i,c=0;
		int r[8];
		for(i=0;i<8;i++){
			cin>>r[i]>>queen[i];
			if(peace(i,queen[i])){
				c++;
			}
			
		}
		if(c==8){
			cout<<"yes"<<endl;
		}
		else{
			cout<<"no"<<endl;
		}
	}
	else{	
		start=clock();
		buildQueen(0);
		finish=clock();
		cout<<(finish-start)/CLOCKS_PER_SEC<<"s"<<endl;
		cout<<"count:"<<cut<<endl;
		cout<<"answers:"<<answers<<endl;
		cout<<"cut_branches"<<cut_branches<<endl;
	} 
}
