# CPP02

**C++ module for the core curriculum @42Berlin**

- Ad-hoc polymorphism
- operator overloading
- Orthodox Canonical Form

## 01 My First Class in Orthodox Canonical Form

- [ ] Orthodox Canonical Form

  - [ ] Default construstor
  - [ ] Copy Constructor
  - [ ] Copy assignment operator
  - [ ] Default Destructor

- [ ] Operator overloading
- [ ] Fixed point numbers vs Floating point numbers

The main.cpp is given, in the subject.

### The orthodox canonical form and the rule of three

- [Rule of three](<https://en.wikipedia.org/wiki/Rule_of_three_(C%2B%2B_programming)>)
- [Copy constructor](<https://en.wikipedia.org/wiki/Copy_constructor_(C%2B%2B)>)
- [Copy assignment operator](<https://en.wikipedia.org/wiki/Assignment_operator_(C%2B%2B)>)
- [Destructor](<https://en.wikipedia.org/wiki/Destructor_(computer_programming)>)

### `static const int _fractionalBits`

We are required to define the number of fractional bits as `static const int`. If the fractional bits were not declared as static within the Fixed class, it would imply that each instance of the Fixed class could potentially have its own value for fractional bits.

The **static** keyword in C++ indicates that the member variable or method belongs to the class itself, rather than to any specific instance of the class.

A static member variable is shared among all instances of the class. It exists independently of any class instances, meaning that it is created when the program starts and destroyed when the program ends, regardless of whether any objects of the class are created or destroyed in the meantime.

static member variables and methods can be accessed using the class name instead of an instance of the class.

### Constructor from a const float

```cpp
Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;

	_fixedValue = roundf(value * (1 << _fractionalBits));
}
```

**Implicit conversion**
We could explicitly convert the float to an int with `static_cat<type>` `_fixedValue = static_cast<int>(roundf(floatValue _ (1 << FRAC_BITS)));` but it is not necessary.
**1 << \_fractionalBits** since fractionalBits is a constant (8) we can use it directly the resutl of 1 << 8 or 256
**roundf** rounds to the nearest integer value, rounding halfway cases away from zero, regardless of the current rounding Practical example: `0.1 \ 256 = 25.6`, which is rounded to 26 with roundf. Otherwise we would have 25 as result.
**scaling factor** `1 << _fractionalBits` is the scaling factor. It is used to convert the float value to a fixed-point value. The idea behing is that since we can't bit shift the floating point number we multiply it for the scaling factor. To bitshift a number to the left by 8 means to multiply it by 2^8 = 256. Shifting by 1 means multiply by 2\*1 = 2. 1 (bin) << 1 = 10 (bin) which means 1 (dec) << 1 = 2 (dec). While conceptually, shifting a binary floating-point number to the left by the number of fractional bits (e.g., 8 bits) would simulate converting it to a
fixed-point representation (scaling the value by 2^8), in actual C++ code, floating-point numbers cannot be shifted due to their internal IEEE-754 representation. Instead, we multiply by the corresponding power of 2 to achieve the same effect. For instance, instead of shifting 1.5 (decimal) by 8 bits to the left, which is not possible in code, we multiply 1.5 by 2^8 (256) to convert it to a fixed-point representation where the fractional part is scaled up and stored as an integer.\*/

### toFloat converstion method

`float Fixed::toFloat(void) const`

```cpp
// convert the fixed point value to a floating point value.
float Fixed::toFloat(void) const {
  return (float)_fixedValue / (1 << _fractionalBits);
}

// second implementation
float Fixed::toFloat(void) const {
  return static_cast<float>(_fixedValue) / (1 << _fractionalBits);
}
```

## 02 Towards a more useful fixed-point number class

### Overloading the `<<` stream insertion operator

To print our fixed point number. We want to pass a Fixed object and get it printed (as Fixed). For that we will convert it into a Floating point number, and just print it. Actually is a little more complex cause we will resturn a reference to an std::ostream object.

## 03 Now we're talking

Compare the function that overload the << operator and the member functions which overload the operators and arithmentic functions. The first takes 2 arguments the seconds only 1 and it returns the object itself not a reference.

- [ ]
- [ ]

### Overloading the << stream insertion vs Fixed operations

// Note the difference between this overlaoading function and the overloading of the << operator. This one is a member
// function and takes only one argument, the other is defined outside the class and takes two arguments. And this is
// beacasue the left operand is the object itself, and the right operand is the other object. Overloading comparison
// operator >

### Arithmetic operations

The approach of converting fixed-point values to floating-point for arithmetic operations and then converting them back offers several advantages, making it an easier or "better" approach for certain applications. This methodology simplifies the implementation of arithmetic operations by leveraging the inherent capabilities of floating-point arithmetic, such as automatic handling of underflow and overflow, and more intuitive handling of multiplication and division, which can be complex in fixed-point arithmetic due to the need for precise scaling and bit manipulation.

Using floating-point arithmetic abstracts away the manual scaling and bit shifting required in fixed-point operations, reducing the potential for errors and making the code more readable and maintainable. It also takes advantage of the hardware's floating-point unit (FPU), which is optimized for high-speed floating-point calculations, potentially offering improved performance for complex arithmetic operations compared to manual fixed-point calculations.

Furthermore, this approach automatically accommodates a wider range of values and more complex mathematical operations without the developer needing to manually manage scaling factors or worry about precision loss in intermediate steps, as floating-point numbers have a much larger dynamic range and precision than integers of the same bit width.

However, it's important to note that while this method provides ease of implementation and other benefits, it might introduce slight rounding errors due to the nature of floating-point representation. Therefore, the choice between pure fixed-point arithmetic and using floating-point conversions depends on the specific requirements of the application, including its performance characteristics and the acceptable level of precision.

```cpp
/* OLD APPROACH */
// Overloading arithmetic operator +
Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed result;
	result.setRawBits(_rawBitsValue + other.getRawBits());
	return result;
}
// Overloading arithmetic operator -
Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed result;
	result.setRawBits(_rawBitsValue - other.getRawBits());
	return result;
}
// Overloading arithmetic operator *
Fixed Fixed::operator*(const Fixed &other) const
{
	Fixed fixedResult;
	long long int thisRawLong = static_cast<long long int>(_rawBitsValue);
	long long int otherRawLong = static_cast<long long int>(other.getRawBits());
	long long int multipliedValue = (thisRawLong * otherRawLong);
	long long int scaledResult = multipliedValue >> _fractionalBits;
	int result = static_cast<int>(scaledResult);
	fixedResult.setRawBits(result);
	return fixedResult;
}
// Overloading arithmetic operator /
Fixed Fixed::operator/(const Fixed &other) const
{
	// Check for division by zero
	if (other.getRawBits() == 0)
	{
		// Handle division by zero error or throw an exception
		std::cerr << "Error: Division by zero." << std::endl;
		return Fixed(); // or handle differently
	}
	Fixed fixedResult;
	// Scale up the dividend by the number of fractional bits
	long long int thisRawLong = static_cast<long long int>(_rawBitsValue) << _fractionalBits;
	// Convert divisor to long long
	long long int otherRawLong = static_cast<long long int>(other.getRawBits());
	// Perform the division
	long long int dividedValue = thisRawLong / otherRawLong;
	int result = static_cast<int>(dividedValue);
	fixedResult.setRawBits(result);
	return fixedResult;
}
```

**Why we need a const and a not const version of the min and max functions**

For most operations, especially those that either modify the object in place or return a new object, you typically don't need separate `const` and non-`const` versions. The reason why `min` and `max` functions are exceptional, requiring both `const` and non-`const` versions, is because they return a reference to one of the input objects. This behavior introduces specific considerations for `const` correctness that are not as prevalent in other operations.

Here’s a breakdown for other kinds of operations:

1. **Operations that Modify the Object (e.g., `operator++`, `operator--`)**:

   - These are inherently non-`const` because they change the object's state. There's no need for a `const` version because you can't (and shouldn't) modify a `const` object.

2. **Operations that Return a New Object (e.g., `operator+`, `operator-`)**:

   - These operations typically take input objects and return a new object that represents the result. Since the operation does not alter the state of the input objects, it can be a `const` member function (applied to the inputs). The return type is a new object, so there's no concern about returning `const` or non-`const` references.

3. **Operations Returning References**:
   - The `min` and `max` functions fall into this special category because they return a reference to one of the input objects. The need for both `const` and non-`const` versions arises from the desire to maintain `const` correctness while allowing for the flexibility to work with both `const` and non-`const` objects. The distinction ensures that:
     - A `const` object will only ever yield a `const` reference, preventing modifications.
     - A non-`const` object can yield a non-`const` reference, allowing modifications.

In summary, the necessity for both `const` and non-`const` versions of a function is relatively rare and is generally confined to functions that return references to their input objects. For other types of operations, standard practices for `const` correctness (such as marking member functions that do not modify the object's state as `const`) are sufficient to manage const and non-const contexts appropriately.

## Concepts

### Ad-hoc polymorphism

**Polymorphism**, in programming language theory and type theory, is the use of a single symbol to represent multiple different types. In OOP, polymorphism is the provision of a single interface to entities of different types. The concept is borrowed from a principle in biology where an organism or species can have many different forms or stages.

There are three (or four) different types of polymorphism:

- Subtype polymorphism
- Ad-hoc polymorphism
- Parametric polymorphism
- Coercion polymorphism

**Ad-hoc polymorphism** is basically the possibility in C++ of having functions (or operators) with the same name but with different prototypes/signature, i.e. with different parameters (numbers and type) and different return values. This is not possible in C. Ad-hoc polymorphism is 'ad-hoc' in respect to the subtype polymorphism.

### Operator overoading

Operator overloading is a specific case of ad-hoc polymorphism where the specific functions being overloaded are the standard operators (such as +, -, \*, /, etc.). In C++, you can provide custom implementations for these operators for your own types (classes or structs). This means you can define what happens when you use these operators on instances of your custom types. For example, you can define how two objects of a "Complex Number" class are added together using the + operator. Operator overloading allows for a more intuitive interaction with objects, mimicking the behavior of built-in types. Operator overloading is a specific case of polymorphism.

### Resources

- [Polymorphism - Wiki](<https://en.wikipedia.org/wiki/Polymorphism_(computer_science)>)

### Varia

#### Order-only prerequisite operator `|`

This is about the line `$(OBJS): | $(OBJDIR)` in the Makefile.

The syntax `$(OBJS): | $(OBJDIR)` in the Makefile is an order-only prerequisite in make. In make, prerequisites are usually files that must exist and be up-to-date before the target can be generated. However, there are cases where the timestamp of a prerequisite should not cause the target to be considered out-of-date; this is where order-only prerequisites come into play.

An order-only prerequisite is specified after a `|` character in the prerequisites list. This tells `make` that the target (`$(OBJS)` in this case) does not directly depend on the file timestamps of these prerequisites (`$(OBJDIR)`). Instead, it only matters that these prerequisites exist before the target is made. In other words, `make` ensures that the order-only prerequisites are made (if necessary) before the target, but changes to the prerequisites' timestamps will not cause the target to be remade.

`$(OBJS): | $(OBJDIR)` means:

- The object files (`$(OBJS)`) require the directory `$(OBJDIR)` to exist before they are built.
- The existence and up-to-dateness of `$(OBJDIR)` itself does not influence whether the object files need to be rebuilt. As long as the directory exists, `make` does not care about its timestamp when considering whether to rebuild `$(OBJS)`.

This is useful in this context because you want to make sure the directory where the object files will be stored exists (`$(OBJDIR)`) before compiling the source files into object files. However, once this directory exists, its modification time should not trigger a rebuild of the object files. This prevents unnecessary recompilations when only the directory's timestamp changes without any changes to the source files.
