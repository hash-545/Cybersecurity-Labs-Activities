> /SOCTraining/Splunk/Malicious Download

# Splunk - Malicious Download Investigation

## Objectives
- Investigate suspicious process execution on a host from the HR department.
- Identify malicious activity using Windows Logs.
- Correlate process execution with network behavior to detect adversary activity.  
- Understand techniques like LOLBINS for payload delivery and post-exploitation activities.  

## Tools Used
- Splunk (SIEM solution)  
- Windows Event Logs

## Steps Performed
1. Reviewed Event logs ingested into the `win_eventlogs` index.  
2. Counted total logs for March 2022 to assess the scale of activity.
3. Identified potential imposter accounts based on unusual log entries.  
4. Filtered logs to focus on HR department users.  
5. Tracked execution of scheduled tasks to pinpoint the compromised host.  
6. Investigated usage of system processes (LOLBIN) to download payloads.  
7. Extracted payload download details: date, file name, source site, and C2 server URL.  
8. Examined downloaded files for malicious patterns.

## Key Learnings
- Event logs are crucial for tracking process execution and detecting suspicious activity.
- Adversaries often use legitimate system processes (LOLBINs) to evade detection.
- Correlating user activity across network segments helps identify the source and scope of compromise.
- Post-exploitation analysis can reveal the payload origin, file artifacts, and malicious patterns for threat hunting.

## Screenshots
Please refer to the screenshots for more details

![](./Screenshot%20from%202025-10-29%2022-46-23.png)

![](./Screenshot%20from%202025-10-29%2022-53-22.png)

![](./Screenshot%20from%202025-10-29%2023-13-43.png)

![](./Screenshot%20from%202025-10-29%2023-14-35.png)

![](./Screenshot%20from%202025-10-29%2023-15-56.png)

![](./Screenshot%20from%202025-10-29%2023-19-31.png)

![](./Screenshot%20from%202025-10-29%2023-21-13.png)