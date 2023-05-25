#include "Logic.h"
#include<iostream>
#include<vector>
#include"Global.h"
using namespace std;

Logic::Logic() {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			map[i][j] = 0;
		}
	}
}

int Logic::getRoundAlive(int i, int j) {
	int num = 0;
	if (i > 0 && j > 0 && map[i - 1][j - 1]) num++;
	if (i > 0 && map[i - 1][j]) num++;
	if (i > 0 && j < COLS - 1 && map[i - 1][j + 1]) num++;
	if (j > 0 && map[i][j - 1]) num++;
	if (j < COLS - 1 && map[i][j + 1]) num++;
	if (i < ROWS - 1 && j > 0 && map[i + 1][j - 1]) num++;
	if (i < ROWS - 1 && map[i + 1][j]) num++;
	if (i < ROWS - 1 && j < COLS - 1 && map[i + 1][j + 1]) num++;
	return num;
}

void Logic::Click(MyPoint point) {
	map[point.x][point.y] = !map[point.x][point.y];
}

vector<MyPoint> Logic::NextState() {
	vector<MyPoint> MyPoints;
	int RoundAlive[ROWS][COLS];
	//计算当前状态的每一个细胞周围的活的细胞
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			RoundAlive[i][j] = getRoundAlive(i, j);
		}
	}
	//遍历二维数组来更新每一个细胞的状态并且判断当前细胞是否更改，是的话则加入MyPoints。
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			int num = RoundAlive[i][j];
			if (num == 3) {  //周围活细胞等于3则存活
				if (map[i][j] == false) {
					MyPoint point = { i,j };
					MyPoints.push_back(point);
				}
				map[i][j] = true;
			}
			else if (num == 2) {
				//周围活细胞等于2则不变
			}
			else {
				//细胞死亡
				if (map[i][j] == true) {
					MyPoint point = { i,j };
					MyPoints.push_back(point);
				}
				map[i][j] = false;
			}
		}
	}
	return MyPoints;
}

void Logic::Reset() {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			map[i][j] = 0;
		}
	}
}

vector<MyPoint> Logic::Random() {
	vector<MyPoint> MyPoints;
	srand((int)time(0));
	for (int i = 0; i < ROWS * COLS/6; i++) {
		//随机生成行数和列数
		int row = rand() % (ROWS - 1);
		int col = rand() % (COLS - 1);
		//将生成的地方改为1
		map[row][col] = 1;
	}
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			if (map[i][j] == 1) {  //如果是1，则添加
				MyPoint point = { i,j };
				MyPoints.push_back(point);
			}
		}
	}
	return MyPoints;
}