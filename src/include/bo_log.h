//
// Created by zhaobo on 22-9-22.
//

#ifndef BOLOG_BO_LOG_H
#define BOLOG_BO_LOG_H
#include <string>
#include <iostream>
#include <fstream>

typedef enum BologType {
  DEBUG,
  INFO,
  WARNING,
  ERROR
}bolog_type;


class BoLog {
private:

  BoLog() {};
  std::string log_file_dir_;
  std::ofstream write_log_in_file_;



public:
 bolog_type base_bolog_type;

 static BoLog* GetInstance();

 void Init(std::string lfd="", bolog_type bt = INFO);

 std::ostream&  start(bolog_type bt,int32_t line,
                     std::string function_name,
                     std::string file_name);

 std::ostream& GetStream(bolog_type bt);


};



#define BoLog(bt) \
    BoLog::GetInstance()->start(bt, __LINE__, __FUNCTION__, __FILE__)

#define BoLogInIt BoLog::GetInstance()->Init

#endif // BOLOG_BO_LOG_H
