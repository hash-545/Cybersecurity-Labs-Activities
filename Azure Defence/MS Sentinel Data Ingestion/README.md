> /Azure Defence/MS Sentinel Deployment and Data Ingestion

# MS Sentinel Deployment and Data Ingestion

## Introduction

Microsoft Sentinel requires security data ingestion before it can detect threats and correlate security events. This lab focuses on configuring the ingestion pipeline by deploying Content hub solutions and connecting data connectors to bring security telemetry into the Log Analytics workspace.

## Context

A company has recently deployed Microsoft Sentinel but has no configured data sources. As a Microsoft Security Analyst, the task is to enable security monitoring by installing required Content hub solutions and connecting data connectors for Microsoft security services and threat intelligence sources.

## Workflow

### Understanding Microsoft Sentinel Data Ingestion

Microsoft Sentinel uses data connectors to ingest logs from Microsoft services, third-party solutions, and infrastructure components.

Content hub solutions provide packaged security content that can include:

- Data connectors for log ingestion
- Analytics rules for threat detection
- Workbooks for visualisation
- Playbooks for automated response

#### Content Hub for Solutions & Standalone Packages
![Screenshot24](./Screenshot%20(24).png)

### Deploying a Content Hub Solution

For this lab, the Microsoft Entra ID solution is installed from the Content hub to deploy identity-focused security content into the Sentinel workspace.

Microsoft Entra ID is Microsoft's cloud-based identity and access management (IAM) service. It helps organisations manage user identities, authentication, and access control across cloud and hybrid environments.

The Microsoft Entra ID solution enables Microsoft Sentinel to monitor identity-related activities by providing:

- A data connector for ingesting Entra ID audit and sign-in logs
- Analytics rules for detecting suspicious identity behaviour
- Workbooks for visualising authentication and access activity
- Playbooks for automated response actions

#### Entra ID solution with add-ons
![Screenshot23](./Screenshot%20(23).png)

### Configuring Data Connectors

After installing a Content hub solution, the associated data connector must be configured before log ingestion begins.

The connector configuration page provides:

- Connector description
- Supported data types
- Required permissions
- Configuration steps

#### Connected status is shown in green bar
![Screenshot26](./Screenshot%20(26).png)

### Connecting Threat Intelligence Data

The Threat Intelligence Content hub solution is installed to enable the ingestion of external threat intelligence data into Microsoft Sentinel.

Threat intelligence provides security teams with information about known malicious activity, helping analysts identify and investigate potential threats more effectively. In Microsoft Sentinel, this data can be used to enrich investigations by correlating observed activity with known Indicators of Compromise (IOCs).

The Microsoft Defender Threat Intelligence connector is configured to import threat intelligence data into Sentinel, including indicators such as malicious IP addresses, domains, and other threat artefacts associated with suspicious activity.

Once connected, the ingested intelligence populates the `ThreatIntelligenceIndicator` table within the `Log Analytics workspace (LAW)`, allowing Sentinel analytics rules and investigations to leverage this information during threat detection and response.

#### The Microsoft Defender Threat Intelligence Solution
![Screenshot25](./Screenshot%20(25).png)

## Findings

Microsoft Sentinel separates content deployment and data ingestion into different stages. Installing a Content hub solution deploys the required components, but data connectors must still be configured and connected before Sentinel receives security data.

The Microsoft Defender Threat Intelligence connector successfully establishes a connection and enables threat intelligence data ingestion into the ThreatIntelligenceIndicator table within the Log Analytics workspace.

Once connector is configured, it starts logging and becomes active within 10 to 15 minutes. Then, you get the updates on your dashboard and can also be verified form `Data Connector Page`.

![Screenshot](./Screenshot%202026-09-01%20021714.png)

---

## Tools & Resources

**Microsoft Sentinel** provides cloud-native SIEM capabilities for collecting, analysing, and correlating security data.

**Microsoft Azure Portal** manages Sentinel workspaces, Content hub solutions, and data connector configurations.

**Log Analytics Workspace** stores and queries security telemetry ingested by Microsoft Sentinel.

## Key Learnings

Microsoft Sentinel relies on data connectors to ingest security telemetry, while Content hub solutions simplify deployment by packaging required security content. Understanding connector configuration and permissions is essential for building an effective cloud security monitoring environment.
---

> QXV0aG9yOiBodHRwczovL2dpdGh1Yi5jb20vaGFzaC01NDU=