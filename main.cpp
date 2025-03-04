#include "Tests.h"

int main() {
  auto testPath = std::filesystem::current_path().parent_path().append("Tickets");
  if (std::filesystem::exists(testPath)) {
    std::cout << "Test path not found!" << std::endl;

    return 1;
  }
  TestRunner runner(testPath.string());
  runner.runTests();

  return 0;
}
