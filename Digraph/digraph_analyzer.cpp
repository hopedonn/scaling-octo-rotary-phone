#include "digraph_functions.h"
using std::cout;
using std::string;

int main(int argc, char **argv)
{

  if (int out = errorCheck(argc, argv))
  {
    return out;
  }

  std::map<std::string, std::vector<std::string>> words;
  //Intialzing starting variables
  string line;
  string digraph;
  int size = 0;
  std::ifstream myfile(argv[1]);
  std::vector<std::string> stringVect;

  if (myfile.is_open())
  {
    //Putting diagraphs into map
    myfile >> size;
    for (int i = 0; i < size; i++)
    {
      myfile >> line;
      words.emplace(line, std::vector<std::string>());
    }

    while (myfile >> line)
    {
      //Cleaning strings of data
      for (char c : line)
      {
        if (ispunct(c))
          line.erase(line.find_first_of(c));
      }

      for (char &c : line)
      {
        c = tolower(c);
      }
      //Puttnig all strings that are an actual diagraph into their relevant postions on the map
      std::map<std::string, std::vector<std::string>>::iterator ptr;
      for (ptr = words.begin(); ptr != words.end(); ptr++)
      {
        if (line.find(ptr->first) != std::string::npos)
        {
          ptr->second.push_back(line);
        }
      }
    }
    myfile.close();

    //Printing based on the requested orinetaiton
    if (*argv[2] == 'a')
    {
      printMapVector(words);
    }

    if (*argv[2] == 'r')
    {
      printMapVectorRev(words);
    }

    if (*argv[2] == 'c')
    {

      int highest = highestVector(words);

      while (highest > -1)
      {
        printMapVectorCount(words, highest--);
      }
    }
  }
  else
  {
    cout << "Unable to open file";
    return 0;
  }

  //getting inputs
  string input = "";

  //Constant input portion of code to read commands
  do
  {
    std::cout << "q?>";
    std::getline(std::cin, input);
    for (char &c : input)
    {
      c = tolower(c);
    }
    if (input.compare("exit") == 0)
    {
      return 0;
    }
    //Print specific pair of map
    if (words.count(input) >= 1)
    {
      std::map<string, std::vector<std::string>>::iterator it;
      it = words.find(input);
      printsingleVector(it);
      //Printing based on int issused by user
    }
    else if (isdigits(input))
    {
      int x = stoi(input);
      if (printMapVectorCounts(words, x) > 0)
      {
        printMapVectorCount(words, x);
      }
      else
      {
        cout << "None\n";
      }
    }
    else
    {
      cout << "No such digraph\n";
    }
  } while (input.compare("exit") != 0);
}

//Checks if the user entered valid arguments
//Param argc, amount of arguments
//Param argv the arguments passed
int errorCheck(int argc, char **argv)
{

  // if number of arguments is not correct, exit with code 1!
  if (argc != 3)
  {
    cout << "Invalid arguments\n";
    return 1;
  }

  // if the "order" argument is not valid, exit with code 1!
  string order(argv[2]);
  if (order != "r" && order != "a" && order != "c")
  {

    cout << "Invalid arguments\n";
    return 1;
  }

  return 0;
}

//Prints the whole map in proper formatting for project
// param: map<string, vector<string>>, map for printing
void printMapVector(std::map<std::string, std::vector<std::string>> words)
{

  for (std::pair<const std::string, std::vector<std::string>> &ptr : words)
  {

    std::cout << ptr.first << ": ";
    std::cout << '[';
    for (std::vector<std::string>::iterator i = ptr.second.begin(); i != ptr.second.end(); ++i)
    {
      if (std::next(i) != ptr.second.end())
      {
        std::cout << *i << ", ";
      }
      else
      {
        std::cout << *i;
      }
    }
    std::cout << ']';
    std::cout << std::endl;
  }
}

//Printgs a singple pair from a map
//Param: std::map<std::string, std::vector<std::string>>::iterator the location of the pair to print
void printsingleVector(std::map<std::string, std::vector<std::string>>::iterator it)
{

  std::cout << it->second.size() << ": ";
  std::cout << '[';
  for (std::vector<std::string>::iterator i = it->second.begin(); i != it->second.end(); ++i)
  {
    if (std::next(i) != it->second.end())
    {
      std::cout << *i << ", ";
    }
    else
    {
      std::cout << *i;
    }
  }
  std::cout << ']';
  std::cout << std::endl;
}

//Prints the whole map in proper formatting for project in reverse
// param: map<string, vector<string>>, map for printing
void printMapVectorRev(std::map<std::string, std::vector<std::string>> words)
{

  for (std::reverse_iterator<std::map<std::string, std::vector<std::string>>::iterator> ptr = words.rbegin(); ptr != words.rend(); ptr++)
  {
    const std::string &key = ptr->first;
    std::vector<std::string> &value = ptr->second;

    std::cout << key << ": ";
    std::cout << '[';
    for (std::vector<std::string>::iterator i = value.begin(); i != value.end(); ++i)
    {
      if (std::next(i) != value.end())
      {
        std::cout << *i << ", ";
      }
      else
      {
        std::cout << *i;
      }
    }
    std::cout << ']';
    std::cout << std::endl;
  }
}

//Prints all locations where the size of vector is equal to paramater a.
//Param: map<string, vector<string>> map to check
//Param: long unsigned a, check size comapred to
void printMapVectorCount(std::map<std::string, std::vector<std::string>> words, long unsigned a)
{

  for (std::pair<const std::string, std::vector<std::string>> &ptr : words)
  {
    if (ptr.second.size() == a)
    {
      std::cout << ptr.first << ": ";
      std::cout << '[';

      for (std::vector<std::string>::iterator i = ptr.second.begin(); i != ptr.second.end(); ++i)
      {
        if (std::next(i) != ptr.second.end())
        {
          std::cout << *i << ", ";
        }
        else
        {
          std::cout << *i;
        }
      }

      std::cout << ']';
      std::cout << std::endl;
    }
  }
}

//Checks how many vectors in the map contain a size that paramater a is looking for
//Param: map<string, vector<string>> map to check
//Param: long unsigned a, check size comapred to
int printMapVectorCounts(std::map<std::string, std::vector<std::string>> words, long unsigned a)
{
  int output = 0;
  for (std::pair<const std::string, std::vector<std::string>> &ptr : words)
  {
    if (ptr.second.size() == a)
    {
      output++;
    }
  }

  return output;
}

//Goes through a string and checks if the string represents a integer
//Param string input, the string being checked
bool isdigits(std::string input)
{
  for (char c : input)
  {
    if (!isdigit(c))
    {
      return false;
    }
  }
  return true;
}

//Checks what pair within a map contains the largest vector size for its value
//Param: map<string, vector<string>> map to check
int highestVector(std::map<std::string, std::vector<std::string>> words)
{
  long unsigned int output = 0;
  for (std::pair<const std::string, std::vector<std::string>> &ptr : words)
  {
    if (output < ptr.second.size())
    {
      output = ptr.second.size();
    }
  }

  return output;
}