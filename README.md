# Lightning fast boolean matrix

An extremely fast implementation of 8x8 boolean bit matrices for x86_64

This is for a very specific purpose. Specifically, it can
* rotate an 8x8 boolean matrix in *one* x86_64 operation
* compare two 8x8 boolean matrices in *one* x86_64 operation

Parts of the header file are [generated](https://github.com/wulkanat/lightning-bool-matrix-gen)

## Matrix layout

The matrix is saved in a single 64 bit variable. The positions are laid out
to follow these four quadrants
```
\/ \/ \/ \/ \/ \/ \/ <
 > \/ \/ \/ \/ \/ <  <
 >  > \/ \/ \/ <  <  <
 >  >  > \/ <  <  <  <
 >  >  >  > /\ <  <  <
 >  >  > /\ /\ /\ <  <
 >  > /\ /\ /\ /\ /\ <
 > /\ /\ /\ /\ /\ /\ /\
```
The individual positions within a quadrant are arbitrary, as long as subtracting
a 90° rotated matrix of the positions by the matrix of the positions
equals 16 on every position.

In this implementation, we have chosen this layout
```
00 01 02 03 04 05 06 16
54 07 08 09 10 11 23 17
53 59 12 13 14 28 24 18
52 58 62 15 31 29 25 19
51 57 61 63 47 30 26 20
50 56 60 46 45 44 27 21
49 55 43 42 41 40 39 22
48 38 37 36 35 34 33 32
```
Where every number corresponds to the position of a boolean in the 
bitstream.

## Rotations

Because of how the matrix is saved, rotation can be done by rotating the bits
by a multiple of 16 left or right. x86_64 provides the `rorq` and `rolq` instructions
to do this in hardware.

## Comparisons

Comparing two full matrices is trivially done with `==` as each is saved as a single continuous
64 bit int.

## Getting/Setting booleans

