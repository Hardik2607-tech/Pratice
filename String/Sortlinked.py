# Define a simple linked list node structure
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next




def list_to_linkedlist(arr):
    """Convert a Python list into a linked list."""
    dummy = ListNode()
    curr = dummy
    for num in arr:
        curr.next = ListNode(num)
        curr = curr.next
    return dummy.next


def linkedlist_to_list(head):
    """Convert a linked list back into a Python list."""
    arr = []
    while head:
        arr.append(head.val)
        head = head.next
    return arr




def merge(l1, l2):
    """Merge two sorted linked lists."""
    dummy = tail = ListNode()
    while l1 and l2:
        if l1.val < l2.val:
            tail.next = l1
            l1 = l1.next
        else:
            tail.next = l2
            l2 = l2.next
        tail = tail.next
    tail.next = l1 or l2
    return dummy.next


def sortList(head):
    """Sort the linked list using merge sort."""
    # Base case: empty or single node
    if not head or not head.next:
        return head

    # Split the list into two halves
    slow, fast = head, head.next
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next

    mid = slow.next
    slow.next = None  # Break the list

    # Recursively sort both halves
    left = sortList(head)
    right = sortList(mid)

    # Merge the sorted halves
    return merge(left, right)




if __name__ == "__main__":
    # Example 1
    head = list_to_linkedlist([4, 2, 1, 3])
    sorted_head = sortList(head)
    print(linkedlist_to_list(sorted_head))  # Output: [1, 2, 3, 4]

    # Example 2
    head = list_to_linkedlist([-1, 5, 3, 4, 0])
    sorted_head = sortList(head)
    print(linkedlist_to_list(sorted_head))  # Output: [-1, 0, 3, 4, 5]

    # Example 3
    head = list_to_linkedlist([])
    sorted_head = sortList(head)
    print(linkedlist_to_list(sorted_head))  # Output: []
