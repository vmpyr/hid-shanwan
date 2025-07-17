#!/bin/bash

set -e

MOD_NAME="hid-shanwan"
BUILD_DIR="./build"
KO="$BUILD_DIR/$MOD_NAME.ko"

echo "[*] Building module..."
if ! make ; then
    echo "[!] Build failed"
    exit 1
fi
echo "[+] Build successful"

if lsmod | grep -q "$MOD_NAME"; then
    echo "[*] Removing existing module..."
    sudo rmmod $MOD_NAME || {
        echo "[!] Failed to remove module"
        exit 1
    }
    echo "[+] Module removed"
fi

echo "[*] Inserting module..."
sudo insmod "$KO" || {
    echo "[!] Failed to insert module"
    exit 1
}

echo "[+] Module inserted successfully"
sudo dmesg | tail -n 10