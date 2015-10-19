//2015/10/18�쐬

#pragma once

class Menu {
public:	
	//enum
	enum Direction{hori=0,ver=1};//�����O�A�����P
	//�R���X�g���N�^
	

	Menu(int r,//�c�̍s
		int c,//��
		int w,//���j���[��
		int h,//���j���[�̍���
		int ulX,int ulY,//���j���[�̍�����W	
		Direction d//����������
		);//�i�q�󃁃j���[�쐬
	Menu(int r,int c,Direction d);//���R�I���n
	~Menu();//�f�X�g���N�^

	void Initialize();//������
	void Finalize();//�I������
	//�Z�b�^�[	
	//void setArrayTableInitXY();//�A�C�e�����W�̏����ʒu
	void setArrayTableXY();

	void setTableInitXY();//�A�C�e���̏����ʒu�Z�b�g�����@���ڂ̃��j���[��
	
	//
	void setNowTabXY();//���݂̃e�[�u���ʒu
	//void setNowCurXY();//�J�[�\���p���W
	//

	//�Q�b�^�[

	int getNowTabX(), getNowTabY();
	int getNowCurX(),getNowCurY();
	int getTableX(int ROW,int COLUMN);
	int getTableY(int ROW, int COLUMN);
		

	//�v�Z�֌W
	void calHori( );//�v�Z ���@���j���[(���ڐ��j�@���݂̔ԍ���Ԃ�
	//void draw();//�`��
		
	//�C�����C���֐�
	inline int getNum(){return num;}
	inline int getRow(){return row;}
	inline int getColumn(){return column;}
	inline int getNRow(){return nRow;}
	inline int getNColumn(){return nColumn;}
	inline int Menu::getTWidth(){return tWidth;}
	inline int Menu::getTHeight(){return tHeight;}


protected:
	int num;//���݂̍��ڔԍ�
	int dir;//���j���[�̕����@������hori�@���� ver
	int row;//�s
	int column;//��
	int numOfTables;//���ڐ�

	int **tableX,**tableY;//���ڂ̍��W
	int **tableInitX, **tableInitY;//���ڂ̏������W

	int dWidth,dHeight;//�`��̈�́@���@����
	int dUpLeftX,dUpLeftY;//�`��̈�̍���̍��W

	int tWidth,tHeight;//�e�e�[�u���̕��@����

	int nRow,nColumn;//���̍s�@��

	int nowTabX,nowTabY;//���̃e�[�u�����W
};

