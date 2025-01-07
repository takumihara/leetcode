### step1

ループを回すか再帰。

```python
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        return self._addTwoNumbers(l1, l2, 0)

    def _addTwoNumbers(self, l1, l2, carry):
        if not l1 and not l2 and carry == 0:
            return None
        l1_val = l1.val if l1 else 0
        l1_next = l1.next if l1 else None
        l2_val = l2.val if l2 else 0
        l2_next = l2.next if l2 else None
        val = l1_val + l2_val + carry
        carry = val // 10
        val %= 10
        next_ = self._addTwoNumbers(l1_next, l2_next, carry)
        return ListNode(val, next_)

```

### step2

みたもの

- https://github.com/hayashi-ay/leetcode/pull/24
  - get_value とか関数出すのあり
- ## https://github.com/BumbuShoji/Leetcode/pull/6
