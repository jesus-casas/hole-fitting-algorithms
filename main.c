#include <stdio.h>
#include <stdlib.h>

    // Define structure for memory block
    typedef struct memory_block {
        int block_id;
        int block_size;
        int start_address;
        int end_address;
        int is_allocated;
        struct memory_block *next;
    } memory_block;

    // Declare global variables
    int physical_memory_size;
    memory_block *head = NULL;

    // Function declarations
    void enter_parameters();
    void allocate_memory_first_fit();
    void allocate_memory_best_fit();
    void deallocate_memory();
    void defragment_memory();
    void print_blocks();
    void free_all_memory();

    // Enter parameters function
    void enter_parameters() {
        printf("Enter size of physical memory: ");
        scanf("%d", &physical_memory_size);
    }

    // Allocate memory function
    void allocate_memory_first_fit() {

    }

    // Allocate memory function
    void allocate_memory_best_fit() {

    }

    // Deallocate memory function
    void deallocate_memory() {

    }

    // Defragment memory function
    void defragment_memory() {

    }

    // Print blocks function
    void print_blocks() {
        memory_block *current = head;
        printf("ID     \tStart Address\tEnd Address\n");
        printf("--------------------------------------\n");
        while (current != NULL) {
            printf("%d\t%d\t%d\n", current->block_id, current->start_address, current->end_address);
            current = current->next;
        }
    }

    // Free all memory function
    void free_memory() {
        // Implement free all memory blocks

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
                allocate_memory_first_fit(); // First-fit
                print_blocks();
                break;
            case 3:
                allocate_memory_best_fit(); // Best-fit
                print_blocks();
                break;
            case 4:
                deallocate_memory();
                print_blocks();
                break;
            case 5:
                defragment_memory();
                print_blocks();
                break;
            case 6:
                free_memory();
                printf("Quitting program...\n");
                return 0;
            default:
                printf("Invalid choice. Please enter a number between 1 and 6.\n");
        } // end switch case
    } // end while loop

    return 0;
}