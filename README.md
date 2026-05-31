# 42 C++ Modules

<div align="center">

[![42 School](https://img.shields.io/badge/42-Istanbul-000000?style=flat&logo=42&logoColor=white)](https://42istanbul.com.tr/)
[![C++98](https://img.shields.io/badge/C++-98-00599C?style=flat&logo=c%2B%2B&logoColor=white)](https://en.cppreference.com/w/cpp/98)
[![Modules](https://img.shields.io/badge/Modules-00→09-brightgreen?style=flat)](#-module-breakdown)
[![Exercises](https://img.shields.io/badge/Exercises-33-blue?style=flat)](#-module-breakdown)
[![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0)

**A complete, exercise-by-exercise reference for 42 School's C++ track — from `main` to merge-insertion sort.**

</div>

---

## 📚 Table of Contents

- [Overview](#-overview)
- [Repository Structure](#-repository-structure)
- [Cross-Module Concept Map](#-cross-module-concept-map)
- [Module Breakdown](#-module-breakdown)
  - [Module 00 — Namespaces, Classes, I/O](#module-00--namespaces-classes-io)
  - [Module 01 — Memory, Pointers, References](#module-01--memory-pointers-references)
  - [Module 02 — Ad-hoc Polymorphism & Operator Overloading](#module-02--ad-hoc-polymorphism--operator-overloading)
  - [Module 03 — Inheritance](#module-03--inheritance)
  - [Module 04 — Subtype Polymorphism, Abstract, Interfaces](#module-04--subtype-polymorphism-abstract-interfaces)
  - [Module 05 — Exceptions](#module-05--exceptions)
  - [Module 06 — C++ Casts & RTTI](#module-06--c-casts--rtti)
  - [Module 07 — Templates](#module-07--templates)
  - [Module 08 — Templated Containers & Iterators](#module-08--templated-containers--iterators)
  - [Module 09 — STL Containers & Algorithms](#module-09--stl-containers--algorithms)
- [Getting Started](#-getting-started)
- [Compilation Flags](#-compilation-flags)
- [Algorithm Spotlight — Ford-Johnson Merge-Insertion Sort](#-algorithm-spotlight--ford-johnson-merge-insertion-sort)
- [C++ Glossary](#-c-glossary)
- [Additional Resources](#-additional-resources)
- [Author](#-author) • [License](#-license) • [Academic Integrity](#-academic-integrity)

---

## 📖 Overview

This repository is the complete solution set for **42 School İstanbul's C++ Modules** project — ten modules, thirty-three exercises, walking from the first `std::cout` to a hand-rolled Ford-Johnson merge-insertion sort. Every exercise is written in **strict C++98**, the standard 42 enforces to make sure you understand what later standards hide behind `auto`, `std::unique_ptr`, and `=default`.

This README is written as a **reference for other 42 students worldwide**. Read the concept, look at the snippet, then write your own. Don't copy-paste — the project teaches you to think in OOP, not to assemble code from someone else's repo.

### Learning trajectory

| Modules | Theme | Mental model you build |
|---------|-------|------------------------|
| **00–02** | Object basics | A class is data + behaviour, with a strict lifecycle (ctor → use → dtor) |
| **03–04** | Polymorphism | Same call, different behaviour, dispatched at runtime through the vtable |
| **05–06** | Control flow & types | Errors are values that bubble up; types have a runtime identity |
| **07–08** | Generic programming | Code that compiles into many concrete forms — once, correctly |
| **09** | STL in production | Real containers, real algorithms, real complexity tradeoffs |

### Why C++98?

Because the constraints teach you. No `auto`, so you write the type and understand it. No smart pointers, so you confront ownership directly. No range-for, so you live with iterators. No `nullptr`, just `NULL`. By the time you reach Module 09 you understand what every modern C++ feature is *trying to hide*, and that understanding makes modern C++ a tool instead of a magic spell.

---

## 🗂️ Repository Structure

```
CPP_Modules/
├── Module00/                  # C++ basics, classes, stdio
│   ├── ex00/  Megaphone
│   └── ex01/  PhoneBook
├── Module01/                  # Memory, pointers, references
│   ├── ex00/  Zombie (BraiiiiiiinnnzzzZ)
│   ├── ex01/  Zombie Horde (Moar brainz!)
│   ├── ex02/  HI THIS IS BRAIN
│   ├── ex03/  HumanA / HumanB (Unnecessary violence)
│   ├── ex04/  Replace (Sed is for losers)
│   ├── ex05/  Harl 2.0
│   └── ex06/  Harl filter
├── Module02/                  # Operator overloading, canonical form
│   ├── ex00/  Fixed (canonical form)
│   ├── ex01/  Fixed (with conversions)
│   └── ex02/  Fixed (full operators)
├── Module03/                  # Inheritance
│   ├── ex00/  ClapTrap
│   ├── ex01/  ScavTrap
│   ├── ex02/  FragTrap
│   └── ex03/  DiamondTrap
├── Module04/                  # Polymorphism, abstract classes, interfaces
│   ├── ex00/  Animal / WrongAnimal
│   ├── ex01/  Brain (deep copy)
│   ├── ex02/  AAnimal (abstract)
│   └── ex03/  AMateria / ICharacter / IMateriaSource
├── Module05/                  # Exceptions
│   ├── ex00/  Bureaucrat
│   ├── ex01/  Form
│   ├── ex02/  AForm + concrete forms
│   └── ex03/  Intern (factory)
├── Module06/                  # C++ casts & RTTI
│   ├── ex00/  ScalarConverter
│   ├── ex01/  Serializer
│   └── ex02/  Base / A / B / C (dynamic_cast)
├── Module07/                  # Templates
│   ├── ex00/  whatever.hpp (swap/min/max)
│   ├── ex01/  iter.hpp
│   └── ex02/  Array<T>
├── Module08/                  # Templated containers, iterators
│   ├── ex00/  easyfind
│   ├── ex01/  Span
│   └── ex02/  MutantStack
├── Module09/                  # STL containers & algorithms
│   ├── ex00/  BitcoinExchange (std::map)
│   ├── ex01/  RPN (std::stack)
│   └── ex02/  PmergeMe (Ford-Johnson)
├── LICENSE
└── README.md                  # ← you are here
```

Each exercise follows the same layout:

```
ModuleXX/exYY/
├── srcs/        ← Makefile + .cpp files
└── includes/    ← .hpp files
```

The `Makefile` lives **inside** `srcs/`, so `cd ModuleXX/exYY/srcs && make` is the universal build command.

---

## 🧭 Cross-Module Concept Map

Looking for where a specific concept is introduced? Jump straight to it.

| Concept | First introduced |
|---------|------------------|
| Class basics, encapsulation | M00 ex01 |
| Standard I/O (`std::cin` / `std::cout`) | M00 ex00 |
| `new` / `delete` | M01 ex00 |
| `new[]` / `delete[]` | M01 ex01 |
| References vs pointers | M01 ex03 |
| File streams (`ifstream` / `ofstream`) | M01 ex04 |
| Pointer-to-member function | M01 ex05 |
| Orthodox Canonical Form | M02 ex00 |
| Operator overloading | M02 ex02 |
| `friend` for `<<` overloading | M02 ex01 |
| Single inheritance | M03 ex01 |
| Multiple & diamond inheritance | M03 ex03 |
| Virtual functions | M04 ex00 |
| Virtual destructors | M04 ex00 |
| Deep copy | M04 ex01 |
| Pure virtual / abstract class | M04 ex02 |
| Interfaces (pure-interface classes) | M04 ex03 |
| Factory pattern | M04 ex03, M05 ex03 |
| Custom exceptions (`std::exception` subclass) | M05 ex00 |
| Nested classes | M05 ex00 |
| `static_cast` / `reinterpret_cast` | M06 ex00–ex01 |
| `dynamic_cast` & RTTI | M06 ex02 |
| `const_cast` | M06 (referenced) |
| Function templates | M07 ex00 |
| Class templates | M07 ex02 |
| `typename` disambiguator | M07 ex02, M08 ex02 |
| STL algorithms (`std::find`, `std::lower_bound`) | M08 ex00, M09 ex00 |
| `std::vector` / `std::list` / `std::deque` | M08, M09 |
| `std::map` + ordered key lookup | M09 ex00 |
| `std::stack` adapter | M08 ex02, M09 ex01 |
| Adapter subclassing (exposing `c`) | M08 ex02 |
| Ford-Johnson merge-insertion sort | M09 ex02 |
| Jacobsthal sequence | M09 ex02 |

---

## 📘 Module Breakdown

Every exercise below uses this structure:

> **Goal** — one sentence. **Key components** — the classes and files involved. **Techniques** — the C++ features being practiced. **Snippet** — 5–15 illustrative lines (always C++98). **Sample output** — what running the binary actually prints. **Gotcha** — the subtle thing that costs an hour the first time.

---

### Module 00 — Namespaces, Classes, I/O

The first contact with C++ as a strongly-typed, object-oriented language. You leave with a working class, a destructor that runs at the right time, and an intuition for `std::cin`/`std::cout`.

**Concepts introduced:**
- Namespaces (`std::`) and the `::` scope resolution operator
- Class declaration vs. definition, member functions, member variables
- Constructors, destructors, initialiser lists
- `static` and `const` keywords on members
- `std::string` basics, character utilities (`<cctype>`)

#### ex00 — Megaphone

**Goal:** Convert every command-line argument to uppercase and print on one line.

**Key components:** `megaphone.cpp` (single file, no class).

**Techniques:** `argc`/`argv` iteration, `std::toupper`, `std::string` iteration.

```cpp
#include <iostream>
#include <cctype>

int main(int argc, char **argv) {
    if (argc == 1) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }
    for (int i = 1; i < argc; ++i) {
        for (size_t j = 0; argv[i][j]; ++j)
            std::cout << static_cast<char>(std::toupper(argv[i][j]));
    }
    std::cout << std::endl;
    return 0;
}
```

```text
$ ./megaphone "shhhhh... I think the students are asleep..."
SHHHHH... I THINK THE STUDENTS ARE ASLEEP...

$ ./megaphone
* LOUD AND UNBEARABLE FEEDBACK NOISE *
```

**Gotcha:** `std::toupper` returns `int`; the cast to `char` is not optional if you want clean compilation with `-Wall -Wextra -Werror`.

#### ex01 — PhoneBook

**Goal:** A REPL that stores up to 8 contacts. `ADD` appends (oldest overwritten when full), `SEARCH` lists in a 4-column table and lets you look up a single entry by index.

**Key components:** `Contact` (data), `PhoneBook` (storage + commands), `Validator` (input parsing).

**Techniques:** Encapsulation with private members + getters, fixed-size arrays, circular indexing, column-width formatting, defensive input validation (no empty fields, numbers-only phone).

```cpp
class PhoneBook {
public:
    PhoneBook();
    void addContact(const Contact& c);
    void searchContacts() const;
private:
    Contact      _contacts[8];
    unsigned int _count;      // contacts stored so far (cap 8)
    unsigned int _next;       // next write index (rolls 0..7)
};

void PhoneBook::addContact(const Contact& c) {
    _contacts[_next] = c;
    _next = (_next + 1) % 8;
    if (_count < 8) ++_count;
}
```

```text
$ ./phonebook
Welcome to the PhoneBook. Commands: ADD, SEARCH, EXIT.
> ADD
First name: Ada
Last  name: Lovelace
Nickname  : Countess
Phone     : 12345
Secret    : likes punch cards
> SEARCH
|     Index|First name| Last name|  Nickname|
|         0|       Ada|  Lovelace|  Counte...|
Enter index: 0
First name: Ada
Last  name: Lovelace
Nickname  : Countess
Phone     : 12345
Secret    : likes punch cards
> EXIT
```

**Gotcha:** Fields wider than 10 characters must be truncated with a trailing `.` in the column view, but the *full* value is printed when you select an index. Don't lose the original data — only the display is truncated.

---

### Module 01 — Memory, Pointers, References

You stop thinking of variables as names and start thinking of them as *addresses with types stuck to them*. Heap vs stack lifetime becomes visible because every destructor announces itself.

**Concepts introduced:**
- Stack vs heap allocation (`new` / `delete`, `new[]` / `delete[]`)
- The fundamental difference between **references** and **pointers**
- File I/O with `<fstream>` (`std::ifstream`, `std::ofstream`)
- Pointers to member functions (`void (Class::*)()`)
- `switch`/`case` with deliberate fall-through

#### ex00 — Zombie (BraiiiiiiinnnzzzZ)

**Goal:** Two factories: one returns a heap zombie (caller must `delete`), one creates a stack zombie that dies at scope exit.

**Key components:** `Zombie` class with `name`, `announce()`, and a destructor that prints `<name> destroyed`.

**Techniques:** `new` for heap, value semantics for stack, RAII demonstrated by the destructor message.

```cpp
Zombie* newZombie(std::string name) {
    return new Zombie(name);      // caller owns the heap allocation
}

void randomChump(std::string name) {
    Zombie z(name);               // stack — destroyed at function return
    z.announce();
}
```

```text
$ ./zombie
Foo: BraiiiiinnnzzzZ...
Foo destroyed              ← stack zombie at function exit
Bar: BraiiiiinnnzzzZ...
Bar destroyed              ← heap zombie after explicit delete
```

**Gotcha:** Forget the `delete` on the heap zombie and the destructor message never prints. That silence is your memory leak.

#### ex01 — Zombie Horde (Moar brainz!)

**Goal:** Allocate an array of N zombies in one call.

**Techniques:** `new Zombie[N]` and the mandatory matching `delete[]`. Default constructor required because `new T[N]` cannot pass arguments.

```cpp
Zombie* zombieHorde(int N, std::string name) {
    Zombie* horde = new Zombie[N];
    for (int i = 0; i < N; ++i)
        horde[i].setName(name);
    return horde;
}
// caller:  delete[] horde;
```

**Gotcha:** `delete horde` (without `[]`) is undefined behaviour. The compiler won't warn — only sanitisers will.

#### ex02 — HI THIS IS BRAIN

**Goal:** Print the same string's address and value three ways: directly, through a pointer, through a reference.

**Techniques:** Aliasing — references *are* the object, pointers *point to* the object.

```cpp
std::string  s = "HI THIS IS BRAIN";
std::string* p = &s;
std::string& r = s;

std::cout << &s << "  " << s  << std::endl;
std::cout <<  p << "  " << *p << std::endl;
std::cout << &r << "  " << r  << std::endl;
```

All three addresses are identical. **The reference is not a separate object** — it's another name for `s`.

#### ex03 — HumanA / HumanB (Unnecessary violence)

The headline lesson of the whole module: **when to use a reference, when to use a pointer.**

**Goal:** Two humans with a `Weapon`. One always has a weapon, the other might not.

```cpp
class HumanA {
    std::string _name;
    Weapon&     _weapon;          // reference: must be set at construction
public:
    HumanA(std::string n, Weapon& w) : _name(n), _weapon(w) {}
    void attack() const { std::cout << _name << " attacks with " << _weapon.getType() << std::endl; }
};

class HumanB {
    std::string _name;
    Weapon*     _weapon;          // pointer: may be NULL, may change
public:
    HumanB(std::string n) : _name(n), _weapon(NULL) {}
    void setWeapon(Weapon& w) { _weapon = &w; }
    void attack() const { if (_weapon) std::cout << _name << " attacks with " << _weapon->getType() << std::endl; }
};
```

**Rule of thumb:** Reference = "this thing always exists and never changes identity". Pointer = "this thing is optional or rebindable". 90% of OOP design decisions reduce to which one you reach for.

#### ex04 — Replace (Sed is for losers)

**Goal:** Replace every occurrence of string `s1` with `s2` in a file. Output goes to `<filename>.replace`.

**Techniques:** `std::ifstream`, `std::ofstream`, `std::string::find` + `substr` (no `std::regex` in C++98).

```cpp
std::ifstream in(filename.c_str());
if (!in.is_open()) { std::cerr << "Cannot open " << filename << std::endl; return 1; }

std::string content((std::istreambuf_iterator<char>(in)),
                     std::istreambuf_iterator<char>());

std::string out;
size_t pos = 0, found;
while ((found = content.find(s1, pos)) != std::string::npos) {
    out.append(content, pos, found - pos);
    out.append(s2);
    pos = found + s1.size();
}
out.append(content, pos, std::string::npos);

std::ofstream of((filename + ".replace").c_str());
of << out;
```

**Gotcha:** Don't use `std::string::replace` — the subject explicitly says you can't. Build the new string manually.

#### ex05 — Harl 2.0

**Goal:** `Harl::complain(level)` dispatches to a private method based on the level string — *without* a chain of `if`/`else`.

**Techniques:** Array of pointer-to-member functions, parallel array of level names, linear search to find the index.

```cpp
void Harl::complain(std::string level) {
    void (Harl::*funcs[])() = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
    std::string  names[]   = { "DEBUG", "INFO", "WARNING", "ERROR" };
    for (int i = 0; i < 4; ++i)
        if (names[i] == level) { (this->*funcs[i])(); return; }
}
```

#### ex06 — Harl filter

**Goal:** Same Harl, but a `switch` with deliberate fall-through prints the requested level *and all higher levels*.

```cpp
switch (level) {
    case DEBUG:   harl.debug();   // falls through
    case INFO:    harl.info();    // falls through
    case WARNING: harl.warning(); // falls through
    case ERROR:   harl.error();   break;
    default:      std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}
```

**Gotcha:** Modern compilers warn on fall-through. Here it's intentional. Document it (`/* fallthrough */`) and the warning becomes legible.

---

### Module 02 — Ad-hoc Polymorphism & Operator Overloading

You build a fixed-point number class three times, each more complete than the last. By the end, `Fixed` behaves indistinguishably from a built-in type in arithmetic expressions.

**Concepts introduced:**
- **Orthodox Canonical Form** (default ctor, copy ctor, copy-assignment, destructor)
- Operator overloading: arithmetic, comparison, prefix/postfix inc/dec
- Stream insertion operator (`<<`) as a non-member friend function
- Fixed-point numerics (integer storage, virtual fractional bits)

#### ex00 — Fixed (canonical form)

**Goal:** Implement the four canonical methods, each logging when it runs.

**Techniques:** Member initialiser lists, self-assignment check.

```cpp
class Fixed {
public:
    Fixed();                              // default
    Fixed(const Fixed& other);            // copy
    Fixed& operator=(const Fixed& other); // assign
    ~Fixed();                             // destroy
    int  getRawBits() const;
    void setRawBits(int raw);
private:
    int                _rawBits;
    static const int   _fractionalBits = 8;
};
```

**Gotcha:** The copy-assignment operator's self-assignment check (`if (this != &other)`) seems pedantic for an `int` member — but it's the habit you need by Module 04 when copying through pointers.

#### ex01 — Fixed (with conversions)

**Goal:** Add `Fixed(int)`, `Fixed(float)`, `toInt()`, `toFloat()`, and `operator<<(std::ostream&, const Fixed&)`.

**Techniques:** Bit-shift conversion (`value << _fractionalBits`), `roundf` for float→fixed.

```cpp
Fixed::Fixed(const int v)   : _rawBits(v << _fractionalBits) {}
Fixed::Fixed(const float v) : _rawBits(static_cast<int>(roundf(v * (1 << _fractionalBits)))) {}

float Fixed::toFloat() const { return static_cast<float>(_rawBits) / (1 << _fractionalBits); }
int   Fixed::toInt()   const { return _rawBits >> _fractionalBits; }

std::ostream& operator<<(std::ostream& os, const Fixed& f) {
    return os << f.toFloat();
}
```

#### ex02 — Fixed (full operators)

**Goal:** Implement all twelve operators a numeric type wants.

**Techniques:** Const-correctness, pre/postfix distinction, static overloads for const + non-const.

| Group | Operators |
|-------|-----------|
| Arithmetic | `+` `-` `*` `/` |
| Comparison | `<` `>` `<=` `>=` `==` `!=` |
| Increment | prefix `++a` / postfix `a++` |
| Decrement | prefix `--a` / postfix `a--` |
| Static | `min(a,b)` and `max(a,b)`, each with const + non-const overloads |

```cpp
Fixed& Fixed::operator++() {              // prefix: return reference
    ++_rawBits;
    return *this;
}

Fixed Fixed::operator++(int) {            // postfix: return value (the `int` is a sentinel)
    Fixed tmp(*this);
    ++_rawBits;
    return tmp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)             { return a < b ? a : b; }
const Fixed& Fixed::min(const Fixed& a, const Fixed& b) { return a < b ? a : b; }
```

**Gotcha:** Postfix increment **must** return by value — returning a reference to the temporary would dangle. Prefix returns by reference — `++++a` is the standard test.

---

### Module 03 — Inheritance

The Trap family. Each child class redefines stats and adds one quirky method, and by ex03 you face the diamond.

**Concepts introduced:**
- `public` inheritance, constructor chaining via member initialiser lists
- Method overriding (without `virtual` — that comes in M04)
- The diamond problem and its resolution via virtual inheritance
- Constructor/destructor call order in deep hierarchies

#### ex00 — ClapTrap

The base class. Stats: name (string), hit points (10), energy points (10), attack damage (0). Methods guard against acting when out of energy or HP.

```cpp
void ClapTrap::attack(const std::string& target) {
    if (_hitPoints == 0 || _energyPoints == 0) {
        std::cout << "ClapTrap " << _name << " is too tired to attack." << std::endl;
        return;
    }
    --_energyPoints;
    std::cout << "ClapTrap " << _name << " attacks " << target
              << ", causing " << _attackDamage << " points of damage!" << std::endl;
}
```

#### ex01 — ScavTrap

`class ScavTrap : public ClapTrap`. Stronger stats (100/50/20). Adds `guardGate()`. Calls parent constructor with member initialiser list.

```cpp
ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    _hitPoints    = 100;
    _energyPoints = 50;
    _attackDamage = 20;
}
```

**Gotcha:** Watch the **destructor call order** in the output: ScavTrap's runs first, then ClapTrap's. Construction is the reverse — base first, then derived.

#### ex02 — FragTrap

A sibling to ScavTrap with different stats (100/100/30) and `highFivesGuys()`. Sets up the diamond.

#### ex03 — DiamondTrap

```cpp
class DiamondTrap : public ScavTrap, public FragTrap {
    std::string _name;          // shadows ClapTrap::_name on purpose
public:
    void whoAmI();              // prints both names
};
```

Without virtual inheritance, `DiamondTrap` would have **two** `ClapTrap` subobjects (one via ScavTrap, one via FragTrap). The subject sometimes asks you to make `ClapTrap` a virtual base (`class ScavTrap : virtual public ClapTrap`); other times you resolve ambiguity manually with scope (`ScavTrap::attack()`). Either way, the lesson is the same: multiple inheritance creates *real* ambiguity and the language gives you tools to nail it down.

```text
$ ./diamondtrap
ClapTrap Diamond_clap_name constructed.
ScavTrap Diamond constructed.
FragTrap Diamond constructed.
DiamondTrap Diamond constructed.

Diamond attacks target1, causing 30 points of damage!
I am Diamond — but my ClapTrap name is Diamond_clap_name.
```

---

### Module 04 — Subtype Polymorphism, Abstract, Interfaces

The vtable appears. Calling a method through a base pointer dispatches to the derived implementation — this is the central magic of OOP and Module 04 makes you build it from scratch.

**Concepts introduced:**
- `virtual` member functions and runtime dispatch
- **Virtual destructors** — non-negotiable for any base class with a virtual method
- Pure virtual functions (`= 0`) and abstract classes
- Interfaces (classes with only pure virtual methods)
- Deep copy semantics for classes that own heap resources

#### ex00 — Animal / WrongAnimal

Two parallel hierarchies, one correct (with `virtual`), one deliberately wrong. The contrast makes the vtable visible.

```cpp
class Animal {
public:
    Animal(); virtual ~Animal();                 // virtual destructor!
    virtual void makeSound() const;
    std::string getType() const;
protected:
    std::string _type;
};

class Dog : public Animal {
public:
    Dog();
    virtual void makeSound() const;              // overrides
};
```

```cpp
Animal* a = new Dog();
a->makeSound();   // "Woof!"   — virtual dispatch picks Dog
delete a;         // calls ~Dog() then ~Animal() because ~Animal is virtual
```

**Gotcha:** Forget `virtual` on the destructor and `delete a` calls only `~Animal()`, leaking `Dog`'s subobject. This is the most common silent bug in the project.

#### ex01 — I don't want to set the world on fire

Each animal now owns a `Brain*` (100 `std::string` ideas). This *forces* you to implement deep copy.

```cpp
class Dog : public Animal {
    Brain* _brain;
public:
    Dog() { _brain = new Brain(); }
    Dog(const Dog& other) : Animal(other) {
        _brain = new Brain(*other._brain);       // allocate a fresh Brain
    }
    Dog& operator=(const Dog& other) {
        if (this != &other) {
            Animal::operator=(other);
            delete _brain;
            _brain = new Brain(*other._brain);
        }
        return *this;
    }
    virtual ~Dog() { delete _brain; }
};
```

```text
$ ./brain
Original idea[0] : I am a dog and I love bones.
Copy idea[0]     : I am a dog and I love bones.
Mutating original...
Original idea[0] : ACTUALLY I prefer cats.
Copy idea[0]     : I am a dog and I love bones.  ← unchanged: deep copy worked
```

**Gotcha:** Shallow copy gives two `Dog`s pointing at the same `Brain`. When both destructors run, you `delete` the same pointer twice → crash. The leak detector won't save you; it'll be undefined behaviour.

#### ex02 — Abstract class

```cpp
class AAnimal {
public:
    virtual void makeSound() const = 0;          // pure virtual → abstract
    virtual ~AAnimal();
    // ...
};

// AAnimal* a = new AAnimal();   // ❌ compile error: cannot instantiate abstract class
```

The change is one `= 0`. The effect is enormous: the type system now refuses to let you instantiate an incomplete contract.

#### ex03 — Interface & recap

The Materia system stacks three new ideas on the polymorphism you already know:
- **Abstract base** `AMateria` with pure virtual `clone()` and `use(ICharacter&)`.
- **Pure interface** `ICharacter` and `IMateriaSource` — no data, only pure virtual methods.
- **Factory** `MateriaSource::learnMateria` registers a template; `createMateria(name)` returns a fresh clone.

```cpp
class AMateria {
public:
    AMateria(std::string const & type);
    std::string const& getType() const;
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
    virtual ~AMateria();
protected:
    std::string _type;
};

class Ice : public AMateria {
public:
    Ice();
    virtual AMateria* clone() const { return new Ice(); }
    virtual void use(ICharacter& target) {
        std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
    }
};
```

**Critical pattern — floor-drop on unequip:** `Character::unequip(idx)` does **not** delete the materia. It removes it from the inventory but leaves the pointer alive. The owner of the materia (the test code, typically) is responsible for deleting it. Forgetting this is the #1 leak source in M04 ex03.

---

### Module 05 — Exceptions

Errors stop being return codes and become objects that travel up the stack until something catches them. The bureaucracy theme is on the nose: paperwork, signatures, ranks, and a stamp-loving Intern.

**Concepts introduced:**
- `throw`, `try`, `catch` and stack unwinding
- Custom exceptions inheriting from `std::exception` with overridden `what()`
- Nested exception classes (`Bureaucrat::GradeTooHighException`)
- Designing a class so its invariants are enforced at construction and mutation
- Factory pattern that selects an implementation by string without if-else chains

#### ex00 — Mommy, when I grow up, I want to be a bureaucrat

**Goal:** A `Bureaucrat` has a const name and a grade `1..150` (1 highest). Going out of range throws.

```cpp
class Bureaucrat {
public:
    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw() { return "Grade too high (must be >= 1)"; }
    };
    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw() { return "Grade too low (must be <= 150)"; }
    };

    Bureaucrat(std::string name, int grade);
    void increment();    // throws GradeTooHighException at grade 1
    void decrement();    // throws GradeTooLowException at grade 150
private:
    const std::string _name;
    int               _grade;
};
```

**Gotcha:** `what()` must be declared `throw()` — that's how you promise (in C++98) that the function itself doesn't throw. Forget it and the override doesn't match the base signature.

#### ex01 — Form up, maggots!

**Goal:** A `Form` has a const name, an `_isSigned` flag, and two const grades — one to sign, one to execute. `Bureaucrat::signForm(Form&)` catches `Form::GradeTooLowException` and prints the right message.

```cpp
void Bureaucrat::signForm(Form& f) {
    try {
        f.beSigned(*this);
        std::cout << _name << " signed " << f.getName() << std::endl;
    } catch (std::exception& e) {
        std::cout << _name << " couldn't sign " << f.getName() << " because: " << e.what() << std::endl;
    }
}
```

#### ex02 — No, you need form 28B, not 28C

`Form` becomes `AForm`, abstract by way of `virtual void execute(Bureaucrat const& executor) const = 0`. Three concrete forms with distinct grade requirements:

| Form | Sign grade | Exec grade | Effect |
|------|-----------:|-----------:|--------|
| `ShrubberyCreationForm` | 145 | 137 | Writes ASCII trees to `<target>_shrubbery` |
| `RobotomyRequestForm`   | 72  | 45  | 50% chance of success (`rand()`), prints either "robotomized" or "failed" |
| `PresidentialPardonForm`| 25  | 5   | Prints pardon by Zaphod Beeblebrox |

```cpp
void PresidentialPardonForm::execute(Bureaucrat const& executor) const {
    if (!isSigned())                   throw FormNotSignedException();
    if (executor.getGrade() > getGradeToExecute()) throw GradeTooLowException();
    std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
```

**Gotcha:** Both **signed status** *and* **executor grade** must be checked. Many people forget the signed check and discover it only in evaluation.

#### ex03 — At least this beats coffee-making

**Goal:** `Intern::makeForm(formName, target)` returns a freshly-allocated `AForm*` of the right concrete type — **without** if/else chains.

```cpp
AForm* Intern::makeForm(std::string const& name, std::string const& target) const {
    std::string const  names[]   = { "shrubbery creation", "robotomy request", "presidential pardon" };
    AForm* (*ctors[])(std::string const&) = { &makeShrubbery, &makeRobotomy, &makePardon };
    for (int i = 0; i < 3; ++i) {
        if (names[i] == name) {
            std::cout << "Intern creates " << name << std::endl;
            return ctors[i](target);
        }
    }
    std::cout << "Intern can't find form '" << name << "'" << std::endl;
    return NULL;
}
```

The lookup is O(N) for N=3 — but the *pattern* (parallel arrays of names + function pointers) generalises cleanly. This is the same shape as `Harl::complain` from M01 ex05.

---

### Module 06 — C++ Casts & RTTI

C casts (`(int)x`) are a sledgehammer. C++ gives you four scalpels — pick the right one and the type system will catch your mistakes for you.

**Concepts introduced:**
- `static_cast` — compile-time conversions the language already knows are safe
- `dynamic_cast` — runtime downcast through a polymorphic hierarchy
- `reinterpret_cast` — "trust me, treat these bits as that type"
- `const_cast` — strip (or add) `const`/`volatile`
- Non-instantiable utility classes (private constructor, static methods only)
- Special floating-point literals: `nan`, `nanf`, `inf`, `+inf`, `-inf`, `inff`, ...

#### ex00 — Conversion of scalar types

**Goal:** Parse a string literal and print it converted to `char`, `int`, `float`, `double`. Handle overflow, non-displayable chars, and pseudo-literals.

```cpp
class ScalarConverter {
public:
    static void convert(const std::string& literal);
private:
    ScalarConverter();                            // non-instantiable
    ScalarConverter(const ScalarConverter&);
    ScalarConverter& operator=(const ScalarConverter&);
    ~ScalarConverter();
};
```

```text
$ ./convert 42
char:   '*'
int:    42
float:  42.0f
double: 42.0

$ ./convert nan
char:   impossible
int:    impossible
float:  nanf
double: nan

$ ./convert 4242424242
char:   impossible
int:    impossible          ← overflows
float:  4242424384.0f       ← float precision loss is visible
double: 4242424242.0
```

**Gotcha:** Don't try to detect the type with `std::stringstream` and then reuse the parsed value — different target types have different valid ranges. Detect the *category* (char literal? float? double? int?) first, then convert separately.

#### ex01 — Serialization

**Goal:** Prove a pointer is just an integer.

```cpp
class Serializer {
public:
    static uintptr_t serialize(Data* ptr)   { return reinterpret_cast<uintptr_t>(ptr); }
    static Data*     deserialize(uintptr_t raw) { return reinterpret_cast<Data*>(raw); }
};
```

The test asserts `deserialize(serialize(p)) == p`. The lesson is humbling: a pointer is an address, and an address is a number.

#### ex02 — Identify real type of objects

```cpp
class Base { public: virtual ~Base() {} };       // virtual dtor enables RTTI
class A : public Base {};
class B : public Base {};
class C : public Base {};

Base* generate() {                                // randomly returns A, B, or C
    switch (std::rand() % 3) {
        case 0: return new A;
        case 1: return new B;
        default:return new C;
    }
}

void identify(Base* p) {
    if      (dynamic_cast<A*>(p)) std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p)) std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p)) std::cout << "C" << std::endl;
}

void identify(Base& r) {
    try { (void)dynamic_cast<A&>(r); std::cout << "A" << std::endl; return; } catch (std::bad_cast&) {}
    try { (void)dynamic_cast<B&>(r); std::cout << "B" << std::endl; return; } catch (std::bad_cast&) {}
    try { (void)dynamic_cast<C&>(r); std::cout << "C" << std::endl; return; } catch (std::bad_cast&) {}
}
```

**The headline difference:**
- `dynamic_cast<T*>(ptr)` returns **`NULL`** on failure.
- `dynamic_cast<T&>(ref)` throws **`std::bad_cast`** on failure (references can't be null, so there's no other option).

---

### Module 07 — Templates

You write code once that compiles into many types. C++ templates are turing-complete and famously cryptic — Module 07 keeps them gentle.

**Concepts introduced:**
- Function templates with type deduction
- Class templates and explicit instantiation
- `typename` to disambiguate dependent types
- Header-only template definitions (templates must be visible at every instantiation site)

#### ex00 — whatever.hpp

```cpp
template <typename T>
void swap(T& a, T& b) { T tmp = a; a = b; b = tmp; }

template <typename T>
const T& min(const T& a, const T& b) { return a < b ? a : b; }

template <typename T>
const T& max(const T& a, const T& b) { return a > b ? a : b; }
```

**Gotcha:** The subject specifies that when the arguments are equal, `min` and `max` return the **second** operand. That's why the implementation uses `<` and `>` strictly (not `<=` / `>=`).

#### ex01 — iter.hpp

```cpp
template <typename T>
void iter(T* array, size_t length, void (*f)(T&)) {
    for (size_t i = 0; i < length; ++i) f(array[i]);
}

template <typename T>
void iter(const T* array, size_t length, void (*f)(const T&)) {
    for (size_t i = 0; i < length; ++i) f(array[i]);
}
```

Two overloads — one mutable, one const — so the function adapts to the caller's intent.

#### ex02 — Array

A drop-in `T[]` replacement with bounds-checked access and proper copy semantics.

```cpp
template <typename T>
class Array {
public:
    Array() : _size(0), _elements(NULL) {}
    Array(unsigned int n) : _size(n), _elements(new T[n]()) {}   // value-initialise
    Array(const Array& other) : _size(other._size), _elements(new T[_size]) {
        for (unsigned int i = 0; i < _size; ++i) _elements[i] = other._elements[i];
    }
    Array& operator=(const Array& other);
    ~Array() { delete[] _elements; }

    T&       operator[](unsigned int i);
    const T& operator[](unsigned int i) const;
    unsigned int size() const { return _size; }

    class MyVeryVeryHandsomeMaxEmilianVerstappenOutOfRangeExceptionClassThatNeverExistBeforeLetsGetItSimplyLovely
        : public std::exception {
    public:
        virtual const char* what() const throw() { return "Error: Index out of bounds!"; }
    };
private:
    unsigned int _size;
    T*           _elements;
};
```

**Two things make this exercise click:**
1. `new T[n]()` (note the trailing `()`) value-initialises every element — integer arrays come out as zeros, not garbage.
2. Out-of-bounds access throws a properly-named exception class. (Yes, the name is real. Pick your favourite F1 driver — the subject only insists on *a* custom exception.)

---

### Module 08 — Templated Containers & Iterators

You stop writing containers and start *using* them — but you keep templates everywhere so your utilities adapt to whichever STL container the caller picked.

**Concepts introduced:**
- Iterator typedefs as template constraints (`typename T::iterator`)
- STL algorithm headers (`<algorithm>`, `std::find`, `std::sort`)
- Subclassing an STL adapter to expose its hidden container
- Range constructors via template member functions

#### ex00 — easyfind

```cpp
template <typename T>
typename T::iterator easyfind(T& container, int value) {
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end()) throw NotFoundException();
    return it;
}
```

The `typename` is *not* optional — `T::iterator` is a dependent name; without `typename` the compiler doesn't know it's a type. Works with `std::vector<int>`, `std::list<int>`, `std::deque<int>`, anything with a forward iterator.

#### ex01 — Span

**Goal:** A container that accepts up to N integers and answers `shortestSpan()` and `longestSpan()` (smallest and largest difference between any two stored numbers).

```cpp
class Span {
public:
    Span(unsigned int n);
    void addNumber(int n);

    template <typename It>
    void addNumbers(It first, It last) {           // range insert
        if (_numbers.size() + std::distance(first, last) > _maxSize)
            throw SpanFullException();
        _numbers.insert(_numbers.end(), first, last);
    }

    int shortestSpan() const;                      // sort + adjacent diff
    int longestSpan()  const;                      // max - min
private:
    unsigned int     _maxSize;
    std::vector<int> _numbers;
};
```

**Gotcha:** `shortestSpan` is *not* `min - second-min`. After sorting, the smallest span is the smallest difference between **adjacent** elements. `std::adjacent_difference` is the cleanest way; a manual loop works too.

#### ex02 — MutantStack

**Goal:** `std::stack` doesn't expose iterators by design — it's an adapter. Add iterator support.

```cpp
template <typename T>
class MutantStack : public std::stack<T> {
public:
    MutantStack();
    MutantStack(const MutantStack& other);
    MutantStack& operator=(const MutantStack& other);
    ~MutantStack();

    typedef typename std::stack<T>::container_type::iterator iterator;
    iterator begin() { return this->c.begin(); }
    iterator end()   { return this->c.end();   }
};
```

The trick: `std::stack` stores its underlying container in a **protected** member named `c`. By inheriting publicly, `MutantStack` can reach into `c` and surface its iterators. That `typedef typename std::stack<T>::container_type::iterator iterator;` is the kind of incantation that reads like static — until you decode it word by word.

```text
$ ./mutantstack
top: 17
size: 1
17
5
3
737
0    ← iterating bottom-to-top because std::deque is the default container
```

---

### Module 09 — STL Containers & Algorithms

The capstone. Three exercises, each one shaped like a small real-world problem.

**Concepts introduced:**
- `std::map<K,V>` for sorted associative storage
- `std::lower_bound` for binary search on sorted ranges
- `std::stack<T>` for postfix expression evaluation
- Two-container algorithm comparison (`std::vector` vs `std::deque`)
- Hand-rolled Ford-Johnson **merge-insertion sort** with **Jacobsthal-ordered insertion**

#### ex00 — BitcoinExchange

**Goal:** Given `data.csv` mapping `date,exchange_rate` and an `input.txt` of `date | value` queries, compute and print `date => value = value*rate`. Use the closest *earlier* date in the CSV when the query date is missing.

```cpp
class BitcoinExchange {
public:
    void loadDatabase(const std::string& csvPath);
    void processInput (const std::string& inputPath);
private:
    std::map<std::string, float> _rates;          // ISO-8601 date → rate
};

// inside processInput, for each query line:
std::map<std::string,float>::const_iterator it = _rates.lower_bound(date);
if (it == _rates.end() || it->first != date) {
    if (it == _rates.begin()) { /* no earlier date — error */ }
    --it;                                         // step to closest earlier date
}
float rate = it->second;
std::cout << date << " => " << value << " = " << value * rate << std::endl;
```

```text
$ ./btc input.txt
2011-01-03 => 3 = 0.9
2011-01-03 => 2 = 0.6
2011-01-09 => 1 = 0.32
Error: not a positive number.
Error: too large a number.
2012-01-11 => 1 = 7.1
```

**Why `std::map` and not `std::unordered_map`?** `unordered_map` didn't exist until C++11, and even if it did, `map` lets you do range queries (`lower_bound`) cheaply because the keys are sorted. The closest-earlier-date lookup is *the* reason to pick a sorted container.

#### ex01 — RPN

**Goal:** Evaluate a Reverse Polish Notation expression like `"8 9 * 9 - 9 - 9 - 4 - 1 +"`.

```cpp
int evaluate(const std::string& expr) {
    std::stack<int> s;
    std::stringstream ss(expr);
    std::string tok;
    while (ss >> tok) {
        if (tok.size() == 1 && std::string("+-*/").find(tok[0]) != std::string::npos) {
            if (s.size() < 2) throw std::runtime_error("Error");
            int b = s.top(); s.pop();
            int a = s.top(); s.pop();
            switch (tok[0]) {
                case '+': s.push(a + b); break;
                case '-': s.push(a - b); break;
                case '*': s.push(a * b); break;
                case '/': s.push(a / b); break;
            }
        } else {
            // single-digit operand
            if (tok.size() != 1 || !std::isdigit(tok[0]))
                throw std::runtime_error("Error");
            s.push(tok[0] - '0');
        }
    }
    if (s.size() != 1) throw std::runtime_error("Error");
    return s.top();
}
```

```text
$ ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
42
$ ./RPN "7 7 * 7 -"
42
$ ./RPN "(1 + 1)"
Error
```

**Gotcha:** Operand order matters — `a / b` not `b / a`. The first popped value is the *right-hand* operand. This is the bug everyone writes once.

#### ex02 — PmergeMe

The capstone of the capstone. See the [Algorithm Spotlight](#-algorithm-spotlight--ford-johnson-merge-insertion-sort) below — it deserves its own section.

```text
$ ./PmergeMe `shuf -i 1-100000 -n 3000 | tr '\n' ' '`
Before: 32841 71288 4172 12990 ...
After:  1 4 7 8 11 12 19 ...
Time to process a range of 3000 elements with std::vector : 4823.00000 us
Time to process a range of 3000 elements with std::deque  : 6107.00000 us
```

---

## 🚀 Getting Started

### Prerequisites

- A C++98-capable compiler (`g++`, `clang++`, Apple Clang all work)
- GNU `make`
- A Unix-like shell (Linux, macOS, WSL)

### Build and run any exercise

Every exercise builds the same way:

```bash
cd ModuleXX/exYY/srcs
make            # build → produces a binary in this directory
./<binary>      # run it
make clean      # delete .o files
make fclean     # delete .o files and the binary
make re         # fclean + all
```

### Concrete examples

```bash
# Module 00 / ex01 — interactive PhoneBook
cd Module00/ex01/srcs && make && ./phonebook

# Module 04 / ex03 — Materia system
cd Module04/ex03/srcs && make && ./materia

# Module 09 / ex02 — Ford-Johnson sort on 100 random integers
cd Module09/ex02/srcs && make
./PmergeMe `shuf -i 1-1000 -n 100 | tr '\n' ' '`
```

### Memory leak check (recommended)

The project is graded on leak-free execution. Run any binary under a leak checker:

```bash
# Linux
valgrind --leak-check=full --show-leak-kinds=all ./<binary>

# macOS (Xcode tools)
leaks --atExit -- ./<binary>
```

---

## 📋 Compilation Flags

Every Makefile in this repository uses identical flags:

```makefile
CXX      = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
```

| Flag | Why |
|------|-----|
| `-Wall` | Enable the common warnings — uninitialised variables, unused locals, etc. |
| `-Wextra` | Enable additional warnings that catch real bugs (signed/unsigned compares, missing initialisers in aggregate init). |
| `-Werror` | Treat every warning as an error. There is no "I'll fix it later" with this flag. |
| `-std=c++98` | Lock the standard. No `auto`, no `nullptr`, no range-for, no `std::unique_ptr`, no `=default`, no `=delete`. |

If your build fails because of a C++11-ism you didn't realise you used, that's the lesson: now you know one more thing the modern standards quietly do for you.

---

## 🔬 Algorithm Spotlight — Ford-Johnson Merge-Insertion Sort

Module 09 ex02 is the most algorithmically dense exercise in the project. The goal:

> **Sort N positive integers in fewer comparisons than any standard sort, using two different STL containers, and prove the second container behaves differently.**

The chosen algorithm is **Ford-Johnson merge-insertion sort** (1959) — historically the comparison-optimal sort for small `N`. The implementation uses `std::vector` and `std::deque` side by side, sorts identical input twice, and prints both timings.

### The five-phase walkthrough (worked on `[3, 1, 4, 1, 5, 9, 2]`)

#### Phase 1 — Pair up, larger first

Walk the input two at a time. In each pair, put the larger element first. If the input has odd length, the last element is the **straggler** and waits until the very end.

```
input    : 3  1   4  1   5  9   |   2     ← straggler
pairs    : (3,1) (4,1) (9,5)    |   2
                                   (larger, smaller)
```

#### Phase 2 — Sort the pairs by their "larger" element

Use insertion sort on the pair list, keyed on the first element of each pair. The smaller elements come along for the ride.

```
sorted pairs : (3,1) (4,1) (9,5)
                ^      ^      ^
              larger elements are sorted: 3, 4, 9
```

#### Phase 3 — Build the main chain

The first pair's smaller element starts the chain, followed by all the "larger" elements in order.

```
main chain   : 1  3  4  9                  ← from pairs[0].second, then every pairs[i].first
pending      : 1  5                        ← every pairs[i].second for i >= 1
straggler    : 2
```

#### Phase 4 — Insert the pending chain in **Jacobsthal order**

This is the clever bit. The Jacobsthal sequence is `0, 1, 1, 3, 5, 11, 21, 43, ...` defined by `J(n) = J(n-1) + 2·J(n-2)`. The insertion *indices* the algorithm visits are `1, 3, 5, 11, 21, ...` — each new "group" is the next Jacobsthal number, and within a group you insert in reverse order.

Why this order? Because at each step the prefix of the main chain you're searching has grown to a power of two — so `lower_bound` (binary search) costs the same constant number of comparisons. Inserting in plain left-to-right order would force the prefix to grow by 1 each time, wasting comparisons.

```
pending      : 1  5
insert order : index 1 (which is pending[1] = 5), then index 0 (pending[0] = 1)
                ↓
main becomes : 1  3  4  5  9       (after inserting 5 via lower_bound)
main becomes : 1  1  3  4  5  9    (after inserting 1)
```

#### Phase 5 — Insert the straggler

Same `lower_bound`-based binary insert.

```
final        : 1  1  2  3  4  5  9
```

### Why two containers?

The subject demands you implement the algorithm on **two different STL containers** and compare timings. The implementation in this repo uses `std::vector` and `std::deque`:

| Container | Memory layout | Mid-insert cost | Index access |
|-----------|---------------|-----------------|--------------|
| `std::vector` | Single contiguous block | O(N) — shifts every element after the insert point | O(1), cache-friendly |
| `std::deque`  | Multiple fixed-size blocks | Still O(N), but with better cache behaviour on some platforms | O(1), one extra indirection |

In practice `vector` usually wins for small N because cache locality dominates; `deque`'s win materialises only at much larger sizes or with pathological insert patterns. Printing both timings makes the tradeoff visible.

### Where to look in the code

| File | What's there |
|------|--------------|
| [`Module09/ex02/srcs/PmergeMe.cpp`](Module09/ex02/srcs/PmergeMe.cpp) | `sortVector`, `sortDeque`, `sortPairs`, `createJacobsthalSequence` |
| [`Module09/ex02/includes/PmergeMe.hpp`](Module09/ex02/includes/PmergeMe.hpp) | Class layout + two parallel containers |

---

## 📚 C++ Glossary

Definitions tuned to how each term shows up in this project.

- **Abstract class** — A class with at least one pure virtual method. Cannot be instantiated.
- **Adapter (STL)** — A container interface that wraps another container (`stack`, `queue`, `priority_queue` wrap `deque` by default).
- **Canonical Form / Orthodox Canonical Form** — In C++98: default constructor, copy constructor, copy-assignment operator, destructor. The "four required methods" of a well-behaved class.
- **`const_cast`** — Adds or removes `const`/`volatile`. Used sparingly to interface with legacy APIs.
- **Deep copy** — Copying an object including any heap resources it owns, so the copy and original can be modified independently.
- **Diamond inheritance** — `D` inherits from `B` and `C`, both of which inherit from `A`. Resolved with virtual inheritance to share the `A` subobject.
- **`dynamic_cast`** — Runtime-checked downcast through a polymorphic hierarchy. Returns `NULL` (pointers) or throws `std::bad_cast` (references) on failure. Requires the source type to have a `virtual` function.
- **Encapsulation** — Hiding data behind methods so invariants can be enforced.
- **Factory pattern** — A function or class that returns objects of various concrete types behind a common interface. See `MateriaSource`, `Intern`.
- **Function pointer** — A variable holding the address of a free function: `void (*fp)(int)`.
- **Interface** — A class composed only of pure virtual methods (no data, no implementation). C++ has no `interface` keyword; you express it with an abstract class.
- **Jacobsthal sequence** — `J(n) = J(n-1) + 2·J(n-2)`, starting `0, 1, 1, 3, 5, 11, 21, ...`. Used in Ford-Johnson to choose insertion indices so each binary search runs on a power-of-two prefix.
- **`lower_bound`** — STL algorithm returning the first iterator in a sorted range whose element is *not less than* a target. The right tool for "find the closest key ≥ X".
- **Member function pointer** — Pointer to a non-static method. Syntax: `void (Class::*ptr)() = &Class::method;`. Called with `(obj.*ptr)()` or `(objPtr->*ptr)()`.
- **Merge-insertion sort (Ford-Johnson)** — A comparison-optimal sort for small N. Pairs elements, sorts pairs by their larger half, inserts the smaller halves in Jacobsthal-order.
- **Polymorphism (ad-hoc)** — Same operator/name behaves differently for different argument types. Achieved through overloading.
- **Polymorphism (subtype)** — A base-class pointer dispatches to a derived implementation at runtime via the vtable.
- **Pure virtual function** — A virtual method declared with `= 0`, making its class abstract. Subclasses must override it to be instantiable.
- **RAII** — Resource Acquisition Is Initialization. The lifetime of a resource is bound to the lifetime of an object: acquire in constructor, release in destructor.
- **`reinterpret_cast`** — Treats a bit pattern as a different type. No conversion, no checks. Used for pointer↔integer round-trips and serialization (M06 ex01).
- **RTTI** — Runtime Type Information. The mechanism behind `dynamic_cast` and `typeid`. Enabled by having at least one `virtual` method in the class.
- **Shallow copy** — The default member-by-member copy. Fine for value types; catastrophic for classes owning heap memory (double-delete).
- **Smart pointer** — Not in C++98. The earliest one (`std::auto_ptr`) is deprecated and broken; modern `unique_ptr`/`shared_ptr` arrived in C++11. In this project you manage `new`/`delete` by hand.
- **`static_cast`** — Compile-time conversion the language understands (numeric promotion, related-class upcast/downcast without runtime check, `void*` to typed pointer).
- **Template instantiation** — The compiler generates a concrete class/function for each unique set of template arguments used. Definitions must be visible at the call site, which is why templates live in headers.
- **Virtual destructor** — A destructor declared `virtual` so that `delete base_ptr` calls the derived destructor too. Required on any base class with virtual methods.
- **Virtual function** — A method dispatched at runtime through the vtable based on the dynamic type of the object.
- **`typename` (disambiguator)** — Tells the compiler that a dependent name (e.g. `T::iterator`) is a type, not a static member. Required in template code.

---

## 🔗 Additional Resources

- [CPP Reference](https://en.cppreference.com/) — the definitive reference. Filter to C++98 when in doubt.
- [LearnCpp.com](https://www.learncpp.com/) — readable tutorials covering the language end to end.
- [42 Docs (community)](https://harm-smits.github.io/42docs/) — peer-written notes on every 42 project.
- [Ford-Johnson algorithm — original 1959 paper](https://www.cambridge.org/core/journals/journal-of-symbolic-logic/article/abs/economical-method-for-calculating-the-square-root-of-the-sum-of-the-squares-of-n-numbers/) — for the algorithmically curious.
- [Jacobsthal numbers on OEIS](https://oeis.org/A001045) — the sequence and its properties.
- [ISO C++ Core Guidelines](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines) — once you graduate from C++98, this is the next thing to read.

---

## 👨‍💻 Author

**Ahmet Zorlutuna**
École 42 İstanbul

---

## 📄 License

This project is licensed under the **GNU General Public License v3.0** — see the [LICENSE](LICENSE) file for the full text.

---

## ⚠️ Academic Integrity

This repository is public for **educational and portfolio purposes**. If you are a 42 student working through the same modules:

- **Read it to understand**, not to copy. Each evaluation includes a defence — you cannot fake understanding live.
- **Write your own code.** The subjects are intentionally underspecified so you have to make decisions; copying mine erases your learning.
- **42's academic integrity policy** treats submitted-but-not-understood code as cheating. Use this repo the way you'd use a textbook: as a reference, not as an answer key.

If you find a bug, an unclear explanation, or a better way to do something, open an issue — I'd love to hear it.

---

<div align="center">

**Built one `Makefile` at a time at 42 İstanbul.**

</div>
