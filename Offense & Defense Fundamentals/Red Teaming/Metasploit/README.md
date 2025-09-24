> /RedTeaming/Metasploit
# Metasploit

## Objectives
- Learn how to scan target systems using Metasploit.  
- Understand Metasploit modules for vulnerability scanning and exploitation.  
- Generate payloads with `msfvenom` and obtain Meterpreter or shell sessions.  
- Manage sessions and perform basic post-exploitation tasks.

## Tools Used
- **Metasploit Framework (msfconsole)** — exploitation framework.  
- **msfvenom** — payload generator/encoder.  
- **Nmap (integrated)** — port/service discovery within msfconsole.  
- **Metasploit wordlists** — `/usr/share/wordlists/MetasploitRoom/MetasploitWordlist.txt`.

## Steps Performed
1. **Port Scanning**  
   - Used Metasploit portscan auxiliary modules and ran integrated `nmap` for host discovery.

2. **Service Enumeration**  
   - Enumerated services (SMB, NetBIOS, RDP, HTTP, etc.) using appropriate auxiliary scanners (e.g., `smb_version`, `smb_enumshares`).

3. **Vulnerability Scanning**  
   - Ran vulnerability scanners (example: `scanner/smb/smb_ms17_010`) to find low-hanging fruit.

4. **Exploitation**  
   - Selected exploit modules (example: `exploit/windows/smb/ms17_010_eternalblue`), picked compatible payloads, configured target parameters and listener (`LHOST`/`LPORT`), and executed the exploit to obtain a shell.

5. **Session Management**  
   - Managed active sessions (`sessions -l` / `sessions -i <id>`), backgrounded sessions for multitasking, and upgraded shells to Meterpreter where applicable.

6. **Payload Generation (msfvenom)**  
   - Created payloads for different targets/formats (Windows `.exe`, Linux `.elf`, `php` web shells, Python raw, etc.) and used a handler (multi/handler) to catch callbacks.

## Key Learnings
- Metasploit integrates scanning, exploitation, payloads, and session handling into a single workflow.  
- Accurate service fingerprinting improves the likelihood of successful exploitation.  
- `msfvenom` provides flexibility to generate payloads tailored to the target environment.  
- Proper listener/handler configuration is required to receive reverse shells or Meterpreter callbacks.  
- Session management (backgrounding, interacting, upgrading) enables parallel tasks and persistence.

## Screenshots
Please refer to the attached screenshots in this directory

![](./Post-Exploitation%20Challenge/Screenshot_20250812_010753.png)

![](./Post-Exploitation%20Challenge/Screenshot_20250812_010828.png)

![](./Post-Exploitation%20Challenge/Screenshot_20250812_010848.png)

![](./Windows%20Hacking%20-%20Eternal%20Blue/Screenshot_20250812_170645.png)

![](./Windows%20Hacking%20-%20Eternal%20Blue/Screenshot_20250812_170656.png)

![](./Windows%20Hacking%20-%20Eternal%20Blue/Screenshot_20250812_174036.png)

![](./Windows%20Hacking%20-%20Eternal%20Blue/Screenshot_20250812_174050.png)

![](./Windows%20Hacking%20-%20Eternal%20Blue/Screenshot_20250812_175058.png)

![](./Windows%20Hacking%20-%20Eternal%20Blue/Screenshot_20250812_175109.png)