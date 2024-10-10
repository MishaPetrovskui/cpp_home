#include <iostream>
#include <time.h>
#include <windows.h>
using namespace std;

int randint(int min, int max)
{
	return (rand() % (max - min + 1)) + min;
}

void SetColor(int textColor, int bgColor)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole,
		(bgColor << 4) | textColor);
}

void print_array(int* array, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << ", ";
	}
	cout << "\b\b." << endl;
}

float suma(int* array, int size)
{
	float sumir = 0;
	for (int i = 0; i < size; i++)
	{
		sumir += array[i];
	}
	return sumir;
}

float seredne_arifmetichne(int* array, int size)
{
	float i = suma(array, size) / size;
	return i;
}

bool find_in_array(int value, int array[], int size)
{
	for (int i = 0; i < value; i++)
		if (array[i] == value)
			return true;
	return false;
}

int main()
{
	srand(time(NULL));
	int size1 = 0;
	int size2 = 0;
	int size3 = 0;
	cout << "int size1: ";
	cin >> size1;
	cout << "int size2: ";
	cin >> size2;
	size3 = size1 + size2;
	int* array1 = new int[size1];
	int* array2 = new int[size2];
	int* array3 = new int[size3];
	int* unique_array1 = new int[size1];
	int* unique_array2 = new int[size2];
	int* unique_array3 = new int[size3];
	int unique_size1 = 0, unique_size2 = 0, unique_size3 = 0;
	for (int i = 0; i < size1; i++)
	{
		array1[i] = randint(0, 100);
	}
	print_array(array1, size1);
	for (int i = 0; i < size2; i++)
	{
		array2[i] = randint(0, 100);
	}
	print_array(array2, size2);
	for (int i = 0; i < size1; i++)
	{
		array3[i] = array1[i];
	}
	print_array(array3, size3);
	for (int i = size1; i < size1 + size2; i++)
	{
		array3[i] = array2[i - size1];
	}
	SetColor(2, 0);
	print_array(array1, size1);
	print_array(array2, size2);
	print_array(array3, size3);
	SetColor(7, 0);
	for (int i = 0; i < size1; i++)
	{
		if (!find_in_array(array1[i], unique_array1, unique_size1))
		{
			unique_array1[unique_size1++] = array1[i];
		}
	}

	for (int i = 0; i < size2; i++)
	{
		if (!find_in_array(array2[i], unique_array2, unique_size2))
		{
			unique_array2[unique_size2++] = array2[i];
		}
	}
	for (int i = 0; i < size3; i++)
	{
		if (!find_in_array(array3[i], unique_array3, unique_size3))
		{
			unique_array3[unique_size3++] = array3[i];
		}
	}

	SetColor(12, 0);
	print_array(unique_array1, unique_size1);
	print_array(unique_array2, unique_size2);
	print_array(unique_array3, unique_size3);
	SetColor(7, 0);
	delete[] array1;
	delete[] array2;
	delete[] array3;
	delete[] unique_array1;
	delete[] unique_array2;
	delete[] unique_array3;

	return 0;
}
