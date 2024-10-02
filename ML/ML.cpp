#include <iostream>
using namespace std;

const int LENGTH = 15;
const int R = 6;
const int STANDART_NUMBERS[10][LENGTH] = {
	{ 1, 1, 1 ,1, 0, 1, 1, 0, 1, 1, 0, 1 ,1, 1, 1 },
	{ 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1 ,0, 0, 1 },
	{ 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0 ,1, 1, 1 },
	{ 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1 ,1, 1, 1 },
	{ 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1 ,0, 0, 1 },
	{ 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1 ,1, 1, 1 },
	{ 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 1 ,1, 1, 1 },
	{ 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1 ,0, 0, 1 },
	{ 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1 ,1, 1, 1 },
	{ 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1 ,1, 1, 1 }
};
// BIN0 = 1 
int w[] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };

/*
void ARRAY_WRITE(int **arr)
{
	for (int i = 0; i < 2; i++) {
		*(arr + i) = new int[15];
	}

	for (int i = 0; i < 2; i++) {

		for (int j = 0; j < 15; j++) {
			*(*(arr + i) + j) = 8;
			if (j == 5) { 
				*(*(arr + i) + j) = 10; 
			}
		}
	}
}
*/


void WRITE_ARRAY(int** arr, int* _NumberCOUNT, int *_MAIN_NUM, bool _LEARNING_TRUE)
{	
	for (int i = 0; i < *(_NumberCOUNT); i++) {
		*(arr + i) = new int[LENGTH];
		cout << i + 1 << "_NUMBER!\n";
		for (int U_NUMBER =0, j = 0; j < LENGTH; j++) {			
			if (_LEARNING_TRUE) {
				if (i == 0)
				{
					*(*(arr + i) + j) = STANDART_NUMBERS[*(_MAIN_NUM)][j];
				}
				else
				{
					cin >> U_NUMBER;
					*(*(arr + i) + j) = U_NUMBER;
				}
			}
			else if (!_LEARNING_TRUE) 
			{
				if (i <= 9)
				{
					if (i == *(_MAIN_NUM)) {
						*(*(arr + i) + j) = 0;
					}
					else 
					{
						*(*(arr + i) + j) = STANDART_NUMBERS[i][j];
					}
				}
				else 
				{
					cin >> U_NUMBER;
					*(*(arr + i) + j) = U_NUMBER;
				}

			}
			
		}
	}
}

void show(int** arr, int* _NumberCOUNT)
{
	for (int i = 0; i < *(_NumberCOUNT); i++) 
	{
		for (int j = 0; j < LENGTH; j++) 
		{
			cout << *(*(arr + i) + j);
		}
		cout << "\n";
	}
}

bool CHECK_R(int** arr, int* _NumberCOUNT, bool _main)
{
	int r = 0;
	for (int i = 0; i < *(_NumberCOUNT); i++) 
	{
		r = 0;
		for (int j = 0; j < LENGTH; j++) 
		{
			r += *(*(arr + i) + j) * w[j];
		}
		if ((_main && r < R) || (!_main && r >= R) ) 
		{
			return false;
		}
	}
	return true;
}

void LEARNING_MACHINE(int** TRUE_ARR, int** FALSE_ARR, int* TRUE_NumberCOUNT, int* FALSE_NumberCOUNT)
{
	cout << "START_MACHINE LEARNING..............\n";

	while (!(CHECK_R(&*TRUE_ARR, &*(TRUE_NumberCOUNT), true) && CHECK_R(&*FALSE_ARR, &*(FALSE_NumberCOUNT), false)))
	{
		if (!CHECK_R(&*TRUE_ARR, &*(TRUE_NumberCOUNT), true)) 
		{
			for (int i = 0; i < *(TRUE_NumberCOUNT); i++) 
			{
				for (int j = 0; j < LENGTH; j++) 
				{
					if (*(*(TRUE_ARR + i) + j) == 1)
					{
						w[j] = w[j] + 1;
					}
				}
			}
		}
		if (!CHECK_R(&*FALSE_ARR, &*(FALSE_NumberCOUNT), false)) 
		{
			for (int i = 0; i < *(FALSE_NumberCOUNT); i++)
			{
				for (int j = 0; j < LENGTH; j++)
				{
					if (*(*(FALSE_ARR + i) + j) == 1)
					{
						w[j] = w[j] - 1;
					}
				}
			}
		}
	}
	cout << "END_MACHINE LEARNING..............\n";
}


