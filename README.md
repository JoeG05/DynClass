Write a class that can add or remove member functions at runtime.  Suppose you call this class Dyn_class (for dynamic class).  Then Dyn_class should have functions:
    A constuctor that allows you to give the Dyn_class object an initial list of functions
    remove_func(f): removes function f from a Dyn_class object
    add_func(f): adds function f to a Dyn_class object

Must also overload operator () so that you can call the functions stored inside Dyn_class.

Can use any existing C++ library code.
