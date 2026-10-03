#include <iostream>
#include <cmath>

int main(void)
{
	/* first of all, let's create a simple matrix */
	int matrix[2][2] = {{1, 2}, {3, 4}};
	size_t soem = sizeof(*(matrix)) / sizeof(matrix[0][0]);
	for (int i = 0; i < soem; ++i)
	{
		for (int j = 0; j < soem; ++j)
		{
			std::cout << matrix[i][j];
		}
		std::cout << std::endl;
	}
	return 0;
}
