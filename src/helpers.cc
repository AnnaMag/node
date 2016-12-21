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




void PrintLocalString(v8::Local<v8::String> key){
    uint32_t utf8_length = key->Utf8Length();
    // smart pointers can't be used as WriteUtf8 takes plain char *
    //std::unique_ptr<char*> buffer;//(new char[utf8_length]);
    char* buffer = new char[utf8_length];
    key->WriteUtf8(buffer, utf8_length, nullptr, v8::String::NO_NULL_TERMINATION);
    std::cout << buffer  << std::endl;
    // so we have to explicitely deal with it
    delete[] buffer;
    }

void PrintLocalArray(v8::Local<v8::Array> arr){
    int length = arr->Length();
    for (int i = 0; i < length; i++) {
      Local<String> key = arr->Get(i)->ToString();
      PrintLocalString(key);
    }
}
