#include "functions.h"
using namespace std;
//функция для начальной инициализации двух векторов и матриц
void initialization(double* array_1, double* array_2, int array_size_1, int array_size_2, double** matrix_1, double** matrix_2, int matrix_size) {
	
	for (int i = 0; i < array_size_1; i++)
		array_1[i] = i - i * rand() % 255;//заполнение случайными значениями

	for (int i = 0; i < array_size_2; i++)
		array_2[i] = i + rand() % 255;//заполнение случайными значениями

	for (int i = 0; i < matrix_size; i++)
		for (int j = 0; j < matrix_size; j++) {
			matrix_1[i][j] = rand() % 255 - 100;//заполнение случайными значениями
			matrix_2[i][j] = rand() % 255 - 100;//заполнение случайными значениями
		}
}
