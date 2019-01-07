# spruce style guide

## cpp version
use cpp17 features as long as it follows the rest of the guide 

## headers vs source files

for every Name.h there should exist Name.cpp even if it is empty (good chance that it shouldn't be empty)

#### headers
headers should define only what is needed to use the type within other source files or header files
headers should act as much as possible as forward declarations of the content in the associated source file

###### naming
if creating a forward declaration of a class: create ClassNameFwd.h to contain it
if a header is very long use may create NameImpl.h to contain the implementations and leave forward declarations in Name.h declaring ```#include <path/to/NameImpl.h>``` at the bottom of Name.h

#### source files
sources files should contain as much code as possible

## classes

#### ```class``` vs ```struct```

use 
```struct``` only for types that are encapsulating data
for example [buffer](core/src/memory/buffer.h), [color](core/src/graphics/color.h) and [vec3f](core/src/math/vec/vec3f.h).
for all other types use ```class```

#### naming
if a class is declared with ```struct``` use camelCase classes declared with ```class``` should use PascalCase

### member variables
name using camelCase

### member functions
name using camelCase

#### operator overloading
only overload operators to make syntax clearer and are unsurprising.
do overload ```opearator<<``` for streams to make conversion to string for logging or otherwise easy and consistant 
examples:
- the vector classes override math operators (+,-,\*,/) as the syntax ```vec3f(1, 0, 0) + vec3f(0, 1, 0)``` is clearer than ```vec3f(1, 0, 0).add(vec3f(0, 1, 0))```
- buffers overload ```operator[]``` to provide access as if the buffer was the array that it is abstracting

#### special member functions

do define the special member functions explicitly.
if ```= default``` works use it
use ```= delete``` to delete

for example:
```cpp
class Example {
  public:
    int i = 0; // to allow for Example() = default;
  
    Example() = default;
    Example(const Example&) = default; // indicates this type can be copied, note: no variable name required as it is defaulted
    Example(Example&&) noexcept = default;
  
    Example& operator=(const Example&) = default;
    Example& operator=(Example&&) noexcept = default;
};
```


#### templates
use templates to ensure type safety
do not define a tempalated method inside the class definition in order to make classes more readable. classes should function as a forward declaration of their 
for example:
```cpp
template <typename TYPE>
class Example {
  public:
    void doSomething();
};

template <typename TYPE>
void Example<TYPE>::doSomething() {
  // do something
}
```
is prefered to
```cpp
template <typename TYPE>
class Example {
  public:
    void doSomething() {
      // do something
    }
};
```

## ownership and memory management

## const

## misc formatting
use tabs not spaces for indentation

## comments

## casting
use c-style casts -- note: this may change

## linting
do lint code
suggested: clang-tidy
but anything that works is fine as long as the resulting code follows this guide

## objective-cpp
write only what is necessary using objective-c++
header files remain .h but source become .mm
make sure that objective-cpp code is _very_ self contained
