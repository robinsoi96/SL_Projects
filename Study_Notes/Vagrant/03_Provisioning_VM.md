# Provisioning VM using Vagrant

**Provisioning a virtual machine** means process of setting up and configuring a virtual machine within the necessary software and resources needed for a particular task or application.

- Provisioning can be done manually by logging into the VM and making the necessary changes

- It can also be automated using configuration management tools like Ansible, Chef or Puppet

- Automated provisioning can save time and ensure consistency across multiple VMs or environments

- Vagrant allows for easy provisioning of VMs using configuration files called `Vagrantfile` which specify the desired state of the VM

## Method of Provisioning

### Within `Vagrantfile`

1) Open `Vagrantfile`

2) Edit `config.vm.provision` block in `Vagrantfile` as in the sample code snippet below

    ```ruby
    config.vm.provision "shell", inline:<<-SHELL
        # Add your provisioning commands here
    SHELL
    ```

    The code snippet above uses Shell as the provisioner.

3) Save `Vagrantfile`

4) Provision the VM

    - If the VM is not yet up, run `vagrant up` to start the VM for provisioning

    - If VM is already up, run `vagrant reload` to restart the VM for provisioning

    - Given VM is up, you can run `vagrant provision`, where it will only update the new changes

### Prepare a separate script and then provide script location in `Vagrantfile`

1) Create a new script for the provisioning, e.g. Shell script

2) Edit `config.vm.provision` block in `Vagrantfile` to add the provisioning script as in the sample code snippet below

    ```ruby
    config.vm.provision "shell", path:"<path_name_of_provisioning_script>"
    ```

    The code snippet above uses Shell as the provisioner.

3) Save `Vagrantfile`

4) Provision the VM

    - If the VM is not yet up, run `vagrant up` to start the VM for provisioning

    - If VM is already up, run `vagrant reload` to restart the VM for provisioning

    - Given VM is up, you can run `vagrant provision`, where it will only update the new changes