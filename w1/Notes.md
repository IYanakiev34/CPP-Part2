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
