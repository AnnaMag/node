#include "v8.h"
#include "helpers.h"

#include <iostream>

using v8::Local;
using v8::String;
using v8::Array;

void PrintLocalString(v8::Local<v8::String> key){
    uint32_t utf8_length = key->Utf8Length();
    // smart pointers can't be used as WriteUtf8 takes plain char *
    // e.g. std::unique_ptr<char*> buffer = new char[utf8_length];
    // so we have to clean memory explicitly
    char* buffer = new char[utf8_length];
    key->WriteUtf8(buffer);//, utf8_length, nullptr, v8::String::NO_NULL_TERMINATION);
    std::cout << buffer  << " ";
    delete[] buffer;
    }

void PrintLocalArray(v8::Local<v8::Array> arr){
    int length = arr->Length();
    for (int i = 0; i < length; i++) {
      Local<String> key = arr->Get(i)->ToString();
      PrintLocalString(key);
    }
    std::cout << std::endl;

}
