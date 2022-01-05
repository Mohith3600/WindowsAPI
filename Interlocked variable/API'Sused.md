# InterlockedIncrement64
Increment the variable on 64-bit variable as an atomic operation 

LONG64 InterlockedIncrement64(
LONG64 volatile *Addend);

Parameters
*Addend - A pointer variable to be incremented

# InterlockedAdd64
Performs an atomic add operation on the specified value

LONGLONG _cdec1 InterlockedAdd64(
_Inout_ LONGLONG volatile *Addend,
_In_ LONGLONG Value);

Parameters
*Addend - A pointer variable to First Operand 
Value - A Second Operand

