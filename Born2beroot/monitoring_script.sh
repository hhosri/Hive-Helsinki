#!/bin/bash
arch_kernel=$(uname -a)

pCPU=$(grep "physical id" /proc/cpuinfo |  wc -l)

cores=$(lscpu | grep "Core(s) per socket:" | awk '{printf "%d", $4}')
threads=$(lscpu | grep "Thread(s) per core:" | awk '{printf "%d", $4}')
vCPU=$((cores*threads*pCPU))

ram_total=$(free --mega | grep "Mem:" | awk '{printf "%d", $2}')
ram_used=$(free --mega | grep "Mem:" | awk '{printf "%d", $3}')
ram_percent=$(free --mega | grep "Mem:" | awk '{printf "%.2f", $3*100/$2}')

disk_total=$(df -Bg | grep "/dev/" | grep -v "tmpfs" | grep -v "udev" |awk '{rslt = rslt + $2} END {printf "%d", rslt}')
disk_used=$(df -Bm | grep "/dev/" | grep -v "tmpfs" | grep -v "udev" | awk '{rslt = rslt + $3} END {printf "%d", rslt}')
disk_percent=$(df -Bm | grep "/dev/" | grep -v "tmpfs" | grep -v "udev" | awk '{td = td + $2} {ud = ud + $3} END {printf "%d", ud/td*100}')

cpu_load=$(mpstat | grep "all" | awk '{printf "%.1f", $4+$5+$6+$7+$8+$9+$10+$11+$12}')

last_boot=$(who -b | grep "system boot" | awk '{printf "%s %s",$3,$4 }')

lvm_number=$(lsblk | grep "lvm" | wc -l)
lvm_status=$(if [ $lvm_number -gt 0 ]; then echo "yes"; else echo "no"; fi)

active_conx=$(netstat -tan | grep "ESTABLISHED" | grep "tcp" |  wc -l)

users=$(who | awk '{print $1}' | uniq | wc -l)

IPv4=$(hostname -I)
mac=$(ip link show | grep "link/ether" | awk '{print $2}')

sudo_logs=$( grep "COMMAND=" /var/log/sudo/sudologs.log | wc -l)


wall "
	#Architecture: $arch_kernel
	#CPU physical: $pCPU
	#vCPU: $vCPU
	#Memory Usage: $ram_used/${ram_total}MB (${ram_percent}%)
	#Disk Usage: $disk_used/${disk_total}Gb (${disk_percent}%) 
	#CPU load: ${cpu_load}%
	#Last boot: $last_boot
	#LVM use: $lvm_status
	#Connections TCP: $active_conx ESTABLISHED
	#User log: $users
	#Network: IP $IPv4 ($mac)
	#Sudo: $sudo_logs cmd "
