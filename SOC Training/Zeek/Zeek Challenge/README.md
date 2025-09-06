> /SOCTraining/Zeek/ZeekChallenge
# Zeek Traffic Analysis Lab

## Objectives of the Lab
The objective of this lab was to practice **network traffic analysis** using **Zeek** by investigating captured traffic under different alert scenarios. The focus was on analyzing logs, detecting anomalies, and observing attacker behavior rather than taking response actions.  
Scenarios covered:  
1. **DNS Tunneling** – investigating anomalous DNS queries.  
2. **Phishing Attempt** – analyzing HTTP logs and malicious payloads.  
3. **Log4J Exploitation Attempt** – observing exploitation activity with signatures.  

## Tools Used
- **Zeek Network Security Monitor** – for parsing PCAPs and generating logs.  
- **PCAP Files** – provided as exercise material.  
- **Zeek Logs** (`dns.log`, `conn.log`, `http.log`, `signature.log`).  
- **VirusTotal** – for malicious file and domain investigation.  
- **CyberChef** – for decoding base64 commands and other data transformations.  

## Steps Performed
### Case 1: DNS Tunneling Detection
1. Analyzed `dns-tunneling.pcap` with Zeek.  
2. Reviewed **dns.log** for IPv6-related DNS records.  
3. Checked **conn.log** for the longest connection duration.  
4. Filtered unique DNS queries in **dns.log** to assess query patterns.  
5. Identified the **source host IP** involved in abnormal DNS activity.  

### Case 2: Phishing Attempt Analysis
1. Identified the **suspicious source IP** from logs (converted to defanged format).  
2. Investigated **http.log** for the malicious domain address (defanged).  
3. Submitted the malicious document to **VirusTotal** and identified its file type.  
4. Queried the extracted malicious **.exe** file in VirusTotal and retrieved its filename.  
5. Investigated the contacted domain of the **.exe** in VirusTotal (defanged format).  
6. Analyzed **http.log** to determine the request name of the downloaded .exe payload.  

### Case 3: Log4J Exploitation Attempt
1. Processed `log4shell.pcapng` with Zeek and the `detection-log4j.zeek` script.  
2. Analyzed **signature.log** for the total number of detection hits.  
3. Investigated **http.log** to identify the scanning tool used.  
4. Observed the **exploit file extension** in **http.log**.  
5. Decoded base64 payloads in **log4j.log** using **CyberChef** and determined the created file name.  

## Key Learnings
- Zeek provides detailed visibility into **network events** and anomalies across DNS, HTTP, and custom signatures.  
- **DNS tunneling analysis** highlights abnormal query frequency and helps trace the source host.  
- **Phishing activity** can be confirmed by correlating HTTP logs with VirusTotal findings.  
- **Log4J exploitation attempts** can be observed and validated through Zeek signatures and decoded payloads.  
- Zeek excels at **log analysis and observation**, making it a strong tool for security monitoring and forensic investigation.  

## Screenshots
Please refer to the attached screenshots in this directory.