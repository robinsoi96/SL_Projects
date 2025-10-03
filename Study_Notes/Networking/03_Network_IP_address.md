# Network IP Address

## What is an IP Address?

IP address, or Internet Protocol address, is a **unique string of numbers assigned to each device** connected to a computer network that **uses Internet Protocol** for communication.

It **serves as an identifier** that **allows devices to send and receive data over the network**, ensuring that this data reaches the correct destination.

## Types of IP Address

IP addresses can be classified in several ways based on their structure, purpose, and the type of network they are used in.

### Based on `Addressing Scheme` (IPv4 vs IPv6)

1) **IPv4**

    - The most common form of IP address

    - Consists of four sets of numbers separated by dots, where each set of numbers can range from 0 to 255

        - This format can support over 4 billion unique addresses

        - IPv4 address is broken down into 4 octets as shown in the sample diagram below, where each octet represents 8 bits or a byte, can take a value from 0 to 255 [2<sup>8</sup> = 256 combinations]

        <img src="./images/IPv4_Address_Format.png" alt="IPv4 Address Format">
    
    - Each part of the IP address can indicate various aspects of the network configuration, from the network itself to the specific device within that network

        - For most cases, the network part of the address is represented by the first one to three octets, while the remaining section identifies the host (device)

2) **IPv6**

    - Created to deal with shortage of IPv4 addresses

    - Use 128 bits instead of 32, offering a vastly greater number of possible addresses

    - These addresses are expressed as 8 groups of four hexademical digits, where each group representing 16 bits and seperated by colon (`:`)

For more detailed information on the comparison, may refer to this <a href="https://www.geeksforgeeks.org/computer-networks/differences-between-ipv4-and-ipv6/">article</a>.

## Appendix

Reference link:

- <a href="https://www.geeksforgeeks.org/computer-science-fundamentals/what-is-an-ip-address/">What is an IP Address?</a>