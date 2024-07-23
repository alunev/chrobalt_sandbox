# Adding Starboard to Chrobalt

Lets you build starboard in chrobalt. The target starboard_group is
available as a shared library which can compile all objects but will not link
due to missing symbols.

```
mkdir -p out/Default
cp chrobalt/linux/args.gn out/Default
gn gen out/Default
ninja -C out/Default starboard_group
```
