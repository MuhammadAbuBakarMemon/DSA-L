/*

When using DMA in cpp, it is important that we must ensure that our objects are copied properly to avoid issues 
like double deletion and resource sharing.... 

The Rule of Three in cpp suggests/states that if we define any one of the following three functions we must define all three. these three functions 
ensure proper handling/mangement of resources during copying and assignment especially when DMA is involved

1) Destructor: cleans up dynamically allocated resources (file handles, memory), when the object goes out of scope or is explicitly deleted
    If we do not define a custom destructor then the defualt destructor may not free the dynamically allocated memory leading to memeory leaks

2) Copy Constructor: creates a deep copy of an object when it is passsed by value or returned by value, at the time of object creation
    Without a custom copy constructor c++ will perform shallow copy by default, which can lead to double deletion or data corruption when the objects 
    are manipulated or destroyed

3) Copy Assignment Operator: assigns one object's value to another (already created) object ensuring deep copy if necessary 
    Without a custom copy assignment operator the default shallow assignment is performed, which can lead to resource conflicts, double deletion and 
    incorrect data sharing betweeen objects 

*/