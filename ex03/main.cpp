#include <iostream>
#include <cstdlib> // For std::atof
#include "Point.hpp"

// Function to print test results
void printTestResult(int testNumber, const Point &a, const Point &b, const Point &c, const Point &point, bool result)
{
	std::cout << "Test " << testNumber << ": Checking point (" << point.getX().toFloat() << ", "
			  << point.getY().toFloat() << ")";
	std::cout << " with triangle ((" << a.getX().toFloat() << ", " << a.getY().toFloat() << "), ";
	std::cout << "(" << b.getX().toFloat() << ", " << b.getY().toFloat() << "), ";
	std::cout << "(" << c.getX().toFloat() << ", " << c.getY().toFloat() << ")) - ";
	std::cout << (result ? "Inside" : "Outside or On Edge") << std::endl;
}

// int main()
// {
// 	// Define triangle vertices
// 	Point a(0.0f, 0.0f);
// 	Point b(0.0f, 1.0f);
// 	Point c(1.0f, 0.0f);

// 	// Test points
// 	Point insidePoint(0.2f, 0.2f);
// 	Point outsidePoint(1.0f, 1.0f);
// 	Point onEdgePoint(0.5f, 0.5f);
// 	Point vertexPoint = a; // One of the vertices of the triangle

// 	// Perform tests
// 	bool result;

// 	result = bsp(a, b, c, insidePoint);
// 	printTestResult(1, a, b, c, insidePoint, result);

// 	result = bsp(a, b, c, outsidePoint);
// 	printTestResult(2, a, b, c, outsidePoint, result);

// 	result = bsp(a, b, c, onEdgePoint);
// 	printTestResult(3, a, b, c, onEdgePoint, result);

// 	result = bsp(a, b, c, vertexPoint);
// 	printTestResult(4, a, b, c, vertexPoint, result);

// 	// Add more tests as needed

// 	return 0;
// }

int main(int argc, char *argv[])
{
	if (argc != 9)
	{
		std::cerr << "Usage: " << argv[0] << " Ax Ay Bx By Cx Cy Px Py" << std::endl;
		return -1; // Changed to return a non-zero value to indicate error in usage.
	}

	// Convert arguments to float and create Points
	float Ax = std::atof(argv[1]), Ay = std::atof(argv[2]);
	float Bx = std::atof(argv[3]), By = std::atof(argv[4]);
	float Cx = std::atof(argv[5]), Cy = std::atof(argv[6]);
	float Px = std::atof(argv[7]), Py = std::atof(argv[8]);

	Point A(Ax, Ay), B(Bx, By), C(Cx, Cy), P(Px, Py);

	// Check if P is inside triangle ABC
	if (bsp(A, B, C, P))
	{
		std::cout << "Point (" << Px << ", " << Py << ") is inside the triangle." << std::endl;
		return 1; // Point is inside
	}
	else
	{
		std::cout << "Point (" << Px << ", " << Py << ") is outside the triangle or on an edge." << std::endl;
		return 0; // Point is outside or on an edge
	}

	return 0;
}
