#include "OTAVerifier.h"

#include <esp_log.h>

#include "esp_ota_ops.h"

bool OTAVerifier::updateHandler()
{
    ESP_LOGI(tag, "OTA was successful, rollback canceled");
    esp_ota_mark_app_valid_cancel_rollback();
    return true;
}

void OTAVerifier::performRollbackIfPossible()
{
    if (esp_ota_check_rollback_is_possible())
    {
        ESP_LOGI(tag, "Performing rollback");
        esp_ota_mark_app_invalid_rollback_and_reboot();
    }
    ESP_LOGE(tag, "Rollback requested but not possible");
}
