#ifndef MemoryManagement
#define MemoryManagement
#include "Types.h"
#include "Multiboot.h"

struct BiosMemMap
{
	uint32_t size;
	uint64_t base_address;
	uint64_t length;
	uint32_t type;
};

uint8_t readmemory8(uint64_t address);
uint16_t readmemory16(uint64_t address);
uint32_t readmemory32(uint64_t address);
uint64_t readmemory64(uint64_t address);
void setmemory8(uint64_t address, uint8_t value);
void setmemory16(uint64_t address, uint16_t value);
void setmemory32(uint64_t address, uint32_t value);
void setmemory64(uint64_t address, uint64_t value);

static bool mapAvailable = false;
static uint32_t mapAddress;
static uint32_t mapLength;
static bool memInfoAvailable = false;
static uint32_t lowMem;
static uint32_t uppMem;

static BiosMemMap getMapAddress(int n)
{
	int add = mapAddress;
	BiosMemMap map = *((BiosMemMap*)(add));
	int i = 0;
	while (i < n)
	{
	add += map.size+4;
	map = *((BiosMemMap*)(add));
		i++;
	}
	return map;
}

inline void *operator new(size_t)     throw() {}
inline void *operator new[](size_t)   throw() {}
inline void  operator delete  (void *, void *) throw() { };
inline void  operator delete[](void *, void *) throw() { };

#endif
