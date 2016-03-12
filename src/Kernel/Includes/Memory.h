#ifndef MemoryManagement
#define MemoryManagement
#include "Types.h"

uint8_t readmemory8(uint64_t address);
uint16_t readmemory16(uint64_t address);
uint32_t readmemory32(uint64_t address);
uint64_t readmemory64(uint64_t address);
void setmemory8(uint64_t address, uint8_t value);
void setmemory16(uint64_t address, uint16_t value);
void setmemory32(uint64_t address, uint32_t value);
void setmemory64(uint64_t address, uint64_t value);
uint16_t getTotal();

#endif
