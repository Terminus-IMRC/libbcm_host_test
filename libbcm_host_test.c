#include <stdio.h>
#include <bcm_host.h>

int main(void)
{
    bcm_host_init();

    printf("peripheral_address: %#010x\n", bcm_host_get_peripheral_address());
    printf("peripheral_size: %#010x\n", bcm_host_get_peripheral_size());
    printf("sdram_address: %#010x\n", bcm_host_get_sdram_address());

    const unsigned model_type = bcm_host_get_model_type();
    switch (model_type) {
#define X(x) case x: printf("model_type: %u (%s)\n", x, #x); break;
        X(BCM_HOST_BOARD_TYPE_MODELA)
        X(BCM_HOST_BOARD_TYPE_MODELB)
        X(BCM_HOST_BOARD_TYPE_MODELAPLUS)
        X(BCM_HOST_BOARD_TYPE_MODELBPLUS)
        X(BCM_HOST_BOARD_TYPE_PI2MODELB)
        X(BCM_HOST_BOARD_TYPE_ALPHA)
        X(BCM_HOST_BOARD_TYPE_CM)
        X(BCM_HOST_BOARD_TYPE_CM2)
        X(BCM_HOST_BOARD_TYPE_PI3MODELB)
        X(BCM_HOST_BOARD_TYPE_PI0)
        X(BCM_HOST_BOARD_TYPE_CM3)
        X(BCM_HOST_BOARD_TYPE_CUSTOM)
        X(BCM_HOST_BOARD_TYPE_PI0W)
        X(BCM_HOST_BOARD_TYPE_PI3MODELBPLUS)
        X(BCM_HOST_BOARD_TYPE_PI3MODELAPLUS)
        X(BCM_HOST_BOARD_TYPE_FPGA)
        X(BCM_HOST_BOARD_TYPE_CM3PLUS)
        X(BCM_HOST_BOARD_TYPE_PI4MODELB)
#undef X
        default:
            printf("model_type: %u (Unknown)\n", model_type);
            break;
    }

    printf("is_model_pi4: %u\n", bcm_host_is_model_pi4());
    printf("is_fkms_active: %u\n", bcm_host_is_fkms_active());
    printf("is_kms_active: %u\n", bcm_host_is_kms_active());

    const unsigned processor_id = bcm_host_get_processor_id();
    switch (processor_id) {
#define X(x) case x: printf("processor_id: %u (%s)\n", x, #x); break;
        X(BCM_HOST_PROCESSOR_BCM2835)
        X(BCM_HOST_PROCESSOR_BCM2836)
        X(BCM_HOST_PROCESSOR_BCM2837)
        X(BCM_HOST_PROCESSOR_BCM2838)
#undef X
        default:
            printf("processor_id: %u (Unknown)\n", processor_id);
            break;
    }

    bcm_host_deinit();

    return 0;
}
