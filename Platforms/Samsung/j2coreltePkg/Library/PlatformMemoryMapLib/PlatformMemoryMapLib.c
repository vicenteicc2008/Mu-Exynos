#include <Library/BaseLib.h>
#include <Library/PlatformMemoryMapLib.h>

static ARM_MEMORY_REGION_DESCRIPTOR_EX gDeviceMemoryDescriptorEx[] = {
    /* DDR Regions */
    {"Peripherals",       0x00000000, 0x15000000, AddDev, MMAP_IO, UNCACHEABLE,  MmIO,   NS_DEVICE},
    /* DDR Bank 0 Start */
    {"HLOS 0",            0x40000000, 0x3E800000, AddMem, SYS_MEM, SYS_MEM_CAP, Conv, WRITE_BACK_XN},
    {"UEFI Stack",        0x40C00000, 0x00040000, AddMem, SYS_MEM, SYS_MEM_CAP,  BsData, WRITE_BACK},
    {"CPU Vectors",       0x40C40000, 0x00010000, AddMem, SYS_MEM, SYS_MEM_CAP,  BsCode, WRITE_BACK},
    {"HLOS 1",            0x40000000, 0x40000000, AddMem, SYS_MEM, SYS_MEM_CAP, Conv,   WRITE_BACK},
    {"UEFI FD",           0x50000000, 0x00200000, AddMem, SYS_MEM, SYS_MEM_CAP, BsCode, WRITE_BACK},
    {"Display Reserved",  0x14830000, 0x00800000, AddMem, MEM_RES, SYS_MEM_CAP, Reserv, WRITE_THROUGH_XN},

    /* Terminator for MMU */
    {"Terminator", 0, 0, 0, 0, 0, 0, 0}};

ARM_MEMORY_REGION_DESCRIPTOR_EX *GetPlatformMemoryMap()
{
    return gDeviceMemoryDescriptorEx;
}
