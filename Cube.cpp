#include "Cube.h"
#include <vector>
Cube::Cube(int size)
{
	//הגדרות הקוביה
	cubeSize = size;
	for (size_t i = 0; i < 6; i++)
	{
		wigs[i] = CubeWig(size);
	}
	//הגדרת מערך הפונקציות
	int n = cubeSize;
	arr[0] = new obj[n * 3];
	arr[1] = new obj[n * 3];
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3 * n; j++)
		{
			//הגדרת כיוון, 0 לימין 1 לשמאל
			arr[0][j].dir = (i == 0 ? RIGHT : LEFT);
			//בשביל הפאות
			if (i % n == 0 || i % n == 1)
			{
				arr[i][j].arr = new int[6];
				if (i == 2 * n + 1 || i == n * 3)
					arr[i][j].fp = ROTATE_FACE_ROW;
				else
					arr[i][j].fp = ROTATE_FACE_COL;
				if (i == 1)
				{
					arr[i][j].arr[0] = 4;
					arr[i][j].arr[1] = 2;
					arr[i][j].arr[2] = 0;
					arr[i][j].arr[3] = 3;
					arr[i][j].arr[4] = 5;
				}
				if (i == n)
				{
					arr[i][j].arr[0] = 1;
					arr[i][j].arr[1] = 2;
					arr[i][j].arr[2] = 5;
					arr[i][j].arr[3] = 3;
					arr[i][j].arr[4] = 0;
				}
				if (i == n + 1)
				{
					arr[i][j].arr[0] = 0;
					arr[i][j].arr[1] = 2;
					arr[i][j].arr[2] = 1;
					arr[i][j].arr[3] = 3;
					arr[i][j].arr[4] = 4;
				}
				if (i == n * 2)
				{
					arr[i][j].arr[0] = 5;
					arr[i][j].arr[1] = 2;
					arr[i][j].arr[2] = 4;
					arr[i][j].arr[3] = 3;
					arr[i][j].arr[4] = 1;
				}
				if (i == 2 * n + 1)
				{
					arr[i][j].arr[0] = 2;
					arr[i][j].arr[1] = 5;
					arr[i][j].arr[2] = 1;
					arr[i][j].arr[3] = 0;
					arr[i][j].arr[4] = 4;
				}
				if (i == n * 3)
				{
					arr[i][j].arr[0] = 3;
					arr[i][j].arr[1] = 0;
					arr[i][j].arr[2] = 1;
					arr[i][j].arr[3] = 5;
					arr[i][j].arr[4] = 4;
				}
				arr[i][j].arr[0] = 0;
			}
			else
			{
				//הגדרת מערך בגודל 5 לאינדקסים
				arr[i][j].arr = new int[5];
				//פאה מס'0
				if (i > 1 && i < n)
				{
					arr[i][j].fp = SWAP_COL;
					//ימין
					if (arr[i][j].dir == RIGHT)
					{
						arr[i][j].arr[0] = 0;
						arr[i][j].arr[1] = 3;
						arr[i][j].arr[2] = 5;
						arr[i][j].arr[3] = 2;
					}
					//שמאל
					else
					{
						arr[i][j].arr[0] = 0;
						arr[i][j].arr[1] = 2;
						arr[i][j].arr[2] = 5;
						arr[i][j].arr[3] = 3;
					}
					arr[i][j].arr[4] = i - 1;
				}
				else
				{
					//פאה מס' 1
					if (i > n + 1 && i < n * 2)
					{
						arr[i][j].fp = SWAP_COL;
						//ימין
						if (arr[i][j].dir == RIGHT)
						{
							arr[i][j].arr[0] = 1;
							arr[i][j].arr[1] = 3;
							arr[i][j].arr[2] = 4;
							arr[i][j].arr[3] = 2;
						}
						//שמאל
						else
						{
							arr[i][j].arr[0] = 1;
							arr[i][j].arr[1] = 2;
							arr[i][j].arr[2] = 4;
							arr[i][j].arr[3] = 3;
						}
						arr[i][j].arr[4] = i - n - 1;
					}
					//רוחב הקוביה
					else
					{
						arr[i][j].fp = SWAP_ROW;
						//ימין
						if (arr[i][j].dir == RIGHT)
						{
							arr[i][j].arr[0] = 0;
							arr[i][j].arr[1] = 1;
							arr[i][j].arr[2] = 5;
							arr[i][j].arr[3] = 4;
						}
						//שמאל
						else
						{
							arr[i][j].arr[0] = 0;
							arr[i][j].arr[1] = 4;
							arr[i][j].arr[2] = 5;
							arr[i][j].arr[3] = 1;
						}
						arr[i][j].arr[4] = i - n * 2 - 1;
					}
				}
			}
		}
	}
}
Cube::~Cube() {
}
void Cube::insertString(const std::string& binaryString)
{
	std::vector<std::string> dividedStrings;
	int partLength = binaryString.length() / 6;
	for (int i = 0; i < 6; ++i) {
		int startIndex = i * partLength;
		std::string part = binaryString.substr(startIndex, partLength);
		dividedStrings.push_back(part);
	}
	for (int i = 0; i < 6; i++)
	{
		wigs[i].insertString(dividedStrings[i]);
	}
}
std::string Cube::extructString()
{
	std::string str = "";
	for (int i = 0; i < 6; i++)
	{
		str += wigs[i].extractString();
	}
	return str;
}
void Cube::xorWithFaceZero()
{
	for (size_t i = 1; i < 6; i++)
	{
		for (size_t j = 0; j < cubeSize; j++)
		{
			for (size_t k = 0; k < cubeSize; k++)
			{
				wigs[i].getInternalMatrix(j, k).xorWithOtherMatrix(wigs[0].getInternalMatrix(j, k));
			}
		}
	}
}
void Cube::rotateFace(int sideIndex, direction dir)
{
	if (dir == LEFT)
	{
		if (sideIndex >= 0 && sideIndex < 6)
		{
			wigs[sideIndex].rotateLeft();
			for (size_t i = 0; i < cubeSize; i++)
			{
				for (size_t j = 0; j < cubeSize; j++)
				{
					wigs[sideIndex].getInternalMatrix(i, j).rotateLeft();
				}
			}
		}
	}
	else
	{
		if (sideIndex >= 0 && sideIndex < 6)
		{
			wigs[sideIndex].rotateRight();
			for (size_t i = 0; i < cubeSize; i++)
			{
				for (size_t j = 0; j < cubeSize; j++)
				{
					wigs[sideIndex].getInternalMatrix(i, j).rotateRight();
				}
			}
		}
	}
}
void Cube::swapRow(int a, int b, int c, int d, int index, direction dir)
{
	InternalMatrix* temp = new InternalMatrix[cubeSize];
	for (size_t i = 0; i < cubeSize; i++)
	{
		temp[i] = wigs[d].getInternalMatrix(index, i);
	}
	for (size_t i = 0; i < cubeSize; i++)
	{
		wigs[d].getInternalMatrix(index, i) = wigs[c].getInternalMatrix(index, i);
	}
	for (size_t i = 0; i < cubeSize; i++)
	{
		wigs[c].getInternalMatrix(index, i) = wigs[b].getInternalMatrix(index, i);
	}
	for (size_t i = 0; i < cubeSize; i++)
	{
		wigs[b].getInternalMatrix(index, i) = wigs[a].getInternalMatrix(index, i);
	}
	for (size_t i = 0; i < cubeSize; i++)
	{
		wigs[a].getInternalMatrix(index, i) = temp[i];
	}
}
//החלפת שורה לסדר
void Cube::swapCol(int a, int b, int c, int d, int index, direction dir)
{
	InternalMatrix* temp = new InternalMatrix[cubeSize];
	for (size_t i = 0; i < cubeSize; i++)
	{
		temp[i] = wigs[d].getInternalMatrix(i, index);
	}
	for (size_t i = 0; i < cubeSize; i++)
	{
		temp[i] = wigs[c].getInternalMatrix(i, index);
	}
	for (size_t i = 0; i < cubeSize; i++)
	{
		temp[i] = wigs[b].getInternalMatrix(i, index);
	}
	for (size_t i = 0; i < cubeSize; i++)
	{
		temp[i] = wigs[a].getInternalMatrix(i, index);
	}
	for (size_t i = 0; i < cubeSize; i++)
	{
		wigs[a].getInternalMatrix(i, index) = temp[i];
	}
}
void Cube::rotate(int sideIndex, direction dir)
{
	// בדיקה אם הסיבוב הוא על פאה
	if (arr[dir][sideIndex].fp == ROTATE_FACE_COL)
	{
		rotateFace(arr[dir][sideIndex].arr[0], dir);
		swapCol(arr[dir][sideIndex].arr[1], arr[dir][sideIndex].arr[2], arr[dir][sideIndex].arr[3], arr[dir][sideIndex].arr[4], arr[dir][sideIndex].arr[5], dir);
	}
	else
	{
		if (arr[dir][sideIndex].fp == ROTATE_FACE_ROW)
		{
			rotateFace(arr[dir][sideIndex].arr[0], dir);
			swapRow(arr[dir][sideIndex].arr[1], arr[dir][sideIndex].arr[2], arr[dir][sideIndex].arr[3], arr[dir][sideIndex].arr[4], arr[dir][sideIndex].arr[5], dir);
		}
		// סיבוב על אינדקס שהוא לא פאה
		else
		{
			if (arr[dir][sideIndex].fp == SWAP_COL)
				swapCol(arr[dir][sideIndex].arr[0], arr[dir][sideIndex].arr[1], arr[dir][sideIndex].arr[2], arr[dir][sideIndex].arr[3], arr[dir][sideIndex].arr[4], dir);
			else
				swapRow(arr[dir][sideIndex].arr[0], arr[dir][sideIndex].arr[1], arr[dir][sideIndex].arr[2], arr[dir][sideIndex].arr[3], arr[dir][sideIndex].arr[4], dir);
		}
	}
	xorWithFaceZero();
}