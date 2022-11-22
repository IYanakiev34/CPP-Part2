Not sure if this is right, just did a google search on static vs dynamic libraries but there might be more to this.

In addition, answer the following question: assume your initial implementation defined the s_options static data member, and is made available in a software library. The modified implementation defines a static Destructor s_destructor object. You're the developer of that library, and you publish Options's new implementation. What must users of your Object class do so their programs use the new Options implementation:
* When your library is made available as a static library
In a static library, the code is locked in a final executable file, which means that to apply changes, you need to recompile the library. That means you would have to update the file in the library and then recompile the whole thing.
* When your library is made available as a dynamic (shared) library 
In a dynamic library, the code lives outside the executable, so you don't have to recompile. You just have to replace the old file version with the new one.
