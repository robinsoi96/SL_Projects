# SSH with Python [Dummy]

The script provided in this folder is just a dummy script to perform SSH connection and execute command to the DUT (Device Under Test) under the same network.

Execute the command as below:

```
python3 ssh_dummy_sample.py --dut <dut_ip_address> <dut_username> <dut_password> --cmd <command>
```

If the all value of the arguments are correctly set, you will see the output as shown below:

```
Connecting to DUT...
Done connecting the DUT


Command to DUT is: <command>

The output of the command:

<output of the command>

Connection closed
```
