def validIPAddress(queryIP: str) -> str:
    def isIPv4(ip):
        parts = ip.split('.')
        if len(parts) != 4:
            return False
        for part in parts:
            if not part.isdigit():
                return False
            if (part[0] == '0' and len(part) > 1) or not 0 <= int(part) <= 255:
                return False
        return True

    def isIPv6(ip):
        parts = ip.split(':')
        if len(parts) != 8:
            return False
        hex_digits = '0123456789abcdefABCDEF'
        for part in parts:
            if not (1 <= len(part) <= 4) or any(c not in hex_digits for c in part):
                return False
        return True

    if queryIP.count('.') == 3 and isIPv4(queryIP):
        return "IPv4"
    elif queryIP.count(':') == 7 and isIPv6(queryIP):
        return "IPv6"
    else:
        return "Neither"


# Example usage:
if __name__ == "__main__":
    print(validIPAddress("172.16.254.1"))                    # IPv4
    print(validIPAddress("2001:0db8:85a3:0:0:8A2E:0370:7334"))  # IPv6
    print(validIPAddress("256.256.256.256"))                 # Neither
    print(validIPAddress("192.168.01.1"))                    # Neither
    print(validIPAddress("02001:0db8:85a3:0000:0000:8a2e:0370:7334"))  # Neither
