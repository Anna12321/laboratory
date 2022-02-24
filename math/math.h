#include <iostream>
using namespace std;
//вывод вектора в консоль
void output_array(double* array_numb, int array_size);
//вывод матрицы в консоль
void output_matrix(double** matrix_int_data, int matrix_size);
//замена всех чисел < 0 самим 0
void RELU(double* a, int n);
//замена всех чисел < 0 самим 0
void RELU(double** a, int n);
//функция U_U [ Udal_U ] для удаления элемента == U
void U_U(double* x, int& n, double U);
//определение функции для замены всех элементов на диагонале матрицы на заданный элемент
void DIAG(double** Y, int n, double U);