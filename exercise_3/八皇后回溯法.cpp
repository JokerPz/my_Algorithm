//�����빦������������ʱ��Ҫѡ����0���0��ѡ���ܣ�ѡ��0Ϊ����N�ʺ�ı����ڵ���Ŀ�������0���֣�����а˻ʺ�ĵ㼯�жϡ�
//���е㼯�ж�ʱ����������
//1 
//1 4
//2 7
//3 3
//4 8
//5 2
//6 5
//7 1
//8 6
//����N�ʺ�ڵ��ж�ʱ��ֱ������0
//0 
//������Ҫ���������ʺ󣬿����޸�19�е�n��ֵ���Լ�71�е��������txt�ļ��� 
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
	for(int r1=0;r1<row;r1++){//��ǰrow���ʺ���жԱ� 
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
			queen[row]=i;//���Ե�i�� 
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
			queen[row]=-1;//row��ƥ�䲻�ɹ���������һ�㣬�������ԡ� 
		}
	}
}



int main(){
	outfile.open("���ݷ�_8�ʺ�.txt");
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
