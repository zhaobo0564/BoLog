//
// Created by zhaobo on 22-9-22.
//
#include "bo_log.h"
#include <sys/io.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <ctime>

BoLog* BoLog::GetInstance() {
  static BoLog bl;
  return &bl;
}

void BoLog::Init(std::string lfd, bolog_type bt) {
  log_file_dir_ = lfd;
  base_bolog_type = bt;

  // todo check dir is exists
  if (log_file_dir_.empty()) {
    return;
  }
  if (access(log_file_dir_.c_str(), 0) == -1) {
    if (mkdir(log_file_dir_.c_str(), S_IRWXU)) {

    } else {
      std::cerr << "the dir path is not exists\n";
      exit(-1);
    }
  }
  write_log_in_file_.open(log_file_dir_ + "/" + "log.txt");
}

std::ostream&  BoLog::start(bolog_type bt, int32_t line,
                           std::string function_name,
                           std::string file_name) {

  time_t tm;
  time(&tm);
  char time_string[128];
  ctime_r(&tm, time_string);
  std::string type;
  if (bt == INFO) {
    type = "[INFO] ";
  } else if (bt == DEBUG) {
    type = "[DEBUG] ";
  } else if (bt == WARNING) {
    type = "[WARNING] ";
  } else if (bt == ERROR) {
    type = "[ERROR] ";
  }
  return GetStream(bt) << "\n" <<  type << "[" << __DATE__ << " " << __TIME__ << "] " << "[ " << file_name << " " << function_name <<
         " line=" << line << " ]: ";

}

std::ostream& BoLog::GetStream(bolog_type bt) {

  if (log_file_dir_.empty()) {
    if (bt == WARNING) {
      return std::cerr;
    }
    return std::cout;
  }
  return write_log_in_file_;
}