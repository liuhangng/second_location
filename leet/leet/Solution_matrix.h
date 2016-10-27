#pragma once
#include "common.h"

class Solution_matrix
{
public:
	bool isExistMatrix(vector<vector<int>>& matrix, int k) {
		//有序的矩阵
		//两次二分查找
		int row = matrix.size();
		int col = matrix[0].size();
		int up = 0, down = row - 1;
		while (up < down)
		{
			int mid = up + ((down-up)>>1);
			if (matrix[mid][0] == k)return true;
			else
			{
				if (matrix[mid][0] > k)down = mid - 1;
				else up = mid + 1;
			}
		}
		int left = 0, right = col - 1;
		while (left<right)
		{
			int mid = left + ((right - left) >> 1);
			if (matrix[up - 1][mid] == k)return true;
			else
			{
				if (matrix[up-1][mid] > k)right = mid - 1;
				else left = mid + 1;
			}
		}
		return false;
	}
	int kthSmallest(vector<vector<int>>& matrix, int k) {
		int row = matrix.size();
		int lmin = matrix[0][0];
		int rmax = matrix[row - 1][row - 1];
		while (lmin<rmax)
		{
			int mid = lmin + ((rmax - lmin) >> 1);
			int num = 0;
			for (int i=0;i<row;i++)
			{	
				num += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
			}
			if (num < k)
			{
				lmin = mid + 1;
			}
			else
			{
				rmax = mid;
			}
		}
		return lmin;
	}
private:
};
