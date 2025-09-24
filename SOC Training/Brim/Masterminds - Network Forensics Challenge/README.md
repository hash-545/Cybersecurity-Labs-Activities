> /SOCTraining/Brim/Masterminds

# Masterminds - Network Forensics Challenge

## Objectives
The objective of this lab was to investigate compromises in the Finance department at Pfeffer PLC using network captures.  
Primary goals were to identify victim endpoints, malicious domains and servers, downloaded binaries, Command-and-Control (C2) activity, and to perform attribution using available threat intelligence.

## Tools Used
- **Brim** — PCAP ingestion, Zeek log exploration, queries & correlation  
- **Zeek** — connection, DNS, HTTP and files logs for forensic evidence  
- **Suricata** — IDS alerts for detection signals and enrichment  
- **VirusTotal** — binary and domain intelligence  
- **ThreatFox / URLhaus** — actor / distribution correlation and malware tracking  

## Steps Performed
1. **Data Ingestion & Triage**
   - Imported endpoint network captures into Brim and confirmed Zeek/Suricata logs were generated.
   - Reviewed timeline and pool details to prioritize hosts and time ranges.

2. **Infection A**
   - Located the victim host and enumerated its HTTP activity (noting both failed `404` requests and a successful transfer with recorded response size).
   - Counted DNS request variants to the suspicious domain.
   - Retrieved the HTTP URI paths contacted and extracted the downloaded executable.
   - Correlated file hash and artefacts with VirusTotal to identify the malware family.

3. **Infection B**
   - Identified the victim IP and the remote POST endpoint receiving exfiltration-like requests.
   - Counted the number of POST connections to the endpoint.
   - Extracted the binary download URI and resolved the hosting IP.
   - Reviewed Suricata alerts (two "Network Trojan" alerts) and recorded source/destination IPs.
   - Cross-referenced `.top` domain activity with URLhaus to identify the stealer/Trojan involved.

4. **Infection C**
   - Located the victim machine and identified three sequential C2 domains used to deliver binaries.
   - Resolved IP addresses for each C2 domain and counted unique DNS queries to the first domain.
   - Counted total binaries downloaded from the domain and captured the User-Agent used for downloads.
   - Measured total DNS connections in the capture.
   - Used OSINT (safe search practices) to attribute the worm family associated with the first domain.

5. **Correlation & Attribution**
   - Cross-correlated Zeek logs, Suricata alerts, and external intelligence (VirusTotal, ThreatFox, URLhaus).

## Key Learnings
- Combining **Brim + Zeek + Suricata** yields effective visibility for multi-stage compromises (phishing/USB → download → C2 → malware execution).  
- Correlating logs across layers (DNS, HTTP, connections, files) is crucial to reconstruct attack chains.  
- External intelligence (VirusTotal, ThreatFox, URLhaus) is essential for naming malware and linking infrastructure to known campaigns.  
- Phishing and removable-media infections remain high-risk initial access vectors; log evidence often shows subtle indicators that require careful querying.  

## Screenshots as Proof of Work
Please refer to attached screenshots in this directory

![](./Infection_A%20-%201.png)

![](./Infection_A%20-%202.png)

![](./Infection_A%20-%203.png)

![](./Infection_A%20-%204.png)

![](./Infection_A%20-%205.png)

![](./Infection_A%20-%206.png)

![](./Infection_B%20-%201.png)

![](./Infection_B%20-%202.png)

![](./Infection_B%20-%203.png)

![](./Infection_B%20-%204.png)

![](./Infection_C%20-%201.png)

![](./Infection_C%20-%202.png)

![](./Infection_C%20-%203.png)

![](./Infection_C%20-%204.png)

![](./Infection_C%20-%205.png)