> /SOCTraining/WinThreatDetection/NetFor&Intrusion

# Windows Network Forensics & Intrusion Analysis

## Objectives

- Analyse endpoint and network artefacts from a compromised machine to reconstruct the full attack chain.

- Trace the initial compromise through a malicious document to stage 2 payload execution and C2 establishment.

- Investigate internal reconnaissance activity conducted by the attacker over the C2 channel.

- Identify the privilege escalation technique used to achieve SYSTEM-level access.

- Uncover post-compromise persistence mechanisms including backdoor user creation and remote access configuration.

## Tools & Resources

- **EvtxEcmd & Timeline Explorer:** For parsing and analysing Sysmon and Windows Event Log artefacts in CSV format.

- **SysmonView:** For visualising correlated Sysmon events and process relationships from a specific execution chain.

- **Event Viewer:** For reviewing raw Windows Event Logs and exporting log data for further analysis.

- **Wireshark:** For deep packet inspection of the captured network traffic.

- **Brim:** For filtering and querying the packet capture to correlate C2 traffic, encoded payloads, and HTTP patterns.

## Steps Performed

Investigated the full compromise chain on the Windows machine from initial document execution through to full system ownership, covering:

- Artefact verification by comparing SHA256 hashes of the provided evidence files prior to analysis.

- Malicious document identification, compromised username and machine name, and the WinWord.exe process ID from Sysmon logs.

- DNS resolution of the malicious domain, the base64 encoded payload executed by the document, and the associated CVE used for remote code execution.

- Stage 2 payload file path written to disk, the autostart execution command triggered on user login, and the SHA256 hash of the downloaded binary.

- C2 domain and port used by the stage 2 payload, confirmed via Sysmon network events and packet capture.

- Malicious payload URL embedded in the document, C2 traffic encoding method, HTTP method, command parameter, polling URL, and the programming language of the compiled binary.

- Decoded C2 traffic to recover the sensitive file password discovered by the attacker and the listening port identified during internal reconnaissance.

- Reverse SOCKS proxy command executed by the attacker, the tool's SHA256 hash and name, and the service used to authenticate with harvested credentials.

- Privilege escalation binary name and hash, the exploited privilege, the secondary binary used to establish an elevated C2 connection, and the port used.

- Two backdoor user accounts created post-SYSTEM access, the missing option from the failed initial creation attempts, and the command used to add an account to the local administrators group.

- Persistence technique executed after account creation, confirmed via Windows Event Logs and packet capture.

## Key Learnings

This investigation specifically demonstrates how a single malicious document can cascade into full domain compromise when detection gaps exist across endpoint and network visibility. Correlating Sysmon process trees with packet capture data is what closes those gaps, connecting encoded payloads to C2 domains, and C2 activity to post-exploitation commands. Artefact verification before analysis, structured process tree tracing, and cross-source event correlation are non-negotiable steps in any incident response workflow.

## Screenshots

Please refer to the attached screenshots in this directory.

#### Malicious document downloaded
![](./temp_1.png)

#### Compromised machine
![](./temp_2.png)

#### Malicious PID
![](./temp_3.png)

#### Malicious domain IPv4
![](./temp_4.png)

#### Base64 encoded string
![](./temp_5.png)

#### Payload executed by document
![](./temp_6.png)

#### Files dropped by the malware
![](./temp_7.png)

#### Shell queries
![](./temp_8.png)

#### User-agent
![](./temp_9.png)

#### Password retrieved by credential harvesting
![](./temp_10.png)

#### Vulnerable port
![](./temp_11.png)

#### Binary establishing reverse proxy
![](./temp_12.png)

![](./temp_13.png)

![](./temp_14.png)

#### Service used for authentication
![](./temp_15.png)

#### Binary for privilege escalation
![](./temp_16.png)

![](./temp_17.png)

![](./temp_18.png)

#### Users added for persistence
![](./temp_19.png)

![](./temp_21.png)

#### Port used for C2
![](./temp_20.png)

#### Persistence with privilege escalation
![](./temp_22.png)


#### Results & Findings
![](./results_1.png)

![](./results_2.png)

![](./results_3.png)

![](./results_4.png)

![](./results_5.png)

![](./results_6.png)

![](./results_7.png)

---
> QXV0aG9yOiBodHRwczovL2dpdGh1Yi5jb20vaGFzaC01NDU=