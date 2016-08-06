#include "MenuSystem.h"

bool initFromCommandLine(const char* option, i32& number, i32 defaultvalue) {
  for ( u32 i = 1; i < cl_argc; i++ ) {
    string str(cl_argv[i]);
    if ( str == option ) {
      number = atoi(cl_argv[i + 1]);
      return true;
    }
  }
  number = defaultvalue;
  return false;
}

bool initFromCommandLine(const char* option, u32& number, u32 defaultvalue) {
  for ( u32 i = 1; i < cl_argc; i++ ) {
    string str(cl_argv[i]);
    if ( str == option ) {
      number = atoi(cl_argv[i + 1]);
      return true;
    }
  }
  number = defaultvalue;
  return false;
}

bool initFromCommandLine(const char* option, r64& number, r64 defaultvalue) {
  for ( u32 i = 1; i < cl_argc; i++ ) {
    string str(cl_argv[i]);
    if ( str == option ) {
      number = atof(cl_argv[i + 1]);
      return true;
    }
  }
  number = defaultvalue;
  return false;
}

bool initFromCommandLine(const char* option, string& name, const char* defaultvalue) {
  for ( u32 i = 1; i < cl_argc; i++ ) {
    string str(cl_argv[i]);
    if ( str == option ) {
      name = cl_argv[i + 1];
      return true;
    }
  }
  name = string(defaultvalue);
  return false;
}
