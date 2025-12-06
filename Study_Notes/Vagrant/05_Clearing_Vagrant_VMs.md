# Clearing Existing Vagrant VM

1) Navigate to the directory where having the Vagrantfile, creating the VM which you would to clear off including all its resources in the host machine

2) Run the below command to  stop and destroy the VM and its resources managed by that specific Vagrantfile

    ```shell
    vagrant destroy -f
    ```
3) Clean up the global status list of Vagrant by running the below command

    ```shell
    vagrant global-status --prune
    ```

    This command removes entries for environments that are no longer active or managed by Vagrant. 

    **NOTE:** Manually unregister the VM from provider (e.g. Virtualbox, VMWare) in case `vagrant destroy` didn't fully clean up.

## Remove Vagrant box (base image to create VM) if not needed

1) Run the below command to check the box name you would like to remove

    ```shell
    vagrant box list
    ```

2) Run the below command to remove the box name

    ```shell
    vagrant box remove <box_name>
    ```

    **NOTE:** You can add argument `--provider <VM_provider>` in the command above to mention the VM provider as well