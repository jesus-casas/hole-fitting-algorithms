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
    void free_memory();

    // Enter parameters function
    void enter_parameters() {
        printf("Enter size of physical memory: ");
        scanf("%d", &physical_memory_size);
    }

    // Allocate memory function
    void allocate_memory_first_fit() {
        int id, size;

        printf("Enter block id: ");
        scanf("%d", &id);
        printf("Enter block size: ");
        scanf("%d", &size);

        // Check for invalid input
        if (id < 0 || size <= 0) {
        printf("Error: Block ID and size must be positive.\n");
        return;
        }

        // Check for duplicate IDs
        memory_block *current = head;
        while (current != NULL) {
            if (current->block_id == id) {
                printf("Error: Block ID already exists.\n");
                return;
            }
            current = current->next;
        }

    int start = 0;
    if (head == NULL) {
        if (size <= physical_memory_size) {
            start = 0; // Start at the beginning if the list is empty and there's enough space
        }
    } else {
        memory_block *prev = NULL;
        current = head;
        while (current != NULL) {
            if (prev == NULL) { // Check space before the first block
                if (current->start_address >= size) {
                    start = 0;
                    break;
                }
            } else { // Check space between blocks
                int gap = current->start_address - prev->end_address;
                if (gap >= size) {
                    start = prev->end_address;
                    break;
                }
            }
            prev = current;
            current = current->next;
        }
        if (current == NULL && (physical_memory_size - (prev ? prev->end_address : 0) >= size)) {
            start = prev ? prev->end_address : 0; // Check space at the end
        }
    }

        if (start + size > physical_memory_size) {
            printf("Error: No suitable block found.\n");
            return;
        }

        memory_block *new_block = (memory_block *)malloc(sizeof(memory_block));
        new_block->block_id = id;
        new_block->start_address = start;
        new_block->end_address = start + size;
        new_block->next = NULL;

    if (head == NULL || head->start_address > start) {
        new_block->next = head;
        head = new_block;
    } else {
        memory_block *current = head;
        memory_block *prev = NULL;
        while (current != NULL && current->start_address < start) {
            prev = current;
            current = current->next;
        }
        new_block->next = current;
        if (prev != NULL) {
            prev->next = new_block;
        }
    }
}

    // Allocate memory function
void allocate_memory_best_fit() {
    int id, size;

    printf("Enter block id: ");
    scanf("%d", &id);
    printf("Enter block size: ");
    scanf("%d", &size);

    // Check for invalid input
    if (id < 0 || size <= 0) {
        printf("Error: Block ID and size must be positive.\n");
        return;
    }

    // Check for duplicate IDs
    memory_block *current = head;
    while (current != NULL) {
        if (current->block_id == id) {
            printf("Error: Block ID already exists.\n");
            return;
        }
        current = current->next;
    }

    int best_start = -1;
    int min_gap = physical_memory_size + 1; // Initialize with max possible size
    int start = 0;

    memory_block *prev = NULL;
    current = head;
    while (current != NULL) {
        int gap = (prev == NULL ? current->start_address : current->start_address - prev->end_address);
        if (gap >= size && gap < min_gap) {
            best_start = (prev == NULL ? 0 : prev->end_address);
            min_gap = gap;
        }
        prev = current;
        current = current->next;
    }
    // Check the gap between last block and the end of the physical memory
    if (prev != NULL && (physical_memory_size - prev->end_address >= size) && (physical_memory_size - prev->end_address < min_gap)) {
        best_start = prev->end_address;
        min_gap = physical_memory_size - prev->end_address;
    }

    if (best_start == -1) {
        printf("Error: No suitable block found.\n");
        return;
    }

    memory_block *new_block = (memory_block *)malloc(sizeof(memory_block));
    if (new_block == NULL) {
        printf("Error: Memory allocation failed.\n");
        return;
    }
    new_block->block_id = id;
    new_block->block_size = size;
    new_block->start_address = best_start;
    new_block->end_address = best_start + size;
    new_block->next = NULL;

    if (head == NULL || head->start_address > best_start) {
        new_block->next = head;
        head = new_block;
    } else {
        prev = NULL;
        current = head;
        while (current != NULL && current->start_address < best_start) {
            prev = current;
            current = current->next;
        }
        new_block->next = current;
        if (prev != NULL) {
            prev->next = new_block;
        }
    }
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
        printf("\n");
        printf("ID\tStart\tEnd \n");
        printf("-------------------\n");
        while (current != NULL) {
            printf("%d\t%d\t%d\n", current->block_id, current->start_address, current->end_address);
            current = current->next;
        }
    }

    // Free all memory function
    void free_memory() {
        memory_block *current = head;
        while (current != NULL) {
            memory_block *temp = current;
            current = current->next;
            free(temp); // Free each memory block
        }
        head = NULL; // Reset the head to NULL after freeing all blocks
        printf("Memory freed.\n");
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