#include <stdio.h>
#include <stdlib.h>


// maxiumum number of pieces 
#define MAX_PIECES 100  

// store the length and value of the peice
typedef struct {
    int length;
    int value;
} Piece;

// Functions to read input, find the best piece to cut, and print out the result
void read_input(Piece *pieces, int *piece_count);
int find_best_piece(Piece *pieces, int piece_count, int remaining_length);
void print_results(Piece *pieces, int *piece_counts, int piece_count, int total_value, int remainder);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <rod length>\n", argv[0]);
        return 1;
    }

    // Parse the length of the rod 
    int rod_length = atoi(argv[1]);
    if (rod_length <= 0) {
        fprintf(stderr, "Invalid rod length. Must be a positive integer.\n");
        return 1;
    }


    // Read the list of pieces from standard input
    Piece pieces[MAX_PIECES];
    int piece_count = 0;
    read_input(pieces, &piece_count);

    // intialize the piece count and total value
    int piece_counts[MAX_PIECES] = {0};
    int total_value = 0;
    int remainder = rod_length;

    // find and cut the best piece 
    while (remainder > 0) {
        int best_piece_index = find_best_piece(pieces, piece_count, remainder);
        if (best_piece_index == -1) {
            break; // No more pieces can be cut
        }
        piece_counts[best_piece_index]++;
        remainder -= pieces[best_piece_index].length;
        total_value += pieces[best_piece_index].value;
    }

    // print out the result
    print_results(pieces, piece_counts, piece_count, total_value, remainder);

    return 0;
}

// Function to read input from stdin
void read_input(Piece *pieces, int *piece_count) {
    char line[256];
    while (fgets(line, sizeof(line), stdin) != NULL) {
        int length, value;
        if (sscanf(line, "%d, %d", &length, &value) == 2) {
            pieces[*piece_count].length = length;
            pieces[*piece_count].value = value;
            (*piece_count)++;
        } else {
            fprintf(stderr, "Invalid input format. Expected '<length>, <value>'.\n");
            exit(1);
        }
    }
}

// Function to find the best place to cut 

int find_best_piece(Piece *pieces, int piece_count, int remaining_length) {
    int best_index = -1;
    int best_value = 0;

    for (int i = 0; i < piece_count; i++) {
        if (pieces[i].length <= remaining_length && pieces[i].value > best_value) {
            best_value = pieces[i].value;
            best_index = i;
        }
    }

    return best_index;
}

// Function out the result 
void print_results(Piece *pieces, int *piece_counts, int piece_count, int total_value, int remainder) {
    for (int i = 0; i < piece_count; i++) {
        if (piece_counts[i] > 0) {
            printf("%d @ %d = %d\n", piece_counts[i], pieces[i].length, pieces[i].value * piece_counts[i]);
        }
    }
    printf("Remainder: %d\n", remainder);
    printf("Value: %d\n", total_value);
}