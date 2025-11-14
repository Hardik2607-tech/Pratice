def replaceWords(dictionary, sentence):
    # Build Trie
    trie = {}
    END = "#"

    for root in dictionary:
        node = trie
        for ch in root:
            node = node.setdefault(ch, {})
        node[END] = root   # Mark end of a valid root

    # Find shortest root for a single word
    def find_root(word):
        node = trie
        for ch in word:
            if ch not in node:     # No matching root path
                return word
            node = node[ch]
            if END in node:        # Found shortest root
                return node[END]
        return word                # No root matched

    # Process each word in the sentence
    return " ".join(find_root(w) for w in sentence.split())


if __name__ == "__main__":
    dictionary = ["cat", "bat", "rat"]
    sentence = "the cattle was rattled by the battery"

    result = replaceWords(dictionary, sentence)
    print(result)
    # Expected output:
    # "the cat was rat by the bat"
