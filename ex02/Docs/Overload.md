# Overload

Overloading is a feature in programming languages that allows developers to _define multiple functions or operators with the same name_ but with different parameters (either by number, type, or both). When an overloaded function or operator is called, the programming language's type system and compiler determine which specific function to invoke based on the arguments passed to it. This is known as "static polymorphism" because the decision is made at compile time.

First appearance is in Ada and ML but the concept is normally associated with C++.

C does not support function overloading or operator overloading.

## Overloading in C++98

In C++98 we can overload **functions** and **operators**.

We can _overload functions_, by providing different parameter lists.

We can _overload operators_ by providing special member functions or friend functions that define the behaviour of operators like `+`, `-`, `*`, and son on.

- Overloading an operator by providing a member function

```c++
class Fixed {

public:
	bool operator>(const Fixed &other) const {
		return this->value > other.value;
	}
}
```

- Overloading an operator by providing a friend function

```c++
class Fixed {
	public:
	friend bool operator>(const Fixed &lhs, const Fixed *rhs) {
		return lhs.value > rhs.value;
	}
}
public:
```

The friend keyword is forbidden. We can achieve the same results without the need of the friend keyword. It breaks encapsulation, but it is also a mean to access class members wihtout the need of modifying the class itself.
