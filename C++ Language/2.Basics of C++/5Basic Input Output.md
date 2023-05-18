# Basic Input/Output

## Stream

An entity where a program can either insert or extract characters to/from sequentially.

| Stream | Description                     |
| ------ | ------------------------------- |
| cin    | standard input stream           |
| cout   | standard output stream          |
| cerr   | standard error(output) stream   |
| clog   | standard logging(output) stream |

## Standard Output(cout)

In most program environments, the standard output by default is screen.

"endl" or "\n" : newline character

## Standard Input(cin)

In most program environment, the standard input by default is keyboard.

## cin and strings

"cin" extraction always considers space(whitespaces, tabs, new-line...) as terminating the value being extracted.

"getline": To get an entire line from "cin"(Always use "getline" instead of "cin").

```c++
getline(cin, mystr);
```

## stringstream

Standard header <sstream>: Called stringstream which allows a string to be treated as a stream. Most useful to convert strings to numerical value and vice versa.

```c++
#include <sstream>

getline(cin, mystr);
stringstream(mystr) >> myint;
```

