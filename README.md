# hole-fitting-algorithms
## Objective:
To simulate memory allocation with hole-fitting algorithms (First-fit, Best-fit) and implement deallocation and defragmentation of memory blocks.


## Specification:
The program simulates memory allocation with a chosen hole-fitting algorithm (First-fit, Best-fit) and implements deallocation and defragmentation. A menu controls the operations, and each choice calls the appropriate procedure, where the choices are: 
Enter parameters 
Allocate memory for a block using First-Fit
Allocate memory for a block using Best-Fit
Deallocate memory for a block
Defragment memory
Quit program and free memory


## Assignment:
The size of physical memory is represented by an integer pm_size.
The allocated blocks are contained within a linked list, where each allocated block is a structure containing: (1) the id, (2) the starting address of the block, (3) the ending address of the block, and (4) a link to the next allocated block.
Each allocation request prompts for: (1) the block id and (2) the size of the new block. If the id is a duplicate and/or the remaining physical memory is not enough to fit the request, the request is rejected, and an appropriate message is displayed.
Each deallocation request prompts for the block id. If the block id is invalid, the request is rejected.
Defragmentation compacts the blocks to be contiguous, and coalesces the holes into one hole at the far--right end (highest memory addresses) of physical memory.

## How to run


## Test input 
1
1024

2
0
128

3
1
320

2
2
224

3
3
288

4
2

2
4
128

4
1

3
5
64

5

6

