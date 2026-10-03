#include <iostream>
#include <cmath>

int main(void)
{
	/* first of all, let's create a simple 2 by 2 matrix */
	int matrix[2][2] = {{1, 2}, {5, 6}};
	for (size_t i = 0; i < 2; ++i)
	{
		std::cout << "[";
		for (size_t j = 0; j < 2; ++j)
		{
			std::cout << matrix[i][j] << ' ';
		}
		std::cout << "]";
		std::cout << std::endl;
	}
	return 0;
}
