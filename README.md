# Push Swap

Push Swap is a sorting project from the 42 curriculum. It sorts integers using
two stacks and a limited instruction set while aiming to minimize the number of
operations. The program prints the generated instructions to standard output.

## Build

```bash
make
```

This builds `push_swap` together with the local Libft and ft_printf dependencies.

## Usage

```bash
./push_swap 2 1 3 6 5 8
./push_swap "2 1 3 6 5 8"
```

Arguments may be passed separately or as one quoted string. Values must be
unique integers within the signed 32-bit range. Invalid input prints `Error` to
standard error; already sorted input produces no instructions.

## Instructions

The generated sequence uses the standard Push Swap operations: `sa`, `sb`,
`ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, and `rrr`.

Small stacks are handled with dedicated routines. Larger inputs are divided
into groups, transferred to stack B, and moved back to stack A in sorted order.

## Cleaning

```bash
make clean
make fclean
make re
```
