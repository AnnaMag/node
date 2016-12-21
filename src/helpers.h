#include "node.h"
#include "node_internals.h"
#include "node_watchdog.h"
#include "base-object.h"
#include "base-object-inl.h"
#include "env.h"
#include "env-inl.h"
#include "util.h"
#include "util-inl.h"
#include "v8-debug.h"
#include "v8.h"

#include <iostream>


using v8::Local;
using v8::String;
using v8::Array;

void PrintLocalString(v8::Local<v8::String> key);
void PrintLocalArray(v8::Local<v8::Array> arr);
