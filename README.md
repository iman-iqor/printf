📌 Project Overview

The Printf project is designed to implement a simplified version of the printf function in C. The goal is to understand variadic functions, the usage of va_list, and the management of formatting options in string printing.

🖥️ Technologies Used

    Language: C
    System Calls: write
    Libraries: stdarg.h

📋 Project Requirements

    Implement the function ft_printf, which behaves like the standard printf.
    Handle different data types, including integers, strings, characters, and pointers.
    Support common format specifiers: %d, %i, %c, %s, %p, %u, %x, and %%.
    Handle optional flags such as width, precision, and alignment.
    Return the number of characters printed.

🔧 Key Features

1️⃣ Variadic Arguments
The function handles a variable number of arguments using va_list, va_start, and va_arg.

2️⃣ Format Specifiers
Supports different specifiers like integers (%d, %i), characters (%c), strings (%s), unsigned integers (%u), hexadecimal (%x), pointers (%p), and literal percent signs (%%).

3️⃣ Handling Flags
Supports width, precision, and alignment flags to properly format the output.

4️⃣ Efficient Output
Uses write() system call to directly print to the standard output.

5️⃣ Memory Management
No dynamic memory is allocated for the format string or arguments, ensuring no memory leaks.

🏁 How to Use

Include the header file in your project:
#include "ft_printf.h"
Call ft_printf to print formatted output:
int count = ft_printf("Hello, %s! You are %d years old.", "Alice", 25);
printf("Printed %d characters.", count);
Supported Specifiers:

    %c - Print a character.
    %s - Print a string.
    %d, %i - Print an integer.
    %u - Print an unsigned integer.
    %x - Print a hexadecimal number.
    %p - Print a pointer.
    %% - Print a literal percent sign.

📜 Final Notes

    printf is one of the most commonly used functions in C, and this project helps you build a solid understanding of string formatting, memory management, and variadic functions.
    Efficient implementation is key, so avoid unnecessary memory allocations and ensure all formatting options are properly handled.
    Focus on understanding how to process different argument types and manage format flags effectively.

🔹 This project is a great way to dive deep into C's type handling and variadic functions! 🚀
