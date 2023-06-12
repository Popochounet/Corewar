# Corewar
[Epitech] Corewar

*War inside Memory*

## WHAT IS IT ?

Corewar is a war simulator between champions, inside a representation of memory.

There can be 2 or more champions fighting.

Each champion must say "I'm Alive" before its "Cycle before die" drop to 0, else it dies.

Each champion has one or more processes that excecute instructions stored in the memory (*see below*).

## HOW TO RUN
Clone the repository
There are multiple binaries, the most interesting one is the visualizer one :

```cd bonus/corewar_visualizer```

Then, make the binary:

```make```

Then, you can lauch the programm, choosing what champion you want to see compete.

Select the available champions in the bonus/champions folder.

Here's an example:

```./corewar ../champions/popo.cor ../champions/42.cor```

Now, you can try different combinations ! Remember that there is no limit for the number of champions selected 👍

## THE INSTRUCTIONS (*simplified*)

Each instruction has its own execution time (*800 cycles for fork, 10 for live*)

0x01 (live) It indicates that the player is alive.

0x02 (ld)   It loads the value of the first parameter into the second parameter.

0x03 (st)   It stores the first parameter’s value into the second.

0x04 (add)  It adds the content of the first two and puts the sum into the third one.

0x05 (sub)  Similar to add, but performing a subtraction.

0x06 (and)  It performs a binary AND between the first two parameters and stores the result into the third one.

0x07 (or)   Similar to and, but performing a binary OR.

0x08 (xor)  Similar to and, but performing a binary XOR (exclusive OR).

0x09 (zjmp) It jumps to this index.

0x0a (ldi) Similar to ld, but take an index as parameter.

0x0b (sti) Similar to st, but take an index as parameter.

0x0c (fork) It creates a new program that inherits different states from the parent.

0x0d (lld) Similar to ld, but the value can be anywhere in the memory.

0x0e (lldi) Similar to ldi, but the value can be anywhere in the memory.

0x0f (lfork) Similar to fork, but the new programm can start anywhere in the memory.

0x10 (aff) It displays on the standard output the character whose ASCII code is the parameter (in base 10). A 256 modulo is applied to this ASCII code.
