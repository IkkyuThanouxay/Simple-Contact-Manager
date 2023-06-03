# Simple Contact Manager

The Simple Contact Manager is a C-based application which allows the user to input contact details such as names and phone numbers. This program manages this information by dynamically allocating and freeing memory as needed.

## How It Works

- The user specifies the number of contacts they wish to store.
- The program will prompt the user to input the name and phone number for the number of contacts specified.
- The entered contacts are then stored in an array.
- The program will then display all the contacts entered by the user.
- After displaying the contacts, the program will free up the memory allocated for the contacts to avoid any memory leaks.

## Usage

The program is contained in a single file called `main.c`. You can compile and run it using the following steps:

```bash
# Open a terminal
# Navigate to the directory containing the `main.c` file.
# Compile the C program using the gcc compiler:
gcc -o SimpleContactManager main.c

# Run the compiled program:
./SimpleContactManager

# When prompted, enter the number of contacts you wish to add.
# Enter the name and phone number of each contact as prompted.
# The program will then display all the entered contacts.
```
## Code Structure
- The program utilizes a structure "Contact_Data" to hold the contact details (name and phone number).
- Memory for these structures is dynamically allocated and resized as needed using malloc, calloc, and realloc functions.
- After the contacts are displayed, the memory allocated is freed up using the free function to prevent memory leaks.
# Note: Please ensure your system has the gcc compiler installed before attempting to compile the program. If not, you may need to install it or use another compatible C compiler.
