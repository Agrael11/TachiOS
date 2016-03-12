#ifndef TYPES
#define TYPES

typedef unsigned char uint8_t;
typedef signed char int8_t;
typedef unsigned short uint16_t;
typedef signed short int16_t;
typedef unsigned int uint32_t;
typedef signed int int32_t;
typedef unsigned long long uint64_t;
typedef signed long long int64_t;
typedef unsigned int size_t;
typedef const char* string;

string addToString(string str, char c);
string combineStrings(string string1, string string2);
string intToString(uint32_t number);
uint16_t strlen(string str);

#endif
