//2015/10/18作成

#pragma once

class Menu {
public:	
	//enum
	enum Direction{hori=0,ver=1};//水平０、垂直１
	//コンストラクタ
	

	Menu(int r,//縦の行
		int c,//列
		int w,//メニュー幅
		int h,//メニューの高さ
		int ulX,int ulY,//メニューの左上座標	
		Direction d//水平か垂直
		);//格子状メニュー作成
	Menu(int r,int c,Direction d);//自由選択系
	~Menu();//デストラクタ

	void Initialize();//初期化
	void Finalize();//終了処理
	//セッター	
	//void setArrayTableInitXY();//アイテム座標の初期位置
	void setArrayTableXY();

	void setTableInitXY();//アイテムの初期位置セットｘｙ　何個目のメニューか
	
	//
	void setNowTabXY();//現在のテーブル位置
	//void setNowCurXY();//カーソル用座標
	//

	//ゲッター

	int getNowTabX(), getNowTabY();
	int getNowCurX(),getNowCurY();
	int getTableX(int ROW,int COLUMN);
	int getTableY(int ROW, int COLUMN);
		

	//計算関係
	void calHori( );//計算 横　メニュー(項目数）　現在の番号を返す
	//void draw();//描画
		
	//インライン関数
	inline int getNum(){return num;}
	inline int getRow(){return row;}
	inline int getColumn(){return column;}
	inline int getNRow(){return nRow;}
	inline int getNColumn(){return nColumn;}
	inline int Menu::getTWidth(){return tWidth;}
	inline int Menu::getTHeight(){return tHeight;}


protected:
	int num;//現在の項目番号
	int dir;//メニューの方向　水平＝hori　垂直 ver
	int row;//行
	int column;//列
	int numOfTables;//項目数

	int **tableX,**tableY;//項目の座標
	int **tableInitX, **tableInitY;//項目の初期座標

	int dWidth,dHeight;//描画領域の　幅　高さ
	int dUpLeftX,dUpLeftY;//描画領域の左上の座標

	int tWidth,tHeight;//各テーブルの幅　高さ

	int nRow,nColumn;//今の行　列

	int nowTabX,nowTabY;//今のテーブル座標
};

