#include "SleepOperation.h"
SleepOperation::SleepOperation() {}
Operation *SleepOperation::Clone() {
  SleepOperation *o = new SleepOperation();
  return o;
}
void SleepOperation::Execute(int &prog_counter) {
  double seconds;

  Token token = params.at(0);
  if (token.IsReal()) {
    seconds = token.GetAsReal();
  } else {
    seconds = token.GetAsNumeric();
  }
  std::cout << "sleep: " << seconds << " seconds" << std::endl;
  long ms_to_sleep = seconds * 1000;
  std::this_thread::sleep_for(std::chrono::milliseconds(ms_to_sleep));
}

