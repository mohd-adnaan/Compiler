# Go Language Compiler

This project is a simple compiler for a subset of the Go programming language, designed to perform lexical analysis and parsing on Go source code. The project utilizes `flex` for lexical analysis and `bison` for parsing, allowing the compiler to recognize tokens, parse expressions, and execute basic syntax checking on the Go code provided as input.

## Features
- **Lexical Analysis**: Recognizes tokens like keywords, identifiers, numbers, operators, and symbols.
- **Syntax Parsing**: Parses statements, expressions, and functions.
- **Error Handling**: Basic syntax error reporting with line number indication.
- **Loop Detection**: Detects and processes simple `for` loops, `if` statements, and variable declarations.
- **Arithmetic Expressions**: Supports basic arithmetic operations.
  
## Files
- **`lexer.l`**: Contains rules for tokenizing the input source code. Written using `flex`.
- **`parser.y`**: Contains grammar rules for parsing the Go language subset. Written using `bison`.
- **`main.c`**: Entry point of the compiler. Coordinates the process between the lexical analyzer and parser.
- **`example.go`**: Sample Go code to be used as input to test the compiler.

## Installation
Ensure that `flex` and `bison` are installed on your system. Compile the code using the following steps:

1. Run `flex` to generate the lexical analyzer:
    ```bash
    flex lexer.l
    ```

2. Run `bison` to generate the parser with debug information:
    ```bash
    bison -d parser.y
    ```

3. Compile the generated files and main program with `gcc`:
    ```bash
    gcc -o my_parser main.c lex.yy.c parser.tab.c -ll
    ```

## Usage
To use the compiler, run it with an input Go file:

```bash
./my_parser < example.go
```

This command will start parsing the input and display each token found along with syntax error information (if any).

## Sample Output
Example output when parsing `example.go`:
```text
Starting parsing...
ID token found: package
ID token found: main
...
Syntax error at line 22: syntax error
PARSING FINISHED SUCCESSFULLY.
```

## Notes
- The project currently has `shift/reduce` conflicts in `parser.y`. These conflicts occur due to grammar ambiguities and may lead to parsing errors.
- Further refinement of the grammar rules in `parser.y` can help reduce conflicts and improve parsing accuracy.

