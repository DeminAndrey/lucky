#include "GetLuckyRecursion.h"

#include <filesystem>
#include <sstream>

class TestRunner {
  std::string m_testPath;

public:
  TestRunner(const std::string &testsPath)
      : m_testPath{testsPath} {
  }

  void runTests() {
    size_t testNumber = 0;
    std::stringstream ss;

    while (true)  {
      ss << m_testPath << "/test." << testNumber << ".in";
      std::string inputName{ss.str()};

      ss.str("");
      ss << m_testPath << "/test." << testNumber << ".out";
      std::string outputName{ss.str()};

      if (!std::filesystem::exists(inputName) ||
          !std::filesystem::exists(outputName)) {
        break;
      }

      std::cout << "Test #" << testNumber << ": ";
      getLuckyTickets::run(inputName, outputName);

      ++testNumber;
      ss.str("");
      std::cout << '\n';
    }
  }
};
