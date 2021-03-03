# 1. goldbach: Goldbach's weak conjecture (22 points)
Goldbach's conjecture is a famous unsolved problem in mathematics. It states that every even number greater than two is the sum of two prime numbers. While the statement has been shown to be true for quintillions of even numbers, mathematicians have not yet devised a rigorous proof of the statement.

In this part of the assignment you will write a C program that demonstrates the related Goldbach's weak conjecture, which states that every odd number greater than 5 is the sum of three primes. This weaker claim is implied by the more famous Goldbach's conjecture, and this weaker claim has potentially been proven by mathematicians.

Your task is to write a C program called goldbach which will take an odd number greater than 5 as a command line argument:

```./goldbach 7```

Your program should then output to the command line a valid equation showing that the given number is the sum of three primes:

```7 = 2 + 2 + 3```

You will receive 5 points for a program that compiles, incremental points for passing a few test cases, and full marks if your program successfully passes 100 randomized inputs.
