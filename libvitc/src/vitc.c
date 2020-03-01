#include <stdlib.h>
#include <stdio.h>

#include <vitc.h>

void *
vitc_mdim_init()
{
    size_t **pRealStart = malloc(sizeof(size_t*));
    if(pRealStart)
    {
        pRealStart[0] = malloc(sizeof(size_t));
        if(pRealStart[0]) {
            *pRealStart[0] = 0;

            return pRealStart;
        }
    }

    fprintf(stderr, "Can't allocate memory!\n");
    exit(-1);
}

void
vitc_mdim_setsize(void *handle, size_t size)
{
    size_t** pArray = (size_t**)handle;
    *pArray[0] = size;
}

void
vitc_mdim_resetptr(void *handle)
{
    /*
     * This method should work with any type of multi-dim array prepended by a size indicator. 
     * To be able to modify the start of the array, we have to use a pointer to a multi-dim array
     * (which means a triple star pointer) here.
     */
    void*** pHandle = handle;
    /*
     * I assume here that the pointer hasn't been reset already and points to the first element of the array
     * which is the size indicator. So I don't have to do arithmetics here.
     */
    size_t** pRealStart = (size_t**)*pHandle;
    const size_t elemCount = *pRealStart[0];

    if (elemCount)
    {
        *pHandle = (void**)++pRealStart;
    }
}

void
vitc_mdim_free(void *handle)
{
    size_t** pRealStart = ((size_t**)handle) - 1;

    for (size_t i = 1; i <= *pRealStart[0]; ++i) {
        free(pRealStart[i]);
    }

    // Free size indicator
    free(pRealStart[0]);

    // Free ptr array
    free(pRealStart);
}