#ifndef _MATRIX_H_
#define _MATRIX_H_

typedef int Type;

class Mat
{
public:
		Mat() {};
		Mat(int r,int c,Type *d);
		Mat Add(Mat m);
		Mat Subtract(Mat m);
		Mat Multiply(Mat m);
		void Print();
				

private:
		int row;
		int col;
		Type *data;
};



#endif
