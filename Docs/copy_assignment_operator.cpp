#include <iostream>

class Sample {
public:
  // Constructor
  Sample(int size) {
    this->size = size;
    data = new int[size];
    for (int i = 0; i < size; i++) {
      data[i] = 0;
    }
  }
  // Custom copy constructor
  Sample(const Sample &other) {
    size = other.size;
    data = new int[size];
    for (int i = 0; i < size; i++) {
      data[i] = other.data[i];
    }
  }
  // Custom copy assignment operator
  // operator is a special keyword used to overload operators
  Sample &operator=(const Sample &other) {
    // Check for self assignment
    if (this != &other) {
      // delete[] this->data; // Same
      delete[] data; // Release old resources
      size = other.size;
      data = new int[size]; // Allocate new resources
      for (int i = 0; i < size; i++) {
        data[i] = other.data[i];
      }
    }
    return *this;
  }
  ~Sample() { delete[] data; }

  // Method to modify the first element (if it exists)
  void modifyFirstElement(int value) {
    if (size > 0) {
      data[0] = value;
    }
  }
  // Method to print the first element (if it exists)
  void printFirstElement() {
    if (size > 0) {
      std::cout << data[0] << std::endl;
    }
  }

private:
  int size;
  int *data;
};

int main() {
  Sample obj1(1);
  obj1.modifyFirstElement(10);

  Sample obj2(2);
  obj2.modifyFirstElement(20);

  obj1 = obj2; // Copy assignment operator

  std::cout << "obj1: ";
  obj1.printFirstElement();

  std::cout << "obj2: ";
  obj2.printFirstElement();

  obj1.modifyFirstElement(30);
  std::cout << "obj1 (after modification): ";
  obj1.printFirstElement();

  std::cout << "obj2 (after modification): ";
  obj2.printFirstElement();
}