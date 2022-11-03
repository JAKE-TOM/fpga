connect -url tcp:127.0.0.1:3121
source F:/0.zynq/PS_FPGA/5_AXI_GPIO/AXI_GPIO/AXI_GPIO.sdk/AXI_GPIO_wrapper_hw_platform_0/ps7_init.tcl
targets -set -filter {jtag_cable_name =~ "Digilent JTAG-HS2 201706300081" && level==0} -index 1
fpga -file F:/0.zynq/PS_FPGA/5_AXI_GPIO/AXI_GPIO/AXI_GPIO.sdk/AXI_GPIO_wrapper_hw_platform_0/AXI_GPIO_wrapper.bit
targets -set -nocase -filter {name =~"APU*" && jtag_cable_name =~ "Digilent JTAG-HS2 201706300081"} -index 0
loadhw -hw F:/0.zynq/PS_FPGA/5_AXI_GPIO/AXI_GPIO/AXI_GPIO.sdk/AXI_GPIO_wrapper_hw_platform_0/system.hdf -mem-ranges [list {0x40000000 0xbfffffff}]
configparams force-mem-access 1
targets -set -nocase -filter {name =~"APU*" && jtag_cable_name =~ "Digilent JTAG-HS2 201706300081"} -index 0
stop
ps7_init
targets -set -nocase -filter {name =~ "ARM*#0" && jtag_cable_name =~ "Digilent JTAG-HS2 201706300081"} -index 0
rst -processor
targets -set -nocase -filter {name =~ "ARM*#0" && jtag_cable_name =~ "Digilent JTAG-HS2 201706300081"} -index 0
dow F:/0.zynq/PS_FPGA/5_AXI_GPIO/AXI_GPIO/AXI_GPIO.sdk/AXI_GPIO/Debug/AXI_GPIO.elf
configparams force-mem-access 0
targets -set -nocase -filter {name =~ "ARM*#0" && jtag_cable_name =~ "Digilent JTAG-HS2 201706300081"} -index 0
con
