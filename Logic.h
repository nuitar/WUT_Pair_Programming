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
	int getRoundAlive(int i, int j);   //��ȡ��i��j�еĵ�ǰ�ĸ��ӵ���Χ�Ļ�ϸ������Ŀ
	vector<MyPoint> NextState();   //��һ��״̬
	void Click(MyPoint point);   //�������򽫵�ǰ����ȡ�������µ�ͼ��
};

