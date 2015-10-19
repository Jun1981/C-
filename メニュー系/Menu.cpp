#include "Menu.h"
#include "key.h"

#include "../DxLib/DxLib.h"


//コンストラクタ
Menu::Menu(int r,int c,Direction d){
	row=r;column=c;
	numOfTables=row*column;
	nowTabX=nowTabY=0;
	dir=d;

}
Menu::Menu(int r,int c,int w,int h,int ulX,int ulY,Direction d){
	num=0;
	row=r;column=c;
	numOfTables=row*column;
	dWidth=w;dHeight=h;
	dUpLeftX=ulX;dUpLeftY=ulY;	 
	dir=d;

	nRow=nColumn=0;
	nowTabX=dUpLeftX;nowTabY=dUpLeftY;

	tWidth=dWidth/column;//テーブルの幅
	tHeight=dHeight/row;//テーブルの高さ

	//関数
	setArrayTableXY();
	setTableInitXY();

		

}
//デストラクタ
Menu::~Menu(){

	//delete[] tableX,tableY,tableInitX,tableInitY;
}
void Menu::Finalize(){
	delete[] tableX,tableY,tableInitX,tableInitY;

}
void Menu::setArrayTableXY(){

	tableX=new int*[row];
	tableInitX=new int*[row];
	tableY=new int*[row];
	tableInitY=new int*[row];

	for(int i=0;i<row;i++){		
		tableX[i]=new int[column];
		tableY[i]=new int[column];
		tableInitX[i]=new int[column];
		tableInitY[i]=new int[column];
	}
}

void Menu::setTableInitXY(){

	for(int i=0;i<row;i++){
		for(int j=0;j<column;j++){
			tableX[i][j]=dUpLeftX+tWidth*j;
			tableY[i][j]=dUpLeftY+tHeight*i;
		}
	}
}

void Menu::calHori(){//横メニューの計算

	//右が押されたら
	if(key_Trg==keyRight){
		if(nColumn<column-1){num++;nColumn++;/*現在番号＋＋*/}//右端にイなかったら
		else/*右端にいたら*/if(num==numOfTables-1){num=nRow=nColumn=0;}//最後なら番号リセット		
		else {num++;nColumn=0;nRow+=1;/*下の行に左端に移る*/}

	}	

	//左を押したら
	if(key_Trg==0x01){
		if(nColumn>0)/*左端にイなかったら*/{num--;nColumn--;}
		else /*左端にいたら*/if(num==0){num=numOfTables-1;nRow=row-1;nColumn=column-1;}/*左上にいたら*/
		else /*0以外*/{num--;nRow--;nColumn+=column-1;/*右上に*/}
	}

	setNowTabXY();//現在テーブル位置をセット
	

}
//テーブル左上座標セット
void Menu::setNowTabXY(){
	nowTabX=dUpLeftX+nColumn*tWidth;
	nowTabY=dUpLeftY+nRow*tHeight;

}
//カーソル用座標セット
//void Menu::setNowCurXY(){
//	nowTabX=dUpLeftX+nColumn*tWidth;
//	nowTabY=dUpLeftY+nRow*tHeight+tHeight/2;
//
//}

int Menu::getNowTabX(){
	return nowTabX;
}
int Menu::getNowTabY(){
	return nowTabY;
}
int Menu::getNowCurX(){
		return nowTabX;
}
int Menu::getNowCurY(){
	return nowTabY+tHeight/2;
}

int Menu::getTableX(int ROW,int COLUMN){

	return tableX[ROW][COLUMN];
}
int Menu::getTableY(int ROW,int COLUMN){

	return tableY[ROW][COLUMN];
}


////背景画像
//void Menu::setArrayGh(int n){
//
//	bgGh=new int[n];
//
//}
//
//void Menu::setArrayGhItem(int n){
//
//	itemGh=new int[n];
//	itemX=new int[n];
//	itemY=new int[n];
//	itemInitX=new int[n];
//	itemInitY=new int[n];
//	
//}
//void Menu::setArrayGhItem(){
//
//	itemGh=new int[numOfItems];
//	itemX=new int[numOfItems];
//	itemY=new int[numOfItems];
//	itemInitX=new int[numOfItems];
//	itemInitY=new int[numOfItems];
//	
//}
//
//void Menu::setArrayGhCur(int n){
//	curGh=new int[n];
//	
//}
//
//
////アイテムの位置設定
//void Menu::setItemXY(int x,int y,int n){
//	itemX[n]=x;itemY[n]=y;
//
//}
////アイテムの初期位置設定
//void Menu::setItemInitXY(int x,int y,int n){	
//	itemInitX[n]=x;itemInitY[n]=y;
//}
//
//void Menu::setGh(int n,const char* string){
//		bgGh[n]=LoadGraph(string,0);
//}
//
//void Menu::setGhItem(int n,const char* string){
//		itemGh[n]=LoadGraph(string,0);
//}
//
//void Menu::setGhCur(int n,const char* string){
//		curGh[n]=LoadGraph(string,0);
//}
//
////コンストラクタ
//Menu::Menu(){
//
//	bgGh=itemGh=curGh=itemX=itemY=itemInitX=itemInitY=0;
//
//
//
//}
////終了処理
//void Menu::close(){
//	delete[] bgGh;
//	delete[] itemGh;
//	delete[] curGh;
//	delete[] itemX;
//	delete[] itemY;
//	delete[] itemInitX;
//	delete[] itemInitY;
//}