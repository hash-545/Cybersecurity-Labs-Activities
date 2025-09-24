> /BlueTeaming/Snort - IDS
# IDS Fundamentals with Snort

## Objective
Learn the fundamentals of Intrusion Detection Systems (IDS), their types, and hands-on usage of **Snort** to detect suspicious activity using built-in and custom rules.

## Tools Used
- **Snort** – open-source IDS for real-time traffic analysis  
- **PCAP files** – used for forensic traffic analysis  

## Key Concepts
- **HIDS vs NIDS**  
  - HIDS: Host-based monitoring on individual systems  
  - NIDS: Network-wide monitoring for all traffic  

- **Detection Methods**  
  - Signature-Based: Matches known attack patterns (fast, but misses zero-days)  
  - Anomaly-Based: Detects deviations from normal behavior (can find zero-days, but may create false positives)  
  - Hybrid: Combines both approaches  

- **Snort Modes**  
  - Packet Sniffer: Displays traffic without detection  
  - Packet Logging: Stores traffic in PCAP format for later analysis  
  - NIDS Mode: Monitors in real-time and alerts on rule matches  

## Steps Performed
1. **Exploring Snort Config**  
   - Checked `/etc/snort/` for rule files and configuration.  

2. **Creating Custom Rule**  
   - Added an ICMP detection rule in `local.rules`:  

3. **Testing the Rule**  
   - Ran Snort in NIDS mode on loopback interface.  
   - Pinging `127.0.0.1` triggered the **Loopback Ping Detected** alert.  

4. **Running Snort on PCAP**  
   - Used Snort to analyze historical traffic in `Intro_to_IDS.pcap`.  
   - Detected malicious activity from the captured file.  

## Key Learnings
- IDS can be deployed **host-based** or **network-based** depending on visibility needs.  
- **Signature-based detection** is efficient for known threats, while **anomaly-based** helps catch unknown ones.  
- **Snort** is versatile: it can sniff, log, or act as a full IDS with custom rules.  
- Writing custom rules allows fine-tuned detection of specific attack patterns.  

## Screenshots
Please refer to the attached screenshots in this directory

![](./Snort%20Fundamentals%20Lab.png)