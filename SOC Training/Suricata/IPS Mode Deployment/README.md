> /SOCTraining/Suricata/IPS Mode

# Suricata - Network-Based IPS Deployment

## Objectives
- Configure Suricata to run in active IPS mode.
- Integrate Suricata with the Linux kernel's firewall system (IPtables/NFQUEUE) for packet modification and dropping.
- Create and deploy custom rules designed to trigger a drop/reject action.
- Validate the IPS functionality by simulating an ICMP flood attack.
- Ensure stable operation of the IPS module, including configuration file verification.

## Tools Used
- **Suricata IDS/IPS:** The main network security engine.
- **IPtables / NFQUEUE:** The Linux kernel feature used by Suricata to intercept, inspect, and queue packets for active blocking.
- **hping3:** Used to simulate network traffic and attacks for testing the drop functionality.
- **Ubuntu Server:** The host operating system for deployment.

## Steps Performed
1.  **IPS Mode Configuration:**
    - Modified the `suricata.yaml` file to enable IPS mode, typically by configuring the `af-packet` & `nfqueue` section.
    - Ensured the default action was set to `reject` or `drop` for the relevant rule types.

2.  **Firewall Integration (NFQUEUE Setup):**
    - Configured IPtables rules to redirect incoming and/or outgoing traffic from the network interface(s) into the specific NFQUEUE used by Suricata.
    `sudo iptables -I FORWARD -j NFQUEUE --queue-num 0`

3.  **Custom IPS Rule Creation:**
    - Created a specific test rule to detect and drop ICMP traffic using the `drop` action instead of `alert`.

4.  **Service Deployment and Validation:**
    - Restarted the Suricata service to apply the new IPS configuration and rules.
    - Verified Suricata was running correctly in IPS mode by checking system logs or service status.

5.  **Attack Simulation:**
    - Executed an `hping3` command from an external machine targeting the protected network.
    - Observed that traffic was **dropped** and no response was received, confirming the IPS action was successful.

6.  **Log Review:**
    - Monitored `fast.log` to confirm that Suricata logged the **DROP** event for the test rule, verifying that the engine was processing the packet and actively taking the configured action.

## Key Learnings
- **Active Defense Workflow:** Understood the fundamental difference between passive IDS (`alert`) and active IPS (`drop/reject`) modes and the necessary kernel-level integration.
- **NFQUEUE/IPtables Integration:** Learned how to correctly set up IPtables to hand off packets to a userspace program like Suricata via NFQUEUE for inspection and return.
- **Troubleshooting Config:** Gained experience in debugging highly sensitive YAML configuration files, particularly focusing on indentation to resolve complex parsing errors.
- **IPS Validation:** Established a clear process for validating active blocking using targeted traffic generation and log observation.

## Screenshots
Please refer to the attached screenshots in this directory.

![](./Screenshot_20251120_235643.png)

![](./Screenshot_20251121_004356.png)

![](./Screenshot_20251121_004545.png)

![](./Screenshot_20251121_004910.png)

![](./Screenshot_20251121_004935.png)