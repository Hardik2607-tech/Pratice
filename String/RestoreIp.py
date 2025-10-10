def restore_ip_addresses(s):
    res = []

    def backtrack(start, path):
        # If 4 segments and all digits used
        if len(path) == 4:
            if start == len(s):
                res.append(".".join(path))
            return

        # Try segments of length 1 to 3
        for length in range(1, 4):
            if start + length > len(s):
                break

            segment = s[start:start+length]

            # Skip invalid segments
            if (segment.startswith('0') and len(segment) > 1) or int(segment) > 255:
                continue

            backtrack(start + length, path + [segment])

    backtrack(0, [])
    return res


# 🧪 Example usage
if __name__ == "__main__":
    print(restore_ip_addresses("25525511135"))  # ["255.255.11.135","255.255.111.35"]
    print(restore_ip_addresses("0000"))         # ["0.0.0.0"]
    print(restore_ip_addresses("101023"))       # ["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
