#include <stdio.h>
#include <stdlib.h>

    // Define structure for memory block
    struct memory_block {
        int block_id;
        int block_size;
        int start_address;
        int end_address;
        int is_allocated;
        struct memory_block *next;
    } memory_block;

    // Declare global variables
    int physical_memory_size;
    

    // Function declarations
    void enter_parameters();
    void allocate_memory(int);
    void deallocate_memory();
    void defragment_memory();
    void print_blocks();
    void free_all_memory();

    // Enter parameters function
    void enter_parameters() {
    printf("Enter size of physical memory: ");
    scanf("%d", &physical_memory_size);
}

int main() {
    int choice;
    
    while (1)
    {
        printf("\nHole-fitting Algorithms\n");
        printf("-----------------------\n");
        printf("1) Enter parameters\n");
        printf("2) Allocate memory for block using First-fit\n");
        printf("3) Allocate memory for block using Best-fit\n");
        printf("4) Deallocate memory for block\n");
        printf("5) Defragment memory\n");
        printf("6) Quit program\n");
        printf("\nEnter selection: ");
        // Ask user for input
        scanf("%d", &choice);

        // Add switch case to handle user input
        switch (choice) {
            case 1:
                enter_parameters();
                break;
            case 2:
                allocate_memory(1); // First-fit
                break;
            case 3:
                allocate_memory(2); // Best-fit
                break;
            case 4:
                deallocate_memory();
                break;
            case 5:
                defragment_memory();
                break;
            case 6:
                printf("Quitting program...\n");
                // Implement free all memory blocks

                return 0;
            default:
                printf("Invalid choice. Please enter a number between 1 and 6.\n");
        }
        // Print blocks after each operation
    print_blocks();
    } // end while loop
    
    return 0;
}