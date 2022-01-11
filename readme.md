# dbxcli clone

A lightweight `dbxcli` clone created just for learning purposes.

## Instructions

### Build and run the app

```bash
make
```

Then, simply run the created executable:

```bash
./a.out
```

### Clear up the build artifacts

```bash
make clean
```

---

## Available commands

Use `--help` to see what the available commands are:

```
--help
-------- COMMANDS --------
cp --> copy files
ls --> list the folders/files inside
mkdir --> create new folder
mv --> move folder1/file1 into folder2/file2(creates destination if doesn't exist)
rm --> remove folder/file
search --> search for files/folders
```

### cp

```bash
# The `src` file is relative to the root folder and `dest` is relative to the `dropbox` folder.
cp src dest

cp /path/to/absolute/file.txt some-file.txt

# Make sure the nested folder in `dropbox` already exists.
cp dir/ dir-renamed
```

### ls

```bash
# It is relative to the `dropbox` folder.
ls

ls directory
```

### mkdir

```
mkdir folder
```

### mv

```bash
mv src dest

mv /path/to/absolute/file.txt some-file.txt

mv dir/ dir-renamed
```

### rm

The file or directory that is to be removed is relative to the `dropbox` folder.

```bash
rm file.txt

rm directory/file

rm directory
```

### search

Allows searching for files or directories.

It will print all the files/directories that match the given pattern.

```
search pattern
```

---

## References

* [Compiling C programs with Multiple Files](https://www.youtube.com/watch?v=2YfM-HxQd_8)
* [A Super-Simple Makefile for Medium-Sized C/C++ Projects](https://spin.atomicobject.com/2016/08/26/makefile-c-projects/)