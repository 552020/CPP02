# Orthodox Canonical Form

The Orthodox Canonical Form is a term coined to refer to a class that defines the following member functions:

- **Default Constructor**
- **Copy Constructor**
- **Copy Assignment Operator**
- **Destructor**

C++11 addes two extra special member functions: the `Move Constructor`, `Move Assignment Operator`

The term was created by James Coplien in his book "Advanced C++: Programming Styles and Idioms" (1992);

All these members functions are defined by design, which means that if we don't explicitly define them, the compiler will create them for us, with certain specific behaviours. For example the copy constructor will create 'shallow copy' instead of 'deep copies' of the copied object.

## Copy Assignment Opertors
