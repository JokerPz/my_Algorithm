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
//������Ҫ���������ʺ󣬿����޸�19�е�n��ֵ���Լ�66�е��������txt�ļ��� 
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
	

void findqueen(int num){//�°˻ʺ�
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
	outfile.open("������_8�ʺ�.txt");
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
		cout<<n<<"�ʺ��ʱ:"<<(finish-start)/CLOCKS_PER_SEC<<"s"<<endl;
		cout<<"count"<<cut<<endl<<endl<<endl;
		return 0;
	}
}
