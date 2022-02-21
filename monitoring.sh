#!/bin/bash

#pour Memory Usage
TOTAL_MEMORY=$(vmstat -s | awk '{if(NR == 1) print$1}')
USED_MEMORY=$(vmstat -s | awk '{if(NR == 2) print$1}')
USED_MEMORY_PERCENT=$(expr $USED_MEMORY \* 100 / $TOTAL_MEMORY)

#pour Disk Usage
TOTAL_DISK_SIZE=$(df -h --total --output=size| awk 'END{print$NF}')
USED_DISK_SIZE=$(df -h --total --output=used | awk 'END{print$NF}')
USED_DISK_PERCENT=$(df -h --total | awk 'END{print$(NF - 1)}')

printf "#Architecture: `uname -a` \n"
printf "#CPU physical: `nproc` \n"
printf "#vCPU: `cat /proc/cpuinfo | grep processor | wc -l` \n"
printf "#Memory Usage: `expr $USED_MEMORY / 1024`/`expr $TOTAL_MEMORY / 1024`MB ($USED_MEMORY_PERCENT%%) \n"
printf "#Disk Usage: $USED_DISK_SIZE/$TOTAL_DISK_SIZE ($USED_DISK_PERCENT%)\n"
printf "#CPU Load: `top -bn1 | grep Cpu | awk '{print$2}'`%% \n"
printf "#Last Boot: `who -b | awk '{print $(NF - 1), $NF}'` \n"
printf "#LVM use: `lsblk |grep lvm | awk '{if($1) {print "yes";exit;}else {print "no"}}'` \n"
printf "#Connexions TCP: `netstat -ant | grep ESTABLISHED | wc -l` ESTABLISHED \n"
printf "#User Log: `who | wc -l` \n"
printf "#Network: IP `hostname -I` (`ip addr | grep link/ether | awk '{print $(NF -2)}'`) \n"
printf "#sudo: `sudo cat /var/log/sudo/sudo.log | expr $(wc -l) / 2` cmd"
#printf "#Sudo: `cat /var/log/sudo/sudo.log | grep COMMAND | wc -l` cmd"