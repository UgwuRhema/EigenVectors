#include <iostream>
#include <cmath>

void printMatrix(int **, int, int);

int 
main(void)
{
	/* first of all, let's create a simple 2 by 2 matrix */
	int matrix[2][2] = {{1, 2}, {5, 6}};
	std::cout << "We have a square matrix as so: \n";
	printMatrix(&matrix, 2, 2);
	std::cout << "Let us find the Eigen-vector and its respective Eigen value of this matrix\n";
	return 0;
}

void
printMatrix(int **matrix, size_t rows, size_t columns)
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
