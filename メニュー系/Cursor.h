#pragma once

//�J�[�\���N���X�ł��B
//���j���[�N���X���g���܂�

#include "Image.h"//�摜�N���X
#include "Menu.h"//���j���[�N���X

class Cursor :public Image{
public:

	Cursor(int,int);//�R���X�g���N�^�i�摜�T�C�Y�w��j
	virtual void draw(int,int,int BRIGHTNESS);//�J�[�\���`�� �摜�̐^�񒆂ɍ��킹��






};