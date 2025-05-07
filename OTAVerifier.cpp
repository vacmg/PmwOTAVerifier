#include "OTAVerifier.h"

#include "EspOSInterface.h"

#include "esp_ota_ops.h"

bool OTAVerifier::updateHandler()
{
    OSInterfaceLogInfo(tag, "OTA was successful, rollback canceled");
    esp_ota_mark_app_valid_cancel_rollback();
    return true;
}

void OTAVerifier::performRollbackIfPossible()
{
    if (esp_ota_check_rollback_is_possible())
    {
        OSInterfaceLogInfo(tag, "Performing rollback");
        esp_ota_mark_app_invalid_rollback_and_reboot();
    }
    OSInterfaceLogError(tag, "Rollback requested but not possible");
}
