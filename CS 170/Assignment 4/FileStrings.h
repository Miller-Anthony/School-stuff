/*!*************************************************************************
\file       FileStrings.cpp
\author     Anthony Miller
\par        DP email: anthony.m\@digipen.edu
\par        course: CS170
\par        section: A
\par        assignment: Assignment #4
\date       04/11/2019

\brief
    Various overloaded functions to manipulate a points data

**************************************************************************/

////////////////////////////////////////////////////////////////////////////////
#ifndef FILESTRINGS_H
#define FILESTRINGS_H
////////////////////////////////////////////////////////////////////////////////

#include <string> // string
#include <vector> // vector

//! namespace CS170
namespace CS170
{

  const char SPACE = 32;  //!< ASCII value of a space
  
  //! Class containing utility methods for a string
  class StringUtils
  {
    public:
      static std::string& UpperCase(std::string& string);
      static std::vector<std::string> WordWrap(const std::string& words, 
                                             size_t line_length);
      static std::vector<std::string> Tokenize(const std::string& words);
  };

  //! Class containing info about the dictionary
  class DictionaryInfo
  {
    public:
      size_t shortest; //!< Shortest word in the dictionary
      size_t longest;  //!< Longest word in the dictionary
      size_t count;    //!< Number of words in the dictionary
  };

  //! Class containing methods to check spellings of words
  class SpellChecker
  {
    public:
      enum SCResult { scrFILE_OK = -1,       // File was opened successfully 
                      scrFILE_ERR_OPEN = -2, // File was unable to be opened 
                      scrWORD_OK = 1,        // Word found in dictionary      
                      scrWORD_BAD = 2        // Word not found in dictionary  
                    };

      SpellChecker(const std::string &dictionary);
      SCResult GetInfo(DictionaryInfo &info) const;
      SCResult SpellCheck(const std::string& word) const;
      SCResult WordLengths(std::vector<size_t>& lengths, size_t count) const;
      SCResult WordsStartingWith(char letter, int& count) const;
      SCResult AcronymToWord(const std::string& acronym, 
                             std::vector<std::string>& words, 
                             size_t maxlen = 0) const;
      
    private:
      std::string dictionary_;  //!< value of pi
  };

} // namespace CS170

#endif
////////////////////////////////////////////////////////////////////////////////
