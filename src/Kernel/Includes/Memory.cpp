#include "Ports.h"
#include "Memory.h"
#include "Multiboot.h"

uint8_t readmemory8(uint64_t address)
{
	uint8_t ret = 0;
	ret = *((uint8_t*)address);
	return ret;
}
uint16_t readmemory16(uint64_t address)
{
	uint16_t ret = 0;
	ret = *((uint16_t*)address);
	return ret;
}
uint32_t readmemory32(uint64_t address)
{
	uint32_t ret = 0;
	ret = *((uint32_t*)address);
	return ret;
}
uint64_t readmemory64(uint64_t address)
{
	uint64_t ret = 0;
	ret = *((uint64_t*)address);
	return ret;
}

void setmemory8(uint64_t address, uint8_t value)
{
	uint8_t* pointer = (uint8_t*)address;
	*pointer = value;
}
void setmemory16(uint64_t address, uint16_t value)
{
	uint16_t* pointer = (uint16_t*)address;
	*pointer = value;
}
void setmemory32(uint64_t address, uint32_t value)
{
	uint32_t* pointer = (uint32_t*)address;
	*pointer = value;
}
void setmemory64(uint64_t address, uint64_t value)
{
	uint64_t* pointer = (uint64_t*)address;
	*pointer = value;
}
