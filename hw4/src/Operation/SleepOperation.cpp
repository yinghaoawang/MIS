#include "Operation/SleepOperation.h"
SleepOperation::SleepOperation() {}
Operation *SleepOperation::Clone() {
  SleepOperation *o = new SleepOperation();
  return o;
}
std::string SleepOperation::Execute(int &prog_counter) {
  std::stringstream out;
  double seconds;
  Token token = params.at(0);
  if (token.IsReal()) {
    seconds = token.GetAsReal();
  } else {
    seconds = token.GetAsNumeric();
  }
  out << "sleep: " << seconds << " seconds" << std::endl;
  long ms_to_sleep = seconds * 1000;
  std::this_thread::sleep_for(std::chrono::milliseconds(ms_to_sleep));
  return out.str();
}

