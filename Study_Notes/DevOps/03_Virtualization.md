# Virtualization 

Virtualization allows one single physical machine to run multiple simulated environments (virtual machines or VMs)

## Common Terminologies

| Terminology | Explanation |
| :---: | ---|
| Host OS | Operating System of the Physical Machine |
| Guest OS | Operating System of the Virtual Machine (Guest Machine) |
| VM | Virtual Machine |
| Snapshot | A point-in-time capture of a virtual machine's state, including its operating system, applications, and data. This allows you to revert the VM to a specific configuration if needed, like before a software update or configuration change |
| Hypervisor | A software that you can use to run multiple virtual machines on a single physical machine |

## Types of Hypervisor

### Type 1 Hypervisor

- Bare Metal
- Runs as a Base OS, installed on physical machine
- e.g. VMware esxi, Xen Hypervison, Microsoft Hyper-V hypervisor

<img src="images/Type_1_Hypervisor.png" alt="Type 1 Hypervisor">

### Type 2 Hypervisor

- Runs as a software on Host OS of the physical machine
- e.g. Oracle virtualbox, VMware server

<img src="images/Type_2_Hypervisor.png" alt="Type 2 Hypervisor">

## Prerequisites before setup a VM

Install both `Virtualbox` and `Vagrant`

NOTE: If your machine is Windows, do as below:

a) Enable Virtualization in BIOS menu (keyword to search could be `VTx`, `Secure virtual machine` or `Virtualization`)

b) Search "Windows Features" in start menu and uncheck/disable other windows virtualiztion as below: 
- `Microsoft Hyperv`
- `Windows Hypervisor platform`
- `Windows Subsystem for Linux`
- `Docker Desktop`
- `Virtual Machine Platform`

## Virtualbox VM Manual Installation

Reference documentation link: <a href="https://www.virtualbox.org/manual/">VirtualBox.org Manual</a>

## Virtualbox VM Automated Installation

`Vagrant` is VM automation tool to manage or automate VM lifecycle.

### Basic Command Lines with Vagrant

Before playing around with basic Vagrant command lines, do create directory for Vagrant execution

| **Command Lines** | **Explanation / Remarks** |
|---|---|
| `vagrant init < BOXNAME >` | Initialize Vargant box < BOXNAME > in the current directory. For < BOXNAME >, search "Vargant Cloud" and look for the box you want to initialize. <br><br> After done initialize, you will see `Vagrantfile` created in the directory. In Vagrantfile, you will see value of `config.vm.box` is < BOXNAME >. <br> You can always update the right < BOXNAME > if needed.|
| `vagrant up` | Creates amd configure VM according to your `Vagrantfile` <br><br> Once the VM is up, you can see the create VM is available on the Virtualbox manager GUI. |
| `vagrant box list` | List all downloaded boxes |
| `vagrant status` | Check the status of VM in current directory |
| `vagrant ssh` | Perform SSH and login the VM created via Vagrant |
| `vargant halt` | Power off or shut down the VM <br><br> To restart VM, simply run `vagrant up` |
| `vagrant reload` | Reboot the VM |
| `vagrant destroy` | Delete the VM <br><br> You can also verify on Virtualbox manager GUI that the VM is gone after this command is executed |
| `vagrant global-status` | View status of all VMs in the machine |
| `vagrant global-status --prune` | Remove stable boxes/VMs from cache, and then show status of all remaining boxes/VMs|

**IMPORTANT**: Please remember to power off your VM before power off your machine