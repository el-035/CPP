# C++ Modules

This repository contains my solutions to all ten C++ modules from the 42
curriculum. Across 36 exercises, the projects progress from language
fundamentals to object-oriented design, templates, STL containers, and
algorithmic problem solving.

The projects use C++98 and are compiled with strict warning flags.

## Modules

| Module | Main topics |
| --- | --- |
| CPP00 | C++ syntax, namespaces, classes, streams, and a command-line phonebook |
| CPP01 | Heap allocation, pointers, references, file streams, object lifetimes, and function pointers |
| CPP02 | Orthodox Canonical Form, operator overloading, fixed-point arithmetic, and geometry |
| CPP03 | Inheritance, constructor/destructor order, and diamond-shaped class hierarchies |
| CPP04 | Runtime polymorphism, abstract classes, interfaces, deep copies, and object ownership |
| CPP05 | Exceptions through a hierarchy of bureaucrats, forms, and executable actions |
| CPP06 | Scalar conversion, serialization, runtime type identification, and C++ casts |
| CPP07 | Function templates, generic iteration, and a bounds-checked array template |
| CPP08 | STL containers, iterators, algorithms, range insertion, and iterable stacks |
| CPP09 | Exchange-rate lookup, RPN evaluation, and Ford-Johnson merge-insertion sorting |

Each module contains several independent exercises, each with its own source
files, test program, and Makefile.

```text
cpp00/
  ex00/
  ex01/
cpp01/
  ex00/
  ...
cpp09/
```

## Build

Enter an exercise directory and run `make`:

```sh
cd cpp04/ex02
make
```

Executable names differ by exercise and are defined by `NAME` in each
Makefile. For example:

```sh
./animals
```

The usual cleanup targets are available:

```sh
make clean
make fclean
make re
```

## Highlights

- Reusable classes following the Orthodox Canonical Form
- Polymorphic class hierarchies with correct ownership and deep-copy behavior
- Generic algorithms and containers built with templates
- Practical use of `std::vector`, `std::list`, `std::map`, and `std::stack`
- Ford-Johnson merge-insertion sorting implemented with two container types
