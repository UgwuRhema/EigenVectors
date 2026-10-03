#include <iostream>
#include <cmath>

//since we are only working with square 2 by 2 matrices most
//of the time, let's just hardcode for now, i dont wanna use Templates...
void printMatrix(int (*)[2], size_t, size_t);

/* let's make the identity matrix */
constexpr float identity_matrix[2][2] = {
										{1.0f, 0.0f},
										{0.0f, 1.0f}
									};

int 
main(void)
{
	/* first of all, let's create a simple 2 by 2 matrix */
	int matrix[2][2] = {{1, 2}, {5, 6}};
	std::cout << "We have a square matrix as so: \n";
	printMatrix(matrix, 2, 2);
	std::cout << "Let us find the Eigen-vector and its respective Eigen value of this matrix\n";
	
	std::cout << "First step to finding an Eigen Vector is to find it's respective eigen values\n";
	std::cout << "Using this formula: A - EI = 0\n";
	std::cout << "\twhere A = square matrix, E = Eigen Value and I = Identity matrix\n";

	return 0;
}

void
printMatrix(int (*matrix)[2], size_t rows, size_t columns)
{
	for (size_t i = 0; i < rows; ++i)
	{
		std::cout << "[";
		for (size_t j = 0; j < columns; ++j)
		{
			std::cout << *(*(matrix + i) + j) << ' ';
		}
		std::cout << "\b]";
		std::cout << std::endl;
	}	
}
