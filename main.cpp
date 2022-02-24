#include "functions.h"
#include "math\math.h"
#include <boost/program_options.hpp>

using namespace boost::program_options;

void on_array_size_1(int number)
{
	std::cout << "On array_size_1: " << number << '\n';
}
void on_array_size_2(int number)
{
	std::cout << "On array_size_2: " << number << '\n';
}
void on_matrix_size(int number)
{
	std::cout << "On matrix_size: " << number << '\n';
}

void main(int argc, const char* argv[]) {
	setlocale(LC_ALL, "rus");
	srand(time(NULL));

	//����������� �������� ������������ �������� � ������
	int array_size_1 = 5, array_size_2 = 10;
	int matrix_size = 4;
		
	try//������ ����� ��������� ������
	{
		options_description desc{ "Options" };
		desc.add_options()
			("help,h", "Help screen")
			("array_size_1", value<int>()->notifier(on_array_size_1), "on_array_size_1")//������ ��������
			("array_size_2", value<int>()->notifier(on_array_size_2), "on_array_size_2")//������ ��������
			("matrix_size", value<int>()->notifier(on_matrix_size), "Matrix_size");//������ ������

		variables_map vm;
		//labaratory --array_size_1 7 --array_size_2 3
		store(parse_command_line(argc, argv, desc), vm);
		notify(vm);
		if (vm.count("help"))
			std::cout << desc << '\n';
		else if (vm.count("array_size_1")) {
			std::cout << "Array_size_1: " << vm["array_size_1"].as<int>() << '\n';
			array_size_1 = vm["array_size_1"].as<int>();//���������� � ��� ������ �������� �� ��������� ������
		}
		if (vm.count("help"))
			std::cout << desc << '\n';
		else if (vm.count("array_size_2")) {
			std::cout << "Array_size_2: " << vm["array_size_2"].as<int>() << '\n';
			array_size_2 = vm["array_size_2"].as<int>();//���������� � ��� ������ �������� �� ��������� ������
		}
		if (vm.count("help"))
			std::cout << desc << '\n';
		else if (vm.count("matrix_size")) {
			std::cout << "Matrix_size: " << vm["matrix_size"].as<int>() << '\n';
			matrix_size = vm["matrix_size"].as<int>();//���������� � ��� ������ �������� �� ��������� ������
		}
			}
	catch (const error& ex)
	{
		std::cerr << ex.what() << '\n';
	}
	
	//���������� ������������ �������� � ������ 
	double* array_1 = new double[array_size_1];
	double* array_2 = new double[array_size_2];

	double** matrix_1 = new double* [matrix_size];
	double** matrix_2 = new double* [matrix_size];

	for (int i = 0; i < matrix_size; i++) {
		matrix_1[i] = new double[matrix_size];
		matrix_2[i] = new double[matrix_size];
	}

	//��������� �������������
	initialization(array_1, array_2, array_size_1, array_size_2, matrix_1, matrix_2, matrix_size);
	printf("\n��������� ������ 1: ");
	output_array(array_1, array_size_1);
	printf("\n��������� ������ 2: ");
	output_array(array_2, array_size_2);
	printf("\n��������� ������� 1: \n");
	output_matrix(matrix_1, matrix_size);
	printf("\n��������� ������� 2: \n");
	output_matrix(matrix_2, matrix_size);

	RELU(array_2, array_size_2);
	printf("\n������ ����� ������� RELU: \n");
	output_array(array_2, array_size_2);

	RELU(matrix_2, matrix_size);
	printf("\n������� ����� ������� RELU: \n");
	output_matrix(matrix_2, matrix_size);

	printf("\n������ ����� ������� U_U: \n");
	U_U(array_1, array_size_1, 32.32);
	output_array(array_1, array_size_1);

	printf("\n������ ����� ������� DIAG: \n");
	DIAG(matrix_1, matrix_size, 32.32);
	output_matrix(matrix_1, matrix_size);

	cout << endl;
	system("pause");
}


