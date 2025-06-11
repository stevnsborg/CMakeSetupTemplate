# Demo
---
When developing C/C++ .dll packages, the compiler does not generate an executable. Therefore, if the functions are to be tested or used in a validating setting it can be helpful to compile an executable console application in parallel that installs the module and calls the functions. This demo environment presents an example of such a resource. 

In practice, the project is compiled in a sequence with the module compiling first followed by the **Demo** module to ensure that the functions are kept updated.

The nature and requirements for the **Demo** envinment may change depending on the particular project and the end use cases. Regardless there should always exist a for of sandbox testing site where the quality and performance of the functions can be evaluated during the development phase. The testing serve as the validation cases once the behaviour of the functions have reached some satisfactory constraints.