#ifndef _MENUSYSTEM_H_
#define _MENUSYSTEM_H_

#include "Init.h"

bool initFromCommandLine(const char*, i32&, i32);
bool initFromCommandLine(const char*, u32&, u32);
bool initFromCommandLine(const char*, r64&, r64);
bool initFromCommandLine(const char*, string&, const char*);

#endif
