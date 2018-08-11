/*
Jenny Bloom
10.9.2015
Homework 5
With help/brainstorming from: Collin Duncan, Darwin, and Jeff (in class)
https://en.wikipedia.org/wiki/Hamming_distance
http://stackoverflow.com/questions/557170/bit-operation-for-finding-string-difference

DESCRIPTION:
This program calculates hamming distance and similarity
scores for sample DNA sequences classed as human, mouse,
or unknown. Determine the unknown species based on it's
hamming distance and similarity scores.
*/

// Load necessary libraries.
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char*argv[]) // argv[] will call txt file(s) from the CLI
{
  // Set strings for DNA. Want in strings so length can be calculated.
  string mouseDNA;
  string humanDNA;
  string unknownDNA;

  //Open, and close data files for reading and populate strings ->
  ifstream mouseFile(argv[1]);
  mouseFile >> mouseDNA;
  mouseFile.close();

  ifstream humanFile(argv[2]);
  humanFile >> humanDNA;
  humanFile.close();

  ifstream unknownFile(argv[3]);
  unknownFile >> unknownDNA;
  unknownFile.close();
  // <- Data from files is now stored within declared strings

  // Hamming Distance Huzzah. Counting character differences between two different
  //strings of same length. Must know length to determine Hamming Distance.
  int len_mouseDNA = mouseDNA.length(); //Length of mouse string
  int len_humanDNA = humanDNA.length(); //Length of human string
  int ham_mouseDNA = 0; // setting for iteration
  int ham_humanDNA = 0; // setting for iteration

  // Hamming Distance for mouse vs unkown:
  for (int i = 0; i < len_mouseDNA; i++) //iterating through whole DNA string
  {
    if (mouseDNA[i] != unknownDNA[i]) // if not equal, add to Hamming Distance
      ham_mouseDNA++;
  }

  // Hamming Distance for human vs unknown:
  for (int i = 0; i < len_humanDNA; i++) //iterating through whole DNA string
  {
    if (humanDNA[i] != unknownDNA[i]) // if not equal, add to Hamming Distance
      ham_humanDNA++;
  }

  // Similarity score, if the difference < 0.0001
  // Similarity between known and unknown DNA.
  double tolerance = 0.0001; //set tolerance
  double sim_mouseDNA = double(len_mouseDNA - ham_mouseDNA)/len_mouseDNA;
  double sim_humanDNA = double(len_humanDNA - ham_humanDNA)/len_humanDNA;
  // <- similarity algorithms incorporating hamming distance to determine unknowns.

  string result;   // Set result string to hold output in memory
  // String Comparison for User Output, incorporating tolerance.
  if (double(sim_mouseDNA) > double(sim_humanDNA))
  {
    if (double(sim_mouseDNA) > tolerance)
    {
      result = "Mouse";
    }
  }
  else if (double(sim_humanDNA) > double(sim_mouseDNA))
  {
    if (double(sim_humanDNA) > tolerance)
    {
     result = "Human";
    }
  }
  else
    result = "Identity could not be determined.";

  // Display results to user.
  cout << "MouseCompare: " << sim_mouseDNA << "\n"; //using "\n" vs endl
  cout << "HumanCompare: " << sim_humanDNA << "\n";
  cout << result << "\n";

return 0;  //fin.
}
