### 문자열 압축

> "aaaaaaaaaabbbbb" = "10a5b" 처럼 중복 횟수가 2자리가 넘어가는 경우를 생각해야 한다.

### 주차 요금 계산

>문자열 처리보다 시간 계산에 시간을 더 많이 썻는데 모든 시간을 분으로 바꿔서 계산하면 더 쉽게 해결할 수 있다.

### 가장 큰 수

> 문제를 처음 읽을때는 완전탐색 풀이를 떠올렸다. 모든 조합을 비교해서 가장 큰 수를 고르고 싶었는데 시간초과에 걸려서 다른 방법을 생각해야했다.
>
> 다른 풀이는 문자열 자체를 비교해가면서 정렬하는 것이다. 숫자들을 조합해서 가장 큰 수가 나오려면 일단 가장 앞의 수가 크게 정렬해야한다.
>
> 이때 문자열의 정렬이므로 단순히 아스키코드 값을 비교하는 것이 아니라 비교할 두 대상을 이어 붙인다음의 크기를 비교해야한다. 그래서 비교 함수를 새롭게 정의해 주었고 문제를 해결할 수 있었다.

### 오픈채팅방

> uid를 확인하면서 변경 사항이 생기면 uid(= key)에 해당하는 name(= value) 값을 변경해주면 되는 쉬운 문제지만 Enter, Change와 Leave 명령어는 주어지는 문자열의 개수가 다르다는 점을 확인하지 못했다.
>
> 문제를 다시 제대로 읽어본다면 해결할 수 있는 문제이다.