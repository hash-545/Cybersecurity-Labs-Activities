> /SOCTraining/Zeek/NetworkAnalysis
# Zeek: Network Security Monitoring

## Objectives
The objective of this lab was to practice **network traffic analysis and threat detection** using **Zeek**. By working with Zeek pre-written scripts, custom signatures, and log analysis, we explored event-driven monitoring, alert generation, file extraction, threat intelligence correlation, and package usage to understand how analysts detect and investigate network anomalies.

## Tools Used
- **Zeek** – event-driven network monitoring and traffic analysis framework  
- **Zeek Scripts** – for DHCP hostnames, connection monitoring, FTP brute-force detection, file analysis, and intelligence correlation  
- **Custom Signatures** – created to detect specific events like FTP admin login attempts and HTTP cleartext passwords  
- **Zeek Packages** – e.g., `zeek-sniffpass` for password detection, `geoip-conn` for geolocation  
- **Linux CLI Utilities** (`grep`, `awk`, `sort`, `uniq`, `zeek-cut`) – for log inspection and data correlation  
- **Packet Captures (pcap)** – sample network traffic for analysis  

## Steps Performed
1. **Traffic Analysis**
   - Ran Zeek on provided pcaps with pre-written scripts (e.g., `dhcp-hostname.zeek`) to extract DHCP hostnames.  
   - Investigated terminal outputs and verified correct event extraction.

2. **Signature Development & Testing**
   - Wrote custom signatures for detecting FTP admin login attempts and HTTP cleartext passwords.  
   - Optimized FTP signature to detect all brute-force attempts using the 530 response code.  
   - Ran Zeek with both custom and pre-written signatures and analyzed `signatures.log` and `notice.log` for alerts.

3. **Script Execution & Event Correlation**
   - Used pre-written scripts for:
     - Connection monitoring (`new_connection` event)  
     - FTP signature correlation (`signature_match` event)  
     - File framework: hashing and extraction (`hash-all-files.zeek`, `extract-all-files.zeek`)  
     - Intelligence framework: domain detection (`intel.log`)  
   - Verified log outputs and correlated connection IDs across multiple logs.

4. **Package Installation & Usage**
   - Installed and used Zeek packages via `zkg`, including:
     - `zeek-sniffpass` to detect HTTP cleartext passwords  
     - `geoip-conn` to add geolocation metadata to connection logs  
   - Demonstrated multiple ways to load packages: via script, full path, or package name.

5. **Log Analysis**
   - Analyzed key Zeek logs: `conn.log`, `files.log`, `notice.log`, `signatures.log`, `intel.log`.  
   - Extracted and correlated suspicious events and files, including detection of an `.exe` file transmitted over HTTP.  
   - Investigated IP addresses, connection metadata, and event messages to confirm alerts.

## Key Learnings
- Zeek’s **event-driven framework** allows flexible monitoring and analysis of network traffic.  
- Pre-written scripts simplify detection of common network events and anomalies.  
- Custom signatures enhance monitoring capabilities for specific scenarios like FTP brute-force attacks or cleartext passwords.  
- Log correlation across `conn.log`, `files.log`, `notice.log`, and `intel.log` is essential to reconstruct network events.  
- Zeek packages extend functionality, e.g., geolocation enrichment or password detection, reducing the need for custom development.  
- Effective network threat detection combines **signatures, scripts, packages, and log analysis** for comprehensive monitoring.

## Screenshots
Please refer to the attached screenshots in this directory.