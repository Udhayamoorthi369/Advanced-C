## Create disk partition on Linux using gparted

The gparted tool is a GUI based partitioning utility design to perform partition cTo install gparted on Linux, you can run the following commands
```
$ sudo apt-get install gparted    [Debian/Ubuntu]
$ sudo yum install gparted        [RHEL/CentOS]
```
Now that gparted is installed on your system, simply run “gparted” in order for the tool to start.
```
$ sudo gparted
```
# 1. Create 4 partition with the same size using Gpt
![gpat](https://user-images.githubusercontent.com/89963356/146141570-ffc5e44a-2d7c-4af1-8227-701670fd47c5.png)

* first 2 partition should be EXT4 & second 2 partition should be VFAT

![gapt2 (1)](https://user-images.githubusercontent.com/89963356/146141581-4064feec-c92e-4754-95fd-2acd76e41e6c.png)
