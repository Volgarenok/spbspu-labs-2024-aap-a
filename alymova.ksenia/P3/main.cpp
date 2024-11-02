int main(int argc, char** argv)
{
	int num = 0;
	try
	{
		alymova::check_argc(argc);
		num = alymova::check_num(argv[1]);
	}
	catch (const std::logic_error& e)
	{
		std::cout << e.what() << "\n";
		return 1;
	}
	std::ifstream input(argv[2]);
	std::ofstream output(argv[3]);
	size_t rows = 0, cols = 0;
	if (input_size(input, rows, cols).good())
	{
		int* matrix = nullptr;
		if (num == 2)
		{
			try
			{
				matrix = create_dynamic(rows, cols);
			}
			catch (const std::bad_alloc& e)
			{
				destroy(matrix);
				std::cerr << "Memory not allocated for array\n";
				return 1;
			}
		}
		if (num == 1)
		{
			matrix = create_static(rows, cols);
		}
		size_t read = 0;
		if (!(input_matrix(input, matrix, rows, cols, read)))
		{
			std::cerr << "Input matrix fail\n";
			if (num == 2)
			{
				destroy(matrix);
			}
			return 2;
		}
		change_matrix(matrix, rows, cols);
		if (output.good())
		{
			print_matrix(output, matrix, rows, cols);
		}
	}
}