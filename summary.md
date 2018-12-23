1. coin exhange

coinexchange
baekjoon/2293.cpp

전통적인 코인 교환 문제
풀떄 마다 몫과 나머지를 생각하면서,
중복되는 문제에 봉착하다.
아이디어는, 그냥 3원짜리 추가하는 방법의 수는 i - 3 개에서
3원짜리 한개 더 쓴거라 동일하다는 거이다.

```cache[i] += cache[i - coin[k]]

0일 경우, 1개를 정확힌 샌거라 cache[0] = 1 로 두자

2. coin min exchange

baejoon/2294.cpp

위에 풀고난 뒤에도 몫하고 나머지로 풀다가, 해답 살펴봄

```cache[i] += cache[i - coin[k]]

이것도 그냥 쌓으면 된다

3. 배수로 이루어진 최소값

baekjoon/11047.cpp

범위가 1억, 동전가치는 1백만
단, 주석이 중요한다 모든 변수가 배수로 구성, 최하 변수는 무조건 1
그냥 꺼꾸로 나눠떨어트려가면된다

```n = n % r

위에걸 쓰면 조건 검사 안해도 되어 편함

4. LCS

baekjooon/9251.cpp
baekjooon/9252.cpp

가장 긴 공통 문자열 찾는 것
아직 이건 전에 봤던걸 기역

```int m = max(cache[x+1][y], cache[x][y+1]);
```int n = cache[x+1][y+1] + (a[x] == b[y]);
```cache[x][y] = max(n, m);

비교해가면서 쌓아가면됨 (꺼꾸로 찾지 않아도 되는듯)

    Φ A G G T A B 
   ---------------- 
Φ | 0 0 0 0 0 0 0 
G | 0 0 1 1 1 1 1 
X | 0 0 1 1 1 1 1 
T | 0 0 1 1 2 2 2 
X | 0 0 1 1 2 2 2 
A | 0 1 1 1 2 3 3 
Y | 0 1 1 1 2 3 3 
B | 0 1 1 1 2 3 4


    while (cache[x][y] != 0)
    {
        if (cache[x][y] == cache[x][y+1]) y++;
        else if (cache[x][y] == cache[x+1][y]) x++;
        else
        {
            str << a[x];
            x++; y++;
        }
    }

무조건 따라가서 대각선에서만 추가해주면 된다
