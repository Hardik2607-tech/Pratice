# Definition for singly-linked list
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def insertionSortList(head):
    dummy = ListNode(0)
    curr = head

    while curr:
        prev = dummy
        while prev.next and prev.next.val < curr.val:
            prev = prev.next

        nxt = curr.next
        curr.next = prev.next
        prev.next = curr
        curr = nxt

    return dummy.next


# ---- Helpers to test ----
def list_to_linked(lst):
    dummy = ListNode(0)
    curr = dummy
    for x in lst:
        curr.next = ListNode(x)
        curr = curr.next
    return dummy.next

def linked_to_list(head):
    res = []
    while head:
        res.append(head.val)
        head = head.next
    return res


# ---- Example ----
head = list_to_linked([4, 2, 1, 3])
sorted_head = insertionSortList(head)
print(linked_to_list(sorted_head))   # [1, 2, 3, 4]

head = list_to_linked([-1, 5, 3, 4, 0])
sorted_head = insertionSortList(head)
print(linked_to_list(sorted_head))   # [-1, 0, 3, 4, 5]
