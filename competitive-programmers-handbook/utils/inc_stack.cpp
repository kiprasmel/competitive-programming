#include <bits/stdc++.h>
#include <sys/resource.h>

void inc_stack() {
    const __rlim_t kStackSize = 1024L/*B*/ * 1024L/*KB*/ * 64L/*MB*/; // min stack size = 64 Mb
    struct rlimit rl;
    int result;

    result = getrlimit(RLIMIT_STACK, &rl);
    if (result == 0)
    {
        if (rl.rlim_cur < kStackSize)
        {
            rl.rlim_cur = kStackSize;
            result = setrlimit(RLIMIT_STACK, &rl);
            if (result != 0)
            {
                fprintf(stderr, "setrlimit returned result = %d\n", result);
            }
        }
    }
}

