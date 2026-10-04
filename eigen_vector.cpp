#include <iostream>
#include <cmath>

//since we are only working with square 2 by 2 matrices most
//of the time, let's just hardcode for now, i dont wanna use Templates...
void printMatrix(float (*)[2], size_t, size_t);
void quadEqtn(float, float, float, float *);
float solveDeterminantOfMatrix(float (*)[2]);

/* let's make the identity matrix */
constexpr float identity_matrix[2][2] = {
										{1.0f, 0.0f},
										{0.0f, 1.0f}
									};
int
main(void)
{
	/* first of all, let's create a simple 2 by 2 matrix */
	float matrix[2][2] = {
		{1.0f, 2.0f}, 
		{5.0f, 6.0f}
	};
	std::cout << "We have a square matrix as so: \n";
	printMatrix(matrix, 2, 2);
	std::cout << "Let us find the Eigen-vector and its respective Eigen value of this matrix\n";
	
	std::cout << "First step to finding an Eigen Vector is to find it's respective eigen values\n";
	std::cout << "Using this formula: A - EI = 0\n";
	std::cout << "\twhere A = square matrix, E = Eigen Value and I = Identity matrix\n";

	/* let's try a simple quad equation solver that returns 2 roots */
	float roots[2] = {0};
	quadEqtn(2, -5, -3, roots);
	float determinant = solveDeterminantOfMatrix(matrix);
	std::cout << "The determinant of the matrix is: " << determinant << '\n';
	return 0;
}

void
printMatrix(float (*matrix)[2], size_t rows, size_t columns)
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

float
solveDeterminantOfMatrix(float (*matrix)[2])
{
	//[ a, b ]
	//[ c, d ]

	float first_diagonal = *(*(matrix)) * *(*(matrix + 1) + 1);
	float second_diagonal = matrix[0][1] * matrix[1][0];
	return first_diagonal - second_diagonal;
}

void
quadEqtn(float a, float b, float c, float *eigen_values)
{
	float discriminant = ((b * b) - (4.0f * a * c));
	if (discriminant >= 0.0f)
	{
		float lambda1 = (float)((-b + std::sqrt(discriminant)) / (2.0f * a));
		float lambda2 = (float)((-b - std::sqrt(discriminant)) / (2.0f * a));
		std::cout << "The Eigen Values are: " << lambda1 << " & ";
		std::cout << lambda2 << '\n';
		eigen_values[0] = lambda1;
		eigen_values[1] = lambda2;
	} else {
		std::cerr << "No real Eigen Vectors, only Complex imaginary EigenVectors\n";
		std::cerr << "Which causes rotation of the matrix, which beats the point\n";
		std::cerr << "So we will not be computing that!\n";
	}
}
