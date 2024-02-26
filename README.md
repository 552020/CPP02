# CPP_Module_02

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

The main.cpp is given, in the subject.

### The orthodox canonical form and the rule of three

- [Rule of three](<https://en.wikipedia.org/wiki/Rule_of_three_(C%2B%2B_programming)>)
- [Copy constructor](<https://en.wikipedia.org/wiki/Copy_constructor_(C%2B%2B)>)
- [Copy assignment operator](<https://en.wikipedia.org/wiki/Assignment_operator_(C%2B%2B)>)
- [Destructor](<https://en.wikipedia.org/wiki/Destructor_(computer_programming)>)

## 02 Towards a more useful fixed-point number class

### Overloading the `<<` stream insertion operator

To print our fixed point number. We want to pass a Fixed object and get it printed (as Fixed). For that we will convert it into a Floating point number, and just print it. Actually is a little more complex cause we will resturn a reference to an std::ostream object.

## 03 Now we're talking

Compare the function that overload the << operator and the member functions which overload the operators and arithmentic functions. The first takes 2 arguments the seconds only 1 and it returns the object itself not a reference.

- [ ]
- [ ]

### Arithmetic operations

The approach of converting fixed-point values to floating-point for arithmetic operations and then converting them back offers several advantages, making it an easier or "better" approach for certain applications. This methodology simplifies the implementation of arithmetic operations by leveraging the inherent capabilities of floating-point arithmetic, such as automatic handling of underflow and overflow, and more intuitive handling of multiplication and division, which can be complex in fixed-point arithmetic due to the need for precise scaling and bit manipulation.

Using floating-point arithmetic abstracts away the manual scaling and bit shifting required in fixed-point operations, reducing the potential for errors and making the code more readable and maintainable. It also takes advantage of the hardware's floating-point unit (FPU), which is optimized for high-speed floating-point calculations, potentially offering improved performance for complex arithmetic operations compared to manual fixed-point calculations.

Furthermore, this approach automatically accommodates a wider range of values and more complex mathematical operations without the developer needing to manually manage scaling factors or worry about precision loss in intermediate steps, as floating-point numbers have a much larger dynamic range and precision than integers of the same bit width.

However, it's important to note that while this method provides ease of implementation and other benefits, it might introduce slight rounding errors due to the nature of floating-point representation. Therefore, the choice between pure fixed-point arithmetic and using floating-point conversions depends on the specific requirements of the application, including its performance characteristics and the acceptable level of precision.

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
