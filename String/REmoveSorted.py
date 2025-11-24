# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


def deleteDuplicates(head):
    current = head
    
    while current and current.next:
        if current.val == current.next.val:
            current.next = current.next.next   # Skip duplicate
        else:
            current = current.next
    
    return head


# Helper: build linked list from Python list
def build_list(arr):
    if not arr:
        return None
    head = ListNode(arr[0])
    current = head
    for val in arr[1:]:
        current.next = ListNode(val)
        current = current.next
    return head


# Helper: convert linked list to Python list
def to_list(head):
    result = []
    current = head
    while current:
        result.append(current.val)
        current = current.next
    return result


# ----- Example Testcases -----

head = build_list([1,1,2])
head = deleteDuplicates(head)
print(to_list(head))   # Output: [1, 2]

head = build_list([1,1,2,3,3])
head = deleteDuplicates(head)
print(to_list(head))   # Output: [1, 2, 3]
