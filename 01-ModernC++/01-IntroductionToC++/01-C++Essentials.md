# **TOPICS:**
- ### [[#01. Datatypes]]
	- #### [[#1.1. Built-in Datatypes]]
	- #### [[#1.2. User-Defined Datatypes]]
	- #### [[#1.3. Declare and Assignation of Variables]]
	- #### [[#1.4. Modifiers]]
	- #### [[#1.5. Complex Datatypes]]

## 01. Datatypes:
### 1.1. Built-in Datatypes:
#### 1.1.1. Basic Datatypes:
- `bool`: 1 Byte
- `char`: 1 Byte
- `unsigned char`: 1 Byte
- `int`: 4 Byte
- `unsigned int`: 4 Byte
- `short`: 2 Byte
- `unsigned short`: 2 Byte
- `long`: 4 Byte
- `unsigned long`: 4 Byte
- `long long`: 8 Byte
- `unsigned long long`: 8 Byte
- `float`: 4 Byte
- `double`: 8 Byte
#### 1.1.2. Complex Datatypes:
- `Array`.
- `Vector`.

### 1.2. User-Defined Datatypes:
- Class.
- Struct.
- Enum.
- Customized Datatypes `typedef <Built-in> <User-Defined>`.

### 1.3. Declare and Assignation of Variables:
```cpp
int type1;           // Declaration
type1 = 10;          // Assignation
```

```cpp
char type2 = 'A';    // Normal C initialization
int type3 (1);       // Direct Initialization
int type3 {1};       // Uniform Initialization
```

```cpp
class {              // user-defined datatype
	unsigned int userId;
	std::string userName;
	unsigned char userAge;
}
```

### 1.4. Modifiers
**In C++, modifiers are keywords that modify the behavior of fundamental data types. They can be used to alter the size or properties of a data type. Here are some common modifiers in C++:**

1. **`const`**: 
This keyword is used to declare constants. It indicates that the *value of a variable cannot be changed* ==after it is initialized==.
```cpp
const int myConstVar = 10; 
```

2. **`volatile`**: 
This keyword is used to indicate that a *variable may be changed by some external factors*, such as hardware, and ==should not be optimized by the compiler==.
```cpp
volatile int sensorValue; 
```

3. **`mutable`**: 
It is used in a class to *allow a particular data member to be modified* ==even if the object is declared as const==.
```cpp
class Example { 
public: 
	mutable int mutableVar; 
}; 
```

4. **`static`**: 
-When used with variables, it makes the variable retain its value between function calls.
-When used with function, it make the function visible only in file scope.
-When used with member in class, it makes the member a class function rather than an instance member.
-When used with method in class, it makes the function a class function rather than an instance function.
```cpp
static int staticVar; 
static void staticFunction(); 
```

5. **`extern`**: 
It is used to declare a variable or function that is defined in another file or in an external library.
	These modifiers play a crucial role in controlling the behavior of variables and functions in C++. Keep in mind that the context in which these modifiers are used may affect their meaning and impact.
```cpp
extern int externVar; 
extern void externFunction(); 
```

### 1.5. Complex Datatypes:
#### 1.5.1. Arrays and Vectors:
```cpp
#include <array>
#include <vector>
#define SIZE 5

int main {
	std::array<int,  SIZE> arrayInstance1 {1, 2, 3, 4, 5};
	std::array<char, SIZE> arrayInstance2;
	std::vector<int> vectorInstance1 {10, 20, 30, 40, 50, 60};
	
	arrayInstance2[3] = 10;
	arrayInstance2.at(3) = 10;
	std::cout<< arrayInstance1.front() << std::endl;
	std::cout<< arrayInstance1.back() << std::endl;
	std::cout<< arrayInstance1.size() << std::endl;
	if(arrayInstance2.empty()) {
		std::cout<< "Array is Empty" << std::endl;
	}
	arrayInstance2.fill(0);
	
	for(auto& element: vectorInstance1) {
		std::cout<< element << "\n";
	}`
	
	return 0;
}
```

#### 1.5.2. Strings:
```cpp
#include <string>

int main() {
	std::string text1 {"Bullet"};

	std::string text2;
	text2 = text1;

	std::cout << text1.size() << std::endl;     // Return actual size of string
	std::cout << text1.length() << std::endl;   //size == length
	std::cout << text1.max_size() << std::endl; // Return max size string can reach.
	std::cout << text1.capacity() << std::endl; // Return max size string can reach, b4     string reserve a new memory location to accomdate string expansion.
	
	text2.push_back("Guru");
	
	text1.clear();
	if(text1.empty()) {
		std::cout<< "String is Empty" << std::endl;
	}

	/* Create Array of Containers */
	std::vector<std::string> fullName {"Ahmed", "Mahmoud", "Mohamed"};
	
	return 0;
}
```