# 42 C++ Modules

<div align="center">

[![42 School](https://img.shields.io/badge/42-Istanbul-000000?style=flat&logo=42&logoColor=white)](https://42istanbul.com.tr/)
[![C++98](https://img.shields.io/badge/C++-98-00599C?style=flat&logo=c%2B%2B&logoColor=white)](https://en.cppreference.com/w/cpp/98)
[![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0)

**Modern C++ Object-Oriented Programming Journey**

</div>

---

## 📚 Overview

This repository contains comprehensive solutions to the **C++ Modules** project from [École 42 İstanbul](https://42istanbul.com.tr/). The project serves as an intensive introduction to **object-oriented programming** in C++, progressively covering fundamental to advanced concepts following the **C++98 standard**.

### 🎯 Learning Objectives

- Master object-oriented programming principles
- Understand memory management and resource allocation
- Implement inheritance, polymorphism, and abstraction
- Apply operator overloading and canonical class forms
- Work with templates and STL containers

---

## 🗂️ Repository Structure

```
CPP_Modules_42/
├── Module00/          # C++ Basics
│   ├── ex00/         # Megaphone
│   └── ex01/         # PhoneBook
├── Module01/          # Memory & References
│   ├── ex00/         # BraiiiiiiinnnzzzZ
│   ├── ex01/         # Moar brainz!
│   ├── ex02/         # HI THIS IS BRAIN
│   ├── ex03/         # Unnecessary violence
│   ├── ex04/         # Sed is for losers
│   ├── ex05/         # Harl 2.0
│   └── ex06/         # Harl filter
├── Module02/          # Polymorphism & Operators
│   ├── ex00/         # Fixed-point number class
│   ├── ex01/         # Towards a more useful fixed-point
│   └── ex02/         # Now we're talking
├── Module03/          # Inheritance
│   ├── ex00/         # ClapTrap
│   ├── ex01/         # ScavTrap
│   ├── ex02/         # FragTrap
│   └── ex03/         # DiamondTrap
├── Module04/          # Subtype Polymorphism & Interfaces
│   ├── ex00/         # Polymorphism
│   ├── ex01/         # I don't want to set the world on fire
│   ├── ex02/         # Abstract class
│   └── ex03/         # Interface & recap
├── Module05/          # Repetition & Exceptions
│   ├── ex00/         # Mommy, when I grow up, I want to be a bureaucrat
│   ├── ex01/         # Form up, maggots!
│   ├── ex02/         # No, you need form 28B, not 28C
│   └── ex03/         # At least this beats coffee-making
├── Module06/          # C++ Casts
│   ├── ex00/         # Conversion of scalar types
│   ├── ex01/         # Serialization
│   └── ex02/         # Identify real type of objects
└── README.md
```

---

## 📖 Module Breakdown

### Module 00: Introduction to C++ Basics

**Key Concepts:** Namespaces, classes, member functions, stdio streams, initialization lists, static & const keywords

#### Exercises:
- **ex00 - Megaphone:** Simple program that converts input to uppercase, demonstrating basic I/O and string manipulation
- **ex01 - PhoneBook:** Interactive phonebook application using classes (`Contact`, `PhoneBook`) with contact management (add, search)

**Skills:** Basic class design, encapsulation, user input handling, data validation

---

### Module 01: Memory Allocation, Pointers, and References

**Key Concepts:** Memory allocation (stack vs heap), pointers to members, references, switch statements

#### Exercises:
- **ex00 - BraiiiiiiinnnzzzZ:** Creating and managing `Zombie` objects with heap and stack allocation
- **ex01 - Moar brainz!:** Implementing `zombieHorde()` function to create multiple zombies dynamically
- **ex02 - HI THIS IS BRAIN:** Demonstrating the difference between pointers and references
- **ex03 - Unnecessary violence:** `Weapon`, `HumanA`, and `HumanB` classes showing proper use of references vs pointers
- **ex04 - Sed is for losers:** File manipulation program replacing strings in files (C++ file I/O)
- **ex05 - Harl 2.0:** `Harl` class with member function pointers for complaint logging
- **ex06 - Harl filter:** Filtering Harl's complaints using switch statements

**Skills:** Dynamic memory management, understanding pointers vs references, member function pointers, file operations

---

### Module 02: Ad-hoc Polymorphism & Operator Overloading

**Key Concepts:** Orthodox Canonical Class Form, operator overloading, fixed-point numbers, ad-hoc polymorphism

#### Exercises:
- **ex00 - Fixed-point number class:** Basic `Fixed` class implementing orthodox canonical form (default constructor, copy constructor, copy assignment operator, destructor)
- **ex01 - Towards a more useful fixed-point:** Enhanced `Fixed` class with int/float constructors and conversion functions
- **ex02 - Now we're talking:** Complete `Fixed` class with arithmetic operators (+, -, *, /), comparison operators (<, >, <=, >=, ==, !=), and increment/decrement operators (++, --)

**Skills:** Orthodox canonical form, operator overloading, fixed-point arithmetic, const correctness

---

### Module 03: Inheritance

**Key Concepts:** Inheritance hierarchies, access specifiers (public, protected, private), virtual functions, diamond problem

#### Exercises:
- **ex00 - ClapTrap:** Base class with basic attributes (name, hit points, energy points, attack damage) and methods (attack, takeDamage, beRepaired)
- **ex01 - ScavTrap:** Derived class inheriting from `ClapTrap` with modified attributes and a special `guardGate()` function
- **ex02 - FragTrap:** Another derived class from `ClapTrap` with different attributes and `highFivesGuys()` function
- **ex03 - DiamondTrap:** Multiple inheritance from both `ScavTrap` and `FragTrap`, demonstrating the diamond problem resolution

**Skills:** Class inheritance, method overriding, virtual functions, multiple inheritance, diamond problem

---

### Module 04: Subtype Polymorphism, Abstract Classes, and Interfaces

**Key Concepts:** Subtype polymorphism, virtual functions, abstract classes, interfaces, deep copy, memory management with composition

#### Exercises:
- **ex00 - Polymorphism:** Basic implementation of `Animal` base class with derived `Dog` and `Cat` classes demonstrating virtual functions and polymorphic behavior. Includes `WrongAnimal` and `WrongCat` to show the importance of virtual destructors
- **ex01 - I don't want to set the world on fire:** Extending the Animal hierarchy with a `Brain` class (containing 100 ideas). `Dog` and `Cat` now contain a `Brain*` attribute, demonstrating deep copy vs shallow copy in copy constructors and assignment operators
- **ex02 - Abstract class:** Refactoring `Animal` into `AAnimal` (abstract animal) by making `makeSound()` pure virtual. This prevents instantiation of the base class, enforcing derived classes to implement the behavior
- **ex03 - Interface & recap:** Complete interface implementation with `AMateria` abstract class, concrete `Ice` and `Cure` classes, `ICharacter` and `Character` classes for inventory management, and `IMateriaSource`/`MateriaSource` for materia creation. Demonstrates proper memory management with floor-dropped items to prevent leaks

**Skills:** Virtual functions and polymorphism, abstract classes and pure virtual functions, interface design, deep copy implementation, composition and aggregation, proper memory management in complex hierarchies

---

### Module 05: Repetition and Exceptions

**Key Concepts:** C++ exception handling (try/catch/throw), custom exception classes, exception hierarchies, form signing workflows

#### Exercises:
- **ex00 - Mommy, when I grow up, I want to be a bureaucrat:** `Bureaucrat` class with a constant name and a grade (1 highest, 150 lowest). Throws `GradeTooHighException` or `GradeTooLowException` when grade is out of bounds; demonstrates basic exception design
- **ex01 - Form up, maggots!:** `Form` class with grade requirements to sign and execute. `Bureaucrat::signForm()` attempts to sign a form and catches exceptions, showcasing interaction between classes through exceptions
- **ex02 - No, you need form 28B, not 28C:** `AForm` abstract base class replaces `Form`. Concrete forms `ShrubberyCreationForm`, `RobotomyRequestForm`, and `PresidentialPardonForm` each implement `execute()` with distinct behaviors (creates ASCII trees, robotomizes with 50% success, grants presidential pardon)
- **ex03 - At least this beats coffee-making:** `Intern` class with a `makeForm()` method that creates the correct `AForm` subclass by name without using if-else chains, using an array of form-factory function pointers

**Skills:** Exception handling and custom exception types, abstract classes with pure virtual functions, factory pattern, working with dynamic memory in polymorphic hierarchies

---

### Module 06: C++ Casts

**Key Concepts:** C++ explicit type casts (`static_cast`, `dynamic_cast`, `reinterpret_cast`), type conversion, serialization, run-time type identification (RTTI)

#### Exercises:
- **ex00 - Conversion of scalar types:** `ScalarConverter` utility class (non-instantiable) with a static `convert()` method that parses a string literal and prints its value as `char`, `int`, `float`, and `double`. Handles special floating-point values (`nan`, `inf`, `-inf`) and edge cases
- **ex01 - Serialization:** `Serializer` utility class with static `serialize(Data*)` and `deserialize(uintptr_t)` methods using `reinterpret_cast` to convert a pointer to an integer and back, demonstrating low-level pointer manipulation
- **ex02 - Identify real type of objects:** `Base` class with virtual destructor and three empty derived classes `A`, `B`, `C`. Two `identify()` functions determine the actual dynamic type at run time — one using a pointer (try `dynamic_cast`) and one using a reference (catch bad cast)

**Skills:** C++ cast operators, scalar type conversion and overflow detection, `reinterpret_cast` for serialization, `dynamic_cast` and RTTI for type identification

---

## 🚀 Getting Started

### Prerequisites

- **Compiler:** g++ or clang++ with C++98 support
- **Make:** GNU Make
- **OS:** Linux, macOS, or Unix-like system

### Building and Running

Each exercise has its own `Makefile` in the `srcs/` directory:

```bash
# Navigate to any exercise
cd Module00/ex00/srcs/

# Compile the project
make

# Run the executable (name varies by exercise)
./megaphone [arguments]

# Clean object files
make clean

# Clean everything including executable
make fclean

# Recompile from scratch
make re
```

### Example Usage

```bash
# Module00/ex00 - Megaphone
$ ./megaphone "shhhhh... I think the students are asleep..."
SHHHHH... I THINK THE STUDENTS ARE ASLEEP...

# Module00/ex01 - PhoneBook
$ ./phonebook
> ADD
Enter first name: John
Enter last name: Doe
...
> SEARCH
...

# Module01/ex00 - Zombie
$ ./zombie
Creating zombies...
```

---

## 📋 Compilation Flags

All exercises are compiled with strict flags to ensure code quality:

```makefile
-Wall -Wextra -Werror -std=c++98
```

- `-Wall`: Enable all warnings
- `-Wextra`: Enable extra warnings
- `-Werror`: Treat warnings as errors
- `-std=c++98`: Enforce C++98 standard

---

## 🧪 Key Concepts Covered

### Module 00
✓ Basic class structure and encapsulation  
✓ Member functions and data members  
✓ Constructors and destructors  
✓ Stdio streams (std::cin, std::cout)  
✓ Static and const keywords

### Module 01
✓ Stack vs Heap memory allocation  
✓ Pointers and references  
✓ Dynamic memory management (new/delete)  
✓ Member function pointers  
✓ File I/O streams  
✓ Switch statements

### Module 02
✓ Orthodox Canonical Class Form  
✓ Copy constructor and copy assignment operator  
✓ Operator overloading (arithmetic, comparison, increment/decrement)  
✓ Float to fixed-point conversion  
✓ Ad-hoc polymorphism

### Module 03
✓ Class inheritance (single and multiple)  
✓ Access specifiers (public, protected, private)  
✓ Virtual functions and method overriding  
✓ Diamond inheritance problem  
✓ Constructor/destructor call order in inheritance

### Module 04
✓ Subtype polymorphism with virtual functions  
✓ Abstract classes and pure virtual functions  
✓ Interface design and implementation  
✓ Deep copy vs shallow copy  
✓ Composition and memory management  
✓ Proper cleanup in complex object hierarchies

### Module 05
✓ Exception handling with try/catch/throw  
✓ Custom exception classes and inheritance  
✓ Interaction between classes through exceptions  
✓ Abstract forms and concrete implementations  
✓ Factory pattern without if-else chains

### Module 06
✓ `static_cast`, `dynamic_cast`, `reinterpret_cast`  
✓ Scalar type conversion and edge cases  
✓ Pointer serialization with `reinterpret_cast`  
✓ Run-time type identification (RTTI) with `dynamic_cast`  
✓ Non-instantiable utility classes

---

## 📚 Additional Resources

- [CPP Reference](https://en.cppreference.com/) - Comprehensive C++ reference
- [LearnCpp.com](https://www.learncpp.com/) - Free C++ tutorial
- [42 Docs](https://harm-smits.github.io/42docs/) - Community-driven 42 project documentation
- [Orthodox Canonical Form](https://www.francescosabatini.com/orthodox-canonical-class-form/) - Deep dive into C++ canonical forms

---

## 📝 Notes

- All projects follow the **C++98 standard** as required by 42 School
- Each exercise is designed to be progressively more challenging
- Code adheres to the 42 School coding standards and norms
- Proper memory management is enforced (no memory leaks)
- Code is tested with valgrind for memory leak detection

---

## 👨‍💻 Author

**Ahmet Zorlutuna**  
École 42 İstanbul Student

---

## 📄 License

This project is licensed under the GNU General Public License v3.0 - see the [LICENSE](LICENSE) file for details.

---

## ⚠️ Academic Integrity

This repository is made public for educational and portfolio purposes. If you're a 42 student working on these projects, please use this as a reference only and write your own code. Copying code violates 42's academic integrity policy.

---

<div align="center">

**Happy Coding! 🚀**

*Made with ❤️ at 42 İstanbul*

</div>
