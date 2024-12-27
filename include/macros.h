#ifndef MACROS_H
#define MACROS_H

#define ALIGNED(x) __attribute__((aligned(x)))

#define ARRAY_COUNT(arr) (s32)(sizeof(arr) / sizeof(arr[0]))
#define ARRAY_COUNTU(arr) (u32)(sizeof(arr) / sizeof(arr[0]))

#endif