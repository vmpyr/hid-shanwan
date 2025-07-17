MODULE := hid-shanwan
KDIR := /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)

obj-m := $(MODULE).o
KO := $(MODULE).ko

.PHONY: all run clean reload

all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

load: all
	@if [ -f "$(KO)" ]; then \
		echo "[+] Built $(KO)"; \
		echo "[*] Removing module (if exists)..."; \
		sudo rmmod $(MODULE) 2>/dev/null || echo "[!] Module not loaded"; \
		echo "[*] Inserting module..."; \
		sudo insmod $(KO) && echo "[+] Module inserted."; \
		sudo dmesg | tail -n 20; \
	else \
		echo "[!] Build failed: $(KO) not found."; \
		exit 1; \
	fi

reload: load

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean
