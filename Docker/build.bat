ocker run --rm -it -v "%cd%":/root/env os-dev make build
qemu-system-x86_64 -cdrom Kernelite.iso -m 512M