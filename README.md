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
   ```
2. **Install dependencies:**
   The server requires Python 3.6+ and standard libraries. If there are third-party dependencies, install them using:
   ```bash
   pip install -r requirements.txt
   ```

## Usage

1. **Run the server:**
   ```bash
   python dns_server.py --mode recursive    # For recursive mode
   python dns_server.py --mode iterative    # For iterative mode
   ```

2. **Configuration:**
   - Edit the configuration file (if present) to specify DNS root servers, cache settings, or supported record types.
   - By default, the server listens on port 5353 (can be changed via command-line).

3. **Testing:**
   - Use the provided client script or a tool like `dig` or `nslookup`:
     ```bash
     dig @localhost -p 5353 example.com
     ```

## Project Structure

```
dns_implementation/
├── dns_server.py       # Main server code
├── dns_client.py       # Sample DNS client
├── utils/              # Utilities and helper functions
├── tests/              # Unit tests
├── README.md           # Project documentation
└── requirements.txt    # Python dependencies
```

## Contributing

Contributions are welcome! Please open issues or submit pull requests for improvements, bug fixes, or new features.

1. Fork the repository and clone it locally.
2. Create a new branch.
3. Make your changes and add tests.
4. Submit a pull request.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Contact

For questions or feedback, please open an issue or reach out via [GitHub Issues](https://github.com/aditya-tangirala/dns_implementation/issues).
