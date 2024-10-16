### 1st

```python
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        index_by_num = {}
        for i, num in enumerate(nums):
            if target - num in index_by_num:
                return [i, index_by_num[target - num]]
            index_by_num[num] = i
```

### 2nd

見たもの

- LeetCode の解説
  - `complement`
- https://github.com/hayashi-ay/leetcode/pull/14
- https://github.com/ryoooooory/LeetCode/pull/18
  - `numToIndex`
- https://github.com/seal-azarashi/leetcode/pull/11

きになるところ

- ループ後の帰り値
  - leetcode の解説は、`[]`
  - hayashi さんは、`[-1, -1]` or exception
  - https://github.com/seal-azarashi/leetcode/pull/11#discussion_r1672537855
    - 面接官と話して決めるで良い
- 同じ数値が二回きた時の処理がちょっとわかりづらい気がする
  - まあコードから自明か？

```python
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        index_by_num = {}
        for i, num in enumerate(nums):
            complement = target - num
            if complement in index_by_num:
                return [i, index_by_num[complement]]
            index_by_num[num] = i
        raise Exception("unreachable")
```

### 3rd

```python
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        index_by_num = {}
        for i, num in enumerate(nums):
            complement = target - num
            if complement in index_by_num:
                return [i, index_by_num[complement]]
            index_by_num[num] = i
        raise Exception("unreachable")
```
