// SPDX-License-Identifier: GPL-2.0
#include <linux/module.h>
#include <linux/hid.h>
#include <linux/kernel.h>
#include <linux/usb.h>

#include "hid-ids.h"

static int shanwan_probe(struct hid_device *hdev, const struct hid_device_id *id)
{
    int ret;

    dev_info(&hdev->dev, "Shanwan gamepad connected\n");

    ret = hid_parse(hdev);
    if (ret)
    {
        hid_err(hdev, "Parse failed\n");
        return ret;
    }

    ret = hid_hw_start(hdev, HID_CONNECT_DEFAULT);
    if (ret)
    {
        hid_err(hdev, "HW start failed\n");
        return ret;
    }

    return 0;
}

static void shanwan_remove(struct hid_device *hdev)
{
    hid_hw_stop(hdev);
    dev_info(&hdev->dev, "Shanwan gamepad disconnected\n");
}

static const struct hid_device_id shanwan_devices[] = {
    {HID_USB_DEVICE(USB_VENDOR_ID_SHANWAN, USB_DEVICE_ID_SHANWAN_ANDROID_GAMEPAD)},
    {}};
MODULE_DEVICE_TABLE(hid, shanwan_devices);

static struct hid_driver shanwan_driver = {
    .name = "hid-shanwan",
    .id_table = shanwan_devices,
    .probe = shanwan_probe,
    .remove = shanwan_remove,
};

module_hid_driver(shanwan_driver);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Ujjwal Sarswat (vmpyr)");
MODULE_DESCRIPTION("Basic HID driver for: 2563:0526 ShenZhen ShanWan Technology Co., Ltd. Android Gamepad");
