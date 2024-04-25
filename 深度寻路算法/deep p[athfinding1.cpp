
#include<iostream>
#define ROWS 10
#define COLS 10
#include<vector>
using namespace std;
//枚举4个方向
enum dir {
	p_up,
	p_down,
	p_left,
	p_right
};
//辅助地图结构
struct AuxiliaryMap {
	//是否走过，1是0否
	int isFind;
	//是否为墙，1是0否
	int isVal;
};

struct Cpoint {
	int col;
	int row;
	bool operator ==(Cpoint& Curpos){
		if (Curpos.col == this->col && Curpos.row == this->row)
			return true;
		return false;
	}
	Cpoint(){}
	Cpoint(int row, int col):row(row),col(col){}
};
//树结构
struct MyTreeNode {
	MyTreeNode(int row, int col) {
		CurPos.row = row;
		CurPos.col = col;
		pParent = NULL;
		pChild.clear();
	}
	Cpoint CurPos;//当前坐标
	//子节点
	vector<MyTreeNode*>pChild;
	//父节点
	MyTreeNode* pParent;
};
bool iscanwalk(AuxiliaryMap pathMap[ROWS][COLS], Cpoint Curpos) {
	if (Curpos.col < 0 || Curpos.row < 0 || Curpos.col >= ROWS || Curpos.row >= COLS)
		return false;
	if (pathMap[Curpos.row][Curpos.col].isFind)
		return false;
	if (pathMap[Curpos.row][Curpos.col].isVal)
		return false;
	return true;
}

int main() {
	int map[ROWS][COLS]{
		{0,1,1,1,1,1,1,1,1,1},
		{0,0,1,0,0,0,0,0,1,1},
		{1,0,0,0,1,1,1,0,1,1},
		{1,1,1,0,1,1,1,0,1,1},
		{1,1,1,0,1,0,0,0,1,1},
		{1,1,1,0,1,0,1,0,1,1},
		{1,1,1,0,1,0,1,0,1,1},
		{0,0,0,0,0,0,1,0,0,1},
		{1,1,1,0,1,1,1,1,0,0},
		{1,1,1,0,0,0,0,0,1,0},
	};
	AuxiliaryMap pathMap[ROWS][COLS] = { 0 };

//辅助地图赋值
	for(int i=0;i<ROWS;i++)
		for (int j = 0; j < COLS; j++)
		{
			pathMap[i][j].isVal = map[i][j];
		}

//开始与结束
	Cpoint beginPos(0, 0);
	Cpoint endPos(9, 9);
//根节点
	MyTreeNode* pRoot = new MyTreeNode(beginPos.row, beginPos.col);
// 辅助地图标记根节点已走过
	pathMap[beginPos.row][beginPos.col].isFind = 1;
//数组下一层
	vector<MyTreeNode*>NextTier;
//数组当前层	
	vector<MyTreeNode*>CurrentTier;
	CurrentTier.push_back(pRoot);

	MyTreeNode* Temp=NULL;
	Cpoint test;
	while (1) {
		NextTier.clear();
		for (int i = 0; i < CurrentTier.size(); i++) {
			//清空下一层
			for (int j = 0; j < 4; j++)
			{
				test = CurrentTier[i]->CurPos;
				switch (j)
				{
				case p_up:
					test.row--;
					break;
				case p_down:
					test.row++;
					break;
				case p_left:
					test.col--;
					break;
				case p_right:
					test.col++;
					break;
				}
				//是否能走
				if (iscanwalk(pathMap,test))
				{
				//创建新节点
					Temp = new MyTreeNode(test.row, test.col);
				//将新节点放入树中
					CurrentTier[i]->pChild.push_back(Temp);
				//辅助地图标记走过
					pathMap[test.row][test.col].isFind = 1;
				//新节点父节点
					Temp->pParent = CurrentTier[i];
				//下一层
					NextTier.push_back(Temp);
					if (test == endPos)
						goto exit;
				}
			}
		}
		if (NextTier.size() == 0)
			break;
		CurrentTier = NextTier;
	
}
exit:
	while (Temp) {
		{cout << "(" << Temp->CurPos.row << "," << Temp->CurPos.col << ")" << endl;
		Temp = Temp->pParent;
		}
	}

}
