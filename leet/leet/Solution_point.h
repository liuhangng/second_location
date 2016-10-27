#pragma once

#include "common.h"

struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};

struct  line
{
	int  x; //INT_MIN
	int  y;  //
	int k;//б�� INT_MAX
};

class Solution_point {
public:
	int maxPoints(vector<Point>& points) {
		if (points.size() < 3)return points.size();
		int res = 0; 
		for (int i=0;i<points.size();i++)
		{
			int localmax = 0,overlap=0;
			int heng = 0,shu=0;
			map<int, map<int, int>>cache;
			for (int j=i+1;j<points.size();++j)
			{
				int x = points[j].x - points[i].x;
				int y = points[j].y - points[i].y;
				if (x == 0 && y == 0)++overlap;//�������غ���
				else if (x == 0)
					localmax = std::max(localmax, ++shu);
				else if(y==0)
					localmax = std::max(localmax, ++heng);
				else
				{
					int gdc = generateGDC(x, y);
					if (gdc != 0)//Լ��
					{
						x /= gdc;
						y /= gdc;
					}
					localmax = std::max(localmax, ++cache[x][y]);
				}	
			}
			res = std::max(localmax + overlap + 1, res);
		}
		return res;
	}
private:
	int generateGDC(int x, int y)//�������
	{
		if (y == 0)return x;
		return generateGDC(y, x%y);  //��Ϊx%y�Ĳ��ֱ�ȻҲ�ǹ����ӵı���
	}
};