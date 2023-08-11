#!/bin/bash
echo '#include <stdio.h>' > output.c && echo 'int main() { printf("with proper grammar, but the outcome is a piece of art,\\n"); return 0; }' >> output.c && gcc -Wall output.c -o output && ./output
