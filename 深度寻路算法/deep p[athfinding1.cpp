
#include<iostream>
#define ROWS 10
#define COLS 10
#include<vector>
using namespace std;
//ö��4������
enum dir {
	p_up,
	p_down,
	p_left,
	p_right
};
//������ͼ�ṹ
struct AuxiliaryMap {
	//�Ƿ��߹���1��0��
	int isFind;
	//�Ƿ�Ϊǽ��1��0��
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
//���ṹ
struct MyTreeNode {
	MyTreeNode(int row, int col) {
		CurPos.row = row;
		CurPos.col = col;
		pParent = NULL;
		pChild.clear();
	}
	Cpoint CurPos;//��ǰ����
	//�ӽڵ�
	vector<MyTreeNode*>pChild;
	//���ڵ�
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

//������ͼ��ֵ
	for(int i=0;i<ROWS;i++)
		for (int j = 0; j < COLS; j++)
		{
			pathMap[i][j].isVal = map[i][j];
		}

//��ʼ�����
	Cpoint beginPos(0, 0);
	Cpoint endPos(9, 9);
//���ڵ�
	MyTreeNode* pRoot = new MyTreeNode(beginPos.row, beginPos.col);
// ������ͼ��Ǹ��ڵ����߹�
	pathMap[beginPos.row][beginPos.col].isFind = 1;
//������һ��
	vector<MyTreeNode*>NextTier;
//���鵱ǰ��	
	vector<MyTreeNode*>CurrentTier;
	CurrentTier.push_back(pRoot);

	MyTreeNode* Temp=NULL;
	Cpoint test;
	while (1) {
		NextTier.clear();
		for (int i = 0; i < CurrentTier.size(); i++) {
			//�����һ��
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
				//�Ƿ�����
				if (iscanwalk(pathMap,test))
				{
				//�����½ڵ�
					Temp = new MyTreeNode(test.row, test.col);
				//���½ڵ��������
					CurrentTier[i]->pChild.push_back(Temp);
				//������ͼ����߹�
					pathMap[test.row][test.col].isFind = 1;
				//�½ڵ㸸�ڵ�
					Temp->pParent = CurrentTier[i];
				//��һ��
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
