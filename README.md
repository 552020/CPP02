# CPP_Module_02

## 01 My First Class in Orthodox Canonical Form

- [ ] Orthodox Canonical Form
  - [ ] Default construstor
  - [ ] Copy Constructor
  - [ ] Copy assignment operator
  - [ ] Default Destructor

The main.cpp is given, in the subject.

## 02 Towards a more useful fixed-point number class

### Overloading the `<<` stream insertion operator

To print our fixed point number. We want to pass a Fixed object and get it printed (as Fixed). For that we will convert it into a Floating point number, and just print it. Actually is a little more complex cause we will resturn a reference to an std::ostream object.
