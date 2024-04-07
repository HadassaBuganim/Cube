#ifndef CUBE_H
#define CUBE_H
#pragma once
#include "CubeWig.h"
typedef enum { RIGHT, LEFT } direction;
typedef enum { ROTATE_FACE_COL, ROTATE_FACE_ROW, SWAP_COL, SWAP_ROW } function;
typedef struct {
	direction dir;
	function fp;
	int* arr;
}obj;
class Cube
{
public:
	Cube(int size);
	~Cube();
	void rotateFace(int sideIndex, direction dir);
	void xorWithFaceZero();
	//a,b,c,d הם אינדקסים במערך הפאות בין 0 ל-6
	void swapRow(int a, int b, int c, int d, int index, direction dir);
	void swapCol(int a, int b, int c, int d, int index, direction dir);
	void rotate(int sideIndex, direction dir);
	//מובטח שמתקבלת מחרוזת שאורכה בדיוק כגודל התווים הנכנסים לקוביה כלומר אן בשניה * 24 
	void insertString(const std::string& binaryString);
	std::string extructString();
private:
	CubeWig wigs[6];
	int cubeSize;
	obj* arr[2];
};
#endif // CUBE_H
