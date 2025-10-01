 
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

![Nmap Scan](./nmap_scans%20%201.png)

![](./nmap_scans%20%202.png)

![](./nmap_scans%20%203.png)