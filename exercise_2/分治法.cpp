#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;

struct point{//点结构 
	double x;
	double y;
};
bool sortX(point p1,point p2){
	return p1.x<p2.x;
}

bool sortY(point p1,point p2){
	return p1.y<p2.y;
}

double getDis(point p1,point p2){
	return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}

double minDis(vector<point> &poi,int low,int high){
	if((high-low)==0){
		return 9999;
	}
	else if((high-low)==1){
		return getDis(poi[low],poi[high]);
	}
	else if((high-low)==2){
		return (getDis(poi[low],poi[low+1])<getDis(poi[low+1],poi[low+2]))?
				(getDis(poi[low],poi[low+1])<getDis(poi[low],poi[low+2]))?(getDis(poi[low],poi[low+1])):(getDis(poi[low],poi[low+2])):
				(getDis(poi[low+1],poi[low+2])<getDis(poi[low],poi[low+2]))?getDis(poi[low+1],poi[low+2]):(getDis(poi[low],poi[low+2]));
	}
	else{
		int mid=(low+high)/2;
		int i,j;
		double dl=minDis(poi,low,mid);
		double dr=minDis(poi,mid+1,high);
		double d=(dl<dr)?dl:dr;
		vector<point> pot1;
		pot1.erase(pot1.begin(),pot1.end());
		for(i=low;i<=high;i++){//筛选界线边界区域点 
			if(fabs(poi[mid].x-poi[i].x)<=d)
				pot1.push_back(poi[i]);
		}

		sort(pot1.begin(),pot1.end(),sortY);

		for(i=0;i<(pot1.size());i++){//Y轴排序 
			for(j=i+1;j<=7+i;j++){
				if((pot1[i].y-pot1[j].y)>=d){
					break;
				}
				double dp=getDis(pot1[i],pot1[j]);
				if(dp<d){
				d=dp;
				}
		
			}
		}
		return d;
	}
}
	


int main(){
	srand((unsigned)time(NULL));
	int n=100000;
	int i,j;
	double start,finish;
	for(j=0;j<10;j++){
		
		vector<point> poi;
		poi.erase(poi.begin(),poi.end());
		for(i=0;i<n;i++){
			point point1;
			point1.x=rand()/100.0;
			point1.y=rand()/100.0;
			poi.push_back(point1);
			
		}
		start=clock();
		sort(poi.begin(),poi.end(),sortX); 
		finish=clock();
		cout<<"第"<<j+1<<"次测试"<<endl
			<<"最短路径："<<minDis(poi,0,poi.size())<<endl
			<<"消耗时间："<<((finish-start)/CLOCKS_PER_SEC)<<'s'<<endl<<endl; 
	}

} 
