#include "Init.h"

u32 cl_argc;
char** cl_argv;

// string casename;
// string casedir;

void init(u32 argc, char* argv[]) {
  cl_argc = argc;
  cl_argv = new char*[cl_argc];
  for ( u32 i = 0; i < cl_argc; i++ )
    cl_argv[i] = argv[i];
  /*  
  casename = argv[0];
  casedir = "./";
  
  for ( u32 i = 1; i < cl_argc; i++ ) {
    string str(cl_argv[i]);
    if ( str == "--casename" )
      casename = cl_argv[i + 1];
  }
  for ( u32 i = 1; i < cl_argc; i++ ) {
    string str(cl_argv[i]);
    if ( str == "--casedir" )
      casedir = cl_argv[i + 1];
  }

  fout.open(casename);
  */
}
