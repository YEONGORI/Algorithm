### 두 큐 합 같게 만들기
>이 문제를 해결할 때 큐를 pop하는 과정에서 vector의 erase 함수를 사용했다.
>earse 함수는 container size(n)만큼의 시간복잡도 O(n)을 갖는다.
>
>따라서 문제에서 제시된 두 벡터(queue1, queue2)를 순회하는 시간 O(n)에 O(n)이 곱해져 총 O(n^2)의 시간복잡도를 갖게되어 시간초과가 발생한다.
>
>결국 문제를 해결하기 위해서는 두 벡터를 배열처럼 사용해야한다. 때문에 두 배열(벡터)의 인덱스인 i1, i2를 사용해 배열의 시작 인덱스를 pop이 발생할 때 마다 1씩 늘려주었다.

---