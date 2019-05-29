//Copyright (c) 2007-2008, Marton Anka
//
//Permission is hereby granted, free of charge, to any person obtaining a 
//copy of this software and associated documentation files (the "Software"), 
//to deal in the Software without restriction, including without limitation 
//the rights to use, copy, modify, merge, publish, distribute, sublicense, 
//and/or sell copies of the Software, and to permit persons to whom the 
//Software is furnished to do so, subject to the following conditions:
//
//The above copyright notice and this permission notice shall be included 
//in all copies or substantial portions of the Software.
//
//THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS 
//OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
//FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL 
//THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
//LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING 
//FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS 
//IN THE SOFTWARE.

#ifdef _M_IX86
#define _M_IX86_X64
#elif defined _M_X64
#define _M_IX86_X64
#endif

struct HOOK_INFO
{
    PVOID *ppSystemFunction;    // pointer to pointer to function to be hooked
    PVOID pHookFunction;        // hook function
    ULONG bytesRewritten;       // number of bytes, overwritten with int 3 when Mhook_SetHookExAntiDetours called
    PVOID pFunBodyAfterJump;    // pointer to function body after jump
    BOOL isHookSetSuccessfully; // hook setting status
};

#define ANTI_DET_EXTRA_INSTRUCTIONS_MAX -1
// stores all hook logic, other hook setting functions just call this
int Mhook_SetHookExAntiDetours(HOOK_INFO* hooks, int hookCount, int extraInstrucion);

// returns number of successfully set hooks
int Mhook_SetHookEx(HOOK_INFO* hooks, int hookCount);
BOOL Mhook_SetHook(PVOID *ppSystemFunction, PVOID pHookFunction);
int Mhook_UnhookEx(PVOID** hooks, int hookCount);
BOOL Mhook_Unhook(PVOID *ppHookedFunction);