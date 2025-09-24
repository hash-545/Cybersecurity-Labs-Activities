> /BlueTeaming/DigitalForensics/
# Digital Forensics

## Objectives
- Understand the **NIST four-phase framework** for digital forensics: **Collection, Examination, Analysis, and Reporting**.  
- Explore different **types of digital forensics** (computer, mobile, network, database, cloud, email).  
- Learn **evidence acquisition methods** (authorization, chain of custody, write blockers).  
- Gain hands-on practice with forensic tools for **disk and memory imaging** as well as **metadata analysis**.  
- Apply knowledge in simulated investigations, including analyzing PDF metadata and photo EXIF data.  


## Tools Used
- **pdfinfo** – Extract metadata from PDF files.  
- **ExifTool** – Extract metadata (EXIF data) from images.  


## Steps Performed
1. Studied the **NIST four phases**: Collection → Examination → Analysis → Reporting.  
2. Studied forensic evidence types and secure acquisition practices (authorization, chain of custody, write blockers).  
3. Extracted PDF metadata using `pdfinfo` to identify creation details.  
4. Retrieved photo EXIF metadata with `exiftool`, including **GPS coordinates**, to determine location.  


## Key Learnings
- Digital forensics follows a **structured methodology** to ensure evidence integrity and admissibility.  
- Proper **authorization and chain of custody** are critical for legal reliability.  
- Disk and memory imaging provide **complementary evidence** (persistent vs. volatile).  
- Metadata (documents, images) can reveal **hidden details** such as author, software used, timestamps, and geolocation.  
- Tools like FTK Imager, Autopsy, Volatility, and ExifTool are foundational in digital forensic investigations.  


## Screenshots
Please refer to the screenshots attached in this directory
![](./Image%20&%20pdf%20analysis.png)