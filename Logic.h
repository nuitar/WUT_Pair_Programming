#pragma once
#include<iostream>
#include<vector>
#include"Global.h"
using namespace std;

class Logic
{
private:
	bool map[ROWS][COLS];
public:
	Logic();
	int getRoundAlive(int i, int j);   //获取第i行j列的当前的格子的周围的活细胞的数目
	vector<MyPoint> NextState();   //下一个状态
	void Click(MyPoint point);   //点击鼠标则将当前格子取反，更新地图。
};

