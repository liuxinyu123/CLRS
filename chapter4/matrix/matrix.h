#ifndef _MATRIX_H_
#define _MATRIX_H_

typedef int Type;

class Mat
{
public:
		Mat(int r = 1,int c = 1);
		void SetRow(int r);
		void SetColomn(int c);
		void InitMat();
		void FreeMat();
		int GetRow();
		int GetColomn();
		Type Read(int r,int c);
		void Write(int r,int c,Type d);
		int IsSquare();
		Mat& Add(Mat m);
		Mat& Subtract(Mat m);
		Mat& Multiply(Mat m);
		void Print();
				

private:
		int row;
		int col;
		Type *data;
};



#endif
