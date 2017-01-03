#include "v8.h"

#include <iostream>

using v8::Local;
using v8::String;
using v8::Array;

void PrintLocalString(v8::Local<v8::String> key);
void PrintLocalArray(v8::Local<v8::Array> arr);
