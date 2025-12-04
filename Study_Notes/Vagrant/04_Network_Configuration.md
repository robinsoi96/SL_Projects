# Vagrant Network Configuration

Vagrant offers the following three network options:

1) Port forwarding
2) Private network (host-only network)
3) Public network (bridged network)

<br>

## Basic Usage of Networking

**All networks are configured within Vagrantfile using the `config.vm.network` method call.**

### Multiple Networks

Multiple networks can be defined by having multiple `config.vm.network` blocks in the Vagrantfile

### Enabling Networks

Networks are automatically configured and enabled after they've been defined in Vagrantfile as part of `vagrant up`, `vagrant reload` or `vagrant reload --provision` process

### Setting Hostname

Hostname of VM can be defined in Vagrantfile by updating the value of `config.vm.hostname`

<br>

## Port Forwarding

Vagrant forwarded ports allow you to access a port on your host machine and have all data forwarded to a port on the guest machine, over either TCP or UDP.

- For example: If the guest machine is running a web server listening on port 80, you can make a forwarded port mapping to port 8080 (or anything) on your host machine. You can then open your browser to localhost:8080 and browse the website, while all actual network data is being sent to the guest.

Play around with `config.vm.network "forwarded_port"` block to define the forwarded port

- Syntax:

    ```ruby
    config.vm.network "forward_port", <option_1>: <value_1>, ..., <option_N>: <value_N>
    ```

- Options available:

    | Option | Data Type for Value | Value to fill in |
    |:---:|:---:|---|
    | `auto_correct` | boolean | By default, it is "false". <br><br> If set to "true", the host port will be changed automatically in case it collides with a port already in use. |
    | `guest` | integer | The port number on the guest (VM) that you want to be exposed on the host. <br> This can be any port. |
    | `guest_ip` | string | The guest IP to bind the forwarded port to. <br> If this is not set, the port will go to every IP interface. <br><br> By default, it is empty. |
    | `host` | integer | The port number on the host that you want to use to access the port on the guest (VM). <br><br> This **must be greater than port 1024** unless Vagrant is running as root (which is not recommended) |
    | `host_ip` | string | The IP on the host you want to bind the forwarded port to. <br> If not specified, it will be bound to every IP. <br><br> By default, this is empty.|
    | `protocol` | string | Either "udp" or "tcp". This specifies the protocol that will be allowed through the forwarded port. <br><br> By default this is "tcp". |
    | `id` | string | Name of the rule (can be visible in VirtualBox). <br> By default this is "protocol""guest" (example : "tcp123").|

You can use `config.vm.usable_port_range` to **define allowed port range assignable by Vagrant when port collision is detected**.

- Syntax:

    ```ruby
    config.vm.usable_port_range = <Port_1>...<Port_2>

    # ... here means to
    # In short, the syntax above means ranging from Port_1 to Port_2
    ```

<br>

## Private Network (Host-only Network)

Vagrant private networks allow you to access your guest machine by some address that is not publicly accessible from the global internet. In general, this means your machine gets an address in the private address space.

You can play around with `config.vm.network "private_network"` block in Vagrantfile.

For more information on the implementation, can refer to this <a href="https://developer.hashicorp.com/vagrant/docs/networking/private_network">link</a>

<br>

## Public Network (Bridged Network)

Vagrant public networks are less private than private networks, and the exact meaning actually varies from provider to provider, hence the ambiguous definition. The idea is that while private networks should never allow the general public access to your machine, public networks can.

You can play around with `config.vm.network "public_network" block in Vagrantfile.

For more information on the implementation, can refer to this <a href="https://developer.hashicorp.com/vagrant/docs/networking/public_network">link</a>

<br>

## Appendix

For more information on Networking with Vagrant, may refer to this <a href="https://developer.hashicorp.com/vagrant/docs/networking">document</a>.