def narayana(seq):
    count = len(seq)
    i = count
    while(True):
        if i < 2:
            return False
        i-=1
        if seq[i] > seq[i-1]:
            break    

    j = count
    while j > i and seq[i-1] >= seq[j-1]:
        j -= 1
        
    seq[i-1], seq[j-1] = seq[j-1], seq[i-1]

    j = count
    while i < j - 1:
        j -= 1
        seq[i], seq[j] = seq[j], seq[i]
        i += 1
    return True


kek = int(input())
nums = []
while kek != 0:
    nums.append(kek % 10)
    kek = int((kek - (kek % 10)) / 10)
nums.reverse()
is_done = narayana(nums)
if is_done:
    for i in range(len(nums)):
        print(nums[i], end='')
else:
    print("-1")