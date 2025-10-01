 
> /SOCTraining/Wireshark/Malicious Traffic Analysis
# Wireshark: Malicious Traffic Analysis  

## Objectives of the Lab  
- Analyze different types of malicious and suspicious traffic at the packet level  
- Detect scanning, spoofing, tunneling, and cleartext credential leaks  
- Apply advanced Wireshark filters for HTTP, FTP, Telnet, and DNS traffic  
- Gain hands-on practice identifying attacker techniques

## Tools Used  
- Wireshark (filters, protocol statistics, conversation analysis)  
- Supporting OSINT resources (for IOC verification)  

## Steps Performed  
- Applied filters to detect **Nmap scans** and reconnaissance attempts.  
- Investigated **ARP spoofing/poisoning traffic** using ARP request/reply analysis.  
- Analyzed **ICMP and DNS tunneling** behaviors to detect covert channels.  
- Reviewed **HTTP traffic** for suspicious URIs and payloads.  
- Extracted **cleartext credentials** from FTP and Telnet sessions.  
- Identified **suspicious domains and IPs** contacted during the session.  

## Key Learnings  
- Learned how to differentiate between normal scanning vs. malicious probing.
- Gained experience detecting **MITM techniques** such as ARP spoofing.
- Practiced uncovering covert communication channels via tunneling.
- Strengthened skills in filtering protocols to reveal credential leaks.  
- Understood how packet-level forensics supports threat hunting and incident response.  

## Screenshots  
Please refer to the attached screenshots in this directory.  

## Nmap Scans Detection
![](./nmap_scans%20%201.png)

![](./nmap_scans%20%202.png)

![](./nmap_scans%20%203.png)

## ARP Poisoning & MITM Detection
![](./ARP_poisoning%20&%20MITM%201.png)

![](./ARP_poisoning%20&%20MITM%202.png)

![](./ARP_poisoning%20&%20MITM%203.png)

## Host Identification
![](./dhcp_netbios_kerberos%201.png)

![](./dhcp_netbios_kerberos%202.png)

![](./dhcp_netbios_kerberos%203.png)

![](./dhcp_netbios_kerberos%204.png)

![](./dhcp_netbios_kerberos%205.png)

![](./dhcp_netbios_kerberos%206.png)

## Tunneling Traffic: DNS & ICMP
![](./dns%20tunneling%20traffic%201.png)

![](./dns%20tunneling%20traffic%202.png)

## FTP Analysis
![](./ftp_analysis%201.png)

![](./ftp_analysis%202.png)

![](./ftp_analysis%203.png)

## HTTP Analysis
![](./http_traffic%201.png)

![](./http_traffic%202.png)

![](./http_traffic%203.png)

![](./http_traffic%204.png)

![](./http_traffic%205.png)

![](./http_traffic%206.png)

## Decrypting TLS & HTTPS
![](./TLS%20&%20https%201.png)

![](./TLS%20&%20https%202.png)

![](./TLS%20&%20https%203.png)

## Cleartext Credentials Hunt
![](./Cleartext%20Creds%20Hunt%201.png)

![](./Cleartext%20Creds%20Hunt%202.png)

![](./Cleartext%20Creds%20Hunt%203.png)

## IPFW in wireshark
![](./IPFW%20Rules%201.png)

![](./IPFW%20Rules%202.png)