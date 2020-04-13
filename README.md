# Custom_Doxygen_Documentation
Create a Doxygen documentation page from a standard C++ Code file

## Requirements
- Python3 (not tested for Python2)
- Doxygen

## How to create a custom documentation
1. Download the entire repository
2. Replace the file "example_code_to_be_documented.cc" with your C++ code (currently only a single C++ file is supported) named e.g. your_code.cc
3. Go the file "/docs/mainpage-framework.h"
4. Add there e.g. the introductory text in standard Doxygen syntax
5. Insert the name of your C++ code file in between the \code ... \endcode section \n
@note You can incorporate normal code snippets with @code ... @endcode, but do not use \code ... \endcode for these
With the above filename it should look like this: \n
\code
your_code.cc
\endcode
6. Run the script "make_documentation.asc". This will merge your code into the mainpage, run Doxygen over it and open the created documentation in the web browser.



## ToDo
- Try to incorporate more than one C++ file