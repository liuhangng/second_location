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
	int k;//斜率 INT_MAX
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
				if (x == 0 && y == 0)++overlap;//两个点重合了
				else if (x == 0)
					localmax = std::max(localmax, ++shu);
				else if(y==0)
					localmax = std::max(localmax, ++heng);
				else
				{
					int gdc = generateGDC(x, y);
					if (gdc != 0)//约分
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
	int generateGDC(int x, int y)//最大公因子
	{
		if (y == 0)return x;
		return generateGDC(y, x%y);  //因为x%y的部分必然也是公因子的倍数
	}
};