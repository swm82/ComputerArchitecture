# You may have noticed that your favorite text editor or integrated development environment (IDE) can help you check if open parentheses, brackets, and braces are properly closed. That is, whether each open '<', '(', '[', and '{' is properly closed with a corresponding '>', ')', ']', and '}' without any intervening open parentheses, brackets, or braces.

For example, these are balanced expressions:
```
<({})>

({<>(){}})
```

But these are not:
```
({)

<<>[<()>]
```

Your task in this part of the assignment is to write a C program using structs and pointers to build a stack data structure, and use that stack to check whether a string is properly balanced. Your program should take as a command line input the path to an input file:

```./balanced tests/test0.txt```

Your program should check whether the expression in the input file is balanced, and then print to the command line "yes" if the expression is balanced, and "no" if it is not.

The corresponding expected outputs are in the answers directory: answers/answer0.txt.
