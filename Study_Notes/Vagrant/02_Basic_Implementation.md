# Basic Implementation with Vagrant

**NOTE:** 

Here assumes you already have Vagrant and VM provider (e.g. VMWare, VirtualBox, etc) installed in your machine.

## Getting started or setup with Vagrant

1) Create a folder where you want to setup a VM with Vagrant

2) Run `vagrant init` to initialize a Vagrant environment in the folder

    - Or you can run `vagrant init <box_name>` to:
        
        - Initialize and update the value of `config.vm.box` in the created Vagrantfile to `<box_name>`

        - `<box_name>` will be the available public pre-configured virtual machine image name under Vagrant Cloud, where you can search in the Internet

3) The default Vagrantfile will be created after the step above is done

    - Vagrantfile is written in `Ruby` language

    - If `vagrant init` is executed just now, most lines in the Vagrantfile will be commented by default

        - Uncomment `config.vm.box` and fill in its value with `<box_name>`, where you can search in the Internet. Optionally, you can run this command `vagrant box add <box_name>`

4) Run `vagrant up` to start your VM (virtual machine)

    - This will create a new VM using the box you selected and start it

    - If it is the first time, Vagrant will download the box from the Internet

5) Run `vagrant ssh` to SSH into your VM

    - You can run commands in your VM once able to SSH

    - Type `exit` command in VM to exit SSH

**EXTRAS:**

- Optionally, you can use <a href="https://vagrantfile-generator.vercel.app/">Online Vagrantfile Generator</a> to provide the custom configuration and download the configured Vagrantfile online.