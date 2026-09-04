> /AWS Defence/Cloud Storage Intro

# AWS Cloud Storage: Understanding S3, EBS, and EFS

## Introduction

Storage is one of the foundations of any cloud environment. Applications constantly generate data, from user uploads and logs to databases and configuration files. In AWS, choosing the correct storage service directly affects availability, scalability, cost, and security.

AWS provides three primary storage models:

- Object Storage through Amazon S3
- Block Storage through Amazon EBS
- File Storage through Amazon EFS

Each service solves a different problem. Understanding where each one fits is essential when designing and securing cloud infrastructure.

---

## Storage Models in AWS

### Amazon S3: Object Storage

Amazon S3 stores data as objects inside buckets. Unlike traditional file systems, S3 does not use a folder hierarchy. Instead, it uses object keys that create a folder-like structure.

For example:

```
logs/2026/january/access.log

```

is a single object with a key named `logs/2026/january/access.log`.

S3 is commonly used for:

- Backups
- Application uploads
- Cloud logs
- Static websites
- Data archives

Since S3 buckets are accessible through APIs, the security model relies heavily on identity permissions and bucket policies.

A simple misconfiguration, such as allowing public access to a bucket containing sensitive files, can expose an entire dataset.

---

## Exploring S3 Buckets

The lab environment contains a preconfigured S3 bucket. After accessing the AWS Console, the first step is identifying available storage resources.

The S3 dashboard provides an overview of buckets within the account.

Using AWS CLI provides the same information programmatically:

```bash
aws s3 ls
```

After identifying the bucket, its contents can be explored. The logs directory contains an access log file:

```bash
aws s3 ls s3://storage-lab-bucket/logs/
```

![](./Screenshot%202026-09-05%20014533.png)


One of the most important security checks when working with S3 is verifying that public access is disabled.

```bash
aws s3api get-public-access-block --bucket storage-lab-bucket
```
![](./Screenshot%202026-09-05%20015426.png)


The returned configuration confirms that public ACLs and bucket policies are blocked.

For production environments, S3 should follow a least-privilege approach:

* Enable Block Public Access
* Prefer bucket policies over ACLs
* Enable encryption by default
* Restrict IAM permissions to required buckets and prefixes
* Enable versioning for critical data

---

# Amazon EBS: Persistent Block Storage

While S3 is designed for object storage, applications often require a traditional disk attached to compute resources.

Amazon Elastic Block Store (EBS) provides persistent block storage for EC2 instances.

An EBS volume behaves like a physical hard drive:

* It can be formatted
* Mounted to an operating system
* Used for databases or application files
* Detached and attached to another instance in the same Availability Zone

Unlike temporary instance storage, EBS data survives an EC2 stop/start cycle.

---

## Exploring EBS Volumes

The EC2 dashboard shows the instances and attached storage volumes. The available EBS volumes can also be retrieved using AWS CLI:

```bash
aws ec2 describe-volumes \
--query "Volumes[*].{ID:VolumeId,Size:Size,Type:VolumeType,Encrypted:Encrypted}" \
--output table
```
![](./Screenshot%202026-09-05%20030000.png)


The output reveals important information:

* Volume ID
* Storage size
* Volume type
* Encryption status

Encryption is a critical security control because EBS often contains operating system files, application data, or sensitive information.

---

## EBS Snapshots

Snapshots provide point-in-time backups of EBS volumes.

They are useful for:

* Disaster recovery
* Creating new volumes
* Migrating workloads

Snapshots are incremental, meaning AWS stores only changed blocks after the first snapshot.

However, snapshots require careful permission management. A publicly shared snapshot can expose sensitive data.

Snapshots can be reviewed with:

```bash
aws ec2 describe-snapshots --owner-ids self
```

Security considerations:

* Enable EBS encryption
* Avoid public snapshot sharing
* Remove unused snapshots
* Review permissions regularly

---

## Investigating Attached Storage

The lab instance contains an additional EBS volume.

After connecting through AWS Systems Manager:

```bash
aws ssm start-session --target instance-id
```

The attached disks can be identified:

![](./Screenshot%202026-09-05%20023734.png)
---

# Amazon EFS: Shared File Storage

Amazon Elastic File System (EFS) provides a managed network file system that multiple EC2 instances can access simultaneously.

Unlike EBS, which is attached to a single instance, EFS provides shared storage over the NFS protocol.

Common use cases include:

* Shared application files
* Content management systems
* Web server clusters
* Machine learning workloads

EFS automatically scales as storage requirements change, removing the need for manual capacity planning.

---

## Understanding EFS Mount Targets

To connect EC2 instances to EFS, AWS creates mount targets inside subnets.

A mount target contains:

* Network interface
* IP address
* Security Group controls

The file system itself remains independent from compute resources.

---

# Key Security Lessons

Cloud storage security depends heavily on correct access control.

During this lab, the main security concepts explored were:

* S3 requires strict bucket permissions to prevent accidental exposure.
* EBS volumes and snapshots should always be encrypted.
* EFS access should be restricted using Security Groups and IAM authorisation.
* Storage permissions should follow the Principle of Least Privilege.

Cloud storage is not only about where data is stored. It is about who can access it, how that access is controlled, and how quickly the environment can recover when something goes wrong.

---

> QXV0aG9yOiBodHRwczovL2dpdGh1Yi5jb20vaGFzaC01NDU=

