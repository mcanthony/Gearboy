#ifndef DEFINITIONS_H
#define	DEFINITIONS_H

#include <cstdarg>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <stdint.h>

#define DEBUG_GEARBOY 1

#ifndef NULL
#define NULL 0
#endif

#define SafeDelete(pointer) if(pointer != NULL) {delete pointer; pointer = NULL;}
#define SafeDeleteArray(pointer) if(pointer != NULL) {delete [] pointer; pointer = NULL;}

#define InitPointer(pointer) ((pointer) = NULL)
#define IsValidPointer(pointer) ((pointer) != NULL)

typedef uint8_t u8;
typedef int8_t s8;
typedef uint16_t u16;
typedef int16_t s16;

#define BIT_MASK_4 0x0F
#define BIT_MASK_8 0xFF
#define BIT_MASK_16 0xFFFF

#define FLAG_ZERO 0x80
#define FLAG_SUB 0x40
#define FLAG_HALF 0x20
#define FLAG_CARRY 0x10
#define FLAG_NONE 0

#define MAX_STRING_SIZE 256

inline void Log(const char* const msg, ...)
{
#ifdef DEBUG_GEARBOY
    static int count = 1;
    char szBuf[MAX_STRING_SIZE];

    va_list args;
    va_start(args, msg);
    vsprintf(szBuf, msg, args);
    va_end(args);

    printf("%d: %s\n", count, szBuf);

    count++;
#endif
}

#endif	/* DEFINITIONS_H */
