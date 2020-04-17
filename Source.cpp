#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <cmath>

void made_of_array(float*, int);
float show_array(float*, int);
float find_average(float*, int);
int number_of_elements(float*, int, float);
float find_deviation(float* array, int size, float average);

using namespace std;
int main()
{
	int size, num_elements;
	float* A, average;

	cout << "Enter the size of array" << endl;
	while (1)
	{
		cin >> size;
		if (size < 33 && size > 0)
		{
			break;
		}
		else
		{
			cout << "Error, try again" << endl;
		}
	}
	system("cls");

	A = new float[size];     // выделение памяти под массив
	srand(time(NULL));

	made_of_array(A, size);
	show_array(A, size);
	average = find_average(A, size);
	cout << endl << "Average: " << fixed << setprecision(2) << average << endl;
	num_elements = number_of_elements(A, size, average);
	cout << "Number of elements that smaller than average: " << num_elements << endl;
	find_deviation(A, size, average);

	delete[] A;      // очистка памяти
	return 0;
}

void made_of_array(float* array, int size)
{
	for (int i = 0; i < size; i++)
	{
		array[i] = rand() % 3999 + (-1999);
	}
}

float show_array(float* array, int size)
{
	cout << "Source array: ";
	for (int i = 0; i < size; i++)
	{
		cout << fixed << setprecision(2) << array[i] << "\t";
	}
	return 0;
}

float find_average(float* array, int size)
{
	float s = 0, sum = 0, average;
	for (int i = 0; i < size; i++)
	{
		sum += array[i];
		s++;
	}
	average = sum / s;
	return average;
}

int number_of_elements(float* array, int size, float average)
{
	int s = 0;
	for (int i = 0; i < size; i++)
	{
		if (array[i] < average)
		{
			s++;
		}
	}
	return s;
}

float find_deviation(float* array, int size, float average)
{
	float min = 2000, deviation;
	for (int i = 0; i < size; i++)
	{
		if (array[i] < min)
		{
			min = array[i];
		}
	}
	if (min != 0)
	{
		deviation = fabs((average - min) / min); // формула отклонения 
		cout << "Deviation: " << fixed << setprecision(2) << deviation << "%" << endl;
	}
	else
	{
		cout << "Error" << endl;;
	}
	return 0;
}