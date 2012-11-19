#include "windows.h"

LARGE_INTEGER
WINAPI
LargeIntegerDivide (
    LARGE_INTEGER Dividend,
    LARGE_INTEGER Divisor,
    PLARGE_INTEGER Remainder
    )
{
    LARGE_INTEGER result;
    Remainder->QuadPart = (Dividend.QuadPart % Divisor.QuadPart);
    result.QuadPart = (Dividend.QuadPart / Divisor.QuadPart);
    return result;
}

LARGE_INTEGER
WINAPI
ExtendedLargeIntegerDivide (
    LARGE_INTEGER Dividend,
    ULONG Divisor,
    PULONG Remainder
    )
{
    LARGE_INTEGER result;
    *Remainder = (ULONG)(Dividend.QuadPart % Divisor);
    result.QuadPart = (Dividend.QuadPart / Divisor);
    return result;
}

LARGE_INTEGER
WINAPI
LargeIntegerSubtract (
    LARGE_INTEGER Minuend,
    LARGE_INTEGER Subtrahend
    )
{
    LARGE_INTEGER result;
    result.QuadPart = (Minuend.QuadPart - Subtrahend.QuadPart);
    return result;
}
