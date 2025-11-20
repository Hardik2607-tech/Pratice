class NestedInteger:
    # This is a full implementation so you can run & test locally.
    # LeetCode already provides this, so you do NOT include it there.
    def __init__(self, value=None):
        if value is None:
            self._value = None
            self._list = []
        else:
            self._value = value
            self._list = None

    def isInteger(self):
        return self._value is not None

    def getInteger(self):
        return self._value

    def setInteger(self, value):
        self._value = value
        self._list = None

    def add(self, elem):
        if self._list is None:
            self._list = []
        self._list.append(elem)

    def getList(self):
        return self._list

    def __repr__(self):
        if self.isInteger():
            return str(self._value)
        return "[" + ",".join(repr(x) for x in self._list) + "]"


def deserialize(s: str) -> NestedInteger:
    # Case 1: input is just a number
    if s[0] != '[':
        return NestedInteger(int(s))

    stack = []
    num = ""
    neg = False

    for c in s:
        if c == "-":
            neg = True

        elif c.isdigit():
            num += c

        elif c == "[":
            stack.append(NestedInteger())

        elif c == "," or c == "]":
            # Add number to the last list if exists
            if num:
                val = -int(num) if neg else int(num)
                stack[-1].add(NestedInteger(val))
                num = ""
                neg = False

            # End of a list " ] "
            if c == "]":
                top = stack.pop()
                if stack:
                    stack[-1].add(top)
                else:
                    return top

    return None



print(deserialize("324"))                     # Expect: 324
print(deserialize("[123,[456,[789]]]"))       # Expect: [123,[456,[789]]]
print(deserialize("[-10,[20,-30]]"))          # Expect: [-10,[20,-30]]
