//
// Created by zhaobo on 22-9-22.
//

#include "bo_log.h"

int main() {
  BoLogInIt("./",INFO);
  BoLog(INFO) << "A";
  BoLog(WARNING) << "@@@";
}