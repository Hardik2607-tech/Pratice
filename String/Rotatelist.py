# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


def rotateRight(head, k):
    if not head or not head.next or k == 0:
        return head

    # Step 1: compute length
    length = 1
    tail = head
    while tail.next:
        tail = tail.next
        length += 1

    # Step 2: make list circular
    tail.next = head

    # Step 3: effective rotation
    k = k % length
    steps_to_new_tail = length - k - 1

    # Step 4: find new tail
    new_tail = head
    for _ in range(steps_to_new_tail):
        new_tail = new_tail.next

    # Step 5: new head
    new_head = new_tail.next

    # Step 6: break circle
    new_tail.next = None

    return new_head


# Helper: build linked list from Python list
def build_list(arr):
    if not arr:
        return None
    head = ListNode(arr[0])
    cur = head
    for val in arr[1:]:
        cur.next = ListNode(val)
        cur = cur.next
    return head

# Helper: convert linked list back to Python list
def to_list(head):
    result = []
    while head:
        result.append(head.val)
        head = head.next
    return result


# ------------------------- Example Usage -------------------------

head = build_list([1, 2, 3, 4, 5])
k = 2
new_head = rotateRight(head, k)
print(to_list(new_head))   # Output: [4, 5, 1, 2, 3]

head = build_list([0, 1, 2])
k = 4
new_head = rotateRight(head, k)
print(to_list(new_head))   # Output: [2, 0, 1]
