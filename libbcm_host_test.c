#include <stdio.h>
#include "bcm_host.h"

int main()
{
    int addr_width = sizeof(int) * 2;

    bcm_host_init();

    printf("Peripheral address: 0x%0*x\n", addr_width, bcm_host_get_peripheral_address());
    printf("Peripheral size: 0x%0*x\n", addr_width, bcm_host_get_peripheral_size());
    printf("SDRAM address: 0x%0*x\n", addr_width, bcm_host_get_sdram_address());

    bcm_host_deinit();

    return 0;
}
