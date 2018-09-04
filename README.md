# Push_swap

This project for sorting numbers using `Quick sort algorithm`([Wikipedia link](https://en.wikipedia.org/wiki/Quicksort)) for 2 stacks with my own improvements

This project is about sorting numbers considering two stacks and using only the following instructions:

* `sa` : swap a - swap the first 2 elements at the top of stack a . Do nothing if there is only one or no elements).
* `sb` : swap b - swap the first 2 elements at the top of stack b . Do nothing if there is only one or no elements).
* `ss` : sa and sb at the same time.
* `pa` : push a - take the first element at the top of b and put it at the top of a . Do nothing if b is empty.
* `pb` : push b - take the first element at the top of a and put it at the top of b . Do nothing if a is empty.
* `ra` : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.
* `rb` : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
* `rr` : ra and rb at the same time.
* `rra` : reverse rotate a - shift down all elements of stack a by 1. The flast element becomes the first one.
* `rrb` : reverse rotate b - shift down all elements of stack b by 1. The flast element becomes the first one.
* `rrr` : rra and rrb at the same time

## Compile

`> make all`

## Usage

`push_swap` program for generate instruction set, `checker` program for check and test instruction set

To generate the set of instructions for a set of numbers:

`> ./push_swap n1 n2 n3 n4 n5 n6 ...`

and to check wether the set of instructions really sorts:

`> ./push_swap n1 n2 n3... | ./checker n1 n2 n3 ...`