int main()
{

	int TRUE_NumberCOUNT, FALSE_NumberCOUNT, YOUR_NUMBER;
	cout << "Select u number(0-9) = "; cin >> YOUR_NUMBER;
	cout << "Write count binary number for learning(True) = "; cin >> TRUE_NumberCOUNT;
	TRUE_NumberCOUNT = TRUE_NumberCOUNT + 1; // +YOUR_NUM
	cout << "So, well. Now write this numbers in binary form:" << "\n";
	int** _LEARNING_TRUE = new int* [TRUE_NumberCOUNT];
	WRITE_ARRAY(&*_LEARNING_TRUE, &TRUE_NumberCOUNT, &YOUR_NUMBER, true);
	cout << "Write count binary number for learning(False) = "; cin >> FALSE_NumberCOUNT;
	FALSE_NumberCOUNT = FALSE_NumberCOUNT + 10; // +STANDART_NUMS
	cout << "So, well. Now write this numbers in binary form:" << "\n";
	int** _LEARNING_FALSE = new int* [FALSE_NumberCOUNT];
	WRITE_ARRAY(&*_LEARNING_FALSE, &FALSE_NumberCOUNT, &YOUR_NUMBER, false);
	//show(&*_LEARNING_TRUE, &TRUE_NumberCOUNT);
	//cout << "-----------------------------------------------------------------------------\n";
	//show(&*_LEARNING_FALSE, &FALSE_NumberCOUNT);
	LEARNING_MACHINE(&*_LEARNING_TRUE, &*_LEARNING_FALSE, &TRUE_NumberCOUNT, &FALSE_NumberCOUNT);

	//cleaning.....
	delete[] _LEARNING_FALSE;
	delete[] _LEARNING_TRUE;

	int* p = &TRUE_NumberCOUNT;
	cout << "Okey, now enter binary number for determine. How much will numbers? "; cin >> *p;
	int** ptrTEST_ARR = new int* [*p];
	for (int i = 0; i < *p; i++)
	{
		*(ptrTEST_ARR + i) = new int[LENGTH];

		for (int U_NUMBER, j = 0; j < LENGTH; j++)
		{
			cin >> U_NUMBER;
			*(*(ptrTEST_ARR + i) + j) = U_NUMBER;
		}
	}
	
	for (int r = 0, i = 0; i < *p; i++)
	{
		for (int U_NUMBER, j = 0; j < LENGTH; j++)
		{
			r += *(*(ptrTEST_ARR + i) + j) * w[j];
		}
		if (r >= R) 
		{
			cout << "Is u NUMBER = " << YOUR_NUMBER << "\n";
		}
		else 
		{
			cout << "Is not u NUMBER = " << YOUR_NUMBER << "\n";
		}
	}
	// cleaning....
	p = nullptr;
	delete p;

	cout << "-----------------------------\n";
	for (int i = 0; i < LENGTH; i++) 
	{
		cout << w[i] << " ";
		if (i % 3 == 2 || i == 2) {
			cout << "\n";
		}
	}

	//int* point = new int[5] {1,2};
	//int** pointer = new int*[2];

	//cout << *point << "\n";
	//cout << *(point + 1) * 2 << "\n";
	//cout << *(point + 2) << "\n";
	
	//delete[]point;
 
	//cout << *(pointer) << "\n";
	//cout << *(pointer)+2 << "\n";
	//cout << *(pointer + 2) << "\n" << "=================================================================================="<<"\n";
	//cout << *(*(pointer + 1) + 5) * 8 << "\n";

	//ARRAY_WRITE(&*pointer);

	//cout << *(*(pointer)) << "\n"; //8
	//cout << *(*(pointer)) + 2 << "\n"; //10
	//cout << *(pointer + 2) << "\n"; // memory
	//cout << *(*(pointer + 1) + 5) * 8 << "\n"; // 80

	
	return 0;
}
