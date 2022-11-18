# Notes on the first 2 exercises

## Copy/Move constructor

1. Copy: copies the object into another new object
2. Move: steals the resources into the object

## Overloading of =/[]

1.  =
    - if other object is lvalue then we copy the resources
    - if rvalue then we steal the resources with swap and return \*this
2.  []
    - Return reference to elements
    - Think about if operating on const object or not
    - Implement them as inline
    - Implement the getElement(std::size_t idx) to be private memeber function to avoid code duplication

## Overloading +=/-=

1. Think about if operating on const reference or rvalue reference
2. This about the calling object if it is && or &
   - if & then we should proceed to return a reference
     - create copy steal add or remove and swap and return
   - if && return move contructed object
     - directly add or remove and then return move object to be move constructed

## Overloading binary operators +/-

1. Should be implemented as free function or friends: this allows for promotions to either lhs or rhs
2. Make use of the already built += or -= functions
3. Cannot bind && ot & since they are free functions

## Overloading -=,_=,/= / _ - same

1. Basically the same

## Creating a copy of a file without streams

1. Use the std::filesystem::copy
2. Make it with the same timestamp for last modification
   - Get the original timestamp
   - Gte the copy timestamp
   - copyT - (copyT - origT)

## Bitwise overloading

1. Use static_cast to cast between int and the enum type for overloading
2. For the show(Enum::Type name) name function make char const \*array of the names based on the set bits display names
3. Bitset size() function return the size of the bitset ie. how many there are
4. Bitset count() function return how many are set to 1
5. Bitset test(size_t idx) function test if bit at position i is set (starts from the back)
   - 00000011 -> bit.test(0) = 1

## Exercise 5

### Why is First::fun called?

1. First::fun() is called because the the First namespace contains the argument types (in our case the Enum type) and it also
   contains the function fun(). Thus due to the Koening lookup when we just call fun() we see that the Enum type is defined in the
   First namespace and we use the fuction in this namespace. In order to call fun() from the Second namespace we can do
   something like: Second::fun(args).
2. The operator << is simplfied due to the reaosn mentioned above. For example std::cout << there is no << in the gloab namespace thus is examines the
   namespace of std and finds the operator. Based on the function call arguments and where their defined the compiler can resolve the statement.
   For example operator<<(std::cout,"Hello World\n) is a valid function call.
3. The Koenig Lookup works on namespaces. Since the function fun() defines in main has a parameter type defined inside a namespace (First)
   and First also has a function with identical signature then there is ambiguity that the compiler cannot resolves. The program cannot even compile and produces error: call of overloaded 'fun(First::Enum) is ambigious'. As stated above this is due to having a function with mathics signature from a namespace defined outside of a namespace having arguments that are defined inside the namespace in mind. (First).

## Exercise 6

### Output

1. NONE
2. EMERG
3. CRIT ALERT
4. WARNING ERR
5. DEBUG INFO WARNING ERR CRIT ALERT EMERG
