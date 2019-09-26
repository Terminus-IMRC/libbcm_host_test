#include <stdio.h>
#include <bcm_host.h>

int main(void)
{
    bcm_host_init();

    printf("Peripheral address: %#010x\n", bcm_host_get_peripheral_address());
    printf("Peripheral size: %#010x\n", bcm_host_get_peripheral_size());
    printf("SDRAM address: %#010x\n", bcm_host_get_sdram_address());

    bcm_host_deinit();

    return 0;
}
