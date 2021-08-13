# Custom_Doxygen_Documentation
Create a Doxygen documentation page from a standard C++ Code file

# DEPRECATED !
The proper way to do this was found in the mean time, which will be added here soon (however, that's not on my priority list, sorry). If you need it right away, send me a message or create an Issue.
# !

## New steps
1. add Doxgyen code block to the CMakeList.txt
2.  e.g. exclude directories
3. add file extensions
4. "cmake ."
5. "make doc ."
6. enjoy as "index.html"
7. add Doxgygen to eclipse
8. add LaTeXMacros if needed

The design of the documentation is inspired by the deal.ii tutorial programs. Because I was not able to figure out how one can configure Doxygen such that it exactly creates  what is shown in this documentation, I created this quick and dirty script to do this for me the old-school way.

## Requirements
- Python3 (not tested for Python2)
- Doxygen

## How to create a custom documentation
1. Download the entire repository
2. Replace the file "example_code_to_be_documented.cc" with your C++ code (currently only a single C++ file is supported) named e.g. your_code.cc
3. Go the file "/docs/mainpage-framework.h"
4. Add there e.g. the introductory text in standard Doxygen syntax
5. Insert the name of your C++ code file in between the \code ... \endcode section

@note You can incorporate normal code snippets with @code ... @endcode, but do not use \code ... \endcode for these

With the above filename it should look like this:

\code

your_code.cc

\endcode

6. Run the script "make_documentation.asc". This will merge your code into the mainpage, run Doxygen over it and open the created documentation in the web browser. To run the .asc file you might have to call

chmod 755 make_documentation.asc # this enables the file to run in the terminal as a shell code

7. To host the documentation on a GitHub page you can follow this straightforward guide https://goseeky.wordpress.com/2017/07/22/documentation-101-doxygen-with-github-pages/, where the new index.html file has already been created and properly placed for you in the docs folder.

## Formalism
- use "//..." instead of "// ..." when you don't want the comment to be transformed to normal text, but keep it as a C++ comment


## ToDo
- Try to incorporate more than one C++ file
- Find out how this can directly be done with Doxygen and with an entire collection of files
- using "// @note ..." requires an empty line after the comment ended, maybe we can avoid this or e.g. use "//@note ..." when we do not want this behaviour. The blank could decide whether the following line e.g. another comment shall belong to this @note or @todo, or whether that is something unrelated.
- complement the Formalism (and change its heading)

## BUGS
- For a code line "										* JxW;" the multiplication operator "*" is not printed, e.g. in SRI.
