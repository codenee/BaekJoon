def solution(sequence, k):
    answer = []
    
    sum = 0
    start = 0
    end = 0
    for i in range(len(sequence)):
        end = i
        sum += sequence[end]
        while k < sum:
            sum -= sequence[start]
            start += 1
        if k == sum:    
            if len(answer) == 0 or end - start < answer[1] - answer[0]:
                answer = [start, end]
        
    return answer
