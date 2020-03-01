#pragma once

void *vitc_mdim_init();
void vitc_mdim_setsize(void *handle, size_t size);
void vitc_mdim_resetptr(void *handle);
void vitc_mdim_free(void *handle);