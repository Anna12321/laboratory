#include <iostream>
using namespace std;
//����� ������� � �������
void output_array(double* array_numb, int array_size);
//����� ������� � �������
void output_matrix(double** matrix_int_data, int matrix_size);
//������ ���� ����� < 0 ����� 0
void RELU(double* a, int n);
//������ ���� ����� < 0 ����� 0
void RELU(double** a, int n);
//������� U_U [ Udal_U ] ��� �������� �������� == U
void U_U(double* x, int& n, double U);
//����������� ������� ��� ������ ���� ��������� �� ��������� ������� �� �������� �������
void DIAG(double** Y, int n, double U);