#!/bin/bash

# Basic input check
if [ $# -ne 2 ]; then
    echo "Usage: $0 <RoundName> <DivNumber>"
    echo "Example: $0 123 3"
    exit 1
fi

round="$1"
div="$2"

# Division validation
if [ "$div" -eq 1 ]; then
    echo "First become Candidate Master to attempt Div 1 contests..!"
    exit 1
fi
if ! [[ "$div" =~ ^[2-4]$ ]]; then
    echo "Division must be 2, 3, or 4."
    exit 1
fi

# Fixed base path
base_dir="$HOME/Desktop/ProCoding/CFContests"

# Create contest folder inside base_dir
folder_name="$base_dir/CFR${round}_DIV${div}"
mkdir -p "$folder_name"

# Template file path
template="$base_dir/template.cpp"
if [ ! -f "$template" ]; then
    echo "Error: $template not found at $base_dir"
    exit 2
fi

# Letters based on division
case "$div" in
    2) letters=(A B C D);;
    3) letters=(A B C D E F);;
    4) letters=(A B C D E F G);;
esac

cp "$template" "$folder_name/template.cpp"

# Copy template to all problem files
for l in "${letters[@]}"; do
    cp "$template" "$folder_name/$l.cpp"
done

echo "✅ Folder '$folder_name' created with files: ${letters[*]}.cpp"

# Open folder in VS Code
if command -v code &> /dev/null; then
    code "$folder_name"
fi

