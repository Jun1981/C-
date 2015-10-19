#include "Image.h"
#include "../DxLib/DxLib.h"
#include <tchar.h>

//�R���X�g���N�^
Image::Image(int w,int h){//�摜�T�C�Y�w��

	this->imgWidth=w;this->imgHeight=h;
}
Image::Image(){
	x=y=initX=initY=gh=0;

}
//�Z�b�^�[
void Image::setGh(const TCHAR *str){

 gh=LoadGraph(str,0);

}
void Image::setSizeXY(int w,int h){

	imgWidth=w;imgHeight=h;

}
//void Image::setXY(int a, int b){
//	x=a;y=b;
//
//}

//�Q�b�^�[

int Image::getGh(){
	return gh;
}


//�A�j���\�V�����p�n���h��
//void Image::getArrayAnimGh(int n){
//
//	animGh=new int[n];
//
//
//
//}

//DrawGraph���݈ʒu(���߂���j
void Image::draw(int X,int Y,int BRIGHTNESS){
	SetDrawBright(BRIGHTNESS,BRIGHTNESS,BRIGHTNESS);//���邳��ݒ�
	DrawGraph(X,Y,gh,1);
	SetDrawBright(255,255,255);//���邳�����ɖ߂�
}
//DrawRotaGraph(); ��]��Y�[���𗘗p (�{���A�p�x�j
void Image::draw2(double zoom,int deg){
	DrawRotaGraph(x,y,zoom,(double)(deg/180)*3.14,gh,1,0);
	}

void Image::resetXY(){
	x=initX;y=initY;
}

int Image::getWidth(){
	return imgWidth;
}

int Image::getHeight(){
	return imgHeight;
}
