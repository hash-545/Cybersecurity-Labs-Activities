> /SOCTraining/Suricata

# Suricata IDS

## Objectives of the Lab
The objective of this lab was to practice **network traffic analysis and detection engineering** using Suricata.  
By reviewing PCAP traffic, we created a custom Suricata rule to detect HTTP activity to the geolocation API **ip-api** and validated it with Dalton.  

## Tools Used
- **Suricata** – IDS engine for traffic analysis and rule creation  
- **Wireshark** – PCAP review and protocol inspection  
- **Dalton** – Web-based platform for validating Suricata rules against PCAPs  

## Steps Performed
1. **PCAP Analysis with Wireshark**  
   - Opened `ip-check.pcapng` and reviewed packet details.  
   - Identified protocol as HTTP with source ($HOME_NET) and destination ($EXTERNAL_NET).  
   - Determined direction `$HOME_NET any -> $EXTERNAL_NET any`.  

2. **Rule Creation**  
   - Defined rule action as `alert`.  
   - Constructed header:  
     ```
     http $HOME_NET any -> $EXTERNAL_NET any
     ```
   - Added options using sticky buffers to match:  
     - HTTP method = GET  
     - URI = /json  
     - Host = ip-api.com  
   - Final rule:  
     ```
     alert http $HOME_NET any -> $EXTERNAL_NET any \
     (msg:"TryHackMe - HTTP Query to ip-api"; flow:established,to_server; \
     http.method; content:"GET"; http.uri; content:"/json"; http.host; content:"ip-api.com"; \
     reference:url,ip-api.com/docs; classtype:misc-activity; sid:1000000; rev:1;)
     ```

3. **Testing with Dalton**  
   - Uploaded `ip-check.pcapng` and custom rule.  
   - Disabled predefined ruleset.  
   - Verified that the rule triggered alerts for HTTP traffic to ip-api.  

## Key Learnings
- Suricata rules consist of **action, header, and options**.  
- Sticky buffers (`http.method`, `http.uri`, `http.host`) enable precise HTTP traffic detection.  
- Dalton is effective for validating Suricata rules before live deployment.  
- This lab focused on **analysis and detection only**, not active response actions like blocking or blacklisting.  

## Screenshots
Please refer to the attached screenshots in this directory.