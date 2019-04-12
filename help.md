#Installation (for Ubuntu 16.04)

##Network Simulator 2 (NS2) and TCL/TK

1. Install NS2 from [here](https://sourceforge.net/projects/nsnam/files/allinone/ns-allinone-2.35/ns-allinone-2.35.tar.gz/download, "SourceForge")
2. Run the following commands in a terminal:
```sh
$ sudo apt-get update
$ sudo apt-get dist-upgrade
$ sudo apt-get update
$ sudo apt-get install gcc
$ sudo apt-get install g++-4.9
$ sudo apt-get install build-essential autoconf automake
$ sudo apt-get install tcl8.5-dev tk8.5-dev
$ sudo apt-get install perl xgraph libxt-dev libx11-dev libxmu-dev
$ sudo cp /home/abc/Downloads/ns-allinone-2.35.tar.gz /opt/
$ cd /abc/Downloads
$ tar -zxvf ns-allinone-2.35.tar.gz
$ cd ns-allineone-2.35
$ ./install
$ sudo gedit ~/.bashrc
```
3. At this point in time, you will be having a text file open in Gedit. Copy the following lines at the end of the file as they are:
>#LD_LIBRARY_PATH  
>OTCL_LIB=/opt/ns-allinone-2.35/otcl-1.14/  
>NS2_LIB=/opt/ns-allinone-2.35/lib/  
>USR_Local_LIB=/usr/local/lib/  
>export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$OTCL_LIB:$NS2_LIB:$USR_Local_LIB  
>  
>#TCL_LIBRARY  
>TCL_LIB=/opt/ns-allinone-2.35/tcl8.5.10/library/  
>USR_LIB=/usr/lib/  
>export TCL_LIBRARY=$TCL_LIBRARY:$TCL_LIB:$USR_LIB  
>  
>#PATH  
>XGRAPH=/opt/ns-allinone-2.35/xgraph-12.2/:/opt/ns-allinone-2.35/bin/:/opt/ns-allinone-2.35/tcl8.5.10/unix/:/opt/ns-allinone-2.35/tk8.5.10/unix/  
>NS=/opt/ns-allinone-2.35/ns-2.35/  
>NAM=/opt/ns-allinone-2.35/nam-1.15/  
>export PATH=$PATH:$XGRAPH:$NS:$NAM  

4. Open a terminal in the ns-allinone-2.35 folder, and execute the following code:
```sh
$ source ~/.bashrc
$ sudo apt install g++-4.9
$ export CC=gcc-4.9 CXX=g++-4.9 && ./install
$ sudo apt install ns2

If you see a '%' sign after executing the last command, you are good to go.
