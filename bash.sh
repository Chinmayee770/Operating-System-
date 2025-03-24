#!/bin/bash

# Check if command-line arguments are provided
if [ $# -eq 0 ]; then
    echo "Usage: $0 <name>"
    exit 1
fi

# Retrieve command-line argument
name=$1

# Function to greet the user
greet() {
    echo "Hello, $1!"
}

# Main function
main() {
    echo "Welcome to Greeting Script"
    echo "Please enter your age:"
    read -p "Age: " age

    echo "Hello, $name! You are $age years old."
}

# Call main function
main