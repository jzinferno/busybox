# Building busybox with the latest Android NDK

```bash
# Export variable with full path to NDK folder
export NDK_ROOT=/path/to/ndk

# Generate headers
make jzinferno_defconfig
make applets/applets.o

# Run build
$NDK_ROOT/ndk-build -j$(nproc --all)
```
