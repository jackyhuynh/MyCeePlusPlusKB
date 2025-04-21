# More Topics on Hashing

While MD5 and SHA-1 are common, keep in mind they have known security vulnerabilities and are generally not recommended for security-sensitive applications like password hashing. SHA-256 is a more secure option.

Here are basic examples using C++ for each, leveraging common libraries:

**1. MD5 Example (using a third-party library)**

Since MD5 is not directly available in the standard C++ library, we'll use a simple third-party implementation. For practical purposes, you might want to integrate a more robust and well-maintained library.

```cpp
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "md5.h" // Assuming you have an "md5.h" header file

std::string md5_hash(const std::string& input) {
    return md5(input); // Assuming the md5 function returns a hex string
}

int main() {
    std::string text = "Hello, MD5!";
    std::string hash = md5_hash(text);
    std::cout << "MD5 Hash of \"" << text << "\": " << hash << std::endl;
    return 0;
}
```

**Note:** You'll need to find and include an `md5.h` and `md5.cpp` implementation. A simple search online will provide several options.

**2. SHA-1 Example (using OpenSSL)**

OpenSSL is a widely used cryptography library. Will need to have it installed and linked to your project.

```cpp
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <openssl/sha.h>
#include <vector>

std::string sha1_hash(const std::string& input) {
    unsigned char hash[SHA_DIGEST_LENGTH];
    SHA1(reinterpret_cast<const unsigned char*>(input.c_str()), input.length(), hash);
    std::stringstream ss;
    for (int i = 0; i < SHA_DIGEST_LENGTH; ++i) {
        ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(hash[i]);
    }
    return ss.str();
}

int main() {
    std::string text = "Hello, SHA-1!";
    std::string hash = sha1_hash(text);
    std::cout << "SHA-1 Hash of \"" << text << "\": " << hash << std::endl;
    return 0;
}
```

**3. SHA-256 Example (using OpenSSL)**

Similar to SHA-1, we can use OpenSSL for SHA-256.

```cpp
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <openssl/sha.h>
#include <vector>

std::string sha256_hash(const std::string& input) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256(reinterpret_cast<const unsigned char*>(input.c_str()), input.length(), hash);
    std::stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(hash[i]);
    }
    return ss.str();
}

int main() {
    std::string text = "Hello, SHA-256!";
    std::string hash = sha256_hash(text);
    std::cout << "SHA-256 Hash of \"" << text << "\": " << hash << std::endl;
    return 0;
}
```

**Important Considerations for Uniform Distribution:**

* **Cryptographic Hash Functions are Designed for This:** MD5, SHA-1, and SHA-256 are specifically designed to produce hash values that appear to be uniformly distributed. This means that small changes in the input data should result in seemingly random and significantly different hash values.
* **Output Range:** The output range is determined by the bit length of the hash function:
    * MD5: 128 bits (32 hexadecimal characters)
    * SHA-1: 160 bits (40 hexadecimal characters)
    * SHA-256: 256 bits (64 hexadecimal characters)
* **Collisions:** While these functions aim for uniformity, collisions (different inputs producing the same hash) are theoretically possible due to the pigeonhole principle. The likelihood of collisions varies depending on the hash function and the amount of data being hashed. SHA-256 has a much larger output space, making collisions significantly less likely than MD5 or SHA-1.
* **Security Implications:** As mentioned earlier, MD5 and SHA-1 are considered cryptographically weak for many modern security applications due to the discovery of practical collision attacks. SHA-256 is generally considered more secure.

These examples provide a basic illustration of how to generate hashes using these common algorithms in C++. Remember to choose the appropriate hash function based on your specific needs and security requirements. For applications requiring strong security, SHA-256 or even stronger algorithms like SHA-3 are recommended.

### More Topics:
- https://developer.nvidia.com/blog/maximizing-performance-with-massively-parallel-hash-maps-on-gpus/
- https://www.crowdstrike.com/en-us/cybersecurity-101/data-protection/data-hashing/
- https://www.geeksforgeeks.org/consistent-hashing/
