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

	//стандартные значения размерностей векторов и матриц
	int array_size_1 = 5, array_size_2 = 10;
	int matrix_size = 4;
		
	try//работа через командную строку
	{
		options_description desc{ "Options" };
		desc.add_options()
			("help,h", "Help screen")
			("array_size_1", value<int>()->notifier(on_array_size_1), "on_array_size_1")//размер векторов
			("array_size_2", value<int>()->notifier(on_array_size_2), "on_array_size_2")//размер векторов
			("matrix_size", value<int>()->notifier(on_matrix_size), "Matrix_size");//размер матриц

		variables_map vm;
		//labaratory --array_size_1 7 --array_size_2 3
		store(parse_command_line(argc, argv, desc), vm);
		notify(vm);
		if (vm.count("help"))
			std::cout << desc << '\n';
		else if (vm.count("array_size_1")) {
			std::cout << "Array_size_1: " << vm["array_size_1"].as<int>() << '\n';
			array_size_1 = vm["array_size_1"].as<int>();//записываем в наш размер значение из командной строки
		}
		if (vm.count("help"))
			std::cout << desc << '\n';
		else if (vm.count("array_size_2")) {
			std::cout << "Array_size_2: " << vm["array_size_2"].as<int>() << '\n';
			array_size_2 = vm["array_size_2"].as<int>();//записываем в наш размер значение из командной строки
		}
		if (vm.count("help"))
			std::cout << desc << '\n';
		else if (vm.count("matrix_size")) {
			std::cout << "Matrix_size: " << vm["matrix_size"].as<int>() << '\n';
			matrix_size = vm["matrix_size"].as<int>();//записываем в наш размер значение из командной строки
		}
			}
	catch (const error& ex)
	{
		std::cerr << ex.what() << '\n';
	}
	
	//объявление динамических векторов и матриц 
	double* array_1 = new double[array_size_1];
	double* array_2 = new double[array_size_2];

	double** matrix_1 = new double* [matrix_size];
	double** matrix_2 = new double* [matrix_size];

	for (int i = 0; i < matrix_size; i++) {
		matrix_1[i] = new double[matrix_size];
		matrix_2[i] = new double[matrix_size];
	}

	//начальная инициализация
	initialization(array_1, array_2, array_size_1, array_size_2, matrix_1, matrix_2, matrix_size);
	printf("\nНачальный вектор 1: ");
	output_array(array_1, array_size_1);
	printf("\nНачальный вектор 2: ");
	output_array(array_2, array_size_2);
	printf("\nНачальная матрица 1: \n");
	output_matrix(matrix_1, matrix_size);
	printf("\nНачальная матрица 2: \n");
	output_matrix(matrix_2, matrix_size);

	RELU(array_2, array_size_2);
	printf("\nВектор после функции RELU: \n");
	output_array(array_2, array_size_2);

	RELU(matrix_2, matrix_size);
	printf("\nМатрица после функции RELU: \n");
	output_matrix(matrix_2, matrix_size);

	printf("\nВектор после функции U_U: \n");
	U_U(array_1, array_size_1, 32.32);
	output_array(array_1, array_size_1);

	printf("\nВектор после функции DIAG: \n");
	DIAG(matrix_1, matrix_size, 32.32);
	output_matrix(matrix_1, matrix_size);

	cout << endl;
	system("pause");
}


