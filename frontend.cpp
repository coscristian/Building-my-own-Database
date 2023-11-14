#include<iostream> // Input - Output
#include <cstdlib> // Memory management
#include <string> // String management
#include <sys/types.h> // size_t

using namespace std;

// Buffer management
typedef struct {
    string buffer;
    size_t buffer_length;
    size_t input_length;
} InputBuffer;

// Creates and initializes a input buffer
InputBuffer* new_input_buffer() {
    InputBuffer* input_buffer = (InputBuffer*)malloc(sizeof(InputBuffer));
    //input_buffer->buffer = "a";
    input_buffer->buffer_length = 0;
    input_buffer->input_length = 0;

    return input_buffer;
}

void print_prompt() {
    printf("db > ");
}

void read_input(InputBuffer* input_buffer) {
    //    ssize_t bytes_read =
    //        getline(cin, &(input_buffer->buffer), &(input_buffer->buffer_length));
    string line;
    getline(cin, line);

    input_buffer->buffer = line;
    input_buffer->input_length = line.size();

    if (input_buffer->input_length <= 0) {
        //printf("Error reading input\n");
        cout << "Error reading ";
        exit(EXIT_FAILURE);
    }
    // Ignore trailing newline
    input_buffer->input_length = input_buffer->input_length - 1;
    input_buffer->buffer[input_buffer->input_length - 1] = 0;
}

int main() {
    InputBuffer* input_buffer = new_input_buffer();

    while (true) {
        print_prompt();
        read_input(input_buffer);

        if (input_buffer->buffer == ".exit\n") {
            free(input_buffer);
            exit(EXIT_SUCCESS);
        }
        else {
            cout << "Unrecognized\n";
        }
    }



    return 0;
}
