class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


def reverseBetween(head, left, right):
    if not head or left == right:
        return head

    dummy = ListNode(0)
    dummy.next = head
    pre = dummy

    # Step 1: move pre to the node before `left`
    for _ in range(left - 1):
        pre = pre.next

    # Step 2: reverse the sublist
    curr = pre.next
    prev = None

    for _ in range(right - left + 1):
        nxt = curr.next
        curr.next = prev
        prev = curr
        curr = nxt

    # Step 3: reconnect
    pre.next.next = curr   # Connect tail of reversed sublist
    pre.next = prev        # Connect pre to new head of reversed part

    return dummy.next


# -----------------------
# Helper functions for testing
# -----------------------

def build_list(arr):
    """Build a linked list from a Python list."""
    dummy = ListNode(0)
    curr = dummy
    for x in arr:
        curr.next = ListNode(x)
        curr = curr.next
    return dummy.next


def to_list(head):
    """Convert a linked list back to a Python list."""
    res = []
    while head:
        res.append(head.val)
        head = head.next
    return res


# -----------------------
# Example Test
# -----------------------

head = build_list([1, 2, 3, 4, 5])
new_head = reverseBetween(head, 2, 4)
print(to_list(new_head))    # Output: [1, 4, 3, 2, 5]
