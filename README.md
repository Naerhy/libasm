# libasm

Introduction to assembly language.

## Description

The goal of the project is to rewrite several libc functions in assembly language and build a static library from them. This allows you to discover the basic elements of the language and learn more about the inner workings of a CPU.

Some constraints are imposed by the subject:
- x86-64 architecture
- Intel syntax
- compilation with NASM
- prohibition to use the `-no-pie` compilation flag

Even though the mandatory part of the project is sufficient to learn the basics of assembly language, implementing the bonus functions is much more complex and requires careful management of registers usage.

A test program is included in order to check that all the functions are working as expected.

## Usage

```
# build the static library
make

# run tests
make test
```
