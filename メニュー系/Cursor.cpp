#include "Cursor.h"
#include "Image.h"
#include "../DxLib/DxLib.h"

//�R���X�g���N�^
Cursor::Cursor(int w,int h){//�摜�T�C�Y�w��

	this->imgWidth=w;this->imgHeight=h;
}

void Cursor::draw(int a,int b,int BRIGHTNESS){
	SetDrawBright(BRIGHTNESS,BRIGHTNESS,BRIGHTNESS);//���邳��ݒ�
	DrawGraph(a,b-imgHeight/2,gh,1);
	SetDrawBright(255,255,255);//���邳�����ɖ߂�
}

