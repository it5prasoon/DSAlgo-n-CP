import random
import sys


def reset_ppo(le):
    something = []
    for j_iter in range(le):
        something.append(0)
    return something


def leaked_answers(N, M, K):
    marks_per_set_col = reset_ppo(K)
    for j_iter in range(N):
        point_per_option_row = reset_ppo(M)
        answers = list(sys.stdin.readline().split())
        for k_iter in range(K):
            point_per_option_row[int(answers[k_iter]) - 1] += 1
        best_option = [i for i, x in enumerate(point_per_option_row) if x == max(point_per_option_row)]
        best_option = list(map(lambda x: x + 1, best_option))
        print(best_option[random.randint(0, len(best_option) - 1)], end=" ")


test_cases = int(sys.stdin.readline())
for i_iter in range(test_cases):
    sec_line = list(sys.stdin.readline().split())
    NN = int(sec_line[0])
    MM = int(sec_line[1])
    KK = int(sec_line[2])
    leaked_answers(NN, MM, KK)