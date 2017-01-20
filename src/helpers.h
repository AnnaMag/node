#include "v8.h"

#include <iostream>

using v8::Local;
using v8::String;
using v8::Array;
using v8::Isolate;

void PrintLocalString(v8::Local<v8::String> key);
void PrintLocalArray(v8::Local<v8::Array> arr);
Local<String> StdStringToLocalString(std::string sText, v8::Isolate* isolate);
