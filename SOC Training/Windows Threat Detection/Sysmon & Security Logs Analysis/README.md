> /SOCTraining/WindowsThreatDetection/Sysmon&SecurityLogsAnalysis
# Windows Sysmon & Security Analysis

## Objectives
- Understand how to locate and interpret key Windows Event Logs.
- Analyze Security logs for authentication-based attacks such as brute force and RDP abuse.
- Investigate user account manipulation using Windows event IDs.
- Leverage Sysmon logs for process, network, and persistence analysis.
- Examine PowerShell history to uncover attacker activity not visible in standard logs.

## Tools & Resources
- **Event Viewer:** Analysis of Security and Sysmon EVTX logs.
- **Sysmon:** Process creation, network, file, and registry monitoring.
- **Windows Security Logs:** Authentication and user management investigation.
- **PowerShell:** Command tracking for post-compromise activity.
- **Manual Log Correlation:** Logon ID and Process ID cross-referencing with other malicious activity.

## Steps Performed
- Reviewed `evtx` logs in Event Viewer.
- Filtered Security logs for:
  - **Failed Logon** to detect brute-force attempts.
  - **Successful Logon** to identify malicious RDP access (Logon Type 10).
- Identified attacker IP responsible for brute force activity.
- Determined compromised user account.
- Correlated Logon ID from 4624 event for session tracking.
- Reviewed user management events:
  - User creation
  - Added to privileged group
- Identified backdoor account creation and group privilege escalation.
- Verified Logon ID consistency across login and account modification events.
- `Sysmon.evtx` to analyze:
  - **Process Creation** for browser usage and malware execution.
  - **Network** connections and DNS resolution.
  - **File creation** and **registry** persistence mechanisms.
- Identified:
  - Web browser used by compromised user.
  - Malicious file downloaded.
  - Download URL.
  - Persistence file dropped on the host.
  - Command & Control (C2) server IP and port.
  - Corresponding malicious domain.
- Reviewed PowerShell history file:
  - Identified first executed command.
  - Retrieved execution date.
  - Located hidden flag in user PowerShell history.

## Key Learnings
This activity demonstrated how critical Windows logging is for SOC operations and incident response. Authentication logs (4624/4625) are essential for detecting brute-force and RDP-based compromises, while user management events reveal persistence and privilege escalation attempts. Sysmon significantly enhances visibility into process execution, malware behavior, persistence, and C2 communication. Finally, PowerShell history provides valuable insight into attacker commands that are not visible in traditional process logs.

## Screenshots
Please refer to the attached screenshots in this directory.


#### **IP attempting brute-force**
![](./sec_logs1.png)


#### **Compromised User**
![](./sec_logs2.png)


#### **Malicious user creation & session logon ID**
![](./sec_logs3.png)


#### **Backdoor group**
![](./sec_logs4.png)


#### **Web browser used to download malicious file**
![](./sec_logs5.png)


#### **Malicious file**
![](./sec_logs6.png)


#### **Malware URL**
![](./sec_logs7.png)


#### **File created for persistence**
![](./sec_logs8.png)


#### **C2 server pinged by malware**
![](./sec_logs9.png)


#### **Malicious domain involved**
![](./sec_logs10.png)


#### **PS commands executed by attacker**
![](./sec_logs11.png)


#### **Date of execution**
![](./sec_logs12.png)


#### **Hidden flag in history**
![](./sec_logs13.png)


#### **Results**
![](./result1.png)


![](./result2.png)


![](./result3.png)


![](./result4.png)


![](./result5.png)


---

> QXV0aG9yOiBodHRwczovL2dpdGh1Yi5jb20vaGFzaC01NDU=