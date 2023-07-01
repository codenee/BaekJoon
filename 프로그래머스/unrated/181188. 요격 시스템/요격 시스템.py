def solution(targets):
    answer = 1
    targets.sort(key=lambda x : x[1])
    now = targets[0][1]
    for i in range(1, len(targets)):
        if now <= targets[i][0] :
            answer += 1
            now = targets[i][1]
        else :
            min(now, targets[i][1])
    return answer