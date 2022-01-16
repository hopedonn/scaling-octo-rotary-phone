 #include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>

 //Checks if the user entered valid arguments
//Param argc, amount of arguments
//Param argv the arguments passed
 int errorCheck(int argc, char** argv);




//Prints the whole map in proper formatting for project
// param: map<string, vector<string>>, map for printing
 void printMapVector( std::map<std::string, std::vector<std::string>> words);

//Printgs a singple pair from a map
//Param: std::map<std::string, std::vector<std::string>>::iterator the location of the pair to print
 void printsingleVector(std::map<std::string, std::vector<std::string>>::iterator it);


//Prints the whole map in proper formatting for project in reverse
// param: map<string, vector<string>>, map for printing
void printMapVectorRev(std::map<std::string, std::vector<std::string>> words);

//Prints all locations where the size of vector is equal to paramater a.
//Param: map<string, vector<string>> map to check
//Param: long unsigned a, check size comapred to
void printMapVectorCount(std::map<std::string, std::vector<std::string>> words, long unsigned a);


//Goes through a string and checks if the string represents a integer
//Param string input, the string being checked
bool isdigits(std::string input);

//Checks how many vectors in the map contain a size that paramater a is looking for
//Param: map<string, vector<string>> map to check
//Param: long unsigned a, check size comapred to
int printMapVectorCounts(std::map<std::string, std::vector<std::string>> words, long unsigned a);


//Checks what pair within a map contains the largest vector size for its value
//Param: map<string, vector<string>> map to check
int highestVector(std::map<std::string, std::vector<std::string>> words);