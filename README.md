# DNAComparison
This program calculates Hamming distance and similarity scores for sample DNA sequences from a human, a mouse, and an unknown species to determine the identity of the unknown species.

This was a great intro CPP project because it built on prior Python projects within the course, and it enabled the ability to whet the biometrics appetite! 

## Project Focus:
This program built proficiency in:
* Read in command-line arguments
* Read in data from files
* Loop through strings

## Running the Program:
The program takes three command-line arguments, in the following order: mouseDNA_filename humanDNA_filename unknownDNA_filename

For example, from terminal:

```console
🐅 Active Line: g++ DNA.cpp
🐅 Active Line: ./a.out mouseDNA1.txt humanDNA1.txt unknownDNA1.txt 
```
Expected output should be something like this:

```console
MouseCompare: 0.958333
HumanCompare: 0.833333
Mouse
```

## Additional Details:
For further reading, please check out the [source document.](https://github.com/JennyBloom/DNAComparison/blob/master/HW5-CppDNA.pdf)
