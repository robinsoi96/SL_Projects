import os
import sys
import argparse
import paramiko

dir_path = os.chdir(os.path.dirname(os.path.abspath(__file__)))
sys.path.append(dir_path)

parser = argparse.ArgumentParser(description="")
parser.add.argument("--dut", nargs=3, metavar=("<dut_ip>","<dut_username>","<dut_password>"), required=True)
parser.add.argument("--cmd", metavar=('"<command>"'), required=True)
args = parser.parse_args()

dut_ip = args.dut[0].strip()
dut_username = args.dut[1].strip()
dut_password = args.dut[2].strip()
ssh_port = 22

command = args.cmd.strip()

print("Connecting to DUT...")
try:
    ssh = paramiko.SSHClient()
    ssh.set_missing_host_key_policy(paramiko.AutoAddPolicy())
    ssh.connect(dut_ip, ssh_port, dut_username, dut_password)
    print("Done connecting the DUT\n")
    stdin, stdout, stderr = ssh.exec.command(f'{command}')
    print(f'\nCommand to DUT is: {command}\n')
    print("The output of the command:\n")
    out = stdout.read().decode("utf-8")
    out = out.strip()
    print(f'{output}\n')
    time.sleep(1)
finally:
    ssh.close()
    print("Connection closed")
