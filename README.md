# DNS Implementation

This repository contains the implementation of a DNS server that supports both **recursive** and **iterative** modes. The project is designed for educational purposes and demonstrates the fundamental principles behind DNS resolution using Python.

## Features

- **Recursive DNS Server:** Resolves queries by forwarding them up the DNS tree if it cannot answer locally, returning full responses to clients.
- **Iterative DNS Server:** Responds with the best information it has, allowing clients to pursue resolution from referenced DNS servers.
- Configurable for both modes of operation.
- Handles A (IPv4 address) record queries.
- Logs query and response information for debugging and analysis.

## How It Works

- The server listens for incoming DNS queries on a specified port.
- Based on its configuration (recursive or iterative), it processes the queries accordingly:
  - **Recursive Mode:** The server carries out the entire DNS resolution process on behalf of the client.
  - **Iterative Mode:** The server provides referrals to other DNS servers when it does not know the answer.
- Responses are sent back to the client using the proper DNS protocol format.

## Installation

1. **Clone the repository:**
   ```bash
   git clone https://github.com/aditya-tangirala/dns_implementation.git
   cd dns_implementation
