# cook your code here
from itertools import imap
t = int(raw_input())

for _ in xrange(t):
    N, M, K = imap(int, raw_input().split())

    a = []

    for _ in xrange(N):
        a.append(list(imap(int, raw_input().split())))

    dp_store = [0] * N
    for row in xrange(N):
        dp_store[row] = [0] * M

    dp_store[0][0] = a[0][0]
    for col in xrange(M):
        dp_store[0][col] = a[0][col] + dp_store[0][col-1]

    for row in xrange(N):
        dp_store[row][0] = a[row][0] + dp_store[row-1][0]

    for row in xrange(1, N):
        for col in xrange(1, M):
            dp_store[row][col] = dp_store[row-1][col] + dp_store[row][col-1] - dp_store[row-1][col-1] + a[row][col]

    count = 0

    for row in xrange(N):
        for col in xrange(M):
            if a[row][col] >= K:
                count += 1

    row_start_prev = None

    for l in xrange(2, min(N, M) + 1):

        suba_sum = dp_store[l-1][l-1]

        if suba_sum >= K * l * l:
            count += (M - (l-1)) * (N - (l-1))
            continue

        row_start = None
        if row_start_prev == None:
            row_start_prev = l-1

        for i in xrange(row_start_prev, N):
            if sum(a[i][-l:]) >= l * K:
                row_start = i
                break
        if row_start == None:
            continue
        row_start_prev = max(row_start, l)

        prev_suba_sum = 0
        rest_worthy = False
        for row in xrange(row_start, N):

            col_start = None
            left = l-1
            right = M-1

            while left <= right:
                mid = (left + right) / 2

                dp_mat = dp_store[row][mid] \
                                - (0 if row - l < 0 else dp_store[row-l][mid]) \
                                - (0 if mid - l < 0 else dp_store[row][mid-l]) \
                                + (0 if mid - l < 0 or row - l < 0 else dp_store[row-l][mid-l])

                if dp_mat < K * l * l:
                    left = mid + 1
                elif dp_mat >= K * l * l:
                    right = mid - 1
                    col_start = mid
                
            if col_start != None:
                if col_start == l-1:
                    count += (M - col_start) * (N - row)
                    break
                else:
                    count += (M - col_start)
                    continue

    print count