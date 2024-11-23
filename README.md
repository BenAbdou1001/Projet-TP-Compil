# Compiler Project

This is a university project focused on building a simple compiler. The main components of the project include:

- **Lexical Analysis**: Uses Flex (`lexical.l`) to generate a lexical analyzer that tokenizes the input source code.
- **Syntax Analysis**: Utilizes Bison (`syntaxique.y`) to define grammar rules for the language.
- **Symbol Table Management**: Stores and manages symbols, identifiers, and keywords found during compilation.
- **Intermediate Code Generation**: Creates quadruples to represent intermediate instructions.

## Getting Started

### Prerequisites

To compile and run the project, make sure you have the following tools installed:

- **Flex**: A tool for generating lexical analyzers.
- **Bison**: A parser generator that produces a C program.
- **GCC**: The GNU Compiler Collection for compiling the C code.

### Files

- `lexical.l`: Contains the rules for lexical analysis.
- `syntaxique.y`: Defines the grammar for syntax analysis.
- `ts.h`: Contains functions for managing the symbol table.
- `quad.h`: Manages the generation and handling of quadruples.

### How to Execute

1. Create a `commande.bat` file with the following content:

    ```batch
    flex lexical.l
    bison -d syntaxique.y
    gcc lex.yy.c syntaxique.tab.c -o projet.exe -lfl -ly
    projet.exe EXAMPLE.txt < EXAMPLE.txt
    ```

2. Run the `commande.bat` file to compile and execute the project. This will:

   - Generate the lexer from `lexical.l`.
   - Generate the parser from `syntaxique.y`.
   - Compile the generated C files using `gcc`.
   - Run the compiled executable `projet.exe` with `EXAMPLE.txt` as the input.

### Example Usage

To test the compiler, include your source code in `EXAMPLE.txt`. The output will display the results of the lexical and syntax analysis, along with any intermediate code (quadruples) generated.

## Project Structure

- **Lexical Analyzer**: Tokenizes the input and handles keywords, identifiers, literals, etc.
- **Parser**: Analyzes the syntax structure according to the grammar rules.
- **Symbol Table**: Keeps track of all identifiers and their attributes.
- **Quadruples**: Represents the intermediate code for further compilation phases.

## License

This project is for educational purposes only and follows the guidelines set by the university.
