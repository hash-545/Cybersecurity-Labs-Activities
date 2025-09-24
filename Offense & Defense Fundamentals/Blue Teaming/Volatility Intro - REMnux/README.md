> /BlueTeaming/Volatility
# Volatility Intro - REMnux

## Objective
The objective of this lab is to practice **preprocessing digital evidence** using **Volatility 3** and the Linux `strings` utility. The focus is on extracting key artifacts from a Windows memory image (`wcry.mem`) to prepare the data for further forensic investigation.

## Tools Used
- **Volatility 3** – memory forensics framework to extract processes, DLLs, and artifacts from RAM images  
- **REMnux** – Linux distro preloaded with forensics and reverse engineering tools  
- **strings** – utility to extract ASCII and Unicode text from binary files  

## Steps Performed
1. **Volatility Plugins**
   - Ran multiple **Windows plugins** such as:
     - `PsTree` – shows process hierarchy  
     - `PsList` – lists active processes  
     - `CmdLine` – extracts process command-line arguments  
     - `FileScan` – scans for file objects  
     - `DllList` – enumerates loaded modules  
     - `PsScan` – scans for hidden or terminated processes  
     - `Malfind` – identifies suspicious memory regions with injected code  
   - Saved each plugin’s output into separate text files for structured evidence storage.  

2. **Batch Preprocessing**
   - Automated preprocessing by running all plugins in a loop.  
   - Generated **seven structured text files**, each containing results for a specific plugin.  

3. **String Extraction**
   - Used the `strings` utility to extract:  
     - ASCII strings  
     - Unicode (16-bit little endian) strings  
     - Unicode (16-bit big endian) strings  
   - Produced three text files containing extracted strings for further keyword searching.  

## Key Learnings
- **Volatility 3** is a powerful framework for extracting forensic artifacts from memory dumps.  
- Preprocessing with multiple plugins helps create structured evidence files for efficient analysis.  
- The `strings` utility complements memory forensics by extracting readable text in different encodings.  
- Preparing evidence in bulk saves significant time for analysts during deep-dive investigations.  

## Screenshots
Please refer to the attached screenshots in this directory

![](./Volatility%20intro.png)